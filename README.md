# 4-bit-Binary-Codes-to-7-Segment-Display-with-Arduino-
4-bit Binary Codes include 5211, 84-2-1, and 2421. 

<img width="960" alt="image" src="https://github.com/Jeydori/4-bit-Binary-Codes-to-7-Segment-Display-with-Arduino-/assets/92672461/17c2990c-13fc-4eee-989b-bb22e71fc104">


In the realm of electronics and digital displays, the fascinating world of 4-bit binary codes converges with the visual appeal of 7-segment displays through the magic of Arduino and LCD technology.

Firstly, let's explore the 4-bit binary codes: 

1. The 8-4-(-2)-(-1) code (84-2-1): This ingenious coding scheme utilizes four bits to represent decimal numbers. Each bit is weighted, with values of 8, 4, -2, and -1, respectively. By manipulating the state (0 or 1) of these bits, different decimal values can be represented but it reserves the 4-bit pattern "1100" for invalid characters.

2. The 5-2-1-1 code (5211): Also employing four bits, this code is primarily used for binary-coded decimal (BCD) arithmetic. Similar to the 8-4-2-1 code, it represents decimal numbers.

3. The 2-4-2-1 code (2421): Yet another four-bit binary code used for BCD representation, this scheme offers efficient coding with weights of 2, 4, 2, and 1 for each respective bit.

Now, let's bring these codes to life using Arduino with 7-segment functionality:

Using Arduino's capabilities, one can interface the 7-segment display to the microcontroller, and through programming, translate the 4-bit binary codes into eye-catching numerical representations.

Through manipulation of the display pins, Arduino transforms the binary data into the appropriate electrical signals, seamlessly illuminating the desired segments of the 7-segment display. This mesmerizing interaction of code and hardware brings forth an aesthetically pleasing numerical showcase, captivating observers with its seamless transition from binary information to crisp, legible numbers.

This fusion of technology, and mathematics showcases the power of electronics and programming, as Arduino and the 7-Segment Display harmoniously collaborate to create an engaging and visually striking experience. The ability to showcase numerical data with precision and charm is a testament to the creative possibilities that arise when these cutting-edge technologies converge.

Needed Components:
  1. 1x Arduino Uno

<img width="161" alt="image" src="https://github.com/Jeydori/4-bit-Binary-Codes-to-7-Segment-Display-with-Arduino-/assets/92672461/6ae73b4e-85f8-44d2-8592-8de5a06ffec4">

  3. 1x LCD Display I2C (Optional)
    
<img width="238" alt="image" src="https://github.com/Jeydori/4-bit-Binary-Codes-to-7-Segment-Display-with-Arduino-/assets/92672461/735b8570-5db6-4ec0-b861-3d2b1a8e99db">

  4. 1x 7-Segment Display (Cathode)

<img width="114" alt="image" src="https://github.com/Jeydori/4-bit-Binary-Codes-to-7-Segment-Display-with-Arduino-/assets/92672461/233e5d7c-19d9-4f3a-955f-a472d448d98d">
     
  5. 2x 4-way Dip Switch (SPST)

<img width="188" alt="image" src="https://github.com/Jeydori/4-bit-Binary-Codes-to-7-Segment-Display-with-Arduino-/assets/92672461/16619786-66f7-4287-bca4-d50e6b7ba0ae">
     
  7. 8x 10k ohm pull-down resistor

<img width="161" alt="image" src="https://github.com/Jeydori/4-bit-Binary-Codes-to-7-Segment-Display-with-Arduino-/assets/92672461/09f07945-a34a-412c-9f7c-da2f03b6a04c">
     
  9. 7x 470 ohm resistor

<img width="157" alt="image" src="https://github.com/Jeydori/4-bit-Binary-Codes-to-7-Segment-Display-with-Arduino-/assets/92672461/0e6960fd-2566-4dee-b816-60f47dfa14a5">
      
  11. solid wires (for actual system)

<img width="218" alt="image" src="https://github.com/Jeydori/4-bit-Binary-Codes-to-7-Segment-Display-with-Arduino-/assets/92672461/68f7bd01-9039-41da-9821-d3b445500375">
      


