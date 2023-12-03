#include <stdio.h>

int isNumber(char i){
    return i - 48 >= 0 && i - 48 < 10; //asci type shi
}

int main() {

    FILE *fptr = fopen("../day2/input.txt", "r");
    if (fptr == NULL) {
        printf("Not able to open the file.\n");
        return 1;
    }
    int sum = 0;
    int whichGame = 0;
    int lastPower = 0;

    while (!feof(fptr)) {

        whichGame++;

        int highestRed = 1;
        int highestGreen = 1;
        int highestBlue = 1;

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

                if (highestRed < tempNumber)
                    highestRed = tempNumber;

                i = i + 7;
            } else if (line[i+2] == 'g'){ //green
                if (highestGreen < tempNumber)
                    highestGreen = tempNumber;

                i = i + 9;
            } else if (line[i+2] == 'b'){ //blue
                if (highestBlue < tempNumber)
                    highestBlue = tempNumber;

                i = i + 8;
            }
        }

        printf("%s%d\n\n", "Power in this line: ", (highestRed * highestGreen * highestBlue));
        sum += (highestRed * highestGreen * highestBlue);
        lastPower = (highestRed * highestGreen * highestBlue);
    }

        printf("\n%s%d\n", "Sum of file: ", sum - lastPower);

    fclose(fptr);

    return 0;
}