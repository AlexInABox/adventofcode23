#include <stdio.h>

int maxRedAmount = 12;
int maxGreenAmount = 13;
int maxBlueAmount = 14;

int redAmount = 0;
int greenAmount = 0;
int blueAmount = 0;

int isNumber(char i){
    return i - 48 >= 0 && i - 48 < 10;
}

int isValid(){
    if (redAmount <= maxRedAmount && greenAmount <= maxGreenAmount && blueAmount <= maxBlueAmount) {
        printf("%s%d%s%d%s%d\n", "red: ", redAmount, " green: ", greenAmount, " blue: ", blueAmount);
        redAmount = 0;
        greenAmount = 0;
        blueAmount = 0;
        return 1;
    } else{
        printf("%s%d%s%d%s%d\n", "red: ", redAmount, " green: ", greenAmount, " blue: ", blueAmount);
        printf("impossible\n\n");
        redAmount = 0;
        greenAmount = 0;
        blueAmount = 0;
        return 0;
    }
}



int main() {


    FILE *fptr = fopen("../day2/input.txt", "r");
    if (fptr == NULL) {
        printf("Not able to open the file.\n");
        return 1;
    }
    int sum = 0;
    int whichGame = 0;
    int lastWasPossible = 1;

    while (!feof(fptr)) {

        whichGame++;
        sum += whichGame;

        char line[500];
        int lengthOfLine;

        fgets(line, 500, fptr);

        for (lengthOfLine = 0; lengthOfLine < 500; lengthOfLine++) {
            if (line[lengthOfLine] == '\n') {
                break;
            }
        }

        printf("%s%d\n", "Game Number: ", whichGame);

        int gameBeginAfterIndex = 0;

        for (int i = 0; i < lengthOfLine; i++) {
            //find the first ':' so to know where the games content begins
            if (line[i] == ':'){
                gameBeginAfterIndex = i+2;
                break;
            }
        }


        for (int i = gameBeginAfterIndex; i < lengthOfLine;) {
            //check the values for each color until a ';' is reached

            int tempNumber = 0;
            int isBigNumber = 0;

            if (isNumber(line[i+1])) { //big number
                tempNumber = (line[i] - 48) * 10 + line[i + 1] - 48;
                isBigNumber = 1;
            }
            else {
                tempNumber = line[i] - 48;
            }

            if (isBigNumber)
                i++;

            if (line[i+2] == 'r'){ //red
                redAmount += tempNumber;

                if ((line[i+5] == ';' || line[i+5] == '\n') && !isValid()){
                    sum -= whichGame;
                    lastWasPossible = 0;
                    break;
                }
                i = i + 7;
            } else if (line[i+2] == 'g'){ //green
                greenAmount += tempNumber;

                if ((line[i+7] == ';' || line[i+7] == '\n') && !isValid()){
                    sum -= whichGame;
                    lastWasPossible = 0;
                    break;
                }
                i = i + 9;
            } else if (line[i+2] == 'b'){ //blue
                blueAmount += tempNumber;

                if ((line[i+6] == ';' || line[i+6] == '\n') && !isValid()){
                    sum -= whichGame;
                    lastWasPossible = 0;
                    break;
                }
                i = i + 8;
            }
        }
    }

    if (lastWasPossible)
        printf("\n%s%d\n", "Sum of file: ", sum - whichGame);
    else
        printf("\n%s%d\n", "Sum of file: ", sum);


    return 0;
}