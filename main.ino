bool doorClosed = true;

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;  

void setup(){
    Serial.begin(9600);
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object

    pinMode(8, OUTPUT);    //red light
    pinMode(7, OUTPUT);    //green light
    digitalWrite(7, HIGH); 
    digitalWrite(8,LOW);
    Serial.begin(9600);
    Serial.println("Welcome to the automated security system!");
    Serial.println("The door is locked!\n");

}

void loop(){

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
            digitalWrite(7,HIGH);
            digitalWrite(8,LOW);
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
            digitalWrite(7,LOW);
            digitalWrite(8,HIGH);
            doorClosed=false;     
        }   

    }
}