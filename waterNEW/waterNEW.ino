#include <SoftwareSerial.h>
int readv;  //var for storing the value read from water indicator
int in = A0; //input pin for water indicator
String incoming_char=""; //stor text message
int led = 13; //led high pin
int relay = 12;
int gsm = 9;
int f=0;
int ff=0;
SoftwareSerial SIM900(7, 8);  //configuring serial input

void setup() 
{
  digitalWrite(gsm, HIGH);
  delay(1000);
  digitalWrite(gsm, LOW);
  delay(5000);
  
  SIM900.begin(19200); // sim900 communicates at 19200 speed
  delay(20000);   // setup time for sim900
  pinMode(in,INPUT);
  Serial.begin(19200);
  pinMode(led,OUTPUT);
  digitalWrite(relay,HIGH);
  pinMode(relay, OUTPUT);
  SIM900.print("AT+CMGF=1\r");   // AT command to set SIM900 to SMS mode
  delay(100);
  SIM900.print("AT+CNMI=2,2,0,0,0\r"); // Set module to send SMS data to serial out upon receipt
  delay(100);
}

void loop() 
{ 
   readv = analogRead(in);
   if(readv > 230 && f==0) //if water level cross the limit 
   {
      f=1;
      sendSMSHigh(); //motor turn OFF sms sent to mobile
      Serial.println("OVERFLOW"); 
   }
   
   if(readv < 80 && ff==0) //if the water level lowered to a critical level
   {
      ff = 1;
      sendSMSLow(); //motor turn ON sms sent to mobile
      Serial.println("UNDERFLOW");
   }
   
   // Serial.print("Level: ");
   //Serial.println(readv);

    
    if(SIM900.available() > 0)
    {
      incoming_char = SIM900.readString(); //Get the character from the cellular serial port
      Serial.print(incoming_char); //Print the incoming character to the terminal
    }
    

    if(incoming_char.indexOf("#ON")>=0)//if the string contains "#ON"
    {
      digitalWrite(relay, LOW);
      digitalWrite(led,HIGH); //turn on motor
      Serial.println("MOTOR ON");
      f = 0; 
      incoming_char=""; //re-initialize string to store 
      SIM900.flush(); //clearing sim900's buffer
    }

    
    if(incoming_char.indexOf("*OFF")>=0)//if the string contains "*OFF"
    {
      digitalWrite(relay, HIGH);
      digitalWrite(led,LOW); //turn on motor
      ff = 0;
      Serial.println("MOTOR OFF"); 
      incoming_char=""; //re-initialize string to store 
      SIM900.flush(); //clearing sim900's buffer
    }
  
}

void sendSMSHigh() 
{
  SIM900.print("AT+CMGF=1\r"); // AT command to set SIM900 to SMS mode
  delay(100);
  SIM900.println("AT + CMGS = \"+8801521229179\""); //SMS sending number
  delay(100);
  SIM900.println("Water level OVERFLOW..!!! turn OFF the motor."); //SMS content
  delay(100);
  SIM900.println((char)26);  // End AT command with a ^Z, ASCII code 26
  delay(100);
  SIM900.println();
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);
  SIM900.print("AT+CNMI=2,2,0,0,0\r");   // Set module to send SMS data to serial out upon receipt 
  delay(100);
  
}

void sendSMSLow()
{
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);
  SIM900.println("AT + CMGS = \"+8801521229179\""); 
  delay(100);
  SIM900.println("Water level UNDERFLOW..!!Turn on the Motor."); 
  delay(100);
  SIM900.println((char)26); 
  delay(100);
  SIM900.println();  
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);
  SIM900.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
  
}
