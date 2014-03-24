#include<omp.h>
#include<stdio.h>

void helloworld()
{
    #pragma omp parallel
        printf("\nthe thread id is %d\n",omp_get_thread_num());
}

void forloop()
{
    int i=0;
    #pragma omp parallel for schedule(static,2)
	for(i=0;i<16;i++)
		printf("\nthe thread id is %d\n",omp_get_thread_num());
}

void array()
{
    int i,a[]={1,2,3,4,5,6,7,8,9,0,10};
    int b[]={0,9,8,7,6,5,4,3,2,1,11};
    int c[11]={0};
    int mn[11];
    #pragma omp parallel for
    for(i=0;i<11;i++){
        c[i]=a[i]+b[i];
	mn[i]=omp_get_thread_num();
    }
    for(i=0;i<11;i++)
        printf("val i=%d %d + %d=%d  manipulation %d id =() for id %d\n",i,a[i],b[i],c[i],mn[i],omp_get_thread_num());
}
int main()
{
    omp_set_num_threads(4);
    //helloworld();
    //forloop();
    array();
    return 0;
}
