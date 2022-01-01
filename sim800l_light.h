#ifndef SIM800L_LIGHT_H
#define SIM800L_LIGHT_H

#include "Arduino.h"

class sim800l_light
{
   private:
      // qui ci va tutto quello che è private e quindi non visibile da fuori la libreria

   public:
      // qui ci va tutto quello che deve essere VISIBILE DA FUORI, compreso eventuali variabili di ritorno o tipi di ritorno
      void begin (void);
};

#endif