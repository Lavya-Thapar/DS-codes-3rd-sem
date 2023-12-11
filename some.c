#include <stdio.h>
#include <string.h>
int main()
{
    char arr1[20]="abc";
    char arr2[20]="def";
    strcat(arr1,arr2);
    printf("%s",arr1);
}