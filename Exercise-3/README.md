# Digital Design & Fabrication – Exercise 3
# Pneumatic Stress Pillow

**Student:** Zahra Rajabi, Fatemeh Mazaherian  
**Course:** Digital Design & Fabrication  
**University:** Carl von Ossietzky University Oldenburg  
**Lecturers:** Prof. Dr. Susanne Boll-Westermann, Mikołaj Woźniak, Tobias Lunte

Exercise3 
# Pneumatic Stress Pillow

## Components Overview

- Arduino Uno

- Breadboard

- 2x Air Pumps

- Air Valve

- 3x MOSFET Modules

- Silicone Tubes

- Force-Sensitive Sensor

- Inflatable Pillow

- USB Cable

- Alligator Clips

![Components](images/components.jpg) 

## Overview

For this project, we worked with different pneumatic and electronic components, including an Arduino Uno, air pumps, an air valve, MOSFET modules, silicone tubes, and a force-sensitive sensor. Using these components, we decided to create an interactive stress pillow system.

The inflatable pillow was connected to the pneumatic system, where the pumps controlled inflation and deflation while the valve switched the airflow direction. The MOSFET modules were used to safely control the pumps and valve through the Arduino.

To make the interaction more responsive, a force-sensitive sensor was integrated into the system. When pressure was applied, the Arduino reacted to the sensor input and controlled the airflow inside the pillow accordingly.



---

## Part A – Pneumatic & Electrical Circuit

### Electrical Wiring

Three IRF520 MOSFET modules were used to control the pneumatic actuators. Each MOSFET module was connected to a separate actuator component.

- One MOSFET controlled the inflation pump.
- One MOSFET controlled the deflation pump.
- One MOSFET controlled the air valve.

The SIG pins of the MOSFET modules were connected to Arduino digital output pins, while the VCC and GND pins were connected to the Arduino power rails through the breadboard.

The pumps and valve were powered using an external laboratory power supply because they required higher current than the Arduino could safely provide directly.

All actuator grounds and the Arduino GND were connected together to create a shared ground connection for stable operation.

### Circuit Images

![Electrical Wiring](images/circuit_setup.jpg)

![Circuit Connection](images/circuit_setup_2.jpg)

---

### Pneumatic Assembly

The system uses two air pumps:
- The first pump inflates the pillow.
- The second pump removes air from the pillow for deflation.

An air valve was placed between the pumps and the inflatable pillow to switch the airflow direction between the two pneumatic paths.

When the valve is powered, the airflow direction changes. When it is unpowered, the default airflow path remains active.

The inflatable pillow was connected to the pneumatic system using silicone tubes. During assembly, special attention was required for the tubing direction and valve connections to ensure correct airflow behavior.

### Pneumatic Setup

![Pneumatic Setup](images/pneumatic_setup.jpg)

---

### Initial Testing

Before integrating the force-sensitive sensor, a simple Arduino test sketch was created to verify the pneumatic system and actuator behavior.

The code sequentially controlled:
- the inflation pump
- the deflation pump
- and the air valve

During the test:
- the pillow inflated for 10 seconds,
- paused briefly,
- then deflated for 5 seconds.

This helped verify:
- correct MOSFET switching
- airflow direction
- valve behavior
- and overall pneumatic functionality.

The LED indicators on the MOSFET modules were also used for debugging. If the LED turned on but the pump did not work, the issue was usually related to the power supply or actuator wiring.

### Test Code
const int pumpInflate = 5;
const int pumpDeflate = 8;
const int valvePin = 10;

void setup() {
  pinMode(pumpInflate, OUTPUT);
  pinMode(pumpDeflate, OUTPUT);
  pinMode(valvePin, OUTPUT);

  digitalWrite(pumpInflate, LOW);
  digitalWrite(pumpDeflate, LOW);
  digitalWrite(valvePin, LOW);
}

void loop() {

  // Inflate
  digitalWrite(valvePin, HIGH);
  digitalWrite(pumpDeflate, LOW);
  digitalWrite(pumpInflate, HIGH);

  delay(10000);

  digitalWrite(pumpInflate, LOW);

  delay(2000);

  // Deflate
  digitalWrite(valvePin, LOW);
  digitalWrite(pumpDeflate, HIGH);

  delay(5000);

  digitalWrite(pumpDeflate, LOW);
  digitalWrite(valvePin, LOW);

  delay(3000);
}

### Test Video

[Watch Test Video](videos/test_video.mp4)

---

After reconnecting the wiring correctly, the button worked as expected and the pillow could successfully inflate and deflate through two different user interactions.

### Combined System

[Watch Final Demo](videos/final_demo.mp4)

---

## Problems & Solutions

During the project, several technical challenges occurred during assembly and testing.

Some of the main issues included:
- incorrect wiring connections
- unstable airflow direction
- confusion with valve ports
- sensor sensitivity adjustments
- debugging MOSFET connections
- button wiring issues

One of the main debugging challenges happened after adding the push button interaction. Although the Serial Monitor outputs appeared correct, the button still did not respond properly. After checking the circuit multiple times, the issue was traced back to an incorrect GND connection in the wiring setup.

Most of the problems were solved by testing each component separately, checking the wiring step by step, and adjusting the Arduino code and pneumatic tubing during debugging.

The LED indicators on the MOSFET modules were especially useful during troubleshooting because they helped verify whether the Arduino signals were working correctly.
