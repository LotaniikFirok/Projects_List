const int Sen1 = A5;  // Analog input pin that the potentiometer is attached to
const int Sen2 = A4;
const int Sen3 = A3;
const int Sen4 = A2;
const int Sen5 = A0;

int mL1 = 9;
int mL2 = 8;
int mR3 = 13;
int mR4 = 12;
int spdL = 10;
int spdR = 11;

int button = 7;

int senVal1 = 0;        // value read from the pot
int senVal2 = 0;
int senVal3 = 0;
int senVal4 = 0;
int senVal5 = 0;

int outVal1 = 0;        // value output to the PWM (analog out)
int outVal2 = 0;
int outVal3 = 0;
int outVal4 = 0;
int outVal5 = 0;

void setup() {

  // put your setup code here, to run once:
  pinMode(mL1,OUTPUT);
  pinMode(mL2,OUTPUT);
  pinMode(mR3,OUTPUT);  
  pinMode(mR4,OUTPUT);
  
  pinMode(spdL, OUTPUT);
  pinMode(spdR, OUTPUT);

  pinMode(button,INPUT_PULLUP);

  Serial.begin(9600);
}

void TurnMotorStraight(){
  digitalWrite(mL1,HIGH);
  digitalWrite(mL2,LOW);
  digitalWrite(mR3,HIGH);
  digitalWrite(mR4,LOW);
  analogWrite(spdL,130);
  analogWrite(spdR,130);
}

void TurnMotorHLeft(){
  digitalWrite(mL1,HIGH);
  digitalWrite(mL2,LOW);
  digitalWrite(mR3,HIGH);
  digitalWrite(mR4,LOW);
  analogWrite(spdL,0);
  analogWrite(spdR,120);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                      
void TurnMotorHRight(){
  digitalWrite(mL1,HIGH);
  digitalWrite(mL2,LOW);
  digitalWrite(mR3,HIGH);
  digitalWrite(mR4,LOW);
  analogWrite(spdL,120);
  analogWrite(spdR,0);
}

void TurnMotorSLeft(){
  digitalWrite(mL1,HIGH);
  digitalWrite(mL2,LOW);
  digitalWrite(mR3,HIGH);
  digitalWrite(mR4,LOW);
  analogWrite(spdL,0);
  analogWrite(spdR,100);
}

void TurnMotorSRight(){
  digitalWrite(mL1,HIGH);
  digitalWrite(mL2,LOW);
  digitalWrite(mR3,HIGH);
  digitalWrite(mR4,LOW);
  analogWrite(spdL,100);
  analogWrite(spdR,0);
}
void TurnMotorReverse(){
  digitalWrite(mL1,LOW);
  digitalWrite(mL2,HIGH);
  digitalWrite(mR3,LOW);
  digitalWrite(mR4,HIGH);
  analogWrite(spdL,85);
  analogWrite(spdR,85);
}

void TurnMotorOFF(){
  digitalWrite(mL1,LOW);
  digitalWrite(mL2,LOW);
  digitalWrite(mR3,LOW);
  digitalWrite(mR4,LOW);
  analogWrite(spdL,0);
  analogWrite(spdR,0);
}

void checkSensor(){
  // read the analog in value:
  senVal1 = analogRead(Sen1);
  senVal2 = analogRead(Sen2);
  senVal3 = analogRead(Sen3);
  senVal4 = analogRead(Sen4);
  senVal5 = analogRead(Sen5);
}

void sensorSerial(){
  Serial.print("One = ");
  Serial.print(senVal1);
  Serial.print("\tTwo = ");
  Serial.print(senVal2);
  Serial.print("\tThree = ");
  Serial.print(senVal3);
  Serial.print("\tFour = ");
  Serial.print(senVal4);
  Serial.print("\tFive = ");
  Serial.print(senVal5); 
  Serial.print("\n");
  
  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}

void loop() {
  // put your main code here, to run repeatedly:
    checkSensor();

    while (digitalRead(button)!= true){
      checkSensor();
      sensorSerial();
      
      if  (senVal5 >= 910){
        TurnMotorStraight();
      } 
      else if ((senVal2 > 920) && (senVal1 < 920)){
        TurnMotorSLeft();
      }
      else if ((senVal3 > 905) && (senVal4 < 910)){
        TurnMotorSRight();
      }
      else if ((senVal1 > 920) && (senVal4 < 920)){
        TurnMotorHLeft();
      }
      else if ((senVal4 > 920) && (senVal1 < 920)){
        TurnMotorHRight();
      }  
      else if (((senVal2 >= 920) && (senVal1 >= 920) && (senVal3 >= 905) && (senVal5 >= 910)) || ((senVal4 >= 910) && (senVal2 >= 920) && (senVal3 >= 905) && (senVal5 >= 910))){
        delay(400);
      }


      /*
      else if ((senVal2 <= 920) && (senVal1 <= 920) && (senVal3 <= 905) && (senVal4 <= 910)&& (senVal5 <= 910)){
        delay(750);
        checkSensor();
        if ((senVal2 <= 920) && (senVal1 <= 920) && (senVal3 <= 905) && (senVal4 <= 910)&& (senVal5 <= 910)){
          TurnMotorReverse();
          checkSensor();
        
        }
      
      }
      */
      }
     TurnMotorOFF();
      
    }

    
