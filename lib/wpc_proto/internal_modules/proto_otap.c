/* Wirepas Oy licensed under Apache License, Version 2.0
 *
 * See file LICENSE for full license details.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "wpc.h"
#include "proto_otap.h"
#include "proto_config.h"
#include <pb_encode.h>
#include <pb_decode.h>
#include "platform.h"
#include "common.h"

#define LOG_MODULE_NAME "otap_proto"
#define MAX_LOG_LEVEL INFO_LOG_LEVEL
#include "logger.h"

static app_scratchpad_status_t otap_status = {0};

static bool initialize_otap_variables()
{
    if (WPC_get_local_scratchpad_status(&otap_status) != APP_RES_OK)
    {
        LOGE("Cannot get local scratchpad status\n");
        return false;
    }
    return true;
}

bool Proto_otap_init(void)
{
    /* Read initial config from sink */
    if (!initialize_otap_variables())
    {
        LOGE("All the otap settings cannot be read\n");
    }
    return true;
}

void Proto_otap_close(void)
{

}

wp_ScratchpadType otap_convert_type(uint8_t scrat_type)
{
    switch (scrat_type)
    {
        case 1:
            return wp_ScratchpadType_PRESENT;
        case 2:
            return wp_ScratchpadType_PROCESS;
        case 0:
        default:
            return wp_ScratchpadType_BLANK;
    }
}

wp_ScratchpadStatus otap_convert_status(uint8_t scrat_status)
{
    switch (scrat_status)
    {
        case 0:
            return wp_ScratchpadStatus_SUCCESS;
        case 255:
            return wp_ScratchpadStatus_NEW;
        default:
            return wp_ScratchpadStatus_ERROR;
    }
}

app_proto_res_e Proto_otap_handle_get_scratchpad_status(wp_GetScratchpadStatusReq *req,
                                                        wp_GetScratchpadStatusResp *resp)
{
    app_res_e res = APP_RES_OK;

    // TODO: Add some sanity checks

    // Do we need to refresh otap status ?
    if (!initialize_otap_variables())
    {
        LOGE("All the otap settings cannot be read\n");
        res = APP_RES_INTERNAL_ERROR;
    }

    *resp = (wp_GetScratchpadStatusResp){
        .has_stored_scratchpad = true,
        .stored_scratchpad = { .len = otap_status.scrat_len,
                               .crc = otap_status.scrat_crc,
                               .seq = otap_status.scrat_seq_number, },
        .has_stored_status = true,
        .stored_status = otap_convert_status(otap_status.scrat_status),
        .has_stored_type = true,
        .stored_type = otap_convert_type(otap_status.scrat_type),
        .has_processed_scratchpad = true,
        .processed_scratchpad = { .len = otap_status.processed_scrat_len,
                                  .crc = otap_status.processed_scrat_crc,
                                  .seq = otap_status.processed_scrat_seq_number, },
        .has_firmware_area_id = true,
        .firmware_area_id = otap_status.firmware_memory_area_id,
        .has_target_and_action = false,
    };

    Common_Fill_response_header(&resp->header,
                                req->header.req_id,
                                Common_convert_error_code(res));

    return APP_RES_PROTO_OK;
}

app_proto_res_e Proto_otap_handle_upload_scratchpad(wp_UploadScratchpadReq *req,
                                                    wp_UploadScratchpadResp *resp)
{
    app_res_e res = APP_RES_OK;

    // TODO: Add some sanity checks

    if(req->has_scratchpad)
    {
        LOGI("Upload scratchpad: with seq %d of size %d\n", req->seq, req->scratchpad.size);
        res = APP_RES_INVALID_SCRATCHPAD;
        /* Send the file to the sink */
        res = WPC_upload_local_scratchpad(req->scratchpad.size,
                                          req->scratchpad.bytes,
                                          req->seq);
        if (res == APP_RES_OK)
        {
            /* Update parameters */
            initialize_otap_variables();

            /* Do some sanity check: Do not generate error for that */
            if (otap_status.scrat_len != req->scratchpad.size)
            {
                LOGE("Scratchpad is not loaded correctly (wrong size) %d vs %d\n",
                        otap_status.scrat_len,
                        req->scratchpad.size);
            }

            if (otap_status.scrat_seq_number != req->seq)
            {
                LOGE("Wrong seq number after loading a scratchpad image \n");
            }
        }
        else
        {
            LOGE("Cannot upload local scratchpad\n");
        }
    }
    else
    {
        // No scratchpad, do we erase the existing one ?
        LOGE("Upload scratchpad: no scratchpad\n");
    }

    Common_Fill_response_header(&resp->header,
                                req->header.req_id,
                                Common_convert_error_code(res));

    return APP_RES_PROTO_OK;
}


app_proto_res_e Proto_otap_handle_process_scratchpad(wp_ProcessScratchpadReq *req,
                                                     wp_ProcessScratchpadResp *resp)
{
    app_res_e res = APP_RES_OK;

    // TODO: Add some sanity checks

    res = WPC_update_local_scratchpad();
    if (res != APP_RES_OK)
    {
        LOGE("WPC_update_local_scratchpad failed %d\n", res);
    }
    else
    {
        /* Node must be rebooted to process the scratchpad */
        res = WPC_stop_stack();
        if (res != APP_RES_OK)
        {
            LOGE("WPC_stop_stack failed %d", res);
        }

        /* Read back the variables after the restart */
        initialize_otap_variables();
    }

    Common_Fill_response_header(&resp->header,
                                req->header.req_id,
                                Common_convert_error_code(res));

    return APP_RES_PROTO_OK;
}