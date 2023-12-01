#include <stdio.h>

int main() {


    FILE *fptr = fopen("../day1/input.txt", "r");
    if (fptr == NULL) {
        printf("Not able to open the file.\n");
        return 1;
    }
    int sum = 0;
    int lastLine = 0;

    while (!feof(fptr)) {

        char line[100];
        int lengthOfLine;

        fgets(line, 100, fptr);

        for (lengthOfLine = 0; lengthOfLine < 100; lengthOfLine++){
            if (line[lengthOfLine] == '\n'){
                break;
            }
        }

        printf("%s%d\n", "Length of line: ", lengthOfLine);
        int numbersInLine[lengthOfLine];
        int numbersInLineIndex = 0;

        for (int i = 0; i < lengthOfLine; i++){

            if ((line[i] - 48) <= 10 && (line[i] - 48) >= 0 ){
                //we know it's a number...
                numbersInLine[numbersInLineIndex] = line[i] - 48; //convert to int
                numbersInLineIndex++;
            } else{
                if((line[i] == 'o' && line[i+1] == 'n' && line[i+2] == 'e') && lengthOfLine >= i+2){
                    numbersInLine[numbersInLineIndex] = 1;
                    numbersInLineIndex++;
                }
                if((line[i] == 't' && line[i+1] == 'w' && line[i+2] == 'o') && lengthOfLine >= i+2){
                    numbersInLine[numbersInLineIndex] = 2;
                    numbersInLineIndex++;
                }
                if((line[i] == 't' && line[i+1] == 'h' && line[i+2] == 'r' && line[i+3] == 'e' && line[i+4] == 'e') && lengthOfLine >= i+4){
                    numbersInLine[numbersInLineIndex] = 3;
                    numbersInLineIndex++;
                }
                if((line[i] == 'f' && line[i+1] == 'o' && line[i+2] == 'u' && line[i+3] == 'r') && lengthOfLine >= i+3){
                    numbersInLine[numbersInLineIndex] = 4;
                    numbersInLineIndex++;
                }
                if((line[i] == 'f' && line[i+1] == 'i' && line[i+2] == 'v' && line[i+3] == 'e') && lengthOfLine >= i+3){
                    numbersInLine[numbersInLineIndex] = 5;
                    numbersInLineIndex++;
                }
                if((line[i] == 's' && line[i+1] == 'i' && line[i+2] == 'x') && lengthOfLine >= i+2){
                    numbersInLine[numbersInLineIndex] = 6;
                    numbersInLineIndex++;
                }
                if((line[i] == 's' && line[i+1] == 'e' && line[i+2] == 'v' && line[i+3] == 'e' && line[i+4] == 'n') && lengthOfLine >= i+4){
                    numbersInLine[numbersInLineIndex] = 7;
                    numbersInLineIndex++;
                }
                if((line[i] == 'e' && line[i+1] == 'i' && line[i+2] == 'g' && line[i+3] == 'h' && line[i+4] == 't') && lengthOfLine >= i+4){
                    numbersInLine[numbersInLineIndex] = 8;
                    numbersInLineIndex++;
                }
                if((line[i] == 'n' && line[i+1] == 'i' && line[i+2] == 'n' && line[i+3] == 'e') && lengthOfLine >= i+3){
                    numbersInLine[numbersInLineIndex] = 9;
                    numbersInLineIndex++;
                }
            }
        }

        for (int i = 0; i < numbersInLineIndex; i++){
            printf("%d ", numbersInLine[i]);
        }
        printf("\n");

        int finalNumberForLine = numbersInLine[0] * 10 + numbersInLine[numbersInLineIndex-1];
        printf("%s%d\n\n", "--> ", finalNumberForLine);

        lastLine = finalNumberForLine;
        sum += finalNumberForLine;
    }

    printf("%s%d\n", "Sum of all: ", sum - lastLine);

    fclose(fptr);

    return 0;
}
