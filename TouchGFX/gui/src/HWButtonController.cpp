#include <HWButtonController.hpp>

extern uint8_t commState;

HWButtonController::HWButtonController()
{

}

void HWButtonController::init()
{

}

bool HWButtonController::sample(uint8_t& key)
{
  if (commState != 0) {
    key = commState - 1;
    commState = 0;
    return true;
  }
  return false;
}
