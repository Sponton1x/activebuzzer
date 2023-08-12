int Trig = 2;      // Pin 2 Arduino connect by pin with Trigger sensor
int Echo = 3;      // Pin 3 Arduino connect by pin with Echo sensor
int CM;            // Distance in cm
long CZAS;         // Distance pulse length in µs
int buzzerPin = 8; // Pin to buzzer
int ledPin = 13; // Pin to LED diod

void setup()
{
  Serial.begin(9600); // Inicjalization parallel monitor
  pinMode(buzzerPin, OUTPUT);
  pinMode(Trig, OUTPUT); // Set pin 2 in Arduino as output
  pinMode(Echo, INPUT);  // Set pin 3 in Arduino as input
  pinMode(ledPin, OUTPUT); // Set pin diod LED as output
  Serial.println("Test sensor distance");
}

void loop()
{
  measure_distance(); // measurement of distance
  Serial.print("Distance: "); // Display results on LCD in loop for 200 ms
  Serial.print(CM);
  Serial.println(" cm");

    // Control sound buzzer and diod LED according by distance
  if (CM <= 30)
  {
    buzz(1000); // If distance <= 30 cm, buzzer beep very fast (100 ms)
    led(3); // Turn on diod LED for 3 seconds
  }
  else if (CM > 30 && CM < 50)
  {
    buzz(500); // If distance > 30 cm && distancde < 50, buzzer beep slowly (500 ms)
    led(2);
  }
  else if (CM > 50 && CM < 70)
  {
    buzz(100);
    led(1);
  }
  else
  {
    noTone(buzzerPin); // Else, turn off buzzer sound
    digitalWrite(ledPin, LOW); // Turn off LED diod
  }
}

void measure_distance()
{
  digitalWrite(Trig, LOW); // Set the high state to 2 µs - initialization pulse
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH); // Set the high state to 10 µs - initialization pulse
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  digitalWrite(Echo, HIGH);
  CZAS = pulseIn(Echo, HIGH);
  CM = CZAS / 58;// The width of the reflected pulse in µs divided by 58 is the distance in cm
}

// Function to control buzzer sound
void buzz(int duration)
{
  tone(buzzerPin, 1000); // Trun on buzzer of 1000Hz
  delay(duration); // Beep through specific time
  noTone(buzzerPin); // Turn off buzzer sound
}

// Function to control diod
void led(int duration)
{
  digitalWrite(ledPin, HIGH); // Turn on LED diod
  delay(duration * 1000); // Wait for a time
  digitalWrite(ledPin, LOW); // Turn off LED diod
}
