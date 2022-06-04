#ifndef INC_DEBUG_SCREEN_H_
#define INC_DEBUG_SCREEN_H_

#include "string.h"
#include "cmsis_os.h"
#include "touch.h"
#include "ili9341/ili9341.h"

void DBGS_init(void);
void DBGS_tick(void);

#endif /* INC_DEBUG_SCREEN_H_ */
