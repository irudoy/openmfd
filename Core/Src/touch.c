#include "touch.h"

static TS_DrvTypeDef* TsDrv;
static uint16_t TsXBoundary, TsYBoundary;

/**
  * @brief  Initializes and configures the touch screen functionalities and
  *         configures all necessary hardware resources (GPIOs, clocks..).
  * @param  XSize: The maximum X size of the TS area on LCD
  * @param  YSize: The maximum Y size of the TS area on LCD
  * @retval TS_OK: if all initializations are OK. Other value if error.
  */
uint8_t TS_Init(uint16_t XSize, uint16_t YSize)
{
    uint8_t ret = TS_ERROR;

    /* Initialize x and y positions boundaries */
    TsXBoundary = XSize;
    TsYBoundary = YSize;

    /* Read ID and verify if the IO expander is ready */
    if (stmpe811_ts_drv.ReadID(TS_I2C_ADDRESS) == STMPE811_ID)
    {
        /* Initialize the TS driver structure */
        TsDrv = &stmpe811_ts_drv;

        ret = TS_OK;
    }

    if (ret == TS_OK)
    {
        /* Initialize the LL TS Driver */
        TsDrv->Init(TS_I2C_ADDRESS);
        TsDrv->Start(TS_I2C_ADDRESS);
    }

    return ret;
}

/**
  * @brief  Returns status and positions of the touch screen.
  * @param  TsState: Pointer to touch screen current state structure
  */
void TS_GetState(TS_StateTypeDef* TsState)
{
    static uint32_t _x = 0, _y = 0;
    uint16_t xDiff, yDiff, x, y, xr, yr;

    TsState->TouchDetected = TsDrv->DetectTouch(TS_I2C_ADDRESS);

    if (TsState->TouchDetected)
    {
        TsDrv->GetXY(TS_I2C_ADDRESS, &x, &y);

        //Ensures the coordinates is within the screen
        if (y > 3700)
        {
            y = 3700;
        }
        else if (y < 180)
        {
            y = 180;
        }

        /* Y value first correction */
        y -= 180;

        /* Y value second correction */
        y = 3520 - y;

        /* Y value third correction */
        yr = y / 11;

        /* Return y position value */
        if (yr <= 0)
        {
            yr = 0;
        }
        else if (yr > TsYBoundary)
        {
            yr = TsYBoundary - 1;
        }
        else
        {
        }
        y = yr;

        /* X value first correction */
        if (x <= 3000)
        {
            x = 3870 - x;
        }
        else
        {
            x = 3800 - x;
        }

        /* X value second correction */
        xr = x / 15;

        /* Return X position value */
        if (xr <= 0)
        {
            xr = 0;
        }
        else if (xr > TsXBoundary)
        {
            xr = TsXBoundary - 1;
        }
        else
        {
        }

        x = xr;
        xDiff = x > _x ? (x - _x) : (_x - x);
        yDiff = y > _y ? (y - _y) : (_y - y);

        if (xDiff + yDiff > 5)
        {
            _x = x;
            _y = y;
        }

        /* Update the X position */
        TsState->X = _x;

        /* Update the Y position */
        TsState->Y = _y;
    }
}
