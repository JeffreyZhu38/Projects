#include <IRremote.h>
int enA = 2;
int in1 = 6;
int in2 = 4;

int enB = 7;
int in3 = 5;
int in4 = 8;

const int IR_RECEIVE_PIN = 11; 

void setup() {
  // put your setup code here, to run once:
//  Serial.begin(9600);
//  IrReceiver.begin(3, DISABLE_LED_FEEDBACK);
//  pinMode(7, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);

  digitalWrite(enA, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enB, LOW);
}

void straight() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH );
    analogWrite(enA, 250);
    analogWrite(enB, 250);
}

void back() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW );
    analogWrite(enA, 250);
    analogWrite(enB, 250);
}

void Left() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW );
    analogWrite(enA, 250);
    analogWrite(enB, 250);
}

void Right() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH );
    analogWrite(enA, 250);
    analogWrite(enB, 250);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()){ 
    String signal = String(IrReceiver.decodedIRData.decodedRawData, HEX);
    if (signal == "9f600707") {
      straight();
    }
    else if (signal == "9e610707") {
      back();
    }
    else if (signal == "9a650707") {
      Left();
    }
    else if (signal == "9d620707") {
      Right();
    }
    IrReceiver.resume();
  } 
  else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  delay(215);
}
