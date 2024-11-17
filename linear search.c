#include <stdio.h>
#include <stdlib.h>
#include<time.h>
 
void main()
{
int numerator=0;
int denominator = 0;
    srand(time(0));

for (int s=0 ; s<20 ; s++)
{


int sizeofarray= rand()%30+1;


int array[sizeofarray];

for(int i = 0; i<sizeofarray; i++)
        array[i] = rand()%100+1;




int randomnumber = rand()%sizeofarray+1;
int searchx = array[randomnumber-1];

for (int c = 0 ; c < sizeofarray ; c++)
  {
    if (array[c] == searchx)
    {
      printf("size of array is %d and no of comparisons is %d.\n", sizeofarray , c+1);
      numerator = numerator + (sizeofarray)*(c+1);
      denominator = denominator  +  sizeofarray ; 
      break;
    }

}


}



printf("weighted average = %f\n",(float)numerator/denominator);



}
