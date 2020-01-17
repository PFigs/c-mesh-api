/* Wirepas Oy licensed under Apache License, Version 2.0
 *
 * See file LICENSE for full license details.
 *
 */
#ifndef PLATFORM_H_
#define PLATFORM_H_

bool Platform_init(void);

void Platform_usleep(unsigned int time_us);

/**
 * \brief   Get a timestamp in ms since epoch
 * \Note    If this information is not available on the platform,
 *          a different timesatmp can be used and up to upper layer
 *          to convert it later.
 * \return  Timestamp when the call to this function is made
 */
unsigned long long Platform_get_timestamp_ms_epoch(void);

/**
 * \brief  Call at the beginning of a locked section to send a request
 * \Note   It is up to the platform implementation to see if
 *         this lock must be implemented or not. If all the requests
 *         to the stack are done in the same context, it is useless.
 *         But if poll requests (and indication handling) are not done
 *         from same thread as other API requests, it has to be implemented
 *         accordingly to the architecture chosen.
 */
bool Platform_lock_request(void);

/**
 *
 * \brief  Called at the end of a locked section to send a request
 */
void Platform_unlock_request(void);

/**
 * \brief   Set maximum duration the poll requests are accepted to fail
 * \param   duration_s
 *          maximum duration the polling can fail before exit,
 *          zero equals forever.
 * \return  true if setting is available in platform,
 *          false if setting is not available in platform
 */
bool Platform_set_max_poll_fail_duration(unsigned long duration_s);

void Platform_close(void);

#endif /* PLATFORM_H_ */
