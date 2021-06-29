#include "CANCOM.h"
#include "mcp2515_can.h"



  const int SPI_CS_PIN = 10;
const int CAN_INT_PIN = 2;
mcp2515_can CAN(SPI_CS_PIN); // Set CS pin
unsigned char len = 0;
    unsigned char buf[8];

CANCOM *CANCOM::pInstance = NULL;
CANCOM& CANCOM::instance(){
  //static Cleanup cleanup;
  if (pInstance == nullptr)
      pInstance = new CANCOM();
  return *CANCOM::pInstance;
}
CANCOM::CANCOM()
{
  while (CAN_OK != CAN.begin(CAN_500KBPS)) {             // init can bus : baudrate = 500k
          SERIAL_PORT_MONITOR.println("CAN init fail, retry...");
          delay(100);
      }
}

CANCOM::~CANCOM(){
  
}

void CANCOM::sendMessage(OBD2_FRAME frame)
{
  unsigned char stmp[8] = {frame.id, frame.mode, frame.PID, frame.A, frame.B, frame.C, frame.D, 0xAA};
  //Serial.print("send message with value: ");
  //Serial.println(val);
  CAN.sendMsgBuf(0x70, 0, 8, stmp);
}

void CANCOM::receive()
{
  if (CAN_MSGAVAIL == CAN.checkReceive()) {         // check if data coming
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

        unsigned long canId = CAN.getCanId();

        SERIAL_PORT_MONITOR.println("-----------------------------");
        SERIAL_PORT_MONITOR.println("get data from ID: 0x");
        SERIAL_PORT_MONITOR.println(canId, HEX);

        for (int i = 0; i < len; i++) { // print the data
            SERIAL_PORT_MONITOR.print(buf[i]);
            SERIAL_PORT_MONITOR.print("\t");
            
        }
        SERIAL_PORT_MONITOR.println();
    }
}
