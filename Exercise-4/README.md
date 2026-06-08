# Digital Design & Fabrication – Exercise 4  
# E-Textile LED Heart Patch

**Student:** Zahra Rajabi  
**University:** Carl von Ossietzky University Oldenburg  
**Lecturers:** Prof. Dr. Susanne Boll-Westermann, Mikołaj Woźniak, Tobias Lunte

---

## Project Overview

In this exercise, I created an e-textile patch that can be attached to clothing.  
The patch is shaped like a heart and includes six sewable LEDs, a coin-cell battery holder, and conductive thread.

---

## Materials

- Purple textile fabric
- Sewable LEDs
- Sewable coin-cell battery holder
- Coin-cell battery
- Conductive thread
- Sewing needle
- Scissors
- Decorative star
- Regular sewing thread

![Available materials](Images/materials.jpg)
## Test

<img src="./Images/materials.jpg" width="600">
---

## Process

### 1. Preparing the Textile Base

I chose a heart shape for my patch and cut two textile pieces. One layer was used as the base for the circuit, and the second layer was used as the cover.

![Heart textile pieces](Images/heart-pieces.jpg)

---

### 2. Sewing the Circuit

I used conductive thread to connect the LEDs with the battery holder.

To avoid short circuits, I separated the conductive paths. The positive connections were sewn on the back side of the textile, while the negative connections were sewn on the front side. This ensured that the conductive threads did not cross or touch each other.

![Sewing process](Images/sewing-process.jpg)

---

### 3. Testing and Debugging

During testing, the LEDs did not work correctly at first. Some LEDs did not turn on because the first conductive thread had a very high resistance. Later, I also realized that I had connected the LEDs in series instead of parallel.

![Testing circuit](Images/testing.jpg)

---

## Problems and Challenges

The first problem appeared after I had finished sewing the circuit. When I inserted the battery, none of the LEDs turned on. After checking the circuit, I discovered that the conductive thread I had used had a very high electrical resistance.

After replacing the thread, I faced another issue. Some LEDs did not light up correctly because I had connected the LEDs in a series circuit instead of a parallel circuit. Since conductive thread already has resistance, the series circuit caused a voltage drop, and the LEDs could not receive enough power.

To solve this, I redesigned the circuit as a parallel circuit. This allowed the LEDs to receive a more stable voltage.

Another challenge was preventing short circuits. The positive and negative conductive paths must not touch each other. Therefore, I sewed the positive connections on the back side of the textile and the negative connections on the front side.

---

## Final Result

After changing the conductive thread and redesigning the circuit as a parallel circuit, the LEDs worked correctly.

![Final back view](Images/final-back.jpg)

![Final illuminated patch](Images/final-light.jpg)

---

## What I Learned

Through this project, I learned:

- how to create a soft circuit on textile
- how conductive thread works
- how to identify the positive and negative sides of sewable LEDs
- why the resistance of conductive thread matters
- the difference between series and parallel circuits
- why a parallel circuit is better for multiple LEDs
- how to troubleshoot problems in e-textile circuits
- why testing during the process is important

---

## Final Reflection

This project helped me understand that e-textile circuits require both electronic thinking and careful handcrafting.  
Small details, such as the type of conductive thread or the way LEDs are connected, can strongly affect the final result.

Although I faced several problems during the process, solving them helped me understand soft circuits much better.
# TEST

[Open Image](Images/materials.jpg)
