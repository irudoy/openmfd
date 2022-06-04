#include "debug_screen.h"

TS_StateTypeDef touchState;

uint8_t touchStarted = 0;

typedef struct
{
  uint16_t x;
  uint16_t y;
  uint16_t w;
  uint16_t h;
  const char *caption;
  uint8_t orientation;
} UI_Object;

__weak void DBGS_handleClick_DISP(void) {}
__weak void DBGS_handleClick_RETURN(void) {}
__weak void DBGS_handleClick_MENU(void) {}
__weak void DBGS_handleClick_MODE(void) {}
__weak void DBGS_handleClick_UP(void) {}
__weak void DBGS_handleClick_DOWN(void) {}
__weak void DBGS_handleClick_LEFT(void) {}
__weak void DBGS_handleClick_RIGHT(void) {}
__weak void DBGS_handleClick_CENTER(void) {}

/**
 * DISP / RETURN / MENU / MODE
 */
#define BUTTON_W ILI9341_WIDTH / 2 - 1
#define BUTTON_H 50
#define BUTTON_COL_1_X ILI9341_WIDTH / 4
#define BUTTON_COL_2_X BUTTON_COL_1_X * 3 + 1
#define BUTTON_ROW_1_Y ILI9341_HEIGHT - BUTTON_H - BUTTON_H / 2 - 1
#define BUTTON_ROW_2_Y ILI9341_HEIGHT - BUTTON_H + BUTTON_H / 2
UI_Object ButtonDisp = {
  .x = BUTTON_COL_1_X,
  .y = BUTTON_ROW_1_Y,
  .w = BUTTON_W,
  .h = BUTTON_H,
  .caption = "DISP",
};
UI_Object ButtonReturn = {
  .x = BUTTON_COL_2_X,
  .y = BUTTON_ROW_1_Y,
  .w = BUTTON_W,
  .h = BUTTON_H,
  .caption = "RETURN",
};
UI_Object ButtonMenu = {
  .x = BUTTON_COL_1_X,
  .y = BUTTON_ROW_2_Y,
  .w = BUTTON_W,
  .h = BUTTON_H,
  .caption = "MENU",
};
UI_Object ButtonMode = {
  .x = BUTTON_COL_2_X,
  .y = BUTTON_ROW_2_Y,
  .w = BUTTON_W,
  .h = BUTTON_H,
  .caption = "MODE",
};

static void DBGS_Render_Button(UI_Object *obj, uint8_t state)
{
  uint16_t textWidth = strlen(obj->caption) * Font_11x18.width;
  uint16_t textHeight = Font_11x18.height;
  uint16_t textColor = ILI9341_BLACK;
  uint16_t bgColor = state == 1 ? ILI9341_COLOR565(99, 178, 81) : ILI9341_COLOR565(59, 79, 79);

  uint16_t sx = obj->x - obj->w / 2;
  uint16_t sy = obj->y - obj->h / 2;

  ILI9341_FillRectangle(sx, sy, obj->w, obj->h, bgColor);

  ILI9341_WriteString(
    sx + (obj->w / 2 - textWidth / 2),
    sy + (obj->h / 2 - textHeight / 2),
    obj->caption,
    Font_11x18,
    textColor,
    bgColor
  );
}

/**
 * @param x - X pos from center
 * @param y - Y pos from center
 * @param w - width
 * @param h - height
 * @param o - orientation (0 - ^, 1 - >, 2 - v, 3 - <)
 * @param color - fill color
 */
static void DBGS_Triangle(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t o, uint16_t color)
{
  uint8_t x0 = x;
  uint8_t y0 = y - h / 2;
  uint8_t x1 = x + w / 2;
  uint8_t y1 = y + h / 2;
  uint8_t x2 = x - w / 2;
  uint8_t y2 = y + h / 2;
  uint8_t X0, Y0, X1, Y1, X2, Y2;
  switch (o) {
    case 0: X0 = x0; Y0 = y0; X1 = x1; Y1 = y1; X2 = x2; Y2 = y2; break;
    case 1: X0 = x2; Y0 = y0; X1 = x1; Y1 = y1 - h / 2; X2 = x2; Y2 = y2; break;
    case 2: X0 = x2; Y0 = y0; X1 = x1; Y1 = y0; X2 = x0; Y2 = y1; break;
    case 3: X0 = x1; Y0 = y0; X1 = x1; Y1 = y1; X2 = x2; Y2 = y2 - h / 2; break;
    default: break;
  }
  ILI9341_FillTriangle(X0, Y0, X1, Y1, X2, Y2, color);
}

/**
 * XO
 */
#define TRIANGLE_W 60
#define TRIANGLE_H 50
#define TRIANGLE_X ILI9341_WIDTH / 2
#define TRIANGLE_Y 105
UI_Object ButtonUp = {
  .x = TRIANGLE_X,
  .y = 40,
  .w = TRIANGLE_W,
  .h = TRIANGLE_H,
  .orientation = 0,
};
UI_Object ButtonDown = {
  .x = TRIANGLE_X,
  .y = 170,
  .w = TRIANGLE_W,
  .h = TRIANGLE_H,
  .orientation = 2,
};
UI_Object ButtonLeft = {
  .x = 55,
  .y = TRIANGLE_Y,
  .w = TRIANGLE_W,
  .h = TRIANGLE_H,
  .orientation = 3,
};
UI_Object ButtonRight = {
  .x = 185,
  .y = TRIANGLE_Y,
  .w = TRIANGLE_W,
  .h = TRIANGLE_H,
  .orientation = 1,
};
UI_Object ButtonCenter = {
  .x = TRIANGLE_X,
  .y = TRIANGLE_Y,
  .w = 60,
  .h = 60,
};