Majority of this project will revolve in a simulation tool, then next steps will be easier to execute in actual. In this example, we will be using Tinkercad. To simulate the 4-bit Binary Codes to 7-Segment Display using Arduino in Tinkercad, follow these steps:
  1. Search for the above components and then connect to their respective pins in the arduino. Red wires are 5V (Vcc) and Black wires are GND. (Note: all the GND should be in series.)
     <img width="55" alt="image" src="https://github.com/Jeydori/4-bit-Binary-Codes-to-7-Segment-Display-with-Arduino-/assets/92672461/d013b6c9-1ed2-4887-a692-f9e3aa212434">
     <img width="57" alt="image" src="https://github.com/Jeydori/4-bit-Binary-Codes-to-7-Segment-Display-with-Arduino-/assets/92672461/9284aedf-e85a-48a6-8a27-f80322a19ccf">
      <img width="72" alt="image" src="https://github.com/Jeydori/4-bit-Binary-Codes-to-7-Segment-Display-with-Arduino-/assets/92672461/643105d5-8fcb-4020-ba87-d9245633d1a3">
      <img width="194" alt="image" src="https://github.com/Jeydori/4-bit-Binary-Codes-to-7-Segment-Display-with-Arduino-/assets/92672461/c36ab1e9-bd58-482b-a211-bccc10fc6d42">

  2. Declare arrays and variables on pins:

               //7-segment display pins
                #define output7 8 //g
                #define output6 7 //f
                #define output5 6 //e
                #define output4 5 //d
                #define output3 4 //c
                #define output2 3 //b
                #define output1 2 //a
        
               //4-bit binary pins
                #define input4 13 //1000
                #define input3 12 //0100
                #define input2 11 //0010
                #define input1 10 //0001
        
               //binary code switch pins / mode pins
                #define switch4 A3 //display group members (optional)
                #define switch3 A2 //2421
                #define switch2 A1 //5211
                #define switch1 A0 //84-2-1
        
               //array
               int gl_arrayRawInput[4];
            }

     
3. Set variables of pins as output and input in the setup function:
   
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

  4. Create a function for the cases of 7-segment displays:
     
              void setSevenSegmentOutput(int number){switch(number){
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
     
5. Create a function for the array of 4:
   
           void setGlobalArrayToCurrentRawInput() {
            gl_arrayRawInput[3] = digitalRead(input4);
            gl_arrayRawInput[2] = digitalRead(input3);
            gl_arrayRawInput[1] = digitalRead(input2);
            gl_arrayRawInput[0] = digitalRead(input1);
          }

6. On the loop function, this is the code:
   
         //declare a variable for the state of mode switches
            int sw1 = digitalRead(switch1);
            int sw2 = digitalRead(switch2);
            int sw3 = digitalRead(switch3);
            int sw4 = digitalRead(switch4);

          //call the 7-segment case-0 to initialize the 7-segment display to 0
            setSevenSegmentOutput(0);
          
            delay(250);
          
          	//Optional
           //mode: 0001: Nothing
            while (sw1 == 0 && sw2 == 0 && sw3 == 0 && sw4 == 1) {
              //optional
              lcd.setCursor(0,0);
           		lcd.print("Group Members:  ");
             
          
              sw1 = digitalRead(switch1);
              sw2 = digitalRead(switch2);
              sw3 = digitalRead(switch3);
              sw4 = digitalRead(switch4);
              
            }

            //mode: 1000: 84-2-1 code
            while (sw1 == 1 && sw2 == 0 && sw3 == 0 && sw4 == 0) {

              //optional
                lcd.setCursor(0,0);
             		lcd.print("   Code:     :) ");
              	lcd.setCursor(0,1);
            		lcd.print(" 8 4 -2 -1  :'> ");
            		lcd.setBacklight(1);
   
              //call the function you made for the array
              setGlobalArrayToCurrentRawInput();

              //call the function for 7-segment but the case depends on the state of the 4-bit binary input
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

          //mode: 0010: 2421 code
            while (sw1 == 0 && sw2 == 0 && sw3 == 1 && sw4 == 0) {
              
             //optional
              	lcd.setCursor(0,0);
                lcd.print("   Code:     :) ");
              	lcd.setCursor(0,1);
            		lcd.print("  2 4 2 1  :'>  ");
            		lcd.setBacklight(1);

             //call the function you made for the array
              setGlobalArrayToCurrentRawInput();
             
             //call the function for 7-segment but the case depends on the state of the 4-bit binary input 
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

          //mode: 0100: 5211 code
            while (sw1 == 0 && sw2 == 1 && sw3 == 0 && sw4 == 0) {
              
              //optional
              	lcd.setCursor(0,0);
              	lcd.print("   Code:     :) ");
              	lcd.setCursor(0,1);
            		lcd.print("  5 2 1 1  :'>  ");
            		lcd.setBacklight(1);

              //call the function you made for the arrays
              setGlobalArrayToCurrentRawInput();
              
              //call the function for 7-segment but the case depends on the state of the 4-bit binary input 
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
7. End of the coding, test the system if it is working properly, Here is the full sketch of the system:
   https://github.com/Jeydori/4-bit-Binary-Codes-to-7-Segment-Display-with-Arduino-/blob/main/4_bit_binary_codes_to_7_segment_display_with_arduino.ino

After simulating the and checked that the system is working properly, you can now proceed on building it in actual. Upload the code in the arduino then build what we have simulated. Then you are done with this project. Note that if there is power outage, you can add an external voltage source and series the GND to the arduino:).
