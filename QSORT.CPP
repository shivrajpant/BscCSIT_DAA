
  //Implementation of recursive Quick sort algorighm
  //Shiv Raj Pant

  #include <stdio.h>
  #include <conio.h>
  #define N 10

  void q_sort(int numbers[], int down, int up);
  int numlist[N];

  void main()
   {
    int i;
    clrscr();

    printf("Enter the 10 numbers to sort:");
    for (i = 0; i < N; i++)
    scanf("%d",&numlist[i]);
    //perform quick sort on array
    q_sort(numlist,0,N-1);
    printf("List after sorting:\n");

    for (i = 0; i < N; i++)
       printf("%4d", numlist[i]);

    getch();
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
