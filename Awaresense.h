#include <math.h>
const int trigPin = 5;
const int echoPin = 18;
const int trigPin2 = 14;
const int echoPin2 = 12;
const int vpin = 27;
const int vpin2 = 28;
#define SOUND_SPEED 0.034

long duration;
float d;
long duration2;
float d2;
float s;
float s2;
void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(vpin, OUTPUT);
  pinMode(vpin2, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  //echo 1
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  d = duration * SOUND_SPEED/2;
  //echo 2
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  d2 = duration2 * SOUND_SPEED/2;
  s = 330 * pow(1.011, -0.8 * d) + 1;
  s2 = 330 * pow(1.011, -0.8 * d2) + 1;
  if (s>255){
  s = 255;
  }
  if (s2>255){
  s2 = 255;
  }
  digitalWrite(vpin, s);
  digitalWrite(vpin2, s2);
  Serial.println(d2);
  Serial.println(d1);
}
