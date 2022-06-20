#include "comm.h"

extern CAN_HandleTypeDef hcan2;

CAN_RxHeaderTypeDef RxHeader;
CAN_TxHeaderTypeDef TxHeader;

uint8_t TxData[8];
uint8_t RxData[8];

uint32_t TxMailbox;

//TxData[0] = 0x02;
//TxData[1] = 0x04;
//TxData[2] = 0x06;
//TxData[3] = 0x08;
//HAL_CAN_AddTxMessage(&hcan2, &TxHeader, TxData, &TxMailbox);

void COMM_init(void) {
  HAL_CAN_Start(&hcan2);
  HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO0_MSG_PENDING);

  TxHeader.DLC = 8;
  TxHeader.IDE = CAN_ID_STD;
  TxHeader.RTR = CAN_RTR_DATA;
  TxHeader.StdId = 0x666;
}

void COMM_setupCANFilter(void) {
  CAN_FilterTypeDef canFilterConfig;
  canFilterConfig.FilterBank = 14;
  canFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
  canFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
  canFilterConfig.FilterIdHigh = 0x0000;
  canFilterConfig.FilterIdLow = 0x0000;
  canFilterConfig.FilterMaskIdHigh = 0x0000;
  canFilterConfig.FilterMaskIdLow = 0x0000;
  canFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
  canFilterConfig.FilterActivation = ENABLE;

  if (HAL_CAN_ConfigFilter(&hcan2, &canFilterConfig) != HAL_OK) {
    /* Filter configuration Error */
    Error_Handler();
  }
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
  HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData);

  //  CMD_LEFT            0x01
  //  CMD_RIGHT           0x02
  //  CMD_UP              0x03
  //  CMD_DOWN            0x04
  //  CMD_PLAY_PAUSE      0x05
  //  CMD_1               0x06
  //  CMD_3               0x07
  //  CMD_4               0x08
  //  CMD_5               0x09
  //  CMD_REPEAT          0x10
  //  CMD_SCAN            0x11

  // TODO: filter ID 0x669

  switch(RxData[0]) {
    case 0x01:
      DBGD_toggleRandom();
      break;
    case 0x02:
      DBGD_toggleEnable();
      break;
    case 0x03:
      DBGD_stubIncDecAll(true);
      break;
    case 0x04:
      DBGD_stubIncDecAll(false);
      break;
    case 0x05:
      DBGD_resetPeak();
      break;
    default:
      break;
  }
}

