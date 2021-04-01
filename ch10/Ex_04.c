#include <stdio.h>


void printArrayValues(int value[], int size)
{
	for(int i = 0; i < size; i++)
	{
		if(sizeof(value[i]) == sizeof(int))
		{
			printf("The Value is %d \n",value[i]);
		}
		else
		{
			printArrayValues(&value[i], sizeof(value[i]/sizeof(int)));
		}
	}

}


void main()
{
	int value[] = { 1, 2, 3,{4, 5, 6}, 7,\
		      {8, {9, 10, 11,
				  {12, 13, 14}
			  }
		      },
	    {15, 16, 17, 18, 19,
		    {20, 21, 22,
			    {23, 24, 25,
				    {26, 27, 29}
			    }, 30, 31
		    }, 32
	    }, 33
	}

}
