#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

#define buzzerPin 4

#define redButton 2
#define blueButton 3
#define whiteButton 5
#define blackButton 6

LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS1307 rtc;

int alarmHour = 14;
int alarmMinute = 50;

bool alarmEnabled = true;
bool alarmRinging = false;

void setup() {

  pinMode(buzzerPin, OUTPUT);

  pinMode(redButton, INPUT_PULLUP);
  pinMode(blueButton, INPUT_PULLUP);
  pinMode(whiteButton, INPUT_PULLUP);
  pinMode(blackButton, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  rtc.begin();

  // Uncomment once if RTC time is wrong
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop() {

  DateTime now = rtc.now();

  // BLUE -> increase hour
  if(digitalRead(blueButton) == LOW) {

    alarmHour++;

    if(alarmHour > 23) {
      alarmHour = 0;
    }

    delay(250);
  }

  // WHITE -> increase minute
  if(digitalRead(whiteButton) == LOW) {

    alarmMinute++;

    if(alarmMinute > 59) {
      alarmMinute = 0;
    }

    delay(250);
  }

  // BLACK -> enable/disable alarm
  if(digitalRead(blackButton) == LOW) {

    alarmEnabled = !alarmEnabled;

    delay(300);
  }

  // RED -> stop alarm
  if(digitalRead(redButton) == LOW) {

    alarmRinging = false;

    noTone(buzzerPin);

    delay(300);
  }

  // Trigger alarm
  if(alarmEnabled &&
     now.hour() == alarmHour &&
     now.minute() == alarmMinute) {

      alarmRinging = true;
  }

  // Alarm sound
  if(alarmRinging) {

    tone(buzzerPin, 1200);
  }

  else {

    noTone(buzzerPin);
  }

  // LCD
  lcd.setCursor(0, 0);

  lcd.print("Time ");

  print2(now.hour());
  lcd.print(":");

  print2(now.minute());
  lcd.print(":");

  print2(now.second());

  lcd.print(" ");

  lcd.setCursor(0, 1);

  if(alarmEnabled) {
    lcd.print("A ");
  }

  else {
    lcd.print("X ");
  }

  print2(alarmHour);

  lcd.print(":");

  print2(alarmMinute);

  lcd.print("     ");

  delay(200);
}

void print2(int number) {

  if(number < 10) {
    lcd.print("0");
  }

  lcd.print(number);
}
