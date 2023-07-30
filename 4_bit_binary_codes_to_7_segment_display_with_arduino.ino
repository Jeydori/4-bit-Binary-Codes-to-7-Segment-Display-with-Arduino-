#include <Adafruit_LiquidCrystal.h>

#define output7 8
#define output6 7
#define output5 6
#define output4 5
#define output3 4
#define output2 3
#define output1 2

#define input4 13
#define input3 12
#define input2 11
#define input1 10

#define switch4 A3
#define switch3 A2
#define switch2 A1
#define switch1 A0

Adafruit_LiquidCrystal lcd(0);

int gl_arrayRawInput[4];

void setup()
{
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
  pinMode(switch4, INPUT);

  pinMode(input1, INPUT);
  pinMode(input2, INPUT);
  pinMode(input3, INPUT);
  pinMode(input4, INPUT);

  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);
  pinMode(output3, OUTPUT);
  pinMode(output4, OUTPUT);
  pinMode(output5, OUTPUT);
  pinMode(output6, OUTPUT);
  pinMode(output7, OUTPUT);

  Serial.begin(9600);
  
  lcd.begin(16, 2);
  lcd.print("Anything");
  lcd.setCursor(0,1);
  lcd.print("2022 - 2023 :'> ");
  lcd.setBacklight(1);
  delay(2000);
  
}

