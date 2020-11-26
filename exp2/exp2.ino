  int redPIN = 9;
  int yelloPIN = 10;
  int redON = 250;
  int redOFF = 250;

void setup() {
  pinMode(redPIN,OUTPUT);
  pinMode(yelloPIN,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("The red light is blinking");
    for(int i=1;i<=5;i=i+1)
    {
        Serial.println(i);
        digitalWrite(redPIN,HIGH);
        delay(redON);
        digitalWrite(redPIN,LOW);
        delay(redOFF);
    }
    Serial.println("The blue light is blinking");
    for(int j=1;j<=10;j=j+1)
    {
        Serial.println(j);
        digitalWrite(yelloPIN,HIGH);
        delay(redON);
        digitalWrite(yelloPIN,LOW);
        delay(redOFF);
    }

}
