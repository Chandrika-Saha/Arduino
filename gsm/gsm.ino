#include <SoftwareSerial.h>

SoftwareSerial GPRS(7, 8); //Digital Pin 7 = TX, Digital Pin 8 = RX
unsigned char simmbuffer[64];
int bindex=0;

void setup(){
GPRS.begin(19200);
Serial.begin(19200);
Serial.print("Serial ready");
}

void loop(){
if (GPRS.available()){
while(GPRS.available()){
simmbuffer[bindex++]=GPRS.read();
if(bindex == 64)break;
}
Serial.write(simmbuffer,bindex);
for (int i=0; i<bindex;i++){
simmbuffer[i]='0';

}
bindex = 0;
}
if (Serial.available())
GPRS.write(Serial.read());
}
