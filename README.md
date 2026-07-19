# ESP32 BLE RGB Client

A wireless communication application that configures an ESP32 microcontroller as a Bluetooth Low Energy (BLE) Client. The system scans for targeted BLE servers, establishes a stable connection via Generic Attribute Profile (GATT) architecture, and writes custom color packet arrays to update peripheral RGB LEDs.

 Core Hardware Architecture
* **Controller:** ESP32 Development Module
* **Output Peripheral:** Common Cathode / Anode RGB LED or NeoPixel WS2812B Matrix
* **Diagnostic Interface:** Hardware Serial Monitor

 BLE Protocol Configurations
* **Role:** BLE Client (Central Device)
* **Communication Interface:** Custom GATT Service & Characteristics 
* **Data Transmission Packet Structure:** 3-byte array mapping to $[R, G, B]$ color intensity codes ($0$ to $255$).# ESP32_BLE_RGB_Client
