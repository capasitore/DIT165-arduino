
#define  ON  1
#define  OFF  0



float tempC;
int tempPin = 0;

void setup(){
    Serial.begin(9600);  
}

void loop() {
    //lights up segment 2 
    //pinMode(2,ON);
    // ex to display Number 1 light up segment 3 and 4
    pinMode(3,ON); 
    pinMode(4,ON); 

    //reads temperature and prints to the serial monitor
    tempC = analogRead(tempPin);
    tempC = (5.0 * tempC * 100.0)/1024.0;
    Serial.print((byte)tempC);
    Serial.println(" C");
    delay(1000);
  
}

