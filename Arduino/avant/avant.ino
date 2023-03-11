void setup() {
pinMode(2,INPUT); // start or stop
pinMode(4,INPUT); // fdc
pinMode(3,OUTPUT); // pwm
pinMode(5,OUTPUT); // mav
pinMode(6,OUTPUT); // mar
}


void loop() {
 
int marche = 1 ;
 
  
  
  if (digitalRead(2) == HIGH && marche == 1) {
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    delay(500);
    analogWrite(3,128);// pwm
      while(digitalRead(4) == LOW) {
          
          if (digitalRead(2) == HIGH) {
            analogWrite(3,0);// pwm
            delay(500);
          break;  
        }
    }
    marche = 1 ;
    analogWrite(3,0);// pwm
    delay(500);
    digitalWrite(5,LOW);
  } 
}
