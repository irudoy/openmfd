#ifndef GUI_INCLUDE_HWBUTTONCONTROLLER_HPP_
#define GUI_INCLUDE_HWBUTTONCONTROLLER_HPP_

#include <platform/driver/button/ButtonController.hpp>
#include <comm.h>

class HWButtonController : public touchgfx::ButtonController
{
public:
  HWButtonController();
  virtual void init();
  virtual bool sample(uint8_t& key);
private:
};

#endif /* GUI_INCLUDE_HWBUTTONCONTROLLER_HPP_ */
