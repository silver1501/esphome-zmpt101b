# ESPHome ZMPT101B Component

Цей компонент дозволяє вимірювати змінну напругу за допомогою датчика ZMPT101B на ESP32.

## Приклад використання

```yaml
external_components:
  - source: github://ВАШ_КОРИСТУВАЧ/esphome-zmpt101b

sensor:
  - platform: custom
    lambda: |-
      auto zmpt_sensor = new esphome::zmpt101b_sensor::ZMPT101BComponent(36);
      return {zmpt_sensor};
    sensors:
      - name: "AC Voltage RMS"
        unit_of_measurement: "V"
        accuracy_decimals: 2
