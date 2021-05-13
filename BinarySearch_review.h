
int BinarySearch(int array[], int size, int value)
{
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		int middle = low + ((high - low) >> 1);
		if (array[middle]>value)
			high = middle - 1;
		else if (array[middle]<value)
			low = middle + 1;
		else
			return middle;
	}

	return -1;
}