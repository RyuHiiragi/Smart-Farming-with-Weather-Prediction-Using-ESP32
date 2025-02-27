#include <WiFi.h>
#include <HTTPClient.h>

// Replace with your Wi-Fi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Replace with your OpenWeatherMap API key and location
const char* apiKey = "YOUR_API_KEY";
const char* city = "YOUR_CITY";
const char* url = "http://api.openweathermap.org/data/2.5/weather?q=";

// Define pins
#define SOIL_MOISTURE_PIN A0
#define PUMP_PIN 5
#define RED_LED_PIN 6
#define GREEN_LED_PIN 7

// Thresholds for soil moisture and weather prediction
const int moistureThreshold = 30; // Adjust based on soil type
const float rainThreshold = 2.0; // Rainfall in mm (adjust based on API response)

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Set pin modes
  pinMode(SOIL_MOISTURE_PIN, INPUT);
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  // Turn off pump and LEDs initially
  digitalWrite(PUMP_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, HIGH); // Green LED indicates normal condition

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Wi-Fi connected");
}

void loop() {
  // Read soil moisture level
  int moisture = map(analogRead(SOIL_MOISTURE_PIN), 0, 4095, 100, 0); // Convert to percentage
  Serial.print("Soil Moisture: ");
  Serial.print(moisture);
  Serial.println(" %");

  // Fetch weather data
  float rainfall = getWeatherData();
  Serial.print("Rainfall Prediction: ");
  Serial.print(rainfall);
  Serial.println(" mm");

  // Control irrigation based on soil moisture and weather prediction
  if (moisture < moistureThreshold && rainfall < rainThreshold) {
    Serial.println("Irrigation Activated");
    digitalWrite(PUMP_PIN, HIGH); // Turn on the pump
    digitalWrite(RED_LED_PIN, HIGH); // Turn on red LED
    digitalWrite(GREEN_LED_PIN, LOW); // Turn off green LED
    delay(5000); // Irrigate for 5 seconds (adjust as needed)
    digitalWrite(PUMP_PIN, LOW); // Turn off the pump
    digitalWrite(RED_LED_PIN, LOW); // Turn off red LED
    digitalWrite(GREEN_LED_PIN, HIGH); // Turn on green LED
  } else {
    Serial.println("No Irrigation Needed");
  }

  delay(60000); // Check every minute (adjust as needed)
}

float getWeatherData() {
  HTTPClient http;
  String fullUrl = String(url) + city + "&appid=" + apiKey + "&units=metric";
  http.begin(fullUrl);
  int httpResponseCode = http.GET();

  float rainfall = 0.0;
  if (httpResponseCode == 200) {
    String payload = http.getString();
    int rainIndex = payload.indexOf("\"rain\"");
    if (rainIndex != -1) {
      int valueIndex = payload.indexOf("1h", rainIndex);
      if (valueIndex != -1) {
        String rainValue = payload.substring(valueIndex + 4, valueIndex + 8);
        rainfall = rainValue.toFloat();
      }
    }
  } else {
    Serial.print("Error fetching weather data: ");
    Serial.println(httpResponseCode);
  }

  http.end();
  return rainfall;
}
