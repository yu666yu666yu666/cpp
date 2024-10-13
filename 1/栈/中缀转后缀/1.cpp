#include <stdio.h>
#include <string.h>
int main() {
    
    char arr[10001] = {0};
    int str[4] = {0};
    scanf("%s", &arr);
    int len = strlen(arr);
    int i = 0;
    for (i = 0; i < len; i++) {
        if (arr[i] == 'G' || arr[i] == 'g')
            str[0]++;
        else if (arr[i] == 'P' || arr[i] == 'p')
            str[1]++;
        else if (arr[i] == 'L' || arr[i] == 'l')
            str[2]++;
        else if (arr[i] == 'T' || arr[i] == 't')
            str[3]++;
    }
    while (str[0] + str[1] + str[2] + str[3]) {
        if (str[0] > 0) {
            printf("G");
            str[0]--;
        }
        if (str[1] > 0) {
            printf("P");
            str[1]--;
        }
        if (str[2] > 0) {
            printf("L");
            str[2]--;
        }
        if (str[3] > 0) {
            printf("T");
            str[3]--;
        }
    }

    return 0;
}