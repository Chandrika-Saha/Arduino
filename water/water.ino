int readv;
int in = A0;

void setup() {

  pinMode(in,INPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  readv = analogRead(in);
  Serial.print("Level: ");
  Serial.println(readv);
  delay(2000);
}