void loop() 
{
  int sw1 = digitalRead(switch1);
  int sw2 = digitalRead(switch2);
  int sw3 = digitalRead(switch3);
  int sw4 = digitalRead(switch4);

  setSevenSegmentOutput(0);

  delay(250);

	//Optional
  while (sw1 == 0 && sw2 == 0 && sw3 == 0 && sw4 == 1) {
    Serial.println("Group Members");
    
    	lcd.setCursor(0,0);
 		lcd.print("Group Members:  ");
   

    sw1 = digitalRead(switch1);
    sw2 = digitalRead(switch2);
    sw3 = digitalRead(switch3);
    sw4 = digitalRead(switch4);
    
  }
  
  while (sw1 == 1 && sw2 == 0 && sw3 == 0 && sw4 == 0) {
    Serial.println("  8 4-2-1");
    
        lcd.setCursor(0,0);
   		lcd.print("   Code:     :) ");
    	lcd.setCursor(0,1);
  		lcd.print(" 8 4 -2 -1  :'> ");
  		lcd.setBacklight(1);
    
    setGlobalArrayToCurrentRawInput();
    printGlobalArrayRawInput();
    
     if(gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==0&&gl_arrayRawInput[0]==0){
       setSevenSegmentOutput(0);
     } else if(gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==1&&gl_arrayRawInput[0]==1){
       setSevenSegmentOutput(1); 
     } else if(gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==1&&gl_arrayRawInput[0]==0){
       setSevenSegmentOutput(2);  
  	 } else if(gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==0&&gl_arrayRawInput[0]==1){
       setSevenSegmentOutput(3);  
     } else if(gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==0&&gl_arrayRawInput[0]==0){
       setSevenSegmentOutput(4);
     } else if(gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==1&&gl_arrayRawInput[0]==1){
       setSevenSegmentOutput(5);
     } else if(gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==1&&gl_arrayRawInput[0]==0){
       setSevenSegmentOutput(6);
     } else if(gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==0&&gl_arrayRawInput[0]==1){
       setSevenSegmentOutput(7);
     } else if(gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==0&&gl_arrayRawInput[0]==0){
       setSevenSegmentOutput(8);
     } else if(gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==1&&gl_arrayRawInput[0]==1){
       setSevenSegmentOutput(9);
     } else {
       setSevenSegmentOutput(0);
     }
    
    sw1 = digitalRead(switch1);
    sw2 = digitalRead(switch2);
    sw3 = digitalRead(switch3);
    sw4 = digitalRead(switch4);
  }

  while (sw1 == 0 && sw2 == 0 && sw3 == 1 && sw4 == 0) {
    
    Serial.println("   2 4 2 1");
    	lcd.setCursor(0,0);
       	lcd.print("   Code:     :) ");
    	lcd.setCursor(0,1);
  		lcd.print("  2 4 2 1  :'>  ");
  		lcd.setBacklight(1);
   
    setGlobalArrayToCurrentRawInput();
    printGlobalArrayRawInput();
    
     if(gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==0&&gl_arrayRawInput[0]==0){
       setSevenSegmentOutput(0);
     } else if(gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==0&&gl_arrayRawInput[0]==1){
       setSevenSegmentOutput(1); 
     } else if((gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==1&&gl_arrayRawInput[0]==0)||(gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==0&&gl_arrayRawInput[0]==0)){
       setSevenSegmentOutput(2); 
     } else if((gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==1&&gl_arrayRawInput[0]==1)||(gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==0&&gl_arrayRawInput[0]==1)){
       setSevenSegmentOutput(3);
     } else if((gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==0&&gl_arrayRawInput[0]==0)||(gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==1&&gl_arrayRawInput[0]==0)){
       setSevenSegmentOutput(4);
     } else if((gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==0&&gl_arrayRawInput[0]==1)||(gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==1&&gl_arrayRawInput[0]==1)){
       setSevenSegmentOutput(5);
     } else if((gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==0&&gl_arrayRawInput[0]==0)||(gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==1&&gl_arrayRawInput[0]==0)){
       setSevenSegmentOutput(6);
     } else if((gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==0&&gl_arrayRawInput[0]==1)||(gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==1&&gl_arrayRawInput[0]==1)){
       setSevenSegmentOutput(7);
     } else if(gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==1&&gl_arrayRawInput[0]==0){
       setSevenSegmentOutput(8);
     } else if(gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==1&&gl_arrayRawInput[0]==1){
       setSevenSegmentOutput(9);
       
  	 }   
    sw1 = digitalRead(switch1);
    sw2 = digitalRead(switch2);
    sw3 = digitalRead(switch3);
    sw4 = digitalRead(switch4);

  }

  while (sw1 == 0 && sw2 == 1 && sw3 == 0 && sw4 == 0) {
    
    Serial.println("  5 2 1 1");
    	lcd.setCursor(0,0);
    	lcd.print("   Code:     :) ");
    	lcd.setCursor(0,1);
  		lcd.print("  5 2 1 1  :'>  ");
  		lcd.setBacklight(1);
    
    setGlobalArrayToCurrentRawInput();
    printGlobalArrayRawInput();
   
      if(gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==0&&gl_arrayRawInput[0]==0){
       setSevenSegmentOutput(0);
      } else if((gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==0&gl_arrayRawInput[0]==1)||(gl_arrayRawInput[3]==0&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==1&&gl_arrayRawInput[0]==0)){
       setSevenSegmentOutput(1);
      } else if((gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==1&gl_arrayRawInput[0]==1)||(gl_arrayRawInput[3]==0&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==0&&gl_arrayRawInput[0]==0)){
       setSevenSegmentOutput(2);
      } else if((gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==0&gl_arrayRawInput[0]==1)||(gl_arrayRawInput[3]==0&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==1&&gl_arrayRawInput[0]==0)){
       setSevenSegmentOutput(3);
      } else if(gl_arrayRawInput[3]==0&&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==1&gl_arrayRawInput[0]==1){
       setSevenSegmentOutput(4);
      } else if(gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==0&gl_arrayRawInput[0]==0){
       setSevenSegmentOutput(5);
      } else if((gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==0&gl_arrayRawInput[0]==1)||(gl_arrayRawInput[3]==1&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==1&&gl_arrayRawInput[0]==0)){
       setSevenSegmentOutput(6);
      } else if((gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==0&&gl_arrayRawInput[1]==1&gl_arrayRawInput[0]==1)||(gl_arrayRawInput[3]==1&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==0&&gl_arrayRawInput[0]==0)){
       setSevenSegmentOutput(7);
      } else if((gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==0&gl_arrayRawInput[0]==1)||(gl_arrayRawInput[3]==1&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==1&&gl_arrayRawInput[0]==0)){
       setSevenSegmentOutput(8);
      } else if(gl_arrayRawInput[3]==1&&gl_arrayRawInput[2]==1&&gl_arrayRawInput[1]==1&gl_arrayRawInput[0]==1){
       setSevenSegmentOutput(9);
      }
    sw1 = digitalRead(switch1);
    sw2 = digitalRead(switch2);
    sw3 = digitalRead(switch3);
    sw4 = digitalRead(switch4);
  }

}

