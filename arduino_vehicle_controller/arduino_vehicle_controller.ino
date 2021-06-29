#include "VehicleController.h"
#include "CANCOM.h"


VehicleController *vehicleController;

void setup() {
  // put your setup code here, to run once:
  vehicleController = new VehicleController(0x001);

}

void loop() {
  // put your main code here, to run repeatedly:
  
    
  vehicleController->loop();
  
}
