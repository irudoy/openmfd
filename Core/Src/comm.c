#include <comm.h>

extern CAN_HandleTypeDef hcan2;

CAN_RxHeaderTypeDef CANRxHeader;
CAN_TxHeaderTypeDef CANTxHeader;

uint8_t CANTxData[8];
uint8_t CANRxData[8];

uint32_t CANTxMailbox;

uint8_t commState = 0;

//TxData[0] = 0x02;
//TxData[1] = 0x04;
//TxData[2] = 0x06;
//TxData[3] = 0x08;
//HAL_CAN_AddTxMessage(&hcan2, &TxHeader, TxData, &TxMailbox);

void COMM_init(void) {
  HAL_CAN_Start(&hcan2);
  HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO0_MSG_PENDING);

  CANTxHeader.DLC = 8;
  CANTxHeader.IDE = CAN_ID_STD;
  CANTxHeader.RTR = CAN_RTR_DATA;
  CANTxHeader.StdId = 0x666;
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

static void handleLeft() {
  if (MFD_AppState.twinsGauge1 == 0) {
    MFD_AppState.twinsGauge1 = MFD_Gauge__SIZE - 1;
  } else {
    MFD_AppState.twinsGauge1--;
  }
  if (MFD_AppState.twinsGauge2 == 0) {
    MFD_AppState.twinsGauge2 = MFD_Gauge__SIZE - 1;
  } else {
    MFD_AppState.twinsGauge2--;
  }
  MFD_AppState.graphGauge = MFD_AppState.twinsGauge2;
}

static void handleRight() {
  MFD_AppState.twinsGauge1++;
  MFD_AppState.twinsGauge2++;
  if (MFD_AppState.twinsGauge1 >= MFD_Gauge__SIZE) {
    MFD_AppState.twinsGauge1 = 0;
  }
  if (MFD_AppState.twinsGauge2 >= MFD_Gauge__SIZE) {
    MFD_AppState.twinsGauge2 = 0;
  }
  MFD_AppState.graphGauge = MFD_AppState.twinsGauge2;
}

static void handleUp() {
  commState = 1;
  // DBGD_stubIncDecAll(true);
}

static void handleDown() {
  commState = 2;
  // DBGD_stubIncDecAll(false);
}

static void handleCenter() {
  DBGD_resetPeak();
}

static void handleCMD1() {
  DBGD_toggleEnable();
}

static void handleCMD3() {
  DBGD_toggleRandom();
}

static void handleCMD4() {
  MFD_AppState.peakCurState = MFD_AppState.peakCurState == MFD_PeakCur_Peak ? MFD_PeakCur_Current : MFD_PeakCur_Peak;
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
  HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &CANRxHeader, CANRxData);

  if (CANRxHeader.StdId == CBUS_ID) {
    switch(CANRxData[0]) {
      case CBUS_CMD_LEFT:
        handleLeft();
        break;
      case CBUS_CMD_RIGHT:
        handleRight();
        break;
      case CBUS_CMD_UP:
        handleUp();
        break;
      case CBUS_CMD_DOWN:
        handleDown();
        break;
      case CBUS_CMD_PLAY_PAUSE:
        handleCenter();
        break;
      case CBUS_CMD_1:
        handleCMD1();
        break;
      case CBUS_CMD_3:
        handleCMD3();
        break;
      case CBUS_CMD_4:
        handleCMD4();
        break;
      default:
        break;
    }
  }
}

void DBGS_handleClick_DISP(void) {
  handleCMD1();
}

void DBGS_handleClick_RETURN(void) {
  DBGD_toggleEnable();
}

void DBGS_handleClick_MENU(void) {
  handleCMD3();
}

void DBGS_handleClick_MODE(void) {
  handleCMD4();
  //  uint8_t val = 0b10000001;
  //  if (osMessageQueueGetCount(DataQueueHandle) == 0) {
  //    osMessageQueuePut(DataQueueHandle, &val, 0U, 0);
  //  }
}

void DBGS_handleClick_UP(void) {
  handleUp();
}

void DBGS_handleClick_DOWN(void) {
  handleDown();
}

void DBGS_handleClick_LEFT(void) {
  handleLeft();
}

void DBGS_handleClick_RIGHT(void) {
  handleRight();
}

void DBGS_handleClick_CENTER(void) {
  handleCenter();
}

/**
 * Handle Blue Button Push
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  DBGD_resetPeak();
}
