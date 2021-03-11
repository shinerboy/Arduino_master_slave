#include <Wire.h>
//Can replace the first slave address to 1 instead of 0x60
#define SLAVE_ADDRESS 0x60
#define SLAVE_ADDRESS_2 2
#define SLAVE_ADDRESS_3 3
#define SLAVE_ADDRESS_4 4

int j =0;
int motor1;
int motor2;
int motor3;
int motor4;

void setup()
{
  Wire.begin(); 
  Serial.begin(9600);  
}



void loop()
{
  //int motor1 = 180;
  int ar1[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  //int motor2 = 90;
  int ar2[10]={10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int ar3[10]={10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int ar4[10]={10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  if ( j < 10){
    motor1=ar1[j];
    motor2=ar2[j];
    motor3=ar3[j];
    motor4=ar4[j];
    j=j+1;
  }
  if (j >=10) {
    j=0;
  }

  //  ------------SEND DATA TO SLAVES
  Serial.print("Sent: ");
  Serial.print(motor1);
  Serial.println(" to motor 1");
  Wire.beginTransmission(0x60);   
  Wire.write(motor1);                
  Wire.endTransmission();   
  Serial.print("Sent: ");
  Serial.print(motor2);
  Serial.println(" to motor 2");
  Wire.beginTransmission(SLAVE_ADDRESS_2);   
  Wire.write(motor2);                
  Wire.endTransmission();
  Serial.print("Sent: ");
  Serial.print(motor3);
  Serial.println(" to motor 3");
  Wire.beginTransmission(SLAVE_ADDRESS_3);   
  Wire.write(motor3);                
  Wire.endTransmission();
  Serial.print("Sent: ");
  Serial.print(motor4);
  Serial.println(" to motor 4");
  Wire.beginTransmission(SLAVE_ADDRESS_4);   
  Wire.write(motor4);                
  Wire.endTransmission();  
  delay(50);
// ----------- READ DATA FROM SLAVES
// SLAVE 1
  Serial.println("Requesting Slave 1 Data"); 
  Wire.requestFrom(SLAVE_ADDRESS, 1);
  int bytes = Wire.available();
  Serial.print("Slave 1 sent ");
  Serial.print(bytes);
  Serial.print(" of information\n");
  for(int i = 0; i< bytes; i++)
  {
    int x = Wire.read();
    Serial.print("Slave 1 Sent: ");
    Serial.print(x);
    Serial.print("\n");
  }  
  delay(50);
// SLAVE 2
  Serial.println("Requesting Slave 2 Data"); 
  Wire.requestFrom(SLAVE_ADDRESS_2, 1);
  int bytes_2 = Wire.available();
  Serial.print("Slave 2 sent ");
  Serial.print(bytes_2);
  Serial.print(" of information\n");
  for(int i = 0; i< bytes_2; i++)
  {
    int y = Wire.read();
    Serial.print("Slave 2 Sent: ");
    //Serial.print(x, HEX);
    Serial.println(y);
  }  
  delay(50);
// SLAVE 3
  Serial.println("Requesting Slave 3 Data"); 
  Wire.requestFrom(SLAVE_ADDRESS_3, 1);
  int bytes_3 = Wire.available();
  Serial.print("Slave 3 sent ");
  Serial.print(bytes_3);
  Serial.print(" of information\n");
  for(int i = 0; i< bytes_3; i++)
  {
    int y = Wire.read();
    Serial.print("Slave 3 Sent: ");
    //Serial.print(x, HEX);
    Serial.println(y);
  }  
  delay(50);
// SLAVE 4  
  Serial.println("Requesting Slave 4 Data"); 
  Wire.requestFrom(SLAVE_ADDRESS_4, 1);
  int bytes_4 = Wire.available();
  Serial.print("Slave 4 sent ");
  Serial.print(bytes_4);
  Serial.print(" of information\n");
  for(int i = 0; i< bytes_4; i++)
  {
    int y = Wire.read();
    Serial.print("Slave 4 Sent: ");
    //Serial.print(x, HEX);
    Serial.println(y);
  }  
  delay(50);
}
