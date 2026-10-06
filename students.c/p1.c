#include <stdio.h>

int main()
{
    int n, i;
    char name[50][50];

    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("Enter the names of %d students:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%s", name[i]);
    }
    printf("Enter n");
    scanf("%d",&n);
    printf("\nFirst %d students are:\n", n);

    for(i = 0; i < n; i++)
    {
        printf("%s\n", name[i]);
    }

    return 0;
}