#include <Servo.h>
Servo servo1;//create servo object to control a servo
Servo servo2;//create servo object to control a servo
Servo servo3;//create servo object to control a servo
Servo servo4;//create servo object to control a servo
Servo servo5;//create servo object to control a servo
//The following can be modified according to your specific needs
int dataServo1 = 90; // Servo 1 rotation range(dataServo1=0~180)
int dataServo2 = 90; // Servo 2 rotation range(dataServo2=0~180) 
int dataServo3 = 90; // Servo 3 rotation range(dataServo3=0~180)
int dataServo4 = 90; // Servo 4 rotation range(dataServo4=0~180)
int dataServo5 = 90; // Servo 5 rotation range(dataServo5=35~90)

char val;
int incomingByte = 0;          // Received data byte
String inputString = "";         // Used to store received content
boolean newLineReceived = false; //  Previous data end flag
boolean startBit  = false;  //Acceptance Agreement Start Sign
int num_reveice=0;

float dirServo1Offset = 0;    // define a variable for deviation(degree) of the servo
float dirServo2Offset = 0;    // define a variable for deviation(degree) of the servo
float dirServo3Offset = 0;    // define a variable for deviation(degree) of the servo
float dirServo4Offset = 0;    // define a variable for deviation(degree) of the servo
float dirServo5Offset = 0;    // define a variable for deviation(degree) of the servo
int val1;
int val2;
int val3;
int val4;
int val5;
void setup()
{
  servo1.attach(9);//attachs the servo1 on pin 9 to servo object
  servo2.attach(6);//attachs the servo2 on pin 6 to servo object
  servo3.attach(5);//attachs the servo3 on pin 5 to servo object
  servo4.attach(3);//attachs the servo4 on pin 3 to servo object
  servo5.attach(11);//attachs the servo5 on pin 11 to servo object
  
  servo1.write(dataServo1+dirServo1Offset);//goes to dataServo1 degrees 
  servo2.write(dataServo2+dirServo2Offset);//goes to dataServo2 degrees 
  servo3.write(dataServo3+dirServo3Offset);//goes to dataServo3 degrees 
  servo4.write(dataServo4+dirServo4Offset);//goes to dataServo4 degrees 
  servo5.write(dataServo5+dirServo5Offset);//goes to dataServo5 degrees 

  Serial.begin(9600); //  set the baud rate to 9600
}
void loop()
{
 while (Serial.available())
  {
    incomingByte = Serial.read();              //One byte by byte, the next sentence is read into a string array to form a completed packet
    if (incomingByte == '%')
    {
      num_reveice = 0;
      startBit = true;
    }
    if (startBit == true)
    {
      num_reveice++;
      inputString += (char) incomingByte;    
    }
    if (startBit == true && incomingByte == '#')
    {
      newLineReceived = true;
      startBit = false;
    }
    if(num_reveice >= 20)
    {
      num_reveice = 0;
      startBit = false;
      newLineReceived = false;
      inputString = "";
    }  
  }
  if(newLineReceived)
  {
      Serial.println(inputString);
  }
  servo1.write(dataServo1+dirServo1Offset);//goes to dataServo1 degrees 
  servo2.write(dataServo2+dirServo2Offset);//goes to dataServo2 degrees 
  servo3.write(dataServo3+dirServo3Offset);//goes to dataServo3 degrees 
  servo4.write(dataServo4+dirServo4Offset);//goes to dataServo4 degrees 
  servo5.write(dataServo5+dirServo5Offset);//goes to dataServo5 degrees 

  val1 = map(analogRead(0), 0, 1023, 0, 180);  
  val2 = map(analogRead(1), 0, 1023, 0, 180);  
  val3 = map(analogRead(2), 0, 1023, 0, 180);  
  val4 = map(analogRead(3), 0, 1023, 0, 180);
  val5 = map(analogRead(6), 0, 1023, 35, 90);  
 
  dataServo1 = val1;
  dataServo2 = val2;
  dataServo3 = val3;
  dataServo4 = val4;
  dataServo5 = val5;
  delay(50);//wait for 0.05second
