#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 20
#define MAX_LEN 11

int compare(const void* a, const void* b) {
    char ab[MAX_LEN * 2];
    char ba[MAX_LEN * 2];
    
    strcpy(ab, *(const char**)a);
    strcat(ab, *(const char**)b);
    
    strcpy(ba, *(const char**)b);
    strcat(ba, *(const char**)a);
    
    return strcmp(ba, ab);
}

int main() {
    int n;
    scanf("%d", &n);
    
    char* nums[MAX_N];
    char result[MAX_N * MAX_LEN];
    
    for (int i = 0; i < n; i++) {
        nums[i] = (char*)malloc(MAX_LEN * sizeof(char));
        scanf("%s", nums[i]);
    }
    
    qsort(nums, n, sizeof(char*), compare);
    
    result[0] = '\0';
    for (int i = 0; i < n; i++) {
        strcat(result, nums[i]);
        free(nums[i]);
    }
    
    printf("%s\n", result);
    
    return 0;
}