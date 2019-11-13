
  //Implementation of Insertion sort algorithm
  //Shiv Raj Pant


  #include<stdio.h>
  #include<conio.h>
  #include<stdlib.h>

  void main()
    {
     int i,n,temp,ptr;
     int k=0;
     int *a;
     clrscr();
     printf("\n  Enter the number of items to be sorted: ");
     scanf("%d",&n);
     a=(int *)malloc(2*(n+1));
     printf("\n  Enter the items: ");
     for(i=1;i<=n;i++)
      scanf("%d",a+i);

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

     printf("\n The sorted list: \n");
     for(i=1;i<=n;i++)
      printf(" %d",*(a+i));

    getch();
    }