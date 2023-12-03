#include <stdio.h>

int isNumber(char i){
    return i - 48 >= 0 && i - 48 < 10; //asci type shi
}

int main() {

    FILE *fptr = fopen("../day3/input.txt", "r");
    if (fptr == NULL) {
        printf("Not able to open the file.\n");
        return 1;
    }

    int paragraphs = 0;

    while (!feof(fptr)) {
        char line[142];
        fgets(line, 142, fptr);

        paragraphs++;
    }

    fseek(fptr, 0, SEEK_SET);


    printf("%s%d\n", "We have columns: ", paragraphs);

    char wholeDoc[paragraphs][142];
    int sum = 0;



    //search for '*'
    //search for numbers adjacent
    //calculate gear ratio if 2 numbers
    //add ratio to sum

    //now fill 2darray with input

    for (int i = 0; i < paragraphs; i++) {
        fgets(wholeDoc[i], 150, fptr);
    }

    int maxLength;
    for (maxLength = 0; maxLength < 142; maxLength++) {
        if (wholeDoc[1][maxLength] == '\n') {
            break;
        }
    }

    for (int i = 0; i < paragraphs; i++){

        printf("%s%d\n", "checking paragraph: ", i+1);
        for (int o = 0; o < maxLength; o++) {

            //search for '*'
            if (wholeDoc[i][o] != '*'){
                continue;
            }

            //when a '*' has been found:

            int latestAdjacentNumber = 0;
            int gearRatio = 1;
            int amountOfAdjacentNumbers = 0;

            //now search for symbols adjacent
            for (int a = -1; a <= 1; a++) { //column
                if ((i + a) < 0 || (i + a) > paragraphs - 1) {
                    //empty lines cant be checked
                    continue;
                }

                for (int b = -3; b < 2; b++) {
                    if ((o + b) < 0 || (o + b) > maxLength - 1)
                        continue;

                    if (!isNumber(wholeDoc[i + a][o + b]))
                        continue;

                    if (b >= -1) {
                        if (isNumber(wholeDoc[i + a][o + b + 1]) && isNumber(wholeDoc[i + a][o + b + 2])) {
                            latestAdjacentNumber =
                                    (((wholeDoc[i + a][o + b] - 48) * 10) + (wholeDoc[i + a][o + b + 1] - 48)) * 10 +
                                    (wholeDoc[i + a][o + b + 2] - 48);
                            printf("%d ", latestAdjacentNumber);

                            amountOfAdjacentNumbers++;
                            gearRatio *= latestAdjacentNumber;
                            b = b + 2;
                        } else if (isNumber(wholeDoc[i + a][o + b + 1])) {
                            latestAdjacentNumber =
                                    ((wholeDoc[i + a][o + b] - 48) * 10) + (wholeDoc[i + a][o + b + 1] - 48);
                            printf("%d ", latestAdjacentNumber);

                            amountOfAdjacentNumbers++;
                            gearRatio *= latestAdjacentNumber;
                            b = b + 1;
                        } else {
                            latestAdjacentNumber = (wholeDoc[i + a][o + b] - 48);
                            printf("%d ", latestAdjacentNumber);

                            amountOfAdjacentNumbers++;
                            gearRatio *= latestAdjacentNumber;
                        }
                    } else if (b == -2){
                        if (isNumber(wholeDoc[i + a][o + b + 1]) && isNumber(wholeDoc[i + a][o + b + 2])) {
                            latestAdjacentNumber =
                                    (((wholeDoc[i + a][o + b] - 48) * 10) + (wholeDoc[i + a][o + b + 1] - 48)) * 10 +
                                    (wholeDoc[i + a][o + b + 2] - 48);
                            printf("%d ", latestAdjacentNumber);

                            amountOfAdjacentNumbers++;
                            gearRatio *= latestAdjacentNumber;
                            b = b + 2;
                        } else if (isNumber(wholeDoc[i + a][o + b + 1])) {
                            latestAdjacentNumber =
                                    ((wholeDoc[i + a][o + b] - 48) * 10) + (wholeDoc[i + a][o + b + 1] - 48);
                            printf("%d ", latestAdjacentNumber);

                            amountOfAdjacentNumbers++;
                            gearRatio *= latestAdjacentNumber;
                            b = b + 1;
                        }
                    } else if (b == -3){
                        if (isNumber(wholeDoc[i + a][o + b + 1]) && isNumber(wholeDoc[i + a][o + b + 2])) {
                            latestAdjacentNumber =
                                    (((wholeDoc[i + a][o + b] - 48) * 10) + (wholeDoc[i + a][o + b + 1] - 48)) * 10 +
                                    (wholeDoc[i + a][o + b + 2] - 48);
                            printf("%d ", latestAdjacentNumber);

                            amountOfAdjacentNumbers++;
                            gearRatio *= latestAdjacentNumber;
                            b = b + 2;
                        }
                    }
                }
            }

            if (amountOfAdjacentNumbers == 2) {
                printf("\n%s%d\n\n", "Gear ratio: ", gearRatio);
                sum += gearRatio;
            } else{
                printf("\n");
            }
        }
    }

    printf("\n\n%s%d\n", "Sum of game: ",   sum);

    fclose(fptr);
    return 0;
}