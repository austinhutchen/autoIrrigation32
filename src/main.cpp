#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET -1
#define REFRESH_TIME 1200
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
const int relaypin = 5;
const int sensorpin = A0;
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
//turns on relay, in turn turning on pump
delay(500);
}
void pump(){
	display.setTextSize(2);
	delay(REFRESH_TIME/2);
   display.setCursor(0,10);
   display.clearDisplay();
   digitalWrite(relaypin, LOW);
display.print("H20 PUMP \nSIGNL SENT");
display.display();
delay(REFRESH_TIME);
display.clearDisplay();
}
void donothing(int val)
 {
	 delay(REFRESH_TIME/2);
 display.clearDisplay();
 display.setCursor(0,5);
 display.setTextSize(2);
  display.print("PLANT :) \ MOIST: ");
  display.print(val+'0');
  display.display();
  digitalWrite(relaypin, HIGH);
  delay(REFRESH_TIME);
  display.clearDisplay();
}
void loop() {
      	// put your main code here, to run repeatedly:
	while(true){

display.setCursor(0,10);
        display.setTextSize(2);
        display.print("MOISTURE LEVEL: \n");
        sensorval = analogRead(sensorpin);
        display.print(sensorval);
        display.display();
        (sensorval < 600)?pump():donothing(sensorval);


	}
}
