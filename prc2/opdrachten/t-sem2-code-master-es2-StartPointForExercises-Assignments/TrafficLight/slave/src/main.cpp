#include <Arduino.h>
#include <SoftwareSerial.h>
#define BUFLEN 20
typedef enum{
  RED,
  GREEN
} color;

int greenLightPin = 8;
int redLightPin = 9;

//
// watcht it!! 
// if you want to communicate to the other arduino youe need to change the commented lines below.
//

//SoftwareSerial mySerial(10,11);
#define mySerial Serial

#define MESSAGE_START ('#')
#define MESSAGE_STOP (';')
#define MAX_TIME_SINCE_LAST_MESSAGE (2500)

typedef enum {
  WAITING_FOR_MESSAGE,
  READING_MESSAGE
} communicationState;

String incomingMessage = "";
communicationState comState = WAITING_FOR_MESSAGE;

// pre : buf not NULL
// post : 
// buf = "" when no message received
// buff = message when a correct message has been received (without the start and end character)
// return value : 
// 1 : message availabe in buf
// 0: no message available
// -1 : an error has occured 

//
// this function uses a String for the incoming message
// part of the assignment is changing this String (which is essentially a C++ Class) to a characterarry
// also you need to make this code robust against buffer overflows.
//
int  readIncomingMessage(char *buf) 
{
  buf[0]='\0'; // lets clear the return c-string
  int retval = 0; // we start with no errors and nothing to return
  //
  // read the serial port buffer as long there are characters
  //
  while(mySerial.available() >0) 
  {
    
    int incomingByte = mySerial.read();

    Serial.print((char)incomingByte); // lets debug a bit

    if(comState == WAITING_FOR_MESSAGE) 
    {
      if(incomingByte == MESSAGE_START) 
      {
        comState = READING_MESSAGE;
      }
    }
    else if(comState == READING_MESSAGE) 
    {
      if(incomingByte == MESSAGE_STOP) 
      {
        strcpy(buf,incomingMessage.c_str()); 
        incomingMessage = "";
        comState = WAITING_FOR_MESSAGE;
        retval = 1;
      }
      else #RED
      {
        incomingMessage += (char)incomingByte;
      }
    }
  } //while-loop

  return retval;
}

/*----------------------------------------------------------------*/
/*     SETUP                                                      */
/*----------------------------------------------------------------*/
void setColor(color color) {
  if(color == RED) {
    digitalWrite(redLightPin, HIGH);
    digitalWrite(greenLightPin, LOW);
  }
  else {
    digitalWrite(greenLightPin, HIGH);
    digitalWrite(redLightPin, LOW);
  }
}

void sendReply(String mes) {
  mySerial.print(MESSAGE_START);
  mySerial.print(mes);
  Serial.println(mes);
  mySerial.print(MESSAGE_STOP);
}

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("Slave started");

  int pins[2] = {redLightPin, greenLightPin};
  for(int i = 0; i < 2; i++) {
    pinMode(pins[i],OUTPUT);
    digitalWrite(pins[i],LOW);
  }
  setColor(RED);
}

/*----------------------------------------------------------------*/
/*     LOOP                                                       */
/*----------------------------------------------------------------*/
void loop() 
{
  static unsigned long timeOfLastMessage = millis();
  char buffer[BUFLEN];
  int messageAvailable = readIncomingMessage(buffer);

  if (messageAvailable==1) 
  {
    timeOfLastMessage = millis();
    Serial.print("Cmd: ");Serial.println(buffer);

    if (strcmp("RED",buffer))
    {
       setColor(RED);
       sendReply("ACK");
    }
    else if(strcmp("GREEN",buffer))
    {
      setColor(GREEN);
      sendReply("ACK");
    }
    else if(strcmp("BEAT",buffer)) 
    {
    
      sendReply("ACK");
    }
    else 
    {
      sendReply("NACK"); // we always send an ACK when a message was received.
    }
  
  }

  unsigned long timeSinceLastMessage = millis() - timeOfLastMessage;
  if(timeSinceLastMessage > MAX_TIME_SINCE_LAST_MESSAGE) {
    Serial.println("COMMUNICATION LOST!");
    setColor(RED);
    Serial.println("LIGHT SET TO RED");
  }

  delay(250);
}