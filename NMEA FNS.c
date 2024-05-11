<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char extractlatitudesdirection(const char *NMEA){
char *token;
int count=0;
char latitudedirection;
char nmea_copy[100];
strcpy(nmea_copy, NMEA);

token = strtok(nmea_copy,",");
while (token != NULL && count < 6){
    if(count == 3){
        latitudedirection = token[0];
        break;
    }
    count++;
    token = strtok(NULL,",");
}
printf("latitudedirection: %c\n",latitudedirection);
return latitudedirection;

}

float extractlatitudes(const char *NMEA){
char *token;
int count=0;
float latitude;
char nmea_copy[100];
strcpy(nmea_copy, NMEA);

token = strtok(nmea_copy,",");
while (token != NULL && count < 6){
    if(count == 2){
        latitude = atof(token);
        break;
    }
    count++;
    token = strtok(NULL,",");
}
printf("latitude: %f\n",latitude);
return latitude;

}

float extractlongtitudes(const char *NMEA){
char *token;
int count=0;
float longitude;
char nmea_copy[100];
strcpy(nmea_copy, NMEA);

token = strtok(nmea_copy,",");
while (token != NULL && count < 6){
    if(count == 4){
        longitude = atof(token);
        break;
    }
    count++;
    token = strtok(NULL,",");
}
printf("longitude: %f\n",longitude);
return longitude;

}

char extractlongtitudesdirection(const char *NMEA){
char *token;
int count=0;
char longitudedirection;
char nmea_copy[100];
strcpy(nmea_copy, NMEA);

token = strtok(nmea_copy,",");
while (token != NULL && count < 6){
    if(count == 5){
        longitudedirection = token[0];
        break;
    }
    count++;
    token = strtok(NULL,",");
}
printf("longitudedirection: %c\n",longitudedirection);
return longitudedirection;

}



=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char extractlatitudesdirection(const char *NMEA){
char *token;
int count=0;
char latitudedirection;
char nmea_copy[100];
strcpy(nmea_copy, NMEA);

token = strtok(nmea_copy,",");
while (token != NULL && count < 6){
    if(count == 3){
        latitudedirection = token[0];
        break;
    }
    count++;
    token = strtok(NULL,",");
}
return latitudedirection;

}

float extractlatitudes(const char *NMEA){
char *token;
int count=0;
float latitude;
char nmea_copy[100];
strcpy(nmea_copy, NMEA);

token = strtok(nmea_copy,",");
while (token != NULL && count < 6){
    if(count == 2){
        latitude = atof(token);
        break;
    }
    count++;
    token = strtok(NULL,",");
}
printf("latitude: %f\n",latitude);
return latitude;

}

float extractlongtitudes(const char *NMEA){
char *token;
int count=0;
float longitude;
char nmea_copy[100];
strcpy(nmea_copy, NMEA);

token = strtok(nmea_copy,",");
while (token != NULL && count < 6){
    if(count == 4){
        longitude = atof(token);
        break;
    }
    count++;
    token = strtok(NULL,",");
}
printf("longitude: %f\n",longitude);
return longitude;

}

char extractlongtitudesdirection(const char *NMEA){
char *token;
int count=0;
char longitudedirection;
char nmea_copy[100];
strcpy(nmea_copy, NMEA);

token = strtok(nmea_copy,",");
while (token != NULL && count < 6){
    if(count == 5){
        longitudedirection = token[0];
        break;
    }
    count++;
    token = strtok(NULL,",");
}
printf("longitudedirection: %c\n",longitudedirection);
return longitudedirection;

}



>>>>>>> 407b50c (Initialize UART5)
