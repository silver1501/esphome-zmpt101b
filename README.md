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


---

### **3. Завантажте код на GitHub**
- Ініціалізуйте Git:
    ```sh
    git init
    git add .
    git commit -m "Initial commit for ZMPT101B component"
    git branch -M main
    git remote add origin https://github.com/ВАШ_КОРИСТУВАЧ/esphome-zmpt101b.git
    git push -u origin main
    ```
- Замість `ВАШ_КОРИСТУВАЧ` використовуйте ваш нікнейм на GitHub.

---

### **4. Підключіть компонент у `nnbms01.yaml`**

```yaml
external_components:
  - source: ${external_components_source}
    refresh: 0s
  - source: github://silver1501/esphome-zmpt101b
    refresh: 0s

sensor:
  - platform: custom
    lambda: |-
      auto zmpt_sensor = new esphome::zmpt101b_sensor::ZMPT101BComponent(36);  // GPIO36
      return {zmpt_sensor};
    sensors:
      - name: "AC Voltage RMS"
        unit_of_measurement: "V"
        accuracy_decimals: 2