void setGlobalArrayToCurrentRawInput() {
  gl_arrayRawInput[3] = digitalRead(input4);
  gl_arrayRawInput[2] = digitalRead(input3);
  gl_arrayRawInput[1] = digitalRead(input2);
  gl_arrayRawInput[0] = digitalRead(input1);

}

void printGlobalArrayRawInput() {
  Serial.print(gl_arrayRawInput[3]);
  Serial.print(gl_arrayRawInput[2]);
  Serial.print(gl_arrayRawInput[1]);
  Serial.print(gl_arrayRawInput[0]);
  
	
}


void setSevenSegmentOutput(int number){
  switch(number){
   case 0:
    digitalWrite(output1, 1); //a
  	digitalWrite(output2, 1); //b
  	digitalWrite(output3, 1); //c
  	digitalWrite(output4, 1); //d
    digitalWrite(output5, 1); //e
    digitalWrite(output6, 1); //f
    digitalWrite(output7, 0); //g
   break;
   case 1:
    digitalWrite(output1, 0);
  	digitalWrite(output2, 1);
  	digitalWrite(output3, 1);
  	digitalWrite(output4, 0);
    digitalWrite(output5, 0);
    digitalWrite(output6, 0);
    digitalWrite(output7, 0);
   break;
   case 2:
    digitalWrite(output1, 1);
  	digitalWrite(output2, 1);
  	digitalWrite(output3, 0);
  	digitalWrite(output4, 1);
    digitalWrite(output5, 1);
    digitalWrite(output6, 0);
    digitalWrite(output7, 1);
   break;
   case 3:
    digitalWrite(output1, 1);
  	digitalWrite(output2, 1);
  	digitalWrite(output3, 1);
  	digitalWrite(output4, 1);
    digitalWrite(output5, 0);
    digitalWrite(output6, 0);
    digitalWrite(output7, 1);
   break;
   case 4:
    digitalWrite(output1, 0);
  	digitalWrite(output2, 1);
  	digitalWrite(output3, 1);
  	digitalWrite(output4, 0);
    digitalWrite(output5, 0);
    digitalWrite(output6, 1);
    digitalWrite(output7, 1);
   break;
   case 5:
    digitalWrite(output1, 1);
  	digitalWrite(output2, 0);
  	digitalWrite(output3, 1);
  	digitalWrite(output4, 1);
    digitalWrite(output5, 0);
    digitalWrite(output6, 1);
    digitalWrite(output7, 1);
   break;
   case 6:
    digitalWrite(output1, 1);
  	digitalWrite(output2, 0);
  	digitalWrite(output3, 1);
  	digitalWrite(output4, 1);
    digitalWrite(output5, 1);
    digitalWrite(output6, 1);
    digitalWrite(output7, 1);
   break;
   case 7:
    digitalWrite(output1, 1);
  	digitalWrite(output2, 1);
  	digitalWrite(output3, 1);
  	digitalWrite(output4, 0);
    digitalWrite(output5, 0);
    digitalWrite(output6, 0);
    digitalWrite(output7, 0);
   break;
   case 8:
    digitalWrite(output1, 1);
  	digitalWrite(output2, 1);
  	digitalWrite(output3, 1);
  	digitalWrite(output4, 1);
    digitalWrite(output5, 1);
    digitalWrite(output6, 1);
    digitalWrite(output7, 1);
   break;
   case 9:
    digitalWrite(output1, 1);
  	digitalWrite(output2, 1);
  	digitalWrite(output3, 1);
  	digitalWrite(output4, 1);
    digitalWrite(output5, 0);
    digitalWrite(output6, 1);
    digitalWrite(output7, 1);
   break;
   default:
    digitalWrite(output1, 1);
  	digitalWrite(output2, 1);
  	digitalWrite(output3, 1);
  	digitalWrite(output4, 1);
    digitalWrite(output5, 1);
    digitalWrite(output6, 1); 
    digitalWrite(output7, 0); 
    break;
    
  }
}