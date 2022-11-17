#include<stdio.h>
#include<unistd.h>
void mergesort(int a[10],int i,int j);
void merge(int a[10],int l,int m,int h);
void main()
{
  int i,n;
  int a[10];
  char *array[20],str[20];
  printf("\nEnter number of elements to be sort : ");
  scanf("%d",&n);
  printf("\nEnter elements : ");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  mergesort(a,0,n-1);
  printf("\nSorted elements : ");
  for(i=0;i<n;i++)
  printf("%d ",a[i]);
  printf("\n");
  for(i=0;i<n;i++)
  {
    snprintf(str,20,"%d",a[i]);
    array[i]=strdup(str);
  }
  array[i]=NULL;
  execve("binary",array,NULL);
}
void mergesort(int a[10],int i,int j)
{
  int m;
  if(i<j)
  {
    m=(i+j)/2;
    mergesort(a,i,m);
    mergesort(a,m+1,j);
    merge(a,i,m,j);
  }
}
void merge(int a[10],int l,int m,int h)
{
  int k=l,i=l,j=m+1;
  int c[10];
  while(i<=m && j<=h)
  {
    if(a[i]<a[j])
      c[k++]=a[i++];
    else
      c[k++]=a[j++];
  }
  while(j<=h)
    c[k++]=a[j++];
  while(i<=m)
    c[k++]=a[i++];
  for(i=l,k=l;i<=h;i++,k++)
    a[i]=c[k];
}
