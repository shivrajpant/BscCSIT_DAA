
  //Implementation of Insertion sort algorithm
  //Shiv Raj Pant

  
  #include<stdio.h>
  #include<conio.h>
  #include<stdlib.h>

  #define n 10000
  int main()
    {
     int i,temp,ptr;
	FILE *fp,*fp2;
     int k=0;
     int *a;
     clrscr();
     
	
     
	fp=fopen("D:\\BscCSIT_DAA-master\\data.txt","r");

    fp2=fopen("D:\\BscCSIT_DAA-master\\sorted_insert.txt","w");
	
	a=(int *)malloc(2*(n+1));
     
	
     for(i=1;i<=n;i++)
      fscanf(fp,"%d",a+i);

     *(a+0)=-32565;
     for(k=2;k<=n+1;k++)
      {
       temp=*(a+k);
       ptr=k-1;
       while(temp<*(a+ptr))
	{
	 *(a+(ptr+1))=*(a+ptr);
	 ptr--;
	}
       *(a+(ptr+1))=temp;
      }

     

     for(i=1;i<=n+1;i++)
      fprintf(fp2,"%d ",*(a+i));

    printf("\n Sorting finished. The sorted list is written to file sorted_insert.txt\n");

    fclose(fp);
    fclose(fp2);
    getch();
    return 0;
    }