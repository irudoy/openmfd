#include "debug_screen.h"

TS_StateTypeDef touchState;

uint8_t touchStarted = 0;

typedef struct
{
  uint16_t x;
  uint16_t y;
  uint16_t w;
  uint16_t h;
} UI_Object;

/**
 * BTN1
 */
UI_Object btn1 = {
  .x = ILI9341_WIDTH / 2 - 100 / 2,
  .y = ILI9341_HEIGHT / 2 - 100 / 2,
  .w = 100,
  .h = 100,
};
static void DBGS_render_btn1(uint8_t state)
{
  ILI9341_FillRectangle(btn1.x, btn1.y, btn1.w, btn1.h, state == 1 ? ILI9341_MAGENTA : ILI9341_CYAN);
}
__weak void DBGS_handleClick_btn1(void) {
  // use me
}
/**
 * BTN1
 */

static uint8_t DBGS_isTouched(UI_Object obj, TS_StateTypeDef ts)
{
  uint16_t tx = ILI9341_WIDTH - ts.X;
  uint16_t ty = ILI9341_HEIGHT - ts.Y;

  if (tx >= obj.x && tx <= obj.x + obj.w) {
    if (ty >= obj.y && ty <= obj.y + obj.h) {
       return 1;
    }
  }

  return 0;
}

void DBGS_init()
{
  ILI9341_Init();
  TS_Init(ILI9341_WIDTH, ILI9341_HEIGHT);
  ILI9341_FillScreen(0);

  // Initial render UI elements
  DBGS_render_btn1(0);
}

void DBGS_tick()
{
  TS_GetState(&touchState);

  if (touchState.TouchDetected) {
    // set active state
    if (DBGS_isTouched(btn1, touchState) && touchStarted == 0) {
      touchStarted = 1;

      DBGS_render_btn1(1);
      DBGS_handleClick_btn1();
    }
  } else if (touchStarted == 1) {
    touchStarted = 0;

    // reset state
    DBGS_render_btn1(0);
  }
}

