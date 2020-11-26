int potpin = A0;
int readvalue;
float voltage;
int led;
int pinled = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(potpin,INPUT);
  pinMode(pinled,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  readvalue = analogRead(potpin);
  voltage = (5./1023.)*readvalue;
  led = voltage*51;
  Serial.println(voltage);
  Serial.println(led);
  analogWrite(pinled,led);
  delay(100);
}
