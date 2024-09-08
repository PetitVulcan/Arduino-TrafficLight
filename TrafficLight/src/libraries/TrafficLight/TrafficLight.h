#ifndef TrafficLight_h
#define TrafficLight_h

#include "Arduino.h"

class TrafficLight
{
public:
  // Constructeur: définit les pins pour les LED orange, verte, et rouge et active/désactive les logs d'état dans le moniteur serie
  TrafficLight(int orangePin, int greenPin, int redPin, bool logState);

  // Méthodes pour allumer chaque couleur
  void red();
  void orange();
  void green();

  // Méthode pour passer automatiquement d'un état à l'autre sans bloquer
  void init();
  void cycle(int redTime, int orangeTime, int greenTime);
  void runIntersectionCycle(TrafficLight feuRue1, TrafficLight feuRue2, int redTime, int orangeTime, int greenTime, int pauseTime);

  // Méthode pour éteindre toutes les LED
  void allOff();

  // Méthode pour loguer l'état des feux dans le moniteur serie
  void logPhase(const char *phaseName, int remainingTime);

  // Méthode pour faire clignoter la LED orange pour une durée donnée
  void blinkOrange(unsigned long duration);

private:
  int _redPin;
  int _orangePin;
  int _greenPin;

  unsigned long _previousMillis; // Temps précédemment enregistré
  unsigned long _previousLogMillis; // Temps précédemment enregistré pour le dernier log
  unsigned long _startMillis;    // Temps de début du clignotement
  bool _logState;             // État actuel des logs de l'etat du feu dans le moniteur serie
  bool _orangeState;             // État actuel de la LED orange

  void setLights(bool redState, bool orangeState, bool greenState);
};

#endif
