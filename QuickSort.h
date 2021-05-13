#pragma once

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = *a;
}

int Partition(int* array, int p, int r)
{
	int pivot = array[r];
	int i = p;
	int j = p;
	for (; j < r; j ++)
	{
		if (array[j]<pivot)
		{
			Swap(array + i, array + j);
			i ++;
		}
	}

	Swap(array + i, array + r);

	return i;
}

void Quick_Sort(int array[], int p, int r)
{
	if (p >= r)
		return;

	int i = Partition(array, p, r);
	Quick_Sort(array, p, i - 1);
	Quick_Sort(array, i + 1, r);
}