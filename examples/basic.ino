/**
* Firebase examples - NOTE: This example depends on the WeatherBirdProvisioning library
* To setup:  change the LED_BUILTIN pin to a pin that controls the LED used to indicate the ESP32 is being configured
*            change the CONFIG_BUTTON to the GPIO pin connected to the configuration button
*            change the FIREBASE_API_KEY to the key used for the Firebase API (available from the Firebase console)
*            Uncomment out the INITIALIZE if the SPIFFS file system has not yet been initialized - after initialization, this can be commented out
*            Start up the device
*            Provision the Wifi and other settings using the WetherBird app or website - see the WeatherbirdProvisioning Library for details

#include <WiFiMulti.h>
#include "esp_wifi.h"

#define _WBP_LOGLEVEL_        4
#define _WBF_LOGLEVEL_        4

#define FIREBASE_FUNCTION_URL "https://us-central1-weather-2a8a7.cloudfunctions.net/initializeStation"
#define FIREBASE_AUTH_DOMAIN "weather-2a8a7.firebaseapp.com"
#define FIREBASE_DATABASE_URL "https://weather-2a8a7.firebaseio.com"
#define FIREBASE_DATABASE_LOCATION "weather-2a8a7.firebaseio.com"
#define FIREBASE_STORAGE_BUCKET "weather-2a8a7.appspot.com"
#define FIREBASE_API_KEY "REPLACEME!!!!!!!!!!!"

#define LED_BUILTIN 2   // replace with the pin for the LED used to denote configuration
#define CONFIG_BUTTON 15  // GPIO pin connected to the configuration button

//#define INITIALIZE true // set to true to initialize the file system

#include "WeatherBirdProvisioning.h"
#include "WeatherBirdFirebase.h"
WeatherBirdProvisioningManager* provisioningManager;
WeatherBirdFirebase* firebase;
FirebaseAuth firebaseAuth;
FirebaseConfig firebaseConfig;

#define WBP_DEBUG_OUTPUT      Serial
//#define CORE_DEBUG_LEVEL=5

/**
 * Starts the firebase service
 * Returns true if successful
 */
boolean startFirebase() {
  if (provisioningManager->getState() != STATE_CONFIGURED) {
    Serial.println(F("Can not start firebase, Station is not in a provisioned state"));
    return false;
  }
  Serial.println(F("Starting Firebase"));
  firebaseConfig.host = FIREBASE_DATABASE_LOCATION;
  firebaseConfig.api_key = FIREBASE_API_KEY;
  firebaseAuth.user.email = provisioningManager->getStationEmail();
  firebaseAuth.user.password = provisioningManager->getStationPassword();
  return firebase->begin();
}

void setup()
{
  Serial.begin(115200);
  delay(200);
#ifdef INITIALIZE
  SPIFFS.begin(true);
#endif

  provisioningManager = new WeatherBirdProvisioningManager(FIREBASE_FUNCTION_URL, LED_BUILTIN, CONFIG_BUTTON);
  provisioningManager->begin();
  
  firebase = new WeatherBirdFirebase(&firebaseConfig, &firebaseAuth, provisioningManager->getFirebaseStationId());
  if (startFirebase()) {
    Serial.println("Firebase successfully started");
  }
}

#define FIREBASE_UPDATE_DELAY 300000L   // 5 minutes
static uint64_t timestamp = millis() - FIREBASE_UPDATE_DELAY - 1;
static int loopindex = 1;
void loop() {
    provisioningManager->loop();
    firebase->loop();
    if (millis() - timestamp > FIREBASE_UPDATE_DELAY  &&
        provisioningManager->getState() == STATE_CONFIGURED) {
        timestamp = millis();
    firebase->updateSensorValue("test", (float)loopindex);
    Serial.print("Updating sensor value for test to ");
    Serial.println(loopindex);
    loopindex++;
  }
}