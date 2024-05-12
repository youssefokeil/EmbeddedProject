#ifndef decoder_H
#define decoder_H
#include <string.h>
char getLatitudeDirection(char *code);
char getlongitudeDirection(char *code);
float getLatitude(char *code);
float getlongitude(char *code);
void refill(char *code,char *copy);
#endif