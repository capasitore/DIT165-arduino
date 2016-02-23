


int tempPin = 0;
int lastPoll;
int tempC;
int left;
int right;


void setup() {
  pinMode(1, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  Serial.begin (9600);
  int lastPoll = millis();



}

void loop() {
  if((millis() - lastPoll) > 2000){
    tempC = getTemp();
    right = tempC % 10;
    left = tempC / 10;
    lastPoll = millis(); 
  }
  show(left, right);

}


void show(int left, int right){
  if(left == 0){
    showRight();
    getNumber(right);
  } else {
      showRight();
      getNumber(right);
      delay(10);
      showLeft();
      getNumber(left);
      delay(10);
  }
}

void showLeft(){
  digitalWrite(5, LOW);
  digitalWrite(10, HIGH);
}

void showRight(){
  digitalWrite(5, HIGH);
  digitalWrite(10, LOW);

}

void getZero(){
  digitalWrite(1, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}
  
void getOne(){
  digitalWrite(1, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}

void getTwo(){
  digitalWrite(1, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}

void getThree(){
  digitalWrite(1, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}

void getFour(){
  digitalWrite(1, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}

void getFive(){
  digitalWrite(1, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);  
}

void getSix(){
  digitalWrite(1, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  
}

void getSeven(){
  digitalWrite(1, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}

void getEight(){
  digitalWrite(1, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);  
}

void getNine(){
  digitalWrite(1, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);  
}


void getNumber(int num) {
  switch (num) {
    case 0:
      getZero();
      break; 
    case 1:
      getOne();
      break; 
    case 2:
      getTwo();
      break; 
    case 3:
      getThree();
      break; 
    case 4:
      getFour();
      break; 
    case 5:
      getFive();
      break; 
    case 6:
      getSix();
      break; 
    case 7:
      getSeven();
      break; 
    case 8:
      getEight();
      break; 
    case 9:
      getNine();
      break; 
  }
}


int getTemp(){
  int tempC = analogRead(tempPin);
  tempC = (5.0 * tempC * 100.0)/1024.0;
  Serial.print((byte)tempC);
  Serial.println(" C");
  return tempC;
}
  

