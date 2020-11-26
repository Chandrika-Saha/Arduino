#include <SoftwareSerial.h>

// Configure software serial port
SoftwareSerial SIM900(7, 8);
//Variable to save incoming SMS characters
char incoming_char=0;
int led = 13;
int flag=0;
String text = "";

void setup() {
  pinMode(led,OUTPUT);
  // Arduino communicates with SIM900 GSM shield at a baud rate of 19200
  // Make sure that corresponds to the baud rate of your module
  SIM900.begin(19200);
  // For serial monitor
  Serial.begin(19200); 
  // Give time to your GSM shield log on to network
  delay(20000);
  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);
  // Set module to send SMS data to serial out upon receipt 
  SIM900.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
}

void loop() {
  // Display any text that the GSM shield sends out on the serial monitor
 // delay(7000);
   if(SIM900.available() >0) {
    //Get the character from the cellular serial port
    //incoming_char=SIM900.read(); 
    incoming_char = SIM900.read();
    //Print the incoming character to the terminal
    Serial.print(incoming_char); 
    text = String(incoming_char+text); 
  }

  int i;
  for(i=0;i<text.length();i=i+1)
  {
    if(text[i]=='#')
    {
      flag = 1;
    break;
    }
  }

  if(flag ==1)
  {  
     digitalWrite(led,HIGH);
     

     Serial.println(text);
     Serial.println("Kodu Ajad");
     flag = 0;
     text="";
     SIM900.flush();
  }

  for(i=0;i<text.length();i=i+1)
  {
    if(text[i]=='*')
    {
      flag = 2;
      break;
    }
  }

  if(flag ==2)
  {  
     digitalWrite(led,LOW);
     Serial.println(text);
     Serial.println("Modhu Ajad");
     flag = 0;
     text="";
     SIM900.flush();
  }
}

