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

    int time[lengthOfInput];
    int timeIndex = 0;
    int distance[lengthOfInput];
    int distanceIndex = 0;

    for (int i = 0; i <= lengthOfInput; i++){
        //fill array with -1
        time[i] = -1;
        distance[i] = -1;
    }

    int lengthOfNumber;

    for (int i = 0; i < 2; i++){
        for (int o = 0; o <= lengthOfInput; o++){

            if (!(isNumber(row[i][o])))
                continue;

            lengthOfNumber = 0;

            if (isNumber(row[i][o+3]) && isNumber(row[i][o+2]) && isNumber(row[i][o+1]))
                lengthOfNumber = 3;
            else if (isNumber(row[i][o+2]) && isNumber(row[i][o+1]))
                lengthOfNumber = 2;
            else if (isNumber(row[i][o+1]))
                lengthOfNumber = 1;


            if (lengthOfNumber == 3){
                int temp = ((((row[i][o] - 48) * 10 + (row[i][o+1] - 48)) * 10 + (row[i][o+2] - 48))) * 10 + (row[i][o+3] - 48);
                if (i == 0) {
                    time[timeIndex] = temp;
                    timeIndex++;
                }
                else if (i == 1) {
                    distance[distanceIndex] = temp;
                    distanceIndex++;
                }
                o = o + 3;
            } else if (lengthOfNumber == 2){
                int temp = ((row[i][o] - 48) * 10 + (row[i][o+1] - 48)) * 10 + (row[i][o+2] - 48);
                if (i == 0){
                    time[timeIndex] = temp;
                    timeIndex++;
                }
                else if (i == 1){
                    distance[distanceIndex] = temp;
                    distanceIndex++;
                }
                o = o + 2;
            } else if (lengthOfNumber == 1){
                int temp = (row[i][o] - 48) * 10 + (row[i][o+1] - 48);
                if (i == 0){
                    time[timeIndex] = temp;
                    timeIndex++;
                }
                else if (i == 1){
                    distance[distanceIndex] = temp;
                    distanceIndex++;
                }
                o = o + 1;
            } else {
                int temp = row[i][o] - 48;
                if (i == 0) {
                    time[timeIndex] = temp;
                    timeIndex++;
                } else if (i == 1) {
                    distance[distanceIndex] = temp;
                    distanceIndex++;
                }
            }
        }
    }

    printf("%s\n", "Time Array: ");

    for (int i = 0; i < timeIndex; i++){
        printf("%d ", time[i]);
    }


    printf("\n%s\n", "Distance Array: ");
    for (int i = 0; i < distanceIndex; i++){
        printf("%d ", distance[i]);
    }

    int sum = 1;
    for (int i = 0; i < distanceIndex; i++){

        //first race:
        int margin = 0;
        for (int o = 1; o < time[i]; o++){
            int score = (time[i] - o) * o;
            if (score > distance[i])
                margin++;
        }

        sum *= margin;
    }

    printf("\n\n%d", sum);
    fclose(fptr);

    return 0;
}