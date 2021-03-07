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
	val = map(val, 0, 1023, 5, 30);  //преобразовать значение в промежуток 5-30

	if(digitalRead(3)==HIGH&&flag==0)//если кнопка нажата    
	{ 
		digitalWrite(2,HIGH); 
		delay(val);
		digitalWrite(2,LOW);
		flag=1;         
	} 
	
	if(digitalRead(3)==LOW&&flag==1)
	{            
		flag=0;   //обнуляем переменную flag 
	}
	delay(3);         //задержка для стабильности работы
} 


