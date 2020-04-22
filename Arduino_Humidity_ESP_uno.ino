// SCREEN Libraries
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// SCREEN Declaration PINS: SCK = A5 , SDA = A4
#define OLED_RESET     4
Adafruit_SSD1306 display(OLED_RESET);
// SCREEN Declaration function show_t, function screen_setup
void show_t(int, String);
void screen_setup();


// Sensor Pin
int rainPin = A0;



// SETUP
void setup() {
  Serial.begin(115200);
  pinMode(rainPin, INPUT);
  // SCREEN setup
  screen_setup();
}

// LOOP
void loop() {
    // Read Seria for data from the senssor
    long low_humidity = analogRead(rainPin);
    int percent_of_humidity = 100-((low_humidity*100)/1023);
    show_t(4, String(percent_of_humidity)+" %");
    Serial.write(percent_of_humidity);
    delay(33);
}








// SCREEN function setup
void screen_setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}
// SCREEN function show_t
void show_t(int text_size, String line1) {
  display.clearDisplay();
  display.setTextSize(text_size);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(line1);
  //display.println(line2);
  //display.println(line3);
  //display.println(line4);
  display.display();
}
