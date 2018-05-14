
/*************************************** 
Waveshare AlphaBot Car Bluetooth Control

Modified by Konstantinos Xynos (2018) to work with HM-10 (HM10)

Get the WS BLE app and modify the Remote Control buttons to those below.

Any UART application can be used. 

Command Line (implemented):
-----------------------------------------------------------------------------------------------------
{"Car":"Forward"}
{"Car":"Backward"}
{"Car":"Left"}
{"Car":"Right"}
{"Car":"SetSpeed","Value":[200,200]}


CN: www.waveshare.net/wiki/AlphaBot
EN: www.waveshare.com/wiki/AlphaBot
****************************************/

#include "AlphaBot.h"
#include "ArduinoJson.h"


#define START '{'
#define END '}'
bool Started = false;
bool Ended = false;

unsigned long n = 0;

AlphaBot Car1 = AlphaBot();

char inData[80];
byte Num;

void setup()
{
  Serial.begin(9600);
  Serial.println("start!");
 
 // set car speed to 200
  Car1.SetSpeed(200);

}

void loop()
{ 
  // tell the system when to break after going forward.
  if (millis() - n > 200)
  {
    Car1.Brake();
  }
  
  while(Serial.available() > 0)
 {
   char ch = Serial.read();
   if(ch == START)
   {
     Num = 0;
     inData[Num++] = ch;
     Started = true;
     Ended = false;
   }else if(ch == END)
   {
     inData[Num++] = ch;
     inData[Num] = '\0';
     Ended = true;
   }else if(Started && !Ended)
   {
     inData[Num++] = ch;
   }else
   {
     inData[Num++] = ch;
   }
  }
  
   if(Started && Ended)
   {
     // debug 
     // Serial.println(inData);
     StaticJsonBuffer<80> jsonBuffer;
     JsonObject& DecodeData = jsonBuffer.parseObject(inData);
     
     if (!DecodeData.success())
    {
      Serial.println("parseObject() failed");
      Started = false;
      Ended = false;
      return;
    }
    // debug
    //Serial.println("----");
    n = millis(); ;
    const char* Car = DecodeData["Car"];
    // debug
    //Serial.println(Car);
    if(Car)
    {
      if(strcmp(Car,"Forward") == 0)                 //{"Car":"Forward"}
        Car1.Forward();
      else if(strcmp(Car,"Backward") == 0)           //{"Car":"Backward"}
        Car1.Backward();
      else if(strcmp(Car,"Left") == 0)               //{"Car":"Left"}
        Car1.Left();
      else if(strcmp(Car,"Right") == 0)              //{"Car":"Right"}
        Car1.Right();
      else if(strcmp(Car,"SetSpeed") == 0)           //{"Car":"SetSpeed","Value":[200,200]}
      {
        byte LSpeed = DecodeData["Value"][0];
        byte RSpeed = DecodeData["Value"][1];
        Car1.SetSpeed(LSpeed,RSpeed);
      }
      else
        Car1.Brake();
    }

    Started = false;
    Ended = false;
   } 
}


