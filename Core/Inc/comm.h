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

#ifdef __cplusplus
}
#endif

#endif /* INC_COMM_H_ */
