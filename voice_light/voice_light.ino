String sound;
int led = 5;
int led1 = 3;
int led2 = 4;


void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void allon(){

  digitalWrite(led, HIGH);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
}

void alloff(){

  digitalWrite(led, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
} 

void loop() {
  while(Serial.available()){
    delay(10);
    char s = Serial.read();
    if(s == '#'){break;}
    sound += s;
  }
  if(sound.length() > 0){
    Serial.println(sound);
    if(sound == "*light on"){analogWrite(led,1023);}
    else if(sound == "*computer on"){digitalWrite(led1,HIGH);}
    else if(sound == "*TV on"){digitalWrite(led2,HIGH);}
    else if(sound == "*light off"){digitalWrite(led,LOW);}
    else if(sound == "*computer off"){digitalWrite(led1,LOW);}
    else if(sound == "*TV off"){digitalWrite(led2,LOW);}
    else if(sound == "*all on"){allon();}
    else if(sound == "*all off"){alloff();}
    else if(sound == "*dim the light"){analogWrite(led,620);}
    sound = "";
  }
}
