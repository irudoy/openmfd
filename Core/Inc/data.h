#ifndef INC_DATA_H_
#define INC_DATA_H_

/**
 * # CANsult CAN Protocol
 *
 * ## Stream
 *
 * |  ID   | DLC |     Byte 0      |    Byte 1    |     Byte 2      |    Byte 3    |    Byte 4    |    Byte 5    |     Byte 6     |         Byte 7          |
 * |-------|-----|-----------------|--------------|-----------------|--------------|--------------|--------------|----------------|-------------------------|
 * | 0x666 |   8 | BATTERY_VOLTAGE | COOLANT_TEMP | IGNITION_TIMING | LEFT_O2      | TPS          | AAC_VALVE    | LEFT_AF_ALPHA  | LEFT_AF_ALPHA_SELFLEARN |
 * | 0x667 |   8 | VEHICLE_SPEED   | TACH_MSB     | TACH_LSB        | INJ_TIME_MSB | INJ_TIME_LSB | LEFT_MAF_MSB | LEFT_MAF_LSB   |                         |
 * | 0x668 |   8 | BIT_1           | BIT_2        | DEVICE_VOLTAGE  |              |              |              | First DTC Code | Heartbeat               |
 *
 * */

#endif /* INC_DATA_H_ */
