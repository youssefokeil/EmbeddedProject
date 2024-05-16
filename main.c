#include <stdio.h>
#include <stdlib.h>

void savingcsv(float *lat, float *lon, int n) {
    FILE *fp;
    char filename[] = "data.csv";

    fp = fopen(filename, "w+");


    while (n--) {
        printf("%f , %f\n", *lon, *lat);
        fprintf(fp, "%f , %f\n", *lat, *lon);
        lat++;
        lon++;
    }

    fclose(fp);
}

int main() {
    float lat[] = {11.02354,4536};
    float lon[] = {22.0325,435.5324};

    savingcsv(lat, lon, 2);
    return 0;
}