static void DBGS_Render_Arrow(UI_Object *obj, uint8_t state)
{
  uint16_t bgColor = state == 1 ? ILI9341_COLOR565(99, 178, 81) : ILI9341_COLOR565(59, 79, 79);
  uint16_t w = obj->w;
  uint16_t h = obj->h;
  if (obj->orientation == 1 || obj->orientation == 3) {
    w = obj->h;
    h = obj->w;
  }
  DBGS_Triangle(obj->x, obj->y, w, h, obj->orientation, bgColor);
}

static void DBGS_Render_Center(UI_Object *obj, uint8_t state)
{
  uint16_t bgColor = state == 1 ? ILI9341_COLOR565(99, 178, 81) : ILI9341_COLOR565(59, 79, 79);
  ILI9341_FillCircle(obj->x, obj->y, obj->w / 2, bgColor);
}

static uint8_t DBGS_isTouched(UI_Object obj, TS_StateTypeDef ts)
{
  uint16_t tx = ILI9341_WIDTH - ts.X;
  uint16_t ty = ILI9341_HEIGHT - ts.Y;
  uint16_t ox = obj.x - obj.w / 2;
  uint16_t oy = obj.y - obj.h / 2;

  if (tx >= ox && tx <= ox + obj.w) {
    if (ty >= oy && ty <= oy + obj.h) {
       return 1;
    }
  }

  return 0;
}

static void DBGS_RenderAllInactive(void)
{
  DBGS_Render_Button(&ButtonDisp, 0);
  DBGS_Render_Button(&ButtonReturn, 0);
  DBGS_Render_Button(&ButtonMenu, 0);
  DBGS_Render_Button(&ButtonMode, 0);
  DBGS_Render_Arrow(&ButtonUp, 0);
  DBGS_Render_Arrow(&ButtonDown, 0);
  DBGS_Render_Arrow(&ButtonLeft, 0);
  DBGS_Render_Arrow(&ButtonRight, 0);
  DBGS_Render_Center(&ButtonCenter, 0);
}

void DBGS_init()
{
  ILI9341_Init();
  TS_Init(ILI9341_WIDTH, ILI9341_HEIGHT);
  ILI9341_FillScreen(0);

  // Initial render UI elements
  DBGS_RenderAllInactive();
}

void DBGS_tick()
{
  TS_GetState(&touchState);

  if (touchState.TouchDetected) {
    if (DBGS_isTouched(ButtonDisp, touchState) && touchStarted == 0) {
      touchStarted = 1;
      DBGS_Render_Button(&ButtonDisp, 1);
      DBGS_handleClick_DISP();
    }
    if (DBGS_isTouched(ButtonReturn, touchState) && touchStarted == 0) {
      touchStarted = 1;
      DBGS_Render_Button(&ButtonReturn, 1);
      DBGS_handleClick_RETURN();
    }
    if (DBGS_isTouched(ButtonMenu, touchState) && touchStarted == 0) {
      touchStarted = 1;
      DBGS_Render_Button(&ButtonMenu, 1);
      DBGS_handleClick_MENU();
    }
    if (DBGS_isTouched(ButtonMode, touchState) && touchStarted == 0) {
      touchStarted = 1;
      DBGS_Render_Button(&ButtonMode, 1);
      DBGS_handleClick_MODE();
    }
    if (DBGS_isTouched(ButtonUp, touchState) && touchStarted == 0) {
      touchStarted = 1;
      DBGS_Render_Arrow(&ButtonUp, 1);
      DBGS_handleClick_UP();
    }
    if (DBGS_isTouched(ButtonDown, touchState) && touchStarted == 0) {
      touchStarted = 1;
      DBGS_Render_Arrow(&ButtonDown, 1);
      DBGS_handleClick_DOWN();
    }
    if (DBGS_isTouched(ButtonLeft, touchState) && touchStarted == 0) {
      touchStarted = 1;
      DBGS_Render_Arrow(&ButtonLeft, 1);
      DBGS_handleClick_LEFT();
    }
    if (DBGS_isTouched(ButtonRight, touchState) && touchStarted == 0) {
      touchStarted = 1;
      DBGS_Render_Arrow(&ButtonRight, 1);
      DBGS_handleClick_RIGHT();
    }
    if (DBGS_isTouched(ButtonCenter, touchState) && touchStarted == 0) {
      touchStarted = 1;
      DBGS_Render_Center(&ButtonCenter, 1);
      DBGS_handleClick_CENTER();
    }
  } else if (touchStarted == 1) {
    touchStarted = 0;
    // reset state
    DBGS_RenderAllInactive();
  }

  osDelay(30);
}

