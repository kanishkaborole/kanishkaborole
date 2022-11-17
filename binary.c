#include<stdio.h>
int binsearch(int a[20],int i,int j,int key);
void main(int argc,char *argv[],char *envp[])
	{
		  int i,n,key,result;
		  int a[20];
		  for(i=0;i<argc;i++)
		    a[i]=atoi(argv[i]);
		  printf("\nWe are in the binary search now : \n");
		  printf("\n PID=%d\n", getpid());
		  printf("\nEnter the element to be search : \n");
		  scanf("%d",&key);
		  result=binsearch(a,0,argc-1,key);
		  if(result==-1)
		    printf("\n\nELEMENT NOT FOUND\n");
		  else
		    printf("\n\nELEMENT FOUND AT LOCATION %d\n",result+1);
		  printf("\n");
	}


int binsearch(int a[20],int i,int j,int key)
	{
	  int mid;
	  if(i<=j)
	  {
	    mid=(i+j)/2;
	    if(key==a[mid])
	      return mid;
	    else
	      if(key>a[mid])
		return binsearch(a,mid+1,j,key);
	      else
		return binsearch(a,i,mid,key);
	  }
	    else
	    return -1;
	}
