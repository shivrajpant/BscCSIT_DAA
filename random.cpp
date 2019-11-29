#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(void)
{

int i,a;
FILE *fp;

if((fp=fopen("data.txt","w"))==NULL)
	{
	 printf("could not open file");
	 return -1;
	}
else
   {
	for(i=0;i<10000000;i++)
		{
		  a=rand();
		  fprintf(fp,"%d ",a);
		}

    fclose(fp);
    printf("Data written to file");
  }
getch();
return 0;
}
