#ifndef INC_COMM_H_
#define INC_COMM_H_

#include "main.h"
#include "debug_data.h"

#define CBUS_ID 0x669

#define CBUS_CMD_LEFT 0x01
#define CBUS_CMD_RIGHT 0x02
#define CBUS_CMD_UP 0x03
#define CBUS_CMD_DOWN 0x04
#define CBUS_CMD_PLAY_PAUSE 0x05
#define CBUS_CMD_1 0x06
#define CBUS_CMD_3 0x07
#define CBUS_CMD_4 0x08
#define CBUS_CMD_5 0x09
#define CBUS_CMD_REPEAT 0x10
#define CBUS_CMD_SCAN 0x11

#ifdef __cplusplus
extern "C" {
#endif

void COMM_init(void);
void COMM_setupCANFilter(void);

void DBGS_handleClick_DISP(void);
void DBGS_handleClick_RETURN(void);
void DBGS_handleClick_MENU(void);
void DBGS_handleClick_MODE(void);
void DBGS_handleClick_UP(void);
void DBGS_handleClick_DOWN(void);
void DBGS_handleClick_LEFT(void);
void DBGS_handleClick_RIGHT(void);
void DBGS_handleClick_CENTER(void);

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#ifdef __cplusplus
}
#endif

#endif /* INC_COMM_H_ */
