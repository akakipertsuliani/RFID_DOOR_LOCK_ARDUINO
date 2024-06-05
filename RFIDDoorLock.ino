#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

Servo myServo;

#define RST_PIN 9
#define SS_PIN 10

#define LEDNEUTRAL 4
#define LEDOK 3
#define LEDERROR 2
#define noiseBuzzer 6

MFRC522 mfrc522(SS_PIN, RST_PIN);

bool servoONOFF = true;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  myServo.attach(5);
  myServo.write(90);
  pinMode(LEDNEUTRAL, OUTPUT);
  pinMode(LEDOK, OUTPUT);
  pinMode(LEDERROR, OUTPUT);
  pinMode(noiseBuzzer, OUTPUT);
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.println(F("Card detected"));
    if (readBlockData(5) == "k9T2dQ5X1mB6rF7H") {
      if (servoONOFF) {
        myServo.write(0);
        servoONOFF = !servoONOFF;
        digitalWrite(LEDOK, HIGH);
        digitalWrite(LEDNEUTRAL, LOW);
        digitalWrite(LEDERROR, LOW);
        tone(noiseBuzzer, 1000);
        delay(1000);
        digitalWrite(LEDOK, LOW);
        tone(noiseBuzzer, 1000);
      } else if (!servoONOFF) {
        myServo.write(90);
        servoONOFF = !servoONOFF;
        digitalWrite(LEDOK, HIGH);
        digitalWrite(LEDNEUTRAL, LOW);
        digitalWrite(LEDERROR, LOW);
        delay(1000);
        digitalWrite(LEDOK, LOW);
        tone(noiseBuzzer, 1000);
      } else {
        digitalWrite(LEDOK, LOW);
        digitalWrite(LEDNEUTRAL, LOW);
        digitalWrite(LEDERROR, LOW);
        noTone(noiseBuzzer);
      }
    } else {
      digitalWrite(LEDOK, HIGH);
      digitalWrite(LEDNEUTRAL, LOW);
      digitalWrite(LEDERROR, HIGH);
      tone(noiseBuzzer, 1500);
      delay(500);
      digitalWrite(LEDOK, HIGH);
      digitalWrite(LEDNEUTRAL, LOW);
      digitalWrite(LEDERROR, HIGH);
      noTone(noiseBuzzer);
    }

    digitalWrite(LEDOK, HIGH);
    digitalWrite(LEDNEUTRAL, HIGH);
    digitalWrite(LEDERROR, LOW);

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }

  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}

void dump_byte_array(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
  Serial.println();
}