//Motor 1

#include <Wire.h>

#define SLAVE_ADDRESS 0x60 
//byte x = 0x00;
void setup()
{
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
}

void loop()
{
  //delay(100);
  //delay(50);
}

void requestEvent() 
{
  int motor_pos = 5; //This would be replaced by motor position info being sent to master
  Serial.print("Request from Master. Sending: ");
  Serial.print(motor_pos);
  Serial.print("\n");

  //Wire.write(x);
  Wire.write(motor_pos);
}

void receiveEvent(int bytes)
{
  if(Wire.available() != 0)
  {
      int z = Wire.read();
      Serial.print("Received: ");
      Serial.print(z);
      Serial.print("\n");

  }
}
