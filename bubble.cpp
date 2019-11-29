  #include<stdio.h>
  #include<conio.h>
  #include<stdlib.h>


  int main()
    {
     int i,j,temp,n;
     int *a;
    FILE *fp1,*fp2;
    //int *a;

    if((fp1=fopen("data.txt","r"))!=NULL)
        printf("\ndata file data.txt opened successfully for reading\n");
    else
        printf("Error opening input data file");

    if((fp2=fopen("sorted-bubble.txt","w"))!=NULL)
        printf("\noutput file sorted-bubble.txt opened successfully in write mode\n");
    else
        printf("Error opening output file");

    i=1;

    fscanf(fp1,"%d",&temp);

    while(!feof(fp1))
    {
     fflush(stdin);
     fscanf(fp1,"%d",&temp);
     i++;
    }

    fclose(fp1);

    fp1=fopen("data.txt","r");

    n=i-1;

    a=(int *)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
    {
        fscanf(fp1,"%d",a+i);

    }
    //perform quick sort on array
    printf("\nsorting started....\n");

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


      printf("\nSorting complete!\n");

    printf("\nWriting sorted data to output file\n");

    for(i=0;i<n;i++)
     fprintf(fp2,"%d ",*(a+i));

    printf("\nThe sorted file saved 'sorted-bubble'\n");

    fclose(fp1);
    fclose(fp2);
    getch();
    return 0;
    }
