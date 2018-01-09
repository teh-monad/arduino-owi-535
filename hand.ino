#Set GPIO pins
int M1_Left = 2; 
int M1_Right = 3; 
int M2_Up = 4; 
int M2_Down = 5; 
int M3_Up = 8; 
int M3_Down = 9; 
int M4_Up = 6; 
int M4_Down = 7; 

char inData[20]; 
char inChar =- 1;
 
byte index = 0; 

void setup()
{
  pinMode(M1_Left, OUTPUT);
  pinMode(M1_Right , OUTPUT);
  pinMode(M2_Up, OUTPUT);
  pinMode(M2_Down , OUTPUT);
  pinMode(M3_Up, OUTPUT);
  pinMode(M3_Down , OUTPUT);
  pinMode(M4_Up, OUTPUT);
  pinMode(M4_Down , OUTPUT);
  Serial.begin(9600); //9600 or higher;
  while (! Serial);
  Serial.println("Set moves.");
}
#The 'listen' function for COM4, I/O(RX TX) port;
char Comp(char* This) {
    while (Serial.available() > 0) 
                                   
    {
        if(index < 19) 
        {
            inChar = Serial.read();
            inData[index] = inChar;
            index++;
            inData[index] = '\0';
        }
    }

    if (strcmp(inData,This)  == 0) {
        for (int i=0;i<19;i++) {
            inData[i]=0;
        }
        index = 0;
        return(0);
    }
    else {
        return(1);
    }
}

void ROTATE(int direction, int degres)
{
  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;
  
  if(direction== 1){
    inPin1 = LOW;
    inPin2 = HIGH;
  }
  if(direction== 2){
    inPin1 = HIGH;
    inPin2 = LOW;
  }
  
  digitalWrite(M1_Left, inPin1);
  digitalWrite(M1_Right , inPin2);
  delay(degres);     
}

void CAPTURE(int direction, int degres)
{
  boolean inPin3 = LOW;
  boolean inPin4 = HIGH;
  
  if(direction== 1){
    inPin3 = LOW;
    inPin4 = HIGH;
  }
  if(direction== 2){
    inPin3 = HIGH;
    inPin4 = LOW;
  }

  digitalWrite(M2_Up, inPin3);
  digitalWrite(M2_Down , inPin4);
  delay(degres);
}

void CLASTER(int direction, int degres)
{
  boolean inPin5 = LOW;
  boolean inPin6 = HIGH;
  
  if(direction== 1){
    inPin5 = LOW;
    inPin6 = HIGH;
  }
  if(direction== 2){
    inPin5 = HIGH;
    inPin6 = LOW;
  }

  digitalWrite(M3_Up, inPin5);
  digitalWrite(M3_Down , inPin6);
  delay(degres);
}

void SHOULDER(int direction, int degres)
{
  boolean inPin7 = LOW;
  boolean inPin8 = HIGH;
  
  if(direction== 1){
    inPin7 = LOW;
    inPin8 = HIGH;
  }
  if(direction== 2){
    inPin7 = HIGH;
    inPin8 = LOW;
  }

  digitalWrite(M4_Up, inPin7);
  digitalWrite(M4_Down , inPin8);
  delay(degres);
}
#Back both MOTORS to LOW priority;
void stopRotate(){
    digitalWrite(M1_Left, LOW);
    digitalWrite(M1_Right , LOW);
}

void stopCapture(){
    digitalWrite(M2_Up, LOW);
    digitalWrite(M2_Down , LOW);
}

void stopClaster(){
    digitalWrite(M3_Up, LOW);
    digitalWrite(M3_Down , LOW);
}

void stopShoulder(){
    digitalWrite(M4_Up, LOW);
    digitalWrite(M4_Down , LOW);
}

void loop(){
    if (Comp("m1 left")==0) {
        Serial.write("Motor 1 L -> Online\n");
        ROTATE(1, 3000);
        stopRotate();
        delay(250); //250ms
        Serial.write("Motor 1 L -> Offline\n");
    }
    if (Comp("m1 right")==0) {
        Serial.write("Motor 1 R -> Online\n");
        ROTATE(2, 3000);
        stopRotate();
        delay(250); //250ms
        Serial.write("Motor 1 R -> Offline\n");    
     }
    if (Comp("m2 up")==0) {
        Serial.write("Motor 2 L -> Online\n");
        CAPTURE(1, 3000);
        stopCapture();
        delay(250); //250ms
        Serial.write("Motor 2 L -> Offline\n");
    }
    if (Comp("m2 down")==0) {
        Serial.write("Motor 2 R -> Online\n");
        CAPTURE(2, 3000);
        stopCapture();
        delay(250); //250ms
        Serial.write("Motor 2 R -> Offline\n");    
     }
    if (Comp("m3 up")==0) {
        Serial.write("Motor 3 L -> Online\n");
        CLASTER(1, 1000);
        stopClaster();
        delay(250); //250ms
        Serial.write("Motor 3 L -> Offline\n");
    }
    if (Comp("m3 down")==0) {
        Serial.write("Motor 3 R -> Online\n");
        CLASTER(2, 1000);
        stopClaster();
        delay(250); //250ms
        Serial.write("Motor 3 R -> Offline\n");    
     }
    if (Comp("m4 up")==0) {
        Serial.write("Motor 4 L -> Online\n");
        SHOULDER(1, 3000);
        stopShoulder();
        delay(250); //250ms
        Serial.write("Motor 4 L -> Offline\n");
    }
    if (Comp("m4 down")==0) {
        Serial.write("Motor 4 R -> Online\n");
        SHOULDER(2, 3000);
        stopShoulder();
        delay(250); //250ms
        Serial.write("Motor 4 R -> Offline\n");    
     }
}


