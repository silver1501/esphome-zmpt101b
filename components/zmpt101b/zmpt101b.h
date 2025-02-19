#pragma once
#include "esphome.h"
#include <Arduino.h>

namespace esphome {
namespace zmpt101b {

class ZMPT101BSensor : public PollingComponent, public sensor::Sensor {
 public:
  // Оновлення кожну секунду (1000 мс)
  ZMPT101BSensor() : PollingComponent(1000) {}

  // Встановлюємо пріоритет налаштування на рівні апаратури
  float get_setup_priority() const override { return setup_priority::HARDWARE; }

  void setup() override {
    // Налаштування піну, якщо потрібно (наприклад, якщо використовується інший пін)
    // pinMode(A0, INPUT);
  }

  void update() override {
    // Приклад вимірювання з використанням ZMPT101B
    // Параметри калібрування — змініть за необхідністю
    const uint32_t FREQUENCY = 50;
    const uint32_t period = 1000000 / FREQUENCY; // мікросекунди за період
    const int32_t ZERO_VAC = 788;
    const int CALIBRATE_READ = 130;
    const int CALIBRATE_ACTUAL = 225;

    uint32_t t_start = micros();
    uint32_t Vsum = 0;
    uint32_t measurements_count = 0;
    int32_t Vnow;

    while (micros() - t_start < period) {
      // Читаємо аналогове значення з A0 (при потребі змініть пін)
      Vnow = analogRead(36) - ZERO_VAC;
      Vsum += Vnow * Vnow;
      measurements_count++;
    }

    float Vrms = sqrt((float)Vsum / measurements_count) / CALIBRATE_READ * CALIBRATE_ACTUAL;
    publish_state(Vrms);
  }
};

}  // namespace zmpt101b
}  // namespace esphome
