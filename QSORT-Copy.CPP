
  //Implementation of recursive Quick sort algorighm
  //Shiv Raj Pant

  #include <stdio.h>
  #include <conio.h>
  #include <stdlib.h>

  //#define n 100000

  void q_sort(int, int);
  int partitionn(int,int);
  int *a;

  int main()
   {
    int i,temp,n;
    //clrscr();
    FILE *fp1,*fp2;
    //int *a;

    if((fp1=fopen("data.txt","r"))!=NULL)
        printf("\ndata file data.txt opened successfully for reading\n");
    else
        printf("Error opening input data file");

    if((fp2=fopen("sorted-qsort.txt","w"))!=NULL)
        printf("\noutput file sorted-qsort.txt opened successfully in write mode\n");
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
    q_sort(0,n-1);
     printf("\nSorting complete!\n");

    printf("\nWriting sorted data to output file\n");

    for(i=0;i<n;i++)
     fprintf(fp2,"%d ",*(a+i));

    printf("\nThe sorted file saved 'sorted-qsort'\n");

    fclose(fp1);
    fclose(fp2);
    getch();
    return 0;
   }

  void q_sort(int l_hold, int r_hold)
   {
    int r;
    if(l_hold==r_hold)
        return;

    r= partitionn(l_hold,r_hold);

   if (r>l_hold)
    q_sort(l_hold, r-1);
   if (r<r_hold)
    q_sort(r+1,r_hold);
  }

  int partitionn(int l_hold, int r_hold)
  {
   int pivot, down, up;
    int temp;
    down=l_hold;
    up= r_hold;
    pivot = a[l_hold];
    while (down <= up)
     {

      while ((a[down] <= pivot)&&down<=up)
	  down++;

	  while (a[up] >= pivot&&down<=up)
       up--;

      if(down<up)
       {
        temp=a[down];
        a[down]=a[up];
        a[up]=temp;
      }
    }
   temp=a[l_hold];
   a[l_hold]=a[up];
   a[up]=temp;

   return up;
  }
