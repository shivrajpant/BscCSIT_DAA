
  //Implementation of recursive Quick sort algorighm
  //Shiv Raj Pant

  #include <stdio.h>
  #include <conio.h>
  #include <stdlib.h>

  #define N 100000

  void q_sort(int numbers[], int down, int up);
  int numlist[N];

  int main()
   {
    int i;
    clrscr();
    FILE *fp1,*fp2;

    fp1=fopen("D:\\BscCSIT_DAA-master\\data.txt","r");
    fp2=fopen("D:\\BscCSIT_DAA-master\\sorted-qsort.txt","w");

    for (i = 0; i < N; i++)
    	fscanf(fp1,"%d",&numlist[i]);
    //perform quick sort on array
    q_sort(numlist,0,N-1);
    printf("Sorting complete. The sorted file saved 'sorted-qsort'\n");

    for (i = 0; i < N; i++)
       fprintf(fp2,"%d ", numlist[i]);

    fclose(fp1);
    fclose(fp2);
    getch();
    return 0;
   }

  void q_sort(int numlist[], int down, int up)
   {
    int pivot, l_hold, r_hold;

    l_hold = down;
    r_hold = up;
    pivot = numlist[down];
    while (down < up)
     {
      while ((numlist[up] >= pivot) && (down < up))
       up--;
      if (down != up)
       {
	numlist[down] = numlist[up];
	down++;
       }
      while ((numlist[down] <= pivot) && (down < up))
	down++;
      if (down != up)
       {
	numlist[up] = numlist[down];
	up--;
       }
     }
   numlist[down] = pivot;
   pivot = down;
   down = l_hold;
   up = r_hold;
   if (down < pivot)
    q_sort(numlist, down, pivot-1);
   if (up > pivot)
    q_sort(numlist, pivot+1, up);
  }
