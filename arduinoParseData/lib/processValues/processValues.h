#ifndef PROCESS_VALUES
#define PROCESS_VALUES
void setupStepper();
void splitTokens(char *buffer, char *valueType, char *value);
void processValue(char *valueType, char *value);
#endif