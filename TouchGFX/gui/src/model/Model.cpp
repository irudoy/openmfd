#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <cstdint>
#include <cmsis_os.h>

extern osMessageQueueId_t DataQueueHandle;

uint8_t dataQueueMsg;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
//  if (osMessageQueueGet(DataQueueHandle, &dataQueueMsg, 0U, 0) == osOK) {
//    if ((dataQueueMsg & 0b10000001) == 0b10000001) {
//      // TODO
//    }
//  }
}
