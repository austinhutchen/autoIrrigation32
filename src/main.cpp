#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET -1
#define REFRESH_TIME 1000
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
const int relaypin = 5;
const int sensorpin = 0;
int sensorval =0;
#define SOIL_READ_TIME 1000
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
}

  delay(2000);
  display.clearDisplay();
  pinMode(relaypin, OUTPUT);
  pinMode(sensorpin, INPUT);
  delay(500);
  display.setTextSize(2);
  display.setTextColor(WHITE);
}
void pump(){
   display.setCursor(0,10);	
    digitalWrite(relaypin, HIGH);
display.print("H20 PUMP \n SIGNL SENT");
}
void donothing(int val)
 {
 display.setCursor(0,10);
  const char* msg = "HAPPY PLANT \n HAPPINESS LEVEL : \n"+ (val%750 + '0');
  display.print(msg);
  digitalWrite(relaypin, LOW);
  return;
}
void loop() {
      	// put your main code here, to run repeatedly:
	display.setCursor(0,10);
	display.clearDisplay();
	display.setTextSize(2);
	display.print("MOISTURE   LEVEL: \n    ");
	sensorval = analogRead(sensorpin);
	display.println(sensorval);
	display.display();
	delay(REFRESH_TIME);
	display.clearDisplay();
	(sensorval > 750)?donothing(sensorval):pump();
	display.display();
	delay(SOIL_READ_TIME);
	delay(REFRESH_TIME);
}