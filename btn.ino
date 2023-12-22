int btn = 39;
int led = 27;
int press = 0;

void setup() {
  pinMode(btn, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(38400);
}

void loop() {
  press = digitalRead(btn);
  if (press == HIGH) {
    digitalWrite(led, HIGH);
    // Write in byte through serial port b'\x01'
    Serial.write(0x01);
  } else {
    digitalWrite(led, LOW);
  }

//   read serial for 0x02 in byte
    if (Serial.available() > 0) {
        int data = Serial.read();
        if (data == 0x02) {
        digitalWrite(led, HIGH);
        delay(2000);
        }
    }
}
