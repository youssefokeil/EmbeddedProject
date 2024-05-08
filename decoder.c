#include "decoder.h"
#include <stdlib.h>
char getLatitudeDirection(char *code){
	int counter=0;
	char *tokens[20];
	 char *token;
	char latitude;
	token=strtok(code,",");
	while(token !=NULL &&counter<20){
		tokens[counter]=token;
		counter++;
		token=strtok(NULL,",");
	}
if (strncmp(tokens[0],"$GPGGA",6)==0 && counter>=14){
	latitude =tokens[3][0];
}
return latitude;
}

char getlongitudeDirection(char *code){
		char copy[100];
	char *tokens[20];
	char *token;
	char longitude;
	int counter=0;
	
	token=strtok(code,",");
	while(token !=NULL &&counter<20){
		tokens[counter]=token;
		counter++;
		token=strtok(NULL,",");
	}
if (strncmp(tokens[0],"$GPGGA",6)==0 && counter>=14){
	longitude =tokens[5][0];
}
return longitude;
}

float getLatitude(char *code){
	
		char *tokens[20];
	 char *token;
	float latitude;
	int counter=0;
		
	token=strtok(code,",");
	while(token !=NULL &&counter<20){
		tokens[counter]=token;
		counter++;
		token=strtok(NULL,",");
	}
if (strncmp(tokens[0],"$GPGGA",6)==0 && counter>=14){
	latitude =atof(tokens[2]);
}
return latitude;
	
}


float getlongitude(char *code){
			char *tokens[20];
	 char *token;
	float longitude;
	int counter=0;
		char copy[100];
	
	token=strtok(code,",");
	while(token !=NULL &&counter<20){
		tokens[counter]=token;
		counter++;
		token=strtok(NULL,",");
	}
if (strncmp(tokens[0],"$GPGGA",6)==0 && counter>=14){
	longitude =atof(tokens[4]);
}
return longitude;
	
	
}

void refill(char *code,char *copy){
	int i;
	for(i=0;i<100;i++)
	copy[i]=code[i];
}