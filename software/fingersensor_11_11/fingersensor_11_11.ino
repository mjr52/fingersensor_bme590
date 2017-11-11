/* 
  IR Breakbeam sensor demo!
*/
 
#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5

#define SENSORPIN 8

 int count = 0;
 
// variables will change:
int sensorState = 0, lastState=0;         // variable for reading the pushbutton status
 
void setup() {
  // initialize the LED pin as an output:
  //pinMode(LEDPIN, OUTPUT);      
  // initialize the sensor pin as an input:
  pinMode(SENSORPIN, INPUT);   
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
    
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup
  digitalWrite(LED1, LOW); 
  digitalWrite(LED2, LOW); 
  digitalWrite(LED3, LOW); 
  digitalWrite(LED4, LOW); 

  Serial.begin(9600);
}
 
void loop(){
  // read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);
 
  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
  
  //if (sensorState && !lastState) {
    // Want LED state to stay what it is
    //Serial.println("Unbroken");
 // } 
  if (!sensorState && lastState) {
    Serial.println("Broken");
    count = count+1; 
  }

  if (count>15){
    count = 0;
  }
  counttobin(count);
  lastState = sensorState;
}

void counttobin(int num){

  String number = String(num, BIN);
  if (number[0] == 1){
    digitalWrite(LED1, HIGH);
  }
  else {
    digitalWrite(LED1, LOW);
  }
  if (number[1] == 1){
    digitalWrite(LED2, HIGH);
  }
  else {
    digitalWrite(LED2, LOW);
  }
  if (number[2] == 1){
    digitalWrite(LED3, HIGH);
  }
  else {
    digitalWrite(LED3, LOW);
  }
  if (number[3] == 1){
    digitalWrite(LED4, HIGH);
  }
  else {
    digitalWrite(LED4, LOW);
  }

}

  
