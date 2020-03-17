// This Sketch counts the number of pulses a minute.

// Connect the GND on Arduino to the GND on the Geiger counter.

// Connect the 5V on Arduino to the 5V on the Geiger counter.

// Connect the VIN on the Geiger counter to the D2 on Arduino.

unsigned long counts; //variable for GM Tube events

unsigned long previousMillis; //variable for measuring time

void impulse() { // dipanggil setiap ada sinyal FALLING di pin 2

counts++;

}

#define LOG_PERIOD 60000 // count rate

void setup() { //setup

counts = 0;

Serial.begin(9600);

pinMode(2, INPUT);

attachInterrupt(digitalPinToInterrupt(2), impulse, FALLING); //define external interrupts

Serial.println("Start counter");

}

void loop() { //main cycle

unsigned long currentMillis = millis();

if (currentMillis - previousMillis > LOG_PERIOD) {

previousMillis = currentMillis;

Serial.println(counts);

counts = 0; 

}

}
