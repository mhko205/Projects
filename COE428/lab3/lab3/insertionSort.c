#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last)
{
       int i,j,key;
	  	for( j = first+1; j <= last; j++)
		{
		   myCopy(&array[j],&key);
		   i = j-1;
		   while( i >= 0 && (myCompare(array[i],key)>0))
		   {
				
				myCopy(&array[i],&array[i+1]);
				i = i - 1;
		    }	
		   myCopy(&key,&array[i+1]);
        }
}
