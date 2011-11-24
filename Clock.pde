/* Binary Clock
 *--------------------------------------------------
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
 *--------------------------------------------------*/

const int low = 2, high = 11, H = 72, h = 104, M = 77, m = 109, T = 84, t = 116;
int timer = 60, hour, minute, second, incomingByte = 0;
unsigned long time;
static unsigned long lastTick = 0;

void setup()
{
  Serial.begin(9600); 
  // sets the digital pin as output
  for (int ledPin = low; ledPin <= high; ledPin++)
  {
    pinMode(ledPin, OUTPUT); 
  }    
  Serial.println("Hello world! Arduino Loaded.");
  Serial.println("Description: set clock time with COM Port.");
  Serial.println("Usage: 'T' = display time, 'H' = Hour, 'M' = Minute");
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

  //If serial input is greater than 0
  if(Serial.available() > 0) 
  {
    // read the incoming byte:
    incomingByte = Serial.read();
    //Serial.flush();
    
    // print incoming byte:
    Serial.print("Arduino received: ");
    Serial.print(incomingByte, DEC);
    Serial.print(", ");
    Serial.print(incomingByte, BYTE);
    Serial.println("");
    
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
  
  //Checking for invalid inputs
   if ((incomingByte != H) && (incomingByte != h) && (incomingByte != M) && (incomingByte != m) && (incomingByte == T) && (incomingByte == t) && (incomingByte !=0))
  {
    Serial.print("Command not recognized.\n");
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

