

#include <Sim800l.h>
#include <SoftwareSerial.h> //is necesary for the library!! 
Sim800l Sim800l;  //to declare the library
SoftwareSerial sim(10,11);
String text;     // to storage the text of the sms
uint8_t index;   // to indicate the message to read.



void setup(){
  pinMode(8,OUTPUT);
  digitalWrite(8,0);
  ///pinMode(9,OUTPUT);
  //digitalWrite(9,0);
	Serial.begin(9600); // only for debug the results . 
  sim.begin(9600);
	Sim800l.begin(); // initializate the library. 
	index=1; // first position in the prefered memory storage. 
	text=Sim800l.readSms(index);
  Serial.println(text);
  
  sim.println("AT+CMGD=1,4");//DELETE ALL MASSG



}

void loop(){
text=Sim800l.readSms(index);//read massg text than save it to string 
if(text.indexOf("D11")!=-1){
 digitalWrite(7,1);
 }
else if(text.indexOf("D10")!=-1){
 digitalWrite(7,0);
 }
 //هنا يمكنك اضافة اجهزة اخرى للتحكم بها 
//else if(text.indexOf("D21")!=-1){
// digitalWrite(9,1);
// }
//else if(text.indexOf("D20")!=-1){
// digitalWrite(9,0);
// }
// else if(text.indexOf("D0")!=-1){
// digitalWrite(9,0);
// digitalWrite(8,0);
// }
// else if(text.indexOf("D1")!=-1){
// digitalWrite(9,1);
// digitalWrite(8,1);
// }
sim.println("AT+CMGD=1,4");//مسح الرسائل كل مرة
}
