
  int redPIN = 9;
 int yelloPIN = 10;
  //int redON = 250;
 // int redOFF = 250;

void setup() {
    pinMode(p1,OUTPUT);  
  //pinMode(redPIN,OUTPUT);
 // pinMode(yelloPIN,OUTPUT);
}

void loop() {
    //for(int i=1;i<=5;i=i+1)
   // {
       // digitalWrite(redPIN,HIGH);
        //delay(redON);
       // digitalWrite(redPIN,LOW);
       // delay(redOFF);
   // }
   // for(int j=1;j<=5;j=j+1)
   // {
        digitalWrite(p1,HIGH);
        delay(2000);
         digitalWrite(p1,LOW);
         delay(2000);
        //delay(redON);
        //digitalWrite(yelloPIN,LOW);
        //delay(redOFF);
   // }

}
