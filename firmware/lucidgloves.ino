int sensorValue = 0;
String commandFromPC = "";
int loops = 0;
int maxFingers[5] = {0,0,0,0,0};
int minFingers[5] = {1023,1023,1023,1023};

int calib[5] = {500,500,500,500,500};

void setup() {
  // put your setup code here, to run once:
  for (int b = 0; b < 5; b++)
        minFingers[b] = 1023;
    for (int c = 0; c < 5; c++)
        maxFingers[c] = 0;
  Serial.begin(115200);
  //Serial.begin(9600);
  //Serial.println("Startup Complete" + String(minFingers[4]));
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  //commandFromPC = Serial.readStringUntil('\n');
  delay(16);
  //delay(300);
  //if (commandFromPC == "READ_VALUES")
  //if (commandFromPC.length() > 1)
  {
      int theseFingers[5] = {1023-analogRead(A4), 1023-analogRead(A3), 1023-analogRead(A2), 1023-analogRead(A1), 1023-analogRead(A0)};
      int joyX = analogRead(A5);
      int joyY = analogRead(A6);
      int joyClick = digitalRead(2);

      if (joyClick == HIGH){
        joyClick = 1;
      }
      
      for (int i = 0; i < 5; i++){
        if (loops < 5000){
          if (theseFingers[i] > maxFingers[i])
            maxFingers[i] = theseFingers[i];
          if (theseFingers[i] < minFingers[i])
            minFingers[i] = theseFingers[i];
          loops++;
        }
        if (minFingers[i] != maxFingers[i]){
          calib[i] = (int)((float)(theseFingers[i] - minFingers[i]) / (float)(maxFingers[i] - minFingers[i]) * 1000.0f);
        }
      }
      char stringToPrint[75];
      //             fingers        joystick  buttons  gestures
      sprintf(stringToPrint, "%d&%d&%d&%d&%d&%d&%d&%d&%d&%d&%d&%d&%d\n", 
      calib[0], calib[1], calib[2], calib[3], calib[4], 0, 0, 0, 0, 0, 0, 0, 0);
      Serial.print(stringToPrint);
  }
}
