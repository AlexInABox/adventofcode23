#include <stdio.h>
#include <string.h>

int isDigit(int a){
    if (a-48 < 10 && a-48 >= 0){
        return 1;
    }
    return 0;
}

int main() {
    FILE *fptr = fopen("../day1/input.txt", "r");
    if (fptr == NULL) {
        printf("Not able to open the file.\n");
        return 1;
    }
    int sum = 0;
    int lastNumber = 0;

    while (!feof(fptr)) {
        int cleaned[100];
        int combinedNumber;
        char s[100];
        fgets(s, 100, fptr); //read the line and jump cursor to next
        printf("%s\n", s);

        //remove any chars from array
        int o = 0;
        for (int i = 0; i < 100; i++) {
            if (s[i] == '\n'){
                break;
            }
            if (isDigit(s[i])) {
                cleaned[o] = s[i] - 48;
                o++;
            }
        }
        combinedNumber = (cleaned[0] * 10) + cleaned[o-1];
        printf("%d", combinedNumber);
        sum += combinedNumber;
        lastNumber = combinedNumber;
        printf("\n");

        //printf("%s", cleaned);

    }

    printf("%d", sum - lastNumber);

    fclose(fptr);


    return 0;
}