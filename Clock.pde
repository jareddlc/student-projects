/* Binary Clock
 *--------------------------------------------------
 *      - Added Buttons,
 * v.7  - Added getTime function, fixed hour function. Clock auto illuminates each appropriate LED. 11-29-2011
 * v.6  - Added ledTime, printArray, clearArray functions. Binary conversion function now configures array correctly. 11-28-2011
 * v.5  - Added Increase Minute/Hour function, cleaned up some code. 11-28-11 
 * v.4  - Added Binary conversion function, temporary LED toggle switch via COM port. 11-26-2011
 * v.3  - Added basic clock function. 11-23-2011
 * v.2  - (Protoboard)Soldered LEDs to Protoboard. Installed 10 LEDs for minutes and 4 LEDs for hours. No clock function. 11-21-2011
 * v.1  - (Breadboard)Cycled trough an array of 6 LEDs. 11-03-2011
 *
 * Developed By: Jared De La Cruz
 * Project Started 11-03-2011
 *
 *LED Count = 6 for Minutes 
 *LED Count = 4 for Hours
 *
 *ASCII Codes
 *H = 72, h = 104
 *M = 77, m = 109
 *T = 84, t = 116
 *L = 76, l = 108
 *C = 67, c = 99
 *P = 80, p = 112
 *
 *Array[]
 *Mins = {32,16,8,4,2,1}
 *Hours = {8,4,2,1}
 *--------------------------------------------------*/
int tick = 1000, incomingByte, hour, minute, second, arrayCount = 6, buttonCount = 2, buttonState0, buttonState1;
int ledMin[] = {6,7,8,9,10,11}, ledHour[] = {0,1,2,3,4,5}, buttonPin[] = {12,13}, array[6], tarray[6];
static unsigned long lastTick = 0;

void setup()
{
  Serial.begin(9600); 
  //Setting Min Array as OUTPUT
  for(int i=0; i<=arrayCount; i++)
  {
    pinMode(ledMin[i],OUTPUT);
  }
  //Setting Hour Array as OUTPUT
  for(int i=0; i<=arrayCount; i++)
  {
    pinMode(ledHour[i],OUTPUT);
  }
  //Setting Button as INPUT
  for(int i=0;i<buttonCount;i++)
  {
    pinMode(buttonPin[i], INPUT);
  }
  Serial.println("Hello world! Arduino Loaded.");
  Serial.println("Description: set clock time with COM Port.");
  Serial.println("Usage: 'T' = display time, 'H' = Hour, 'M' = Minute");
  Serial.println("Usage: 'L' = Turn on LED, 'l' = Turn off LED");
  Serial.println("Usage: 'P' = Print array, 'C' = Clear array");

}

void loop()
{
  //Counts each second since start of arduino.
  if(millis() - lastTick >= tick)
  {
    lastTick = millis();
    second++;
  }

  //If 60 secs, increase minute and resets second.
  if(second >= 60)
  {
    minute++;
    second = 0;
  }
  
  //If 60 minute, increase hour and resets minute.
  if(minute >= 60) 
  {
  hour++;
  minute = 0;
  }
  
  //If 24 hour, reset hour and resets minute.
  if(hour >= 24) 
  {
  hour = 0;
  minute = 0;
  }
  //Comment-Out GetTime to use some of the COM Port functions. 
  getTime();
  
  //Reading Button
  buttonState0 = digitalRead(buttonPin[0]);
  buttonState1 = digitalRead(buttonPin[1]);
  if(buttonState0 == HIGH) 
  {    
    // turn LED on:    
    Serial.println("Button 0 pressed!");
    minute++;
  }
  
  if(buttonState1 == HIGH)
  {
    Serial.println("Button 1 pressed!");
    hour++;
  }

  
  //If serial input is greater than 0
  if(Serial.available() > 0) 
  {
    // read the incoming byte:
    incomingByte = Serial.read();
    
    // print incoming byte:
    Serial.print("Arduino received: ");
    Serial.print(" Decimnal = ");
    Serial.print(incomingByte, DEC);
    Serial.print(" Byte = ");
    Serial.print(incomingByte, BYTE);
    Serial.print(" Binary = ");
    Serial.println(incomingByte-48,BIN);

    switch(incomingByte)
    {
      case 'H':
      case 'h':
        setHour();
        incomingByte = 0;
        break;
      case 'M':
      case 'm':
        setMin();
        incomingByte = 0;
        break;
      case 'T':
      case 't':
        printTime();
        incomingByte = 0;
        break;
      case 'C':
      case 'c':
        clearArray();
        break;
      case 'P':
      case 'p':
        printArray();
        break;
      case 'L':
        ledON();
        break;
      case 'l':
        ledOFF();
        break;
      default:
         Serial.println("Converting input to binary.");
        //clearArray();
        //toBinary(incomingByte);
        //hourTime();
        //minTime();
        printArray();
        incomingByte = 0; 
    }
  }
}

