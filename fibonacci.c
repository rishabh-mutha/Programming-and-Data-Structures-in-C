    #include<stdio.h>
    
     
    void main()
    {
       int n, i = 0, c;
     
   printf("enter  no of elements in Fibonacci series\n");  
       scanf("%d",&n);
     
       printf("Fibonacci series\n");
     
       for ( c = 1 ; c <= n ; c++ )
       {
          printf("%d\n", Fibonacci(i));
          i++; 
       }
     
       
    }
     
    int Fibonacci(int n)
    {
       if ( n == 0 )
          return 0;
       else if ( n == 1 )
          return 1;
       else
          return ( Fibonacci(n-1) + Fibonacci(n-2) );
    } 
