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

	if(digitalRead(3)==HIGH&&flag==0)  //если кнопка нажата и флаг=0   
	{ 
		digitalWrite(2,HIGH);    //открыть клапан
		delay(del);              //подождать del миллисекунд
		digitalWrite(2,LOW);     //закрыть клапан
		flag=1;                  //поставить флажок=1
	} 
	
	if(digitalRead(3)==LOW&&flag==1)  //если кнопка отпущена
	{            
		flag=0;                      //обнуляем переменную flag 
	}
	delay(3);         //задержка для стабильности работы
} 


