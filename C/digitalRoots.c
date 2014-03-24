#include<stdio.h>

int main() {
    int copy,no;
    scanf("%d",&copy);
    do
    {
        no=0;
        do
            no+=(copy%10);
        while(copy/=10);
        copy=no;
    }while(no>9);
    printf("%d",no);
    return 0;
}
