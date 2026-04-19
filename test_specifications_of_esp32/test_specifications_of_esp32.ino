#include <Arduino.h>
#include "esp_system.h"
#include "esp_chip_info.h"
#include "esp_flash.h"

void setup() {
  Serial.begin(115200);

  // Chip information
  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);

  Serial.printf("ESP32 Chip model: %d cores, WiFi%s%s, ",
                chip_info.cores,
                (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
                (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
  Serial.printf("silicon revision %d\n", chip_info.revision);

  // Flash size
  uint32_t flash_size;
  if (esp_flash_get_size(NULL, &flash_size) == ESP_OK) {
    Serial.printf("Flash size: %d MB\n", flash_size / (1024 * 1024));
  } else {
    Serial.println("Could not get flash size");
  }

  // Free heap memory (RAM available)
  Serial.printf("Free heap memory: %d bytes\n", esp_get_free_heap_size());

  // Minimum free heap ever
  Serial.printf("Minimum free heap ever: %d bytes\n", esp_get_minimum_free_heap_size());

  // CPU frequency
  Serial.printf("CPU frequency: %d MHz\n", getCpuFrequencyMhz());

  // SDK version
  Serial.printf("ESP-IDF version: %s\n", esp_get_idf_version());
}

void loop() {
  // Nothing here, just reporting once
}