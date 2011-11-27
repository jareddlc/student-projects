/* Binary Clock
 *--------------------------------------------------
 * v.4 - Added Binary conversion function, Temporary LED toggle switch via COM port. 11-26-2011
 * v.3 - Added basic clock function. 11-23-2011
 * v.2 - Binary Clock connected. 10 LED's Blink. No clock function. 11-21-2011
 * v.1 - Row of 6 LED's Blink. 11-03-2011
 * Developed By: Jared De La Cruz
 * Project Started 11-03-2011
 *
 *LED Count = 6  
 *41 for double cycle
 *83 for single cycle
 *166 for triple cycle
 *
 *LED Count = 10
 *60 for single cycle
 *
 *ASCII Codes
 *H = 72, h = 104
 *M = 77, m = 109
 *T = 84, t = 116
 *L = 76, l = 108
 *
 *Array[]
 *Mins = {1,2,4,8,16,32}
 *Hours = {1,2,4,8}
 *--------------------------------------------------*/
int timer = 60, incomingByte, hour, minute, second, arrayCount = 6, pinMinCount = 6, pinHourCount = 4, H = 72, h = 104, M = 77, m = 109, T = 84, t = 116, L = 76, l = 108;
int ledMin[] = {11,10,9,8,7,6}, ledHour[] = {5,4,3,2}, array[6];
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
  Serial.println("Temp Usage: 'L' = Turn on LED, 'l' = Turn off LED");
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
  if (minute >=60) 
  {
  hour++;
  minute = 0;
  }
  
  //If 24 hour, reset hour and resets minute.
  if (minute >=24) 
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
    Serial.println(incomingByte);
    Serial.print(incomingByte, DEC);
    Serial.print(", ");
    Serial.print(incomingByte, BYTE);
    Serial.print(" | ");
    Serial.println(incomingByte,BIN);
    
  }
  
  if((incomingByte == H) || (incomingByte == h))
  {
    Serial.print("Hours selected\n");
    incomingByte = 0;
  }
  
  if((incomingByte == M) || (incomingByte == m))
  {
    Serial.print("Minutes selected\n");
    incomingByte = 0;
  }
  
  if((incomingByte == T) || (incomingByte == t))
  {
    printTime();
    incomingByte = 0;
  }
  
  if(incomingByte == L)
  {
    ledON();
  }
  
  if(incomingByte == l)
  {
    ledOFF();
  }
  
  //Checking for invalid inputs
  if((incomingByte != H) && (incomingByte != h) && (incomingByte != M) && (incomingByte != m) && (incomingByte != T) && (incomingByte != t) && (incomingByte != L) && (incomingByte != l) && (incomingByte !=0))
  {
    Serial.print("Command not recognized.\n");
    toBinary(incomingByte);
    incomingByte = 0;
  }
  
}

void printTime()
{
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.print(second);
  Serial.println("");
}

void selMin()
{
  
}

void selHour()
{
  
}

void ledON()
{
   for(int i=0; i<pinMinCount; i++)
   {
     digitalWrite(ledMin[i],HIGH);
   }
}

void ledOFF()
{
  for(int i=0; i<pinMinCount; i++)
   {
     digitalWrite(ledMin[i],LOW);
   }
}

void toBinary(int n)
{
  int temp, i = 0;
  n = n-48;
  while(n>=1)
  {
    temp = n%2;
    n = n/2;
    array[i] = temp;
    i++;
  }
  
  for(int i=0; i<arrayCount; i++)
  {
    Serial.print(array[i]);
  }
}

void clearArray()
{
   for(int i=0; i<arrayCount; i++)
  {
    array[i] = 0;
  } 
}





/***********OLD********************
  /*
  for (int ledPin = low; ledPin<=high; ledPin++)
  {
     digitalWrite(ledPin,HIGH);
     delay(timer);
     digitalWrite(ledPin,LOW);
     delay(timer);
  }
  seconds = seconds + 1;
  Serial.println(seconds);
  for (int ledPin = high-1; ledPin>=low+1; ledPin--)
  {
     digitalWrite(ledPin,HIGH);
     delay(timer);
     digitalWrite(ledPin,LOW);
     delay(timer);
  }*/
  
  //digitalWrite(low,HIGH);
  /*
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) 
  {
  analogWrite(high, fadeValue);          
  delay(21.25);                            
  }
  
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5)
  {
  analogWrite(high, fadeValue);         
  delay(21.25); 
  }
  */

