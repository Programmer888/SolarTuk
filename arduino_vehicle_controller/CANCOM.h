#include "Arduino.h"
#include <stdio.h>

#include "OBD2.h"

#pragma once

class CANCOM {

protected:
  CANCOM();
  
public:
  static CANCOM& instance(); // Class method as the only access to the Singleton Object
  
  virtual            ~CANCOM();
  //void loop();
  void sendMessage(OBD2_FRAME frame);
  void receive();
  OBD2_FRAME createFrame(int id, int mode, int PID, int A, int B, int C, int D);
 // static CANCOM* pInstance; // Static variable holding the pointer to the only instance of this
private:
  static CANCOM *pInstance;
};
