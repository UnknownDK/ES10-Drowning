#ifndef OFFLOADING_H
#define OFFLOADING_H

extern EventGroupHandle_t s_wifi_event_group;


// Function prototypes
void wifi_init_sta(void);
void socket_task(void *pvParameters);


#endif // OFFLOADING_H
