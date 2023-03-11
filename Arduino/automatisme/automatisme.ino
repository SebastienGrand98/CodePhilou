void setup() {
pinMode(2,INPUT); // start or stop
pinMode(4,INPUT); // fdc
pinMode(3,OUTPUT); // pwm
pinMode(5,OUTPUT); // mav
pinMode(6,OUTPUT); // mar
}


void loop() {
 
int marche = 0;

while(marche == 0) { 
  if (digitalRead(2) == HIGH) {
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    delay(500);
    analogWrite(3,80);// pwm
    delay(1000);
      while(digitalRead(4) == LOW) {// fdc
          if(digitalRead(2) == HIGH) {// start or stop
            break;     
        } 
        marche = 1;
        //delay(500); 
    }
    analogWrite(3,0);// pwm
    digitalWrite(6,LOW);
  }
 }
delay(1000); 
while(marche == 1){   
  if (digitalRead(2) == HIGH) {
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    delay(500);
    analogWrite(3,80);// pwm
    delay(1000);
      while(digitalRead(4) == LOW) {//fdc
          if(digitalRead(2) == HIGH) {//start or stop   
           break;   
        }
        marche = 0;
        //delay(500);
    }
    analogWrite(3,0);// pwm
    digitalWrite(5,LOW);
  }
 }
delay(1000); 
}
