#ifndef INC_COMM_H_
#define INC_COMM_H_

#include "main.h"
#include "debug_data.h"

#ifdef __cplusplus
extern "C" {
#endif

void COMM_init(void);
void COMM_setupCANFilter(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_COMM_H_ */
