/* MIDI Controller
 * Created by: Jared De La Cruz 6/25/2012
 * --------------------------------------
 * v.2 - (Breadboard)7 push buttons, 4 potentiometers. Buttons mapped to specific keys, potentiometers are mapped to generic controllers. 2-27-2013
 * v.1 - (Breadboard)First working demo. 1 Digital Button, 1 Potentiometer (requires external hardware to convert serial into midi). 6-25-2012
 */

// MIDI Messages.          http://www.blitter.com/~russtopia/MIDI/~jglatt/tech/midispec.htm
//                         http://www.electronics.dit.ie/staff/tscarff/Music_technology/midi/midi_messages.htm
// Note On/Off:            message(status on/off, pitch/note, velocity).
// Controller:             message(states, controller #0-127, value).
// Program Change:         message(status, program #0-127).
// Pitch Wheel:            message(status, data 0-6 14-bit value, data 0-6 14-bit value).

const int potPin0 = A0;      // Potentiometer Analog Pin
const int potPin1 = A1;
const int potPin2 = A2;
const int potPin3 = A3;
int potCount = 4;
int potArray[] = {A0,A1,A2,A3};

const int buttonPin2 = 2;    // Button Digital Pin.
const int buttonPin3 = 3;
const int buttonPin4 = 4;
const int buttonPin5 = 5;
const int buttonPin6 = 6;
const int buttonPin7 = 7;
const int buttonPin8 = 8;
int buttonCount = 7;
int buttonArray[] = {2,3,4,5,6,7,8};

int potValue0 = 0;          // Value of potentiometer.
int potValue1 = 0;
int potValue2 = 0;
int potValue3 = 0;

int outValue0 = 0;          // Value of potentiometer (0-127).
int outValue1 = 0;
int outValue2 = 0;
int outValue3 = 0;

const int noteC = 60;      // Notes - middle c = 0x3C
const int noteD = 62;
const int noteE = 64;
const int noteF = 65;
const int noteG = 67;
const int noteA = 69;
const int noteB = 71;

int noteOn = 0x90;         // 0x90 to 0x9F where the low nibble is the MIDI channel.
int noteOff = 0x80;        // 0x80 to 0x8F where the low nibble is the MIDI channel.

int controller0 = 0xb0;    // 0xB0 to 0xBF where the low nibble is the MIDI channel.
int controller1 = 0xb1;    // 0xB0 to 0xBF where the low nibble is the MIDI channel.
int controller2 = 0xb2;    // 0xB0 to 0xBF where the low nibble is the MIDI channel.
int controller3 = 0xb3;    // 0xB0 to 0xBF where the low nibble is the MIDI channel.

int velocityOn = 0x40;     // Velocity set to 64.
int velocityOff = 0x00;    // Velocity set to 0.
int modWheel = 0x01;       // Modwheel Channel

int cbState2 = 0;          // Current Button state.
int cbState3 = 0;
int cbState4 = 0;
int cbState5 = 0;
int cbState6 = 0;
int cbState7 = 0;
int cbState8 = 0;

int lbState2 = 0;          // Last Button state.
int lbState3 = 0;
int lbState4 = 0;
int lbState5 = 0;
int lbState6 = 0;
int lbState7 = 0;
int lbState8 = 0;

int lastNote2 = 0;         // note turned on when you press the switch
int lastNote3 = 0;
int lastNote4 = 0;
int lastNote5 = 0;
int lastNote6 = 0;
int lastNote7 = 0;
int lastNote8 = 0;

int cpState0 = 0;          // Current Pot State
int cpState1 = 0;
int cpState2 = 0;
int cpState3 = 0;

int lpState0 = -1;          // Last Pot State
int lpState1 = -1;
int lpState2 = -1;
int lpState3 = -1;

void setup()
{
  // Set MIDI baud rate.
  Serial.begin(31250);
  // Initialize the buttonPin as an input.
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  pinMode(buttonPin7, INPUT);
  pinMode(buttonPin8, INPUT);
}

