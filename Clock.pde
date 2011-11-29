/* Binary Clock
 *--------------------------------------------------
 * v.6 - Added ledTime, printArray, clearArray functions. Binary conversion function now configures array correctly. 11-28-2011
 * v.5 - Added Increase Minute/Hour function, cleaned up some code. 11-28-11 
 * v.4 - Added Binary conversion function, temporary LED toggle switch via COM port. 11-26-2011
 * v.3 - Added basic clock function. 11-23-2011
 * v.2 - (Protoboard)Soldered LEDs to Protoboard. Installed 10 LEDs for minutes and 4 LEDs for hours. No clock function. 11-21-2011
 * v.1 - (Breadboard)Cycled trough an array of 6 LEDs. 11-03-2011
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
 *
 *Array[]
 *Mins = {32,16,8,4,2,1}
 *Hours = {8,4,2,1}
 *--------------------------------------------------*/
int timer = 60, incomingByte, hour, minute, second, arrayCount = 6, pinMinCount = 6, pinHourCount = 4, H = 72, h = 104, M = 77, m = 109, T = 84, t = 116, L = 76, l = 108, C = 67, c = 99, P = 80, p = 112;
int ledMin[] = {6,7,8,9,10,11}, ledHour[] = {2,3,4,5}, array[6], tarray[6];
unsigned long time;
static unsigned long lastTick = 0;

void setup()
{
  Serial.begin(9600); 
  //Setting Min Array as OUTPUT
  for(int i=0; i<=pinMinCount; i++)
  {
    pinMode(ledMin[i],OUTPUT);
  }
  //Setting Hour Array as OUTPUT
  for(int i=0; i<=pinHourCount; i++)
  {
    pinMode(ledHour[i],OUTPUT);
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
  if(millis() - lastTick >= 1000)
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
  if (minute >= 60) 
  {
  hour++;
  minute = 0;
  }
  
  //If 24 hour, reset hour and resets minute.
  if (hour >= 24) 
  {
  hour = 0;
  minute = 0;
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

    if((incomingByte == H) || (incomingByte == h))
    {
      selHour();
      incomingByte = 0;
    }
    else if((incomingByte == M) || (incomingByte == m))
    {
      selMin();
      incomingByte = 0;
    }
    else if((incomingByte == T) || (incomingByte == t))
    {
      printTime();
      incomingByte = 0;
    }
    else if((incomingByte == C) || (incomingByte == c))
    {
      clearArray();
    }
    else if((incomingByte == P) || (incomingByte == p))
    {
      printArray();
    }
    else if(incomingByte == L)
    {
      ledON();
    }
    else if(incomingByte == l)
    {
      ledOFF();
    }
    else
    {
      Serial.println("Converting input to binary.");
      clearArray();
      toBinary(incomingByte);
      ledTime();
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
void selMin()
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
void selHour()
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

//Turns on all LEDs.
void ledON()
{
   for(int i=0; i<pinMinCount; i++)
   {
     digitalWrite(ledMin[i],HIGH);
   }
   for(int i=0; i<pinHourCount; i++)
   {
     digitalWrite(ledHour[i],HIGH);
   }
}

//Turns off all LEDs.
void ledOFF()
{
  for(int i=0; i<pinMinCount; i++)
   {
     digitalWrite(ledMin[i],LOW);
   }
   for(int i=0; i<pinHourCount; i++)
   {
     digitalWrite(ledHour[i],LOW);
   }
}

//Cycles trough array and toggles LEDs.
void ledTime()
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

//Converts incomingByte into binary.
void toBinary(int n)
{
  int temp, x=0, j=0;
  //Fixes ascii table characters.
  n = n-48;  
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
  Serial.print("Input Array = ");
  for(int i=0; i<arrayCount; i++)
  {
    array[i] = 0;
    tarray[i] = 0;
    Serial.print(array[i]);
  }
  Serial.println("");
}
