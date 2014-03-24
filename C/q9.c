/*Program 9
Design, develop, and execute a program in C to read a sparse matrix of integer values and to search the sparse matrix for an element specified by the user. Print the result of the search appropriately. Use the triple <row, column, value> to represent an element in the sparse matrix.
*/

#include<stdio.h>

typedef struct{
  int row,col,value;
}smatrix;

int main(){
  smatrix m[10];
  int i,n,key;
  printf("enter the no of elements\n");
  scanf("%d",&n);
  printf("enter the elements of the sparse matrix in triple<row, column, value> \n");
  for(i=0;i<n;i++)
    scanf("%d%d%d",&m[i].row,&m[i].col,&m[i].value);
  printf("enter the key element\n");
  scanf("%d",&key);
  for (i=0;i<n;i++)
    if(m[i].value==key){
      printf("\nElement found\nrow=%d\tcol=%d\tvalue=%d\n",m[i].row, m[i].col,m[i].value);
      return 0;
    }
  printf("the key element not found");
}