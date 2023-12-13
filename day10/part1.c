#include <stdio.h>

int main(){


    FILE *fptr = fopen("../day10/input.txt", "r");
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

    int yOfS;
    int xOfS;

    for (yOfS = 0; yOfS < columns; yOfS++){
        for (xOfS = 0; xOfS < lineLength; xOfS++){
            if (input[yOfS][xOfS] == 'S')
                break;
        }
        if (xOfS < lineLength)
            break;
    }

    printf("\n%s%d%s%d\n", "x = ", xOfS, " y = ", yOfS);

    //letsa go
    int firstStartX = 0;
    int firstStartY = 0;

    //find the first starting position

    for (int i = -1; i < 2; i++){
        for (int o = -1; o < 2; o++){
            switch (input[yOfS+i][xOfS+o]) {
                case '|':
                    if (o == 0) {
                            firstStartX = xOfS + o;
                            firstStartY = yOfS + i;
                    }
                case '-':
                    if (i == 0){
                            firstStartX = xOfS + o;
                            firstStartY = yOfS + i;
                    }
                case 'L':
                    if ((o == 0 && i == 1) || (o == -1 && i == 0)){
                            firstStartX = xOfS + o;
                            firstStartY = yOfS + i;
                    }
                case 'J':
                    if ((o == 0 && i == 1) || (o == 1 && i == 0)){
                            firstStartX = xOfS + o;
                            firstStartY = yOfS + i;
                    }
                case '7':
                    if ((o == 0 && i == -1) || (o == 1 && i == 0)){
                            firstStartX = xOfS + o;
                            firstStartY = yOfS + i;
                    }
                case 'F':
                    if ((o == 0 && i == -1) || (o == -1 && i == 0)){
                            firstStartX = xOfS + o;
                            firstStartY = yOfS + i;
                    }
                    default:
            }
        }
    }

    printf("%s%d%s%d\n", "X of first: ", firstStartX, " Y of first: ", firstStartY);

    int lengthOfPath = 1;
    int finished = 0;
    int previousX = xOfS;
    int previousY = yOfS;
    int tempPreviousX = 0;
    int tempPreviousY = 0;
    int tempX = firstStartX;
    int tempY = firstStartY;

    while (!finished){
        tempPreviousX = tempX;
        tempPreviousY = tempY;
        switch (input[tempY][tempX]) {
            case '|':
                printf("| ");
                if (previousY < tempY) {
                    tempY++;
                }
                else {
                    tempY--;
                }
                lengthOfPath++;
                break;
            case '-':
                printf("- ");
                if (previousX < tempX) {
                    tempX++;
                }
                else {
                    tempX--;
                }
                lengthOfPath++;
                break;
            case 'L':
                printf("L ");
                if (previousY < tempY) {
                    tempX++;
                }
                else {
                    tempY--;
                }
                lengthOfPath++;
                break;
            case 'J':
                printf("J ");
                if (previousY < tempY){
                    tempX--;
                }
                else {
                    tempY--;
                }
                lengthOfPath++;
                break;
            case '7':
                printf("7 ");
                if (previousY > tempY) {
                    tempX--;
                }
                else {
                    tempY++;
                }
                lengthOfPath++;
                break;
            case 'F':
                printf("F ");
                if (previousY > tempY){
                    tempX++;
                }
                else {
                    tempY++;
                }
                lengthOfPath++;
                break;
            case 'S':
                printf("S ");
                printf("FINSIHED\n");
                finished = 1;
                break;
            default:
                printf("SUCIDE ");
        }
        previousX = tempPreviousX;
        previousY = tempPreviousY;
    }

    printf("%s%d", "Length of path: ", lengthOfPath/2);

    return 0;
}