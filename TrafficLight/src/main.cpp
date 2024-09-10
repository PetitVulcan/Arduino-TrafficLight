
/*
  |\/|   | _  |
  |  |(|(|(/_ |)\/
                /
                  ___     _   _ _               _
                 / _ \___| |_(_) |_/\   /\_   _| | ___ __ _ _ __
                / /_)/ _ \ __| | __\ \ / / | | | |/ __/ _` | '_ \
               / ___/  __/ |_| | |_ \ V /| |_| | | (_| (_| | | | |
               \/    \___|\__|_|\__| \_/  \__,_|_|\___\__,_|_| |_|

              TRAFFIC LIGHT v1.0.0@09-2024 - www.petitvulcan.com
*/

#include <Arduino.h>
#include "TrafficLight.h"

// Declaration des variables pour le choix des fonctions
const int _PINBTN = 5;   // Pin ou le bouton est connecte
int buttonState = 0;     // Variable pour stocker l'état du bouton
int lastButtonState = 0; // Variable pour stocker le dernier état du bouton
int counter = 0;         // Compteur qui sera incrémenté

// Definir les pins pour les LED des deux feux tricolores
TrafficLight road1(2, 3, 4, true);  // Rue 1
TrafficLight road2(8, 9, 10, true); // Rue 2

// Duree des differentes phases
const int greenTime = 30000; // duree pour le vert
const int orangeTime = 5000; // duree pour l'orange
const int redTime = 30000;   // duree ou les deux rues sont au rouge
const int pauseTime = 3000;  // duree ou les deux rues sont au rouge

// Declaration des fonctions locales
void allOff();

void setup()
{
  Serial.begin(9600); // Initialisation du moniteur serie

  // Setup Bouton avec resistance interne de pull-up
  pinMode(_PINBTN, INPUT_PULLUP);

  // Initialisation et test des feux Tricolor
  road1.init();
  road2.init();

  // Extinction de tous les feux
  allOff();
}

void loop()
{
  // Lecture de l'etat actuel du bouton
  buttonState = digitalRead(_PINBTN);

  // Detection d'un appui sur le bouton (changement d'etat de HIGH à LOW)
  if (buttonState == LOW && lastButtonState == HIGH)
  {
    counter = counter == 1 ? 0 : 1; // Incremente le compteur
    Serial.print("Compteur : ");
    Serial.println(counter); // Affiche le compteur dans le moniteur serie
    delay(200);              // Petit delai pour éviter les rebonds (debounce)
    allOff();
  }

  // Mise à jour de l'etat precedent du bouton
  lastButtonState = buttonState;

  if (counter == 0)
  {
    // road1.cycle(greenTime,orangeTime,redTime);
    road1.runIntersectionCycle(road1, road2, greenTime, orangeTime, redTime, pauseTime);
  }
  else if (counter == 1)
  {
    road1.blinkOrange(10000);
    road2.blinkOrange(10000);
  }
}

void allOff()
{
  // Extinction de tous les feux
  road1.allOff();
  road2.allOff();
}
