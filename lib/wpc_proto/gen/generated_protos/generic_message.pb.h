/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.8 */

#ifndef PB_WP_GENERIC_MESSAGE_PB_H_INCLUDED
#define PB_WP_GENERIC_MESSAGE_PB_H_INCLUDED
#include <pb.h>
#include "config_message.pb.h"
#include "data_message.pb.h"
#include "otap_message.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _wp_WirepasMessage {
    struct _wp_StatusEvent *status_event;
    struct _wp_GetConfigsReq *get_configs_req;
    struct _wp_GetConfigsResp *get_configs_resp;
    struct _wp_SetConfigReq *set_config_req;
    struct _wp_SetConfigResp *set_config_resp;
    struct _wp_SendPacketReq *send_packet_req;
    struct _wp_SendPacketResp *send_packet_resp;
    struct _wp_PacketReceivedEvent *packet_received_event;
    struct _wp_GetScratchpadStatusReq *get_scratchpad_status_req;
    struct _wp_GetScratchpadStatusResp *get_scratchpad_status_resp;
    struct _wp_UploadScratchpadReq *upload_scratchpad_req;
    struct _wp_UploadScratchpadResp *upload_scratchpad_resp;
    struct _wp_ProcessScratchpadReq *process_scratchpad_req;
    struct _wp_ProcessScratchpadResp *process_scratchpad_resp;
    struct _wp_GetGwInfoReq *get_gateway_info_req;
    struct _wp_GetGwInfoResp *get_gateway_info_resp;
    struct _wp_SetScratchpadTargetAndActionReq *set_scratchpad_target_and_action_req;
    struct _wp_SetScratchpadTargetAndActionResp *set_scratchpad_target_and_action_resp;
} wp_WirepasMessage;

typedef struct _wp_CustomerMessage {
    /* Customer name is needed to avoid any collision between different customer implementation */
    char customer_name[128]; /* Can be freely used for enhancing API by customers */
} wp_CustomerMessage;

typedef struct _wp_GenericMessage {
    struct _wp_WirepasMessage *wirepas;
    struct _wp_CustomerMessage *customer;
} wp_GenericMessage;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define wp_WirepasMessage_init_default           {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}
#define wp_CustomerMessage_init_default          {""}
#define wp_GenericMessage_init_default           {NULL, NULL}
#define wp_WirepasMessage_init_zero              {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}
#define wp_CustomerMessage_init_zero             {""}
#define wp_GenericMessage_init_zero              {NULL, NULL}

/* Field tags (for use in manual encoding/decoding) */
#define wp_WirepasMessage_status_event_tag       1
#define wp_WirepasMessage_get_configs_req_tag    2
#define wp_WirepasMessage_get_configs_resp_tag   3
#define wp_WirepasMessage_set_config_req_tag     4
#define wp_WirepasMessage_set_config_resp_tag    5
#define wp_WirepasMessage_send_packet_req_tag    6
#define wp_WirepasMessage_send_packet_resp_tag   7
#define wp_WirepasMessage_packet_received_event_tag 8
#define wp_WirepasMessage_get_scratchpad_status_req_tag 9
#define wp_WirepasMessage_get_scratchpad_status_resp_tag 10
#define wp_WirepasMessage_upload_scratchpad_req_tag 11
#define wp_WirepasMessage_upload_scratchpad_resp_tag 12
#define wp_WirepasMessage_process_scratchpad_req_tag 13
#define wp_WirepasMessage_process_scratchpad_resp_tag 14
#define wp_WirepasMessage_get_gateway_info_req_tag 15
#define wp_WirepasMessage_get_gateway_info_resp_tag 16
#define wp_WirepasMessage_set_scratchpad_target_and_action_req_tag 17
#define wp_WirepasMessage_set_scratchpad_target_and_action_resp_tag 18
#define wp_CustomerMessage_customer_name_tag     1
#define wp_GenericMessage_wirepas_tag            1
#define wp_GenericMessage_customer_tag           2

