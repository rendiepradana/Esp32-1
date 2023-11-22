//Rendie Pradana
//21507224032
//GK1
//Water Leveling Using ultrasonic HC-SR05


#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const int triggerPin = 13;
const int echoPin    = 12;

int tinggiMax = 10;

void setup() {
  lcd.begin();
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("Water Level");
  lcd.setCursor(0, 1);
  lcd.print("Kelompok 3");
  delay(5000);
}

void loop() {
  lcd.clear();
  
  long duration, jos;
  int tinggiAir;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(8);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  jos = (duration / 2) / 29.1;
  tinggiAir = tinggiMax - jos;
  
  lcd.setCursor(0, 0);
  lcd.print("Ketinggian Air");
  lcd.setCursor(0, 1);
  lcd.print("= ");
  lcd.print(tinggiAir);
  lcd.print("cm");

  delay(1000);
}