#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define LED_PIN 2

#define SERVICE_UUID        "12345678-1234-1234-1234-123456789abc"
#define CHARACTERISTIC_UUID "abcdefab-1234-5678-1234-abcdefabcdef"

class MyCallbacks : public BLECharacteristicCallbacks {

  void onWrite(BLECharacteristic *pCharacteristic) {

    String value = pCharacteristic->getValue();

    if (value.length() > 0) {

      char cmd = value.charAt(0);

      Serial.print("Received: ");
      Serial.println(cmd);

      if (cmd == 'R') {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("LED ON");
      }

      if (cmd == 'O') {
        digitalWrite(LED_PIN, LOW);
        Serial.println("LED OFF");
      }
    }
  }
};

void setup() {

  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  BLEDevice::init("ESP32_PHONE_CONTROL");

  BLEServer *pServer = BLEDevice::createServer();

  BLEService *pService =
      pServer->createService(SERVICE_UUID);

  BLECharacteristic *pCharacteristic =
      pService->createCharacteristic(
          CHARACTERISTIC_UUID,
          BLECharacteristic::PROPERTY_WRITE
      );

  pCharacteristic->setCallbacks(new MyCallbacks());

  pService->start();

  BLEAdvertising *pAdvertising =
      BLEDevice::getAdvertising();

  pAdvertising->start();

  Serial.println("BLE Server Started");
}

void loop() {
  delay(100);
}