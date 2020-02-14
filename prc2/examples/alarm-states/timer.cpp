static long timerStart = 0;
static bool timerStarted = false;
#define TIMER_ELAPSED_DURATION_IN_MS (5000)

#include <Arduino.h>

void timer_start()
{
  timerStart = millis();
  timerStarted = true;
}

void timer_reset()
{
  timerStarted = false;
}

boolean timer_hasElapsed()
{
  long duration = millis() - timerStart;

  if (timerStarted && (duration > TIMER_ELAPSED_DURATION_IN_MS))
  {
    return true;
  }

  return false;
}