void loop()
{
  // Potentiameter range from 0-1023.
  potValue0 = analogRead(potPin0);
  potValue1 = analogRead(potPin1);
  potValue2 = analogRead(potPin2);
  potValue3 = analogRead(potPin3);

  // Convert range to 0-127.
  outValue0 = potValue0/8;
  outValue1 = potValue1/8;
  outValue2 = potValue2/8;
  outValue3 = potValue3/8;

  if(outValue0 != lpState0)
  {
    lpState0 = outValue0;
    sendMod(controller0, modWheel, outValue0);
  }

  if(outValue1 != lpState1)
  {
    lpState1 = outValue1;
    sendMod(controller1, modWheel, outValue1);
  }

  if(outValue2 != lpState2)
  {
    lpState2 = outValue2;
    sendMod(controller2, modWheel, outValue2);
  }

  if(outValue3 != lpState3)
  {
    lpState3 = outValue3;
    sendMod(controller3, modWheel, outValue3);
  }

  //sendMod(controller0, modWheel, outValue0);
  //sendMod(controller1, modWheel, outValue1);
  //sendMod(controller2, modWheel, outValue2);
  //sendMod(controller3, modWheel, outValue3);

  //processButton(buttonPin2, cbState2, lbState2, noteC, lastNote2);

  // Setting current button state.
  cbState2 = digitalRead(buttonPin2);
  cbState3 = digitalRead(buttonPin3);
  cbState4 = digitalRead(buttonPin4);
  cbState5 = digitalRead(buttonPin5);
  cbState6 = digitalRead(buttonPin6);
  cbState7 = digitalRead(buttonPin7);
  cbState8 = digitalRead(buttonPin8);

  // Checking to see if button is pressed.
  if(cbState2 == 1)
  {
    //
    if(lbState2 == 0)
    {
      // Send note.
      sendNote(0x90, noteC, 0x40);
      // Saving last note played, to send off signal later.
      lastNote2 = noteC;
    }
  }
  // The switch has not been pressed.
  else
  {
    // If button is lifted.
    if(lbState2 == 1)
    {
      sendNote(0x90, lastNote2, 0x00);
    }
  }
  // Set last state to current state, should be 0.
  lbState2 = cbState2;

  // Checking to see if button is pressed.
  if(cbState2 == 1)
  {
    //
    if(lbState2 == 0)
    {
      // Send note.
      sendNote(0x90, noteC, 0x40);
      // Saving last note played, to send off signal later.
      lastNote2 = noteC;
    }
  }
  // The switch has not been pressed.
  else
  {
    // If button is lifted.
    if(lbState2 == 1)
    {
      sendNote(0x90, lastNote2, 0x00);
    }
  }
  // Set last state to current state, should be 0.
  lbState2 = cbState2;

  // Checking to see if button is pressed.
  if(cbState3 == 1)
  {
    //
    if(lbState3 == 0)
    {
      // Send note.
      sendNote(0x90, noteD, 0x40);
      // Saving last note played, to send off signal later.
      lastNote3 = noteD;
    }
  }
  // The switch has not been pressed.
  else
  {
    // If button is lifted.
    if(lbState3 == 1)
    {
      sendNote(0x90, lastNote3, 0x00);
    }
  }
  // Set last state to current state, should be 0.
  lbState3 = cbState3;

  // Checking to see if button is pressed.
  if(cbState4 == 1)
  {
    //
    if(lbState4 == 0)
    {
      // Send note.
      sendNote(0x90, noteE, 0x40);
      // Saving last note played, to send off signal later.
      lastNote4 = noteE;
    }
  }
  // The switch has not been pressed.
  else
  {
    // If button is lifted.
    if(lbState4 == 1)
    {
      sendNote(0x90, lastNote4, 0x00);
    }
  }
  // Set last state to current state, should be 0.
  lbState4 = cbState4;

  // Checking to see if button is pressed.
  if(cbState5 == 1)
  {
    //
    if(lbState5 == 0)
    {
      // Send note.
      sendNote(0x90, noteF, 0x40);
      // Saving last note played, to send off signal later.
      lastNote5 = noteF;
    }
  }
  // The switch has not been pressed.
  else
  {
    // If button is lifted.
    if(lbState5 == 1)
    {
      sendNote(0x90, lastNote5, 0x00);
    }
  }
  // Set last state to current state, should be 0.
  lbState5 = cbState5;

  // Checking to see if button is pressed.
  if(cbState6 == 1)
  {
    //
    if(lbState6 == 0)
    {
      // Send note.
      sendNote(0x90, noteG, 0x40);
      // Saving last note played, to send off signal later.
      lastNote6 = noteG;
    }
  }
  // The switch has not been pressed.
  else
  {
    // If button is lifted.
    if(lbState6 == 1)
    {
      sendNote(0x90, lastNote6, 0x00);
    }
  }
  // Set last state to current state, should be 0.
  lbState6 = cbState6;

  // Checking to see if button is pressed.
  if(cbState7 == 1)
  {
    //
    if(lbState7 == 0)
    {
      // Send note.
      sendNote(0x90, noteA, 0x40);
      // Saving last note played, to send off signal later.
      lastNote7 = noteA;
    }
  }
  // The switch has not been pressed.
  else
  {
    // If button is lifted.
    if(lbState7 == 1)
    {
      sendNote(0x90, lastNote7, 0x00);
    }
  }
  // Set last state to current state, should be 0.
  lbState7 = cbState7;

  // Checking to see if button is pressed.
  if(cbState8 == 1)
  {
    //
    if(lbState8 == 0)
    {
      // Send note.
      sendNote(0x90, noteB, 0x40);
      // Saving last note played, to send off signal later.
      lastNote8 = noteB;
    }
  }
  // The switch has not been pressed.
  else
  {
    // If button is lifted.
    if(lbState8 == 1)
    {
      sendNote(0x90, lastNote8, 0x00);
    }
  }
  // Set last state to current state, should be 0.
  lbState8 = cbState8;
}

void sendNote(int message, int pitch, int velocity)
{
  Serial.write(message);
  Serial.write(pitch);
  Serial.write(velocity);
}

void sendMod(int message, int controller, int value)
{
  Serial.write(message);
  Serial.write(controller);
  Serial.write(value);
}

void processButton(int buttonPin, int cbState, int lbState, int note, int lastNote)
{
    // Setting current button state.
  cbState = digitalRead(buttonPin);

  // Checking to see if button is pressed.
  if(cbState == 1)
  {
    if(lbState == 0)
    {
      // Send note.
      sendNote(0x90, note, 0x40);
      // Saving last note played, to send off signal later.
      lastNote = note;
    }
  }
  // The switch has not been pressed.
  else
  {
    // If button is lifted.
    if(lbState == 1)
    {
      sendNote(0x90, lastNote, 0x00);
    }
  }
  // Set last state to current state, should be 0.
  lbState = cbState;
}
