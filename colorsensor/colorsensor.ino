int red = 11;
int green = 10;
int blue = 6;

int s2 = 7;
int s3 = 8;

int out = 4;
unsigned int pluswidth;
int reds;
int greens;
int blues;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);

  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);

  pinMode(out,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW); //read red value
  pluswidth = pulseIn(out,LOW);
  reds = (pluswidth/400) - 1;
  reds = 255 - reds;

  digitalWrite(s2,HIGH);
  digitalWrite(s3,HIGH);
  pluswidth = pulseIn(out,LOW);
  greens = (pluswidth/400) - 1;
  greens = 255 - greens;

  digitalWrite(s2,LOW);
  digitalWrite(s3,HIGH);
  pluswidth = pulseIn(out,LOW);
  blues = (pluswidth/400) - 1;
  blues = 255 - blues;

  if(reds > greens && greens > blues)
  {
    reds = 255;
    greens = green/2;
    blues = 0;
  }
  if(reds > blues && blues> greens)
  {
    reds = 255;
    greens = 0;
    blues = blues/2;
  }
    if(greens > reds && reds > blues)
  {
    reds = reds/2;
    greens = 255;
    blues = 0;
  }
    if(greens > blues && blues > reds)
  {
    reds = 0;
    greens = 255;
    blues = blues/2;
  }
    if(blues > reds && reds > greens)
  {
    reds = reds/2;
    greens = 0;
    blues = 255;
  }
   if(blues > greens && greens > reds)
  {
    reds = 0;
    greens = green/2;
    blues = 255;
  }
  reds = reds*.3;
  blues = blues*.3;
  analogWrite(red,reds);
  analogWrite(green,greens);
  analogWrite(blue,blues);
    
  Serial.print(reds);
  Serial.print(" , ");
  Serial.print(greens);
  Serial.print(" , ");
  Serial.println(blues);


  delay(200);

}
