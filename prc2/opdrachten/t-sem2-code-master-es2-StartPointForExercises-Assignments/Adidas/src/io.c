#include "io.h"
#include "resource_detector.h"

static FILE *	fpIn 	= NULL;
static FILE *	fpOut = NULL;

bool io_open_file_for_writing(char* file_name) {
    if(fpOut != NULL) return false;
    fpOut = fopen (file_name, "wb");
    return (fpOut != NULL);
}

bool io_write_byte(uint8_t b) {
  int stat = fputc(b, fpOut);
  return (stat != EOF);
}

bool io_close_file_for_writing() {
  if(fpOut == NULL) return false;
  int stat = fclose (fpOut);
  fpOut = NULL;
  return stat != 0;
}

bool io_open_file_for_reading(char* file_name) {
  if(fpIn != NULL) return false;
  fpIn = fopen (file_name, "rb");
  return fpIn != NULL;
}

bool io_read_byte(uint8_t *b) {
  int stat = fgetc(fpIn);
  if(stat == EOF) {
    *b = 0;
    return false;
  }

  *b = stat;
  return true;
}

bool io_close_file_for_reading() {
  if(fpIn == NULL) return false;
  int stat = fclose (fpIn);
  fpIn = NULL;
  return stat != 0;
}
