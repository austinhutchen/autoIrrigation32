// Define the pins
const int relayPin = 2; // Relay connected to digital pin 2
const int sensorPin = A0; // Moisture Sensor in analog pin A0

// Define the moisture threshold
const int moistureThreshold = 300;

void setup() {
  pinMode(relayPin, OUTPUT); // Set the relay pin as output
  digitalWrite(relayPin, HIGH); // Start with the water pump off
}

void loop() {
  int moisture = analogRead(sensorPin); // Read the value from the moisture sensor

  if(moisture < moistureThreshold) {
    // If the moisture level is below the threshold, turn on the pump
    digitalWrite(relayPin, LOW); // Turn ON the water pump
  } else {
    // If the moisture level is above the threshold, turn off the pump
    digitalWrite(relayPin, HIGH); // Turn OFF the water pump
  }

  delay(1000); // Wait for a second before next reading
}
