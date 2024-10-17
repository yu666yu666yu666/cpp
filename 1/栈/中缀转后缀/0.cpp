#include <stdio.h>
#include <math.h>
int main() {
    
    int m, k, num = 0, r = 0, a[10] = {0}, sum = 0;
    scanf("%d %d", &m, &k);
    while (1) {
        r = 0;
        for (int i = 2; i <= pow(m, 0.5); i++)
            if (m % i == 0)
                r = 1;
        if (r == 0) {
            a[num] = m;
            num++;
        }
        if (num >= k)
            break;
        if (m == 2)
            break;
        m--;
    }
    for (int i = 0; i < num - 1; i++) {
        sum += a[i];
        printf("%d+", a[i]);
    }
    sum += a[num - 1];
    printf("%d=%d", a[num - 1], sum);

    return 0;
}