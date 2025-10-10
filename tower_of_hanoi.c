#include <stdio.h>

void towerOfHanoi(int n, char src, char aux, char des)
{
    if (n == 1)
    {
        printf("Disk moved form %c to %c \n", src, des);
        return;
    }

    towerOfHanoi(n - 1, src, aux, des);
    printf("Disk moved form %c to %c \n", src, aux);
    towerOfHanoi(n - 1, aux, des, src);
}

int main()
{

    int disk = 1;
    char src = 'A';
    char aux = 'B';
    char des = 'C';

    printf("Enter number of disks: ");
    scanf("%d", &disk);

    towerOfHanoi(disk, src, aux, des);
}