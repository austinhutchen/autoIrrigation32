
const int relayPin = 2;
const int sensorPin = A0;
float sensorValue = 0;
#define SENSOR_READ_TIME 1000
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
//begins communication with serial monitor
pinMode(relayPin, OUTPUT);
//sets pin 2 to output
pinMode(sensorPin, INPUT);
//sets pin A0 to input
digitalWrite(relayPin, HIGH);
//turns on relay, in turn turning on pump
delay(500);
//runs pump for 1/2 second
}

void loop() {
// put your main code here, to run repeatedly:
Serial.print("MOISTURE LEVEL: ");
//prints "MOISTURE LEVEL: "
sensorValue = analogRead(sensorPin);
//sets "sensorValue" to input value from A0
Serial.print(sensorValue);
//prints moisture level
(sensorValue>750)?digitalWrite(relayPin, HIGH):digitalWrite(relayPin, LOW);

Serial.println();
//prints new line for spacing
delay(SENSOR_READ_TIME);
//waits 1 second before re-checking moisture level
}
