#include <stdio.h>
void reverse_string(char *p)
{
    if(*p)
    {
        reverse_string(p+1);
        printf("%c",*p);
    }
    
}
int main()
{
    char arr[10]="string";
    
    reverse_string(arr);
    
}