#include "sensor.h"
#include "timer.h"
#include "user.h"

enum AlarmState
{
  OFF,
  ON,
  ALARMED
} ;

enum AlarmEvent
{
  NONE,
  BUTTON,
  TIMERELAPSED,
  ALARMTRIGGER
};

/*-------------------------------------------------------*/
void setup()
{
  Serial.begin(9600);

  sensor_begin();
  user_begin();
}

/*-------------------------------------------------------*/
void loop()
{
  static AlarmState state = OFF;
  static AlarmState newState = OFF;
  static AlarmEvent currentEvent = NONE;

  currentEvent = checkForNewEvent();

  if (currentEvent != NONE) {
    handleEvent(state, currentEvent, &newState);

    if (newState != state)
    {
      state = newState;
      Serial.print("State: "); Serial.println(state);
    }
  }
}

/*-------------------------------------------------------*/
AlarmEvent checkForNewEvent()
{
  AlarmEvent event = NONE;

  if (sensor_isTriggered() ) {
    event = ALARMTRIGGER;
  }
  else if (timer_hasElapsed() ) {
    event = TIMERELAPSED;
  }
  else if (user_button_isPressed() ) {
    event = BUTTON;
  }

  return event;
}

/*-------------------------------------------------------*/
void handleEvent(AlarmState state,
                 AlarmEvent event,
                 AlarmState* newState)
{
  switch (state) {
    case OFF:
      {
        if (event == BUTTON)
        {
          user_showAlarmOn();
          *newState = ON;
        }
      }
      break;
    case ON:
      {
        if (event == ALARMTRIGGER)
        {
          user_turnAlarmSignalsOn();
          timer_start();
          *newState = ALARMED;
        }
        else if (event == BUTTON)
        {
          user_showAlarmOff();
          *newState = OFF;
        }
      }
      break;
    case ALARMED:
      {
        if ((event == BUTTON) || (event == TIMERELAPSED))
        {
          *newState = ON;
          timer_reset();
          user_turnAlarmSignalsOff();
        }
      }
      break;
    default:
      {
        Serial.print("State is unknown: ");
        Serial.println(state);
      }
      break;
  }
}

