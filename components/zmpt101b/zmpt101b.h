#include "esphome.h"

namespace esphome {
namespace zmpt101b {

class ZMPT101BComponent : public PollingComponent, public sensor::Sensor {
 public:
  ZMPT101BComponent(int pin) : PollingComponent(1000), pin_(pin) {}

  void setup() override {
    pinMode(pin_, INPUT);
  }

  void update() override {
    const int samples = 1000;
    const float alpha = 0.1;
    static float prev_filtered_rms = 0.0;
    float sum = 0.0;

    for (int i = 0; i < samples; i++) {
      int raw = analogRead(pin_);
      float voltage = (raw / 4095.0) * 3.3;
      sum += voltage * voltage;
      delayMicroseconds(100);
    }

    float mean = sum / samples;
    float rms = sqrt(mean) * 110.0;
    float filtered_rms = alpha * rms + (1 - alpha) * prev_filtered_rms;
    prev_filtered_rms = filtered_rms;

    publish_state(filtered_rms);
  }

 protected:
  int pin_;
};

}  // namespace zmpt101b
}  // namespace esphome
