#ifndef INC_DEBUG_DATA_H_
#define INC_DEBUG_DATA_H_

#include "stdint.h"
#include "stdbool.h"
#include "cmsis_os.h"
#include "main.h"
#include "data.h"

void DBGD_init(void);
void DBGD_toggleRandom(void);
void DBGD_toggleEnable(void);
void DBGD_resetPeak(void);
void DBGD_stubIncDecAll(bool inc);
void DBGD_tick(void);


#endif /* INC_DEBUG_DATA_H_ */
