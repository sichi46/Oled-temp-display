#include <Wire.h>
#include <Adafruit_GFX.h>          // Core graphics library
#include <Adafruit_SSD1306.h>      // Library for the OLED display

// Define OLED display dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Create an SSD1306 display object with I2C address 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Define the analog pin for the MCP9701 sensor
const int sensorPin = A2;

void setup() {
  // Initialize the display
if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C is the default I2C address for SSD1306
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  // Clear the buffer
  display.clearDisplay();
  display.setTextSize(1);            // Set text size to normal 1:1 scale
  display.setTextColor(SSD1306_WHITE); // Set text color to white

  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  // Read the analog value from the MCP9701 sensor
  int sensorValue = analogRead(sensorPin);
  
  // Convert the analog reading (0 - 1023) to voltage (0 - 5V)
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // Calculate the temperature in Celsius using MCP9701 formula
  float temperatureC = (voltage - 0.4) * 100.0;
  
  // Optional: Convert temperature to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  
  // Clear display buffer
  display.clearDisplay();
  
  // Display the temperature in Celsius
  display.setCursor(0, 0);                  // Set the cursor position
  display.print("Temp: ");
  display.print(temperatureC);
  display.println(" C");
  
  // Display the temperature in Fahrenheit
  display.setCursor(0, 16);
  display.print("Temp: ");
  display.print(temperatureF);
  display.println(" F");
  
  // Draw the buffer to the screen
  display.display();
  
  // Optional: Debug output to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  
  delay(1000);  // Update every second
}
