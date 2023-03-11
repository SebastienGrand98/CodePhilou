void setup() {
pinMode(2,INPUT); // start or stop
pinMode(4,INPUT); // fdc
pinMode(3,OUTPUT); // pwm
pinMode(5,OUTPUT); // mav
pinMode(6,OUTPUT); // mar
}


void loop() {
int switchState = LOW ;
int marche = LOW ; 
 
switchState = digitalRead(2);
  if (switchState == HIGH && marche == LOW) {
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    analogWrite(3,255);// pwm
    delay(2000);
      while(digitalRead(4) == LOW) {
        switchState = digitalRead(2);
          if (switchState == HIGH) {
          break;  
        }
    }
    switchState = LOW ;
    marche = HIGH ;
    analogWrite(3,0);// pwm
    digitalWrite(6,LOW);
  }
  if (switchState == HIGH && marche == HIGH) {
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    analogWrite(3,255);// pwm
    delay(2000);
      while(digitalRead(4) == LOW) {
        switchState = digitalRead(2);
          if (switchState == HIGH) {
          break;  
        }
    }
    switchState = LOW ;
    marche = LOW ;
    analogWrite(3,0);// pwm
    digitalWrite(5,LOW);
  } 
}
