// 14221 
int tempPin = 0;
int tempC;
int left;
int right;
int timeLeft = 0;
int updateDelay = 1000;

int binaryOne;
int binaryTwo;
int binaryFour;
int binaryEight;

int maxTemp;
int firstRead = 1;

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

  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(2, INPUT);



  Serial.begin (9600);
}

void loop() {
  
  binaryOne = digitalRead(11);
  binaryTwo = digitalRead(12);
  binaryFour = digitalRead(13);
  binaryEight = digitalRead(2);
  Serial.println();
  Serial.print(binaryOne);
  Serial.print(binaryTwo);
  Serial.print(binaryFour);
  Serial.print(binaryEight);
  Serial.println();
  
  if(timeLeft < 1){
    timeLeft = updateDelay;
    tempC = getTemp();
    if(tempC > maxTemp){
      maxTemp = tempC;
    }
    right = tempC % 10;
    left = tempC / 10;
  }
  else{
    timeLeft += -25;
  }

  if(binaryOne && binaryTwo && binaryFour && binaryEight){

    show(left, right);
  }else{
    int maxLeft = maxTemp / 10;
    int maxRight = maxTemp % 10;
    show(maxLeft, maxRight);
  }



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
  if(firstRead){
    maxTemp = tempC;
    firstRead = 0;
  }
  //Serial.print((byte)tempC);
  //Serial.println(" C");
  return tempC;
}
