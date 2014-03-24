#include<stdio.h>
int main() {
    int i,n;
    sacnf("%d",&n);
    for(i=1;(i*i)<=n;i++)
        if(n%i==0)
            printf("%d ",i);
    printf("%d",n);
    return 0;
}
