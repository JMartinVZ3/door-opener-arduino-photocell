bool doorClosed = true;

#include <Servo.h>

#define BLUE 3
#define GREEN 5
#define RED 6

Servo myservo;  // create servo object to control a servo

int pos = 0;  

void setup(){
    Serial.begin(9600);
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object

    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    Serial.begin(9600);
    Serial.println("Welcome to the automated security system!");
    Serial.println("The door is locked!\n");

}

int redValue;
int greenValue;
int blueValue;

void loop(){

    #define delayTime 10

    redValue = 255;
    greenValue = 0;
    blueValue = 0;

    float sensorVal = analogRead(0)/1023.0*5;

    Serial.println(sensorVal);

    if( sensorVal < 2.5 ){

        if(!doorClosed) {

            Serial.println("\nIt's getting dark. Securing door...");
            for (pos; pos <= 180; pos += 10) {
                myservo.write(pos);  
                delay(1);           
            }
            Serial.println("The door is secured!");  
            redValue = 255;
            greenValue = 0;    
            analogWrite(GREEN, greenValue);
            analogWrite(RED, redValue);
            doorClosed=true;    

        }      

    }else{

        if(doorClosed) {
          
            Serial.println("\nIt's a beautiful day! Opening door...");
            for (pos; pos >= 0; pos -= 10) { 
                myservo.write(pos);         
                delay(1);                  
            }
            Serial.println("The door is now open!");      
            redValue = 0;
            greenValue = 255;
            analogWrite(GREEN, greenValue);
            analogWrite(RED, redValue);
            doorClosed=false;     
        }   

    }
}