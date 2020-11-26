/*********
  Complete project details at http://randomnerdtutorials.com  
*********/

#include <SoftwareSerial.h>
int readv;
int in = A0;

char incoming_char=0;
int led = 13;
int flag=0;
String text = "";
// Configure software serial port
SoftwareSerial SIM900(7, 8); 

void setup() {
  // Arduino communicates with SIM900 GSM shield at a baud rate of 19200
  // Make sure that corresponds to the baud rate of your module
  SIM900.begin(19200);
  // Give time to your GSM shield log on to network
  delay(20000);   
    pinMode(in,INPUT);
  Serial.begin(19200);
  // Send the SMS
 // sendSMS();

  pinMode(led,OUTPUT);
  // Arduino communicates with SIM900 GSM shield at a baud rate of 19200
  // Make sure that corresponds to the baud rate of your module
 // SIM900.begin(19200);
  // For serial monitor
  //Serial.begin(19200); 
  // Give time to your GSM shield log on to network
  //delay(20000);
  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);
  // Set module to send SMS data to serial out upon receipt 
  SIM900.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
 
}

void loop() { 

   readv = analogRead(in);
   if(readv > 230)
   {
    sendSMSHigh();
    Serial.println("KODU");
    int k = 0;
    int i;
    for(i=0;i<20;i=i+1){
    if(SIM900.available() >0)
    {
      k = 1;
      CHECK();
    }
    if(k==0)
    delay(1000);
    }
   }

  if(readv < 80)
   {
    sendSMSLow();
    Serial.println("MODU");
    delay(20000);
   }
   
  Serial.print("Level: ");
  Serial.println(readv);
  //delay(1000);  
  CHECK();
}
void CHECK()
{
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
void sendSMSHigh() {
  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);

  // REPLACE THE X's WITH THE RECIPIENT'S MOBILE NUMBER
  // USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS
  SIM900.println("AT + CMGS = \"+8801521229179\""); 
  delay(100);
  
  // REPLACE WITH YOUR OWN SMS MESSAGE CONTENT
  SIM900.println("Water level CRITICAL..!!!"); 
  delay(100);

  // End AT command with a ^Z, ASCII code 26
  SIM900.println((char)26); 
  delay(100);
  SIM900.println();
  // Give module time to send SMS
  

   
    SIM900.print("AT+CMGF=1\r"); 
  delay(100);
  // Set module to send SMS data to serial out upon receipt 
  SIM900.print("AT+CNMI=2,2,0,0,0\r");
  delay(5000);
}

void sendSMSLow() {
  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);

  // REPLACE THE X's WITH THE RECIPIENT'S MOBILE NUMBER
  // USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS
  SIM900.println("AT + CMGS = \"+8801521229179\""); 
  delay(100);
  
  // REPLACE WITH YOUR OWN SMS MESSAGE CONTENT
  SIM900.println("Turn on the Motor NOWWW!!!"); 
  delay(100);

  // End AT command with a ^Z, ASCII code 26
  SIM900.println((char)26); 
  delay(100);
  SIM900.println();
  // Give module time to send SMS
  

   
    SIM900.print("AT+CMGF=1\r"); 
  delay(100);
  // Set module to send SMS data to serial out upon receipt 
  SIM900.print("AT+CNMI=2,2,0,0,0\r");
  delay(5000);
}
