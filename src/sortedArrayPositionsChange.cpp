/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int i, pos = -1, p, j = 0, pos1 = -1, t, flag1 = 0, flag2 = 0;
	if (len>1 && Arr != NULL)
	{
		for (i = 0; i < len - 1; i++)
		{
			if (i == 0)
			{
				if (Arr[i]>Arr[i + 1])
				{
					pos = i;
					flag1 = 1;
					break;
				}
			}
			else
			{
				if (!((Arr[i] < Arr[i + 1]) && (Arr[i] > Arr[i - 1])))
				{
					pos = i;
					flag1 = 1;
					break;
				}
			}
		}
		p = Arr[pos];
		for (i = len - 1; i > pos; i--)
		{
			if (!(Arr[i] > Arr[i - 1]))
			{
				pos1 = i;
				flag2 = 1;
				break;
			}

		}
		if (flag1 == 1 && flag2 == 1)
		{
			t = Arr[pos];
			Arr[pos] = Arr[pos1];
			Arr[pos1] = t;
		}
		return Arr;
	}
	else
	{
		return NULL;
	}
}