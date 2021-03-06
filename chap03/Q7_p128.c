#include <stdio.h>
#include <stdlib.h>

//---function to compare integers(ascending)---//
int int_cmp(const int *a, const int *b)
{
    if (*a < *b)
        return -1;
    else if(*a > *b)
        return 1;
    else
        return 0;
}

void *seqsearch(const void *key, const void *base, size_t nmemb, size_t size, 
    int(*compar)(const void *, const void *))
{
    int n = nmemb;
    int i;
    for(i = 0; i < n; i++) {
        if (((int *)base)[i] == *(int *)key) {
            return &((int *)base)[i];
        }
    }
    return NULL;
}

int main(void)
{
    int i, nx, ky;
    int *x;
    int *p;
    puts("Search by using bsearch function");
    printf("number of elements: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    printf("Enter in ascending order.\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);
    for(i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while(x[i] < x[i - 1]);
    }
    printf("searching value: ");
    scanf("%d", &ky);

    //using bsearch
    p = seqsearch(&ky,
                x,
                nx,
                sizeof(int),
                (int(*)(const void *, const void *)) int_cmp
                );
    
    if (p == NULL)
        puts("Failed to search.");
    else 
        printf("%d is in x[%d].\n", ky, (int) (p - x));
    free(x);

    return 0;
}