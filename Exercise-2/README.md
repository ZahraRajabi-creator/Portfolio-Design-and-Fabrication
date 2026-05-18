# Digital Design & Fabrication – Exercise 2
## Introduction

In this exercise, we built a functional alarm clock using Arduino Uno and different electronic components. The main goal of the project was to understand how multiple devices can work together in one system.

During the exercise, we worked with an LCD screen, RTC module, buzzer, and push buttons. We also learned how I2C communication works and how Arduino can read inputs and control outputs.

The project was completed step by step by first testing each component separately and then combining all parts into a final alarm clock system. In the final setup, the clock was able to display the current time, set an alarm, and activate a buzzer when the alarm time was reached.

## Sub-circuit 1 – Buzzer

In this exercise, we connected the buzzer to the Arduino Uno and tested it using the provided code.

[Watch the timelapse setup video](videos/timelapse-setup.mp4)

At first, the buzzer did not produce any sound. After checking the circuit and comparing it with the schematic, we noticed that the buzzer was connected in the wrong direction. After correcting the connection, the buzzer started working properly.

The photo below shows the buzzer test circuit on the breadboard.

![Buzzer test circuit](images/buzzer-test.jpg)

The buzzer beeped 3 times based on the value defined in the code.

```cpp
#define buzzerPin 4

int howManyRings = 3;

void setup() {

  pinMode(buzzerPin, OUTPUT);

  for(int i = 0; i < howManyRings; i++) {

    digitalWrite(buzzerPin, HIGH);
    delay(1000);

    digitalWrite(buzzerPin, LOW);
    delay(1000);
  }
}

void loop() {
}
```

During the test, we experimented with different delay values and observed how they changed the buzzer timing.

- With `delay(1000)`, the buzzer stayed ON for 1 second.
- With `delay(100)`, the beeps became very short and fast.
- With `delay(2000)`, the beeps became much longer and slower.

We also changed the value of `howManyRings` from 3 to 4, and the buzzer beeped 4 times instead of 3 times.

The video below shows the buzzer working after fixing the connection.

[Download the buzzer test video](videos/buzzer-test.MOV.zip)

From this experiment, we understood that:
- `HIGH` activates the buzzer
- `LOW` stops the sound
- `delay()` controls the timing of the beeps
