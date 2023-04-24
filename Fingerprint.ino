#include <Wire.h>
#include <Adafruit_Fingerprint.h>
#include <MongoDB.h>

// Initialize the fingerprint sensor module
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&Wire);

// Initialize the MongoDB client
MongoDBClient client("mongodb://<username>:<password>@<host>:<port>/<database>");

void setup() {
  // Start serial communication
  Serial.begin(9600);
  while (!Serial) {}

  // Initialize the fingerprint sensor module
  finger.begin();

  // Check if the fingerprint sensor module is connected
  if (finger.verifySensor() != FINGERPRINT_OK) {
    Serial.println("Failed to connect to fingerprint sensor module");
    while (1) {}
  }

  Serial.println("Place your finger on the sensor...");
}

void loop() {
  // Wait for a fingerprint to be detected
  uint8_t fingerID = finger.getImage();
  if (fingerID != FINGERPRINT_OK) {
    Serial.println("Failed to detect fingerprint");
    delay(1000);
    return;
  }

  // Convert the fingerprint data to a unique ID
  uint32_t fingerprintID = finger.fingerID();

  // Print the unique ID to the serial port
  Serial.print("Fingerprint ID: ");
  Serial.println(fingerprintID);

  // Insert the unique ID into MongoDB
  BSONObjBuilder builder;
  builder.append("fingerprintID", fingerprintID);
  client.insert("<collection>", builder.obj());

  // Wait for a few seconds before detecting the next fingerprint
  delay(5000);
}
