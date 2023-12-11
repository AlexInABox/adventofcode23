#include <stdio.h>

int isNumber(char i){
    return i - 48 >= 0 && i - 48 < 10; //asci type shi
}

int main() {

    FILE *fptr = fopen("../day6/input.txt", "r");
    if (fptr == NULL) {
        printf("Not able to open the file.\n");
        return 1;
    }

    char row[2][500];

    fgets(row[0], 500, fptr);
    fgets(row[1], 500, fptr);
    int lengthOfInput;


    for (lengthOfInput = 0; lengthOfInput < 500; lengthOfInput++) {
        if (row[0][lengthOfInput] == '\n') {
            break;
        }
    }

    //for the first line find every number and add it to the time array
    //same thing for line two but put every number into distance array

    long timeNumber = 0;
    long distanceNumber = 0;

    for (int i = 0; i < 2; i++){
        for (int o = 0; o < lengthOfInput; o++){

            if (!(isNumber(row[i][o])))
                continue;

            int temp = row[i][o] - 48;
            if (i == 0) {
                timeNumber  = timeNumber * 10 + temp;
            } else if (i == 1) {
                printf("%s%d\n", "Found: ", temp);
                distanceNumber  = distanceNumber * 10 + temp;
                printf("%s%ld\n", "NewDistance: ", distanceNumber);

            }
        }
    }

    printf("%s%ld\n", "TimeNumber: ", timeNumber);
    printf("%s%ld\n", "DistanceNumber: ", distanceNumber);

    int margin = 0;
    for (long o = 1; o < timeNumber; o++) {
        long score = (timeNumber - o) * o;
        if (score > distanceNumber) {
            margin++;
        }
    }


    printf("\n\n%d", margin);
    fclose(fptr);

    return 0;
}