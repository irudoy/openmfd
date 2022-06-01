#include "stmpe811.h"

#define TS_I2C_ADDRESS 0x82

typedef struct
{
  uint16_t TouchDetected;
  uint16_t X;
  uint16_t Y;
  uint16_t Z;
} TS_StateTypeDef;

typedef enum
{
  TS_OK = 0x00,
  TS_ERROR = 0x01,
  TS_TIMEOUT = 0x02
} TS_StatusTypeDef;

uint8_t TS_Init(uint16_t XSize, uint16_t YSize);
void TS_GetState(TS_StateTypeDef* TsState);
