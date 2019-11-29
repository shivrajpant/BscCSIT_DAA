  #include<stdio.h>
  #include<conio.h>
  #include<stdlib.h>

  #define n 10

  int main()
    {
     int i,j,temp;
	 FILE *fp,*fp2;
     int *a;
     //clrscr();


	 fp=fopen("D:\\teaching_2076\\DAA\\BscCSIT_DAA-master\\data.txt","r");

     fp2=fopen("D:\\teaching_2076\\DAA\\BscCSIT_DAA-master\\sorted_bubble.txt","w");

	 a=(int *)malloc(sizeof(int)*n);


     for(i=0;i<n;i++)
      fscanf(fp,"%d",a+i);

     for(i=0;i<n-1;i++)
      {
         for (j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
	  }


     for(i=0;i<n;i++)
      fprintf(fp2,"%d ",*(a+i));

    printf("\n Sorting finished. The sorted list is written to file sorted_bubble.txt\n");

    fclose(fp);
    fclose(fp2);
    getch();
    return 0;
    }
