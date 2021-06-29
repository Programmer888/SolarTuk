#pragma once

struct OBD2_FRAME {
  int id;
  int lenght;
  int mode;
  int PID;
  int A;
  int B;
  int C;
  int D;
};

#define ENGINE_SPEED 0x0C
#define VEHICLE_SPEED 0x0D
#define THROTTLE_POSITION 0x11
#define ENGINE_OIL_TEMPERATURE 0x5C
#define STEERING_POSITION 0x14

#define ENGINE_LIGHT 0x15
