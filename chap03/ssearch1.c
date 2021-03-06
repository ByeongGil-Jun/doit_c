#include <stdio.h>
#include <stdlib.h>

// linear search for elements matching keys 
// in array a with n number of elements.
int search(const int a[], int n, int key)
{
    int i = 0;
    while(1) {
        if(i == n)
            return -1;
        if(a[i] == key)
            return i;
        i++;
    }
}

int main(void)
{
    int i, nx, ky, idx;
    int *x;
    puts("linear search");
    printf("number of elements: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for(i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("searching value: ");
    scanf("%d", &ky);
    idx = search(x, nx, ky);
    if(idx == -1)
        puts("failed to search");
    else   
        printf("%d is in x[%d].\n", ky, idx);
    free(x);

    return 0;
}