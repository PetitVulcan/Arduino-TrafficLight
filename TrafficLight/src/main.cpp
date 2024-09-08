#include <Arduino.h>
#include "libraries/TrafficLight/TrafficLight.h"

// Définir les pins pour les LED des deux feux tricolores
TrafficLight road1(2, 3, 4, true);  // Rue 1
TrafficLight road2(8, 9, 10, true); // Rue 2

// Durée des différentes phases
const int greenTime = 30000; // durée pour le vert
const int orangeTime = 5000; // durée pour l'orange
const int redTime = 30000; // durée où les deux rues sont au rouge
const int pauseTime = 3000; // 3 secondes où les deux rues sont au rouge



void setup()
{
  Serial.begin(9600); // Initialisation du moniteur série

  road1.init();
  road2.init();
  road1.allOff();
}

void loop()
{
  //road1.blinkOrange(10000);
  //road1.cycle(greenTime,orangeTime,redTime);
  road1.runIntersectionCycle(road1, road2, greenTime, orangeTime, redTime, pauseTime);
}
