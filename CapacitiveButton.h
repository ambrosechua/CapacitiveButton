#include <CapacitiveSensor.h>

//#define SMOOTHING_CYCLES 10 // increase to reduce activation errors
#define SMOOTHING_TIME 16 // smoothing time in milliseconds
#define TIMEOUT_FACTOR 100 // increase to 600 for reduced repeated touches

class CapacitiveButton {
  public:
  	CapacitiveButton(uint8_t sendPin, uint8_t receivePin, uint16_t threshold = 40);
    bool getState();
    uint16_t getRaw();
    bool update(); // returns true when state has changed
  private:
    CapacitiveSensor sensor;
    uint16_t threshold = 40;
    bool state = false;
    uint16_t average = 0;
    uint16_t last_time = 0;
};

