#include <stdio.h>

int isNumber(char i){
    return i - 48 >= 0 && i - 48 < 10; //asci type shi
}

int main() {

    FILE *fptr = fopen("../day4/input.txt", "r");
    if (fptr == NULL) {
        printf("Not able to open the file.\n");
        return 1;
    }

    int columns = 0;
    int lineLength = 1;
    char testLine[500];

    fgets(testLine, 500, fptr);
    columns++;
    while (!feof(fptr)) {
        char temp[500];
        fgets(temp, 500, fptr);

        columns++;
    }
    fseek(fptr, 0, SEEK_SET);

    //find maxLineLength:
    for (int i = 0; i < 500; i++){
        if (testLine[i] == '\n')
            break;
        lineLength++;
    }


    printf("%s%d\n", "We have columns: ", columns);
    printf("%s%d\n\n", "We have lineLength: ", lineLength);


    //fill 2d array with input

    char input[columns][lineLength];

    for (int i = 0; i < columns; i++){
        fgets(input[i], lineLength, fptr); //won't automatically go to newline since its stopping to read right before the '\n'
        fseek(fptr, 1, SEEK_CUR); //go to next line
        printf("%s\n", input[i]);
    }

    int leftBegin = 0;
    int rightBegin = 0;

    for (int i = 0; i < lineLength; i++){
        if (input[0][i] == ':') {
            leftBegin = i + 2;
            break;
        }
    }

    for (int i = 0; i < lineLength; i++){
        if (input[0][i] == '|') {
            leftBegin = i + 2;
            break;
        }
    }


    int winningNumbers[columns][100];
    int raffleNumbers[columns][100];

    for (int i = 0; i < columns; i++){
        for (int o = 0; o < 100; o++){
            winningNumbers[i][o] = -1;
            raffleNumbers[i][o] = -1;
        }
    }


    for (int i = leftBegin; i < rightBegin - 3; i++){

    }


    return 0;
}