/* Struct field encoding specification for nanopb */
#define wp_WirepasMessage_FIELDLIST(X, a) \
X(a, POINTER,  OPTIONAL, MESSAGE,  status_event,      1) \
X(a, POINTER,  OPTIONAL, MESSAGE,  get_configs_req,   2) \
X(a, POINTER,  OPTIONAL, MESSAGE,  get_configs_resp,   3) \
X(a, POINTER,  OPTIONAL, MESSAGE,  set_config_req,    4) \
X(a, POINTER,  OPTIONAL, MESSAGE,  set_config_resp,   5) \
X(a, POINTER,  OPTIONAL, MESSAGE,  send_packet_req,   6) \
X(a, POINTER,  OPTIONAL, MESSAGE,  send_packet_resp,   7) \
X(a, POINTER,  OPTIONAL, MESSAGE,  packet_received_event,   8) \
X(a, POINTER,  OPTIONAL, MESSAGE,  get_scratchpad_status_req,   9) \
X(a, POINTER,  OPTIONAL, MESSAGE,  get_scratchpad_status_resp,  10) \
X(a, POINTER,  OPTIONAL, MESSAGE,  upload_scratchpad_req,  11) \
X(a, POINTER,  OPTIONAL, MESSAGE,  upload_scratchpad_resp,  12) \
X(a, POINTER,  OPTIONAL, MESSAGE,  process_scratchpad_req,  13) \
X(a, POINTER,  OPTIONAL, MESSAGE,  process_scratchpad_resp,  14) \
X(a, POINTER,  OPTIONAL, MESSAGE,  get_gateway_info_req,  15) \
X(a, POINTER,  OPTIONAL, MESSAGE,  get_gateway_info_resp,  16) \
X(a, POINTER,  OPTIONAL, MESSAGE,  set_scratchpad_target_and_action_req,  17) \
X(a, POINTER,  OPTIONAL, MESSAGE,  set_scratchpad_target_and_action_resp,  18)
#define wp_WirepasMessage_CALLBACK NULL
#define wp_WirepasMessage_DEFAULT NULL
#define wp_WirepasMessage_status_event_MSGTYPE wp_StatusEvent
#define wp_WirepasMessage_get_configs_req_MSGTYPE wp_GetConfigsReq
#define wp_WirepasMessage_get_configs_resp_MSGTYPE wp_GetConfigsResp
#define wp_WirepasMessage_set_config_req_MSGTYPE wp_SetConfigReq
#define wp_WirepasMessage_set_config_resp_MSGTYPE wp_SetConfigResp
#define wp_WirepasMessage_send_packet_req_MSGTYPE wp_SendPacketReq
#define wp_WirepasMessage_send_packet_resp_MSGTYPE wp_SendPacketResp
#define wp_WirepasMessage_packet_received_event_MSGTYPE wp_PacketReceivedEvent
#define wp_WirepasMessage_get_scratchpad_status_req_MSGTYPE wp_GetScratchpadStatusReq
#define wp_WirepasMessage_get_scratchpad_status_resp_MSGTYPE wp_GetScratchpadStatusResp
#define wp_WirepasMessage_upload_scratchpad_req_MSGTYPE wp_UploadScratchpadReq
#define wp_WirepasMessage_upload_scratchpad_resp_MSGTYPE wp_UploadScratchpadResp
#define wp_WirepasMessage_process_scratchpad_req_MSGTYPE wp_ProcessScratchpadReq
#define wp_WirepasMessage_process_scratchpad_resp_MSGTYPE wp_ProcessScratchpadResp
#define wp_WirepasMessage_get_gateway_info_req_MSGTYPE wp_GetGwInfoReq
#define wp_WirepasMessage_get_gateway_info_resp_MSGTYPE wp_GetGwInfoResp
#define wp_WirepasMessage_set_scratchpad_target_and_action_req_MSGTYPE wp_SetScratchpadTargetAndActionReq
#define wp_WirepasMessage_set_scratchpad_target_and_action_resp_MSGTYPE wp_SetScratchpadTargetAndActionResp

#define wp_CustomerMessage_FIELDLIST(X, a) \
X(a, STATIC,   REQUIRED, STRING,   customer_name,     1)
#define wp_CustomerMessage_CALLBACK NULL
#define wp_CustomerMessage_DEFAULT NULL

#define wp_GenericMessage_FIELDLIST(X, a) \
X(a, POINTER,  OPTIONAL, MESSAGE,  wirepas,           1) \
X(a, POINTER,  OPTIONAL, MESSAGE,  customer,          2)
#define wp_GenericMessage_CALLBACK NULL
#define wp_GenericMessage_DEFAULT NULL
#define wp_GenericMessage_wirepas_MSGTYPE wp_WirepasMessage
#define wp_GenericMessage_customer_MSGTYPE wp_CustomerMessage

extern const pb_msgdesc_t wp_WirepasMessage_msg;
extern const pb_msgdesc_t wp_CustomerMessage_msg;
extern const pb_msgdesc_t wp_GenericMessage_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define wp_WirepasMessage_fields &wp_WirepasMessage_msg
#define wp_CustomerMessage_fields &wp_CustomerMessage_msg
#define wp_GenericMessage_fields &wp_GenericMessage_msg

/* Maximum encoded size of messages (where known) */
/* wp_WirepasMessage_size depends on runtime parameters */
/* wp_GenericMessage_size depends on runtime parameters */
#define WP_GENERIC_MESSAGE_PB_H_MAX_SIZE         wp_CustomerMessage_size
#define wp_CustomerMessage_size                  130

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
