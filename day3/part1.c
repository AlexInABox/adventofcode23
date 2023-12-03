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



    //search for number
    //check size of number (either x, xx or xxx)
    //check if is adjacent to any other character than ('.', 'number', '\n')
    //if is adjacent to symbol add to sum

    //now fill 2darray with input

    for (int i = 0; i < paragraphs; i++){
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
        for (int o = 0; o < 142; o++){
            int foundNumber = 0;
            int foundNumberExtraSize = 0; // 0 = oneNumberOnly

            if (wholeDoc[i][o] == '\n')
                break;

            if (isNumber(wholeDoc[i][o])){
                if (isNumber(wholeDoc[i][o+1]) && isNumber(wholeDoc[i][o+2])){
                    foundNumber = (((wholeDoc[i][o] - 48) * 10) + (wholeDoc[i][o+1] - 48)) * 10 + (wholeDoc[i][o+2] - 48);
                    foundNumberExtraSize = 2;
                    printf("%d ", foundNumber);
                } else if (isNumber(wholeDoc[i][o+1])){
                    foundNumber = ((wholeDoc[i][o] - 48) * 10) + (wholeDoc[i][o+1] - 48);
                    foundNumberExtraSize = 1;
                    printf("%d ", foundNumber);
                } else{
                    foundNumber = (wholeDoc[i][o] - 48);
                    printf("%d ", foundNumber);
                }

                //now search for symbols adjacent
                for (int a = -1; a <= 1; a++){
                    int tempSum = sum;
                    if ((i + a) < 0 || (i + a) > paragraphs - 1){
                        //empty lines cant be checked
                        continue;
                    }

                    if (foundNumberExtraSize == 2) {
                        for (int b = -1; b <= 3; b = b + 1) {
                            if ((o + b) < 0 || (o + b) > maxLength - 1){
                                //empty lines cant be checked
                                continue;
                            }

                            if (!((wholeDoc[i + a][o + b] == '.') || isNumber(wholeDoc[i + a][o + b]) ||
                                  (wholeDoc[i + a][o + b] == '\n'))) {
                                //found symbol
                                sum += foundNumber;
                                break;
                            }
                        }
                    } else if (foundNumberExtraSize == 1) {
                        for (int b = -1; b <= 2; b = b + 1) {

                            if (!((wholeDoc[i + a][o + b] == '.') || isNumber(wholeDoc[i + a][o + b]) ||
                                  (wholeDoc[i + a][o + b] == '\n'))) {
                                //found symbol
                                sum += foundNumber;
                                break;
                            }
                        }
                    } else {
                        for (int b = -1; b <= 1; b = b + 1) {

                            if (!((wholeDoc[i + a][o + b] == '.') || isNumber(wholeDoc[i + a][o + b]) ||
                                  (wholeDoc[i + a][o + b] == '\n'))) {
                                //found symbol
                                sum += foundNumber;
                                break;
                            }
                        }
                    }

                    if (sum != tempSum){ //something was added
                        break;
                    }

                }
                o += foundNumberExtraSize;
            }
        }
        printf("\n\n");
    }

    printf("%s%d\n", "Sum of game: ",   sum);

    fclose(fptr);

    return 0;
}