//Prints Time in H:M:S.
void printTime()
{
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.print(second);
  Serial.println("");
}

//Increases minutes.
void setMin()
{
  incomingByte = 0;
  Serial.println("Minutes selected.");
  Serial.println("Increase minutes by: ");
  while(incomingByte == 0)
  {
    if(Serial.available() > 0) 
    {
      // read the incoming byte:
      incomingByte = Serial.read()- '0';
      Serial.print("incomingByte = ");
      Serial.println(incomingByte);
      Serial.print("Previous minutes = ");
      Serial.println(minute);
      minute = minute + incomingByte;
      Serial.print("Current minutes = ");
      Serial.println(minute);
    }
  }
  Serial.print("Minute increased by: ");
  Serial.println(incomingByte);
}

//Increases hours.
void setHour()
{
  incomingByte = 0;
  Serial.println("Hours selected.");
  Serial.println("Increase hours by: ");
  while(incomingByte == 0)
  {
    if(Serial.available() > 0) 
    {
      // read the incoming byte:
      incomingByte = Serial.read()- '0';
      Serial.print("incomingByte = ");
      Serial.println(incomingByte);
      Serial.print("Previous hour = ");
      Serial.println(hour);
      hour = hour + incomingByte;
      Serial.print("Current hour = ");
      Serial.println(hour);
    }
  }
  Serial.print("Hour increased by: ");
  Serial.println(incomingByte);
}

//Cycles trough array and toggles LEDs.
void minTime()
{
  for(int i=0; i<arrayCount; i++)
  {
    if(array[i] == 1)
    {
      digitalWrite(ledMin[i],HIGH);
    }
    else
    {
      digitalWrite(ledMin[i],LOW);
    }
  }
}

void hourTime()
{
  for(int i=0; i<arrayCount; i++)
  {
    if(array[i] == 1)
    {
      digitalWrite(ledHour[i],HIGH);
    }
    else
    {
      digitalWrite(ledHour[i],LOW);
    }
  }
}

void getTime()
{
  clearArray();
  toBinary(minute+48);
  minTime();
  
  clearArray();
  toBinary(hour+48);
  hourTime();
}

//Converts incomingByte into binary.
void toBinary(int n)
{
  int temp, x=0, j=0;
  //Uncomment for debugging.
  //Serial.print("n before = ");
  //Serial.print(n);
  n = n-48;//Fixes ascii table characters.
  //Serial.print("n after = ");
  //Serial.println(n);  
  while(n>=1)
  {
    temp = n%2;
    n = n/2;
    array[x] = temp;
    tarray[x] = temp;
    x++;
  }
  
  //Reverses order of array to binary.
  for(int i=arrayCount-1; i>=0; i--)
  {
    array[i] = tarray[j];
    j++;
  } 
}

//Prints array of converted incomingByte. 
void printArray()
{
  Serial.print("Input Array = ");
  for(int i=0; i<arrayCount; i++)
  {
    Serial.print(array[i]);
  }
  Serial.println("");
}
//Zero-outs array.
void clearArray()
{
  //Uncomment for debugging.
  //Serial.print("Cleared Array = ");
  for(int i=0; i<arrayCount; i++)
  {
    array[i] = 0;
    tarray[i] = 0;
    //Serial.print(array[i]);
  }
  //Serial.println("");
}

//Turns on all LEDs.
void ledON()
{
   for(int i=0; i<arrayCount; i++)
   {
     digitalWrite(ledMin[i],HIGH);
   }
   for(int i=0; i<arrayCount; i++)
   {
     digitalWrite(ledHour[i],HIGH);
   }
}

//Turns off all LEDs.
void ledOFF()
{
  for(int i=0; i<arrayCount; i++)
   {
     digitalWrite(ledMin[i],LOW);
   }
   for(int i=0; i<arrayCount; i++)
   {
     digitalWrite(ledHour[i],LOW);
   }
}
