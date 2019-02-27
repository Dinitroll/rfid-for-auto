
int a;
int val = 0;
int del = A1;
bool stat = false;
unsigned long timing;
void setup() {
  // stat = false;
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, INPUT_PULLUP);
  Serial.begin(4800);
  //while(!Serial);
}

void loop() {
  //stat = false;
  Serial.println("1");
  delay(600);
  if (Serial.available() > 0) {
    stat = true;
    a = Serial.parseInt();
    switch (a) {
      case 1:
        unlock();
        break;
    }
  }
  else if (!Serial.available() > 0)
  {
    // lock();
    stat = false;
  }

}
void unlock() {
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  delay(80);
  digitalWrite(6, LOW);
  delay(80);
  digitalWrite(6, HIGH);
  delay(80);
  digitalWrite(3, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(5, HIGH);
  delay(300);
  digitalWrite(3, LOW);
  delay(300);
  digitalWrite(3, HIGH);
  digitalWrite(5, LOW);
  delay(300);
  digitalWrite(3, LOW);
  while (stat = true) {
    Serial.available();
    Serial.parseInt();
    Serial.println("1");
    delay(600);
    if (Serial.available() > 0) {
      stat = true;
    }
    else {
      lock();
      stat = false;
      break;
    }
    Start();
  }
}
void lock() {
  digitalWrite(6, HIGH);
  delay(100);
  digitalWrite(6, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(7, HIGH);
  delay(600);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  while (stat = false) {
    Serial.available();
    Serial.parseInt();
    Serial.println("1");
    delay(100);
    if (!Serial.available() > 0) {
      stat = false;
    }
    else {
      unlock();
      stat = true;
      break;
    }
  }

}
void res() {
  while (Serial.available())
    Serial.read();
}
void Start() {
  val = analogRead(del);
  int x=val*3;
  int b = digitalRead(12);
  if (b == 0) {
    digitalWrite(8, HIGH);
    delay(1500);
    digitalWrite(9, HIGH);
    delay(x);
    digitalWrite(9, LOW);
    while (b == 0) {
      int b = digitalRead(12);
      if (b == 1) {
        return;
      }
    }

  }
  else {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
}


