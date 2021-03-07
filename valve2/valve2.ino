/*
Created 2016
by AlexGyver
AlexGyver Home Labs Inc.
*/

int flag=0;  //флажок, что кнопка была нажата
int del=20;  //задержка клапана в миллисекундах

void setup()    
{       
	pinMode(2, OUTPUT);    //отсюда пойдут 5 вольт на транзистор
	pinMode(3, INPUT);     //сюда подключена кнопочка
} 

void loop() { 
	int val = analogRead(0);   //считать значение с потенциометра
	val = map(val, 0, 1023, 10, 500);  //преобразовать значение в промежуток 10-500
	if(digitalRead(3)==HIGH&&flag==0)//если кнопка нажата    
	{ 
		delay(val);
		digitalWrite(2,HIGH); 
		delay(del);
		digitalWrite(2,LOW);         
	} 

	delay(3);         //задержка для стабильности работы 
} 


