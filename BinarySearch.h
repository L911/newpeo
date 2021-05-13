#pragma once

int BinarySearch_loop(int array[], int length, int value)
{
	int low = 0;
	int high = length - 1;

	while (low <= high)
	{
		int middle = low + ( ( high - low ) >> 1 );
		if (array[middle] == value)
		{
			return middle;
		}
		else if (array[middle] > value)
		{
			high = middle - 1;
		}
		else
		{
			low = middle + 1;
		}
	}

	return -1;
}

int BinarySearch_recursion(int array[], int low, int high, int value)
{
	int middle = low + ((high - low) >> 1);
	if (array[middle] == value)
	{
		return middle;
	}
	else if (array[middle] > value)
	{
		high = middle - 1;
		return BinarySearch_recursion(array, low, high, value);
	}
	else
	{
		low = middle + 1;
		return BinarySearch_recursion(array, low, high, value);
	}

	return -1;
}

int BinarySearch(int array[], int length, int value)
{
	int low = 0;
	int high = length - 1;
	return BinarySearch_recursion(array, low, high, value);
}


// 第一个出现
int BinarySearchFirst(int array[], int length, int value)
{
	int low = 0;
	int high = length - 1;

	while(low<=high)
	{
		int middle = low + ((high - low) >> 1);
		if (array[middle]>value)
		{
			high = middle - 1;
		}
		else if (array[middle]<value)
		{
			low = middle + 1;
		}
		else
		{
			if (middle == 0 || array[middle - 1] != value)
				return middle;
			else
				high = middle - 1;
		}
	}

	return -1;
}

// 最后一个出现
int BinarySearchLast(int array[], int length, int value)
{
	int low = 0;
	int high = length - 1;

	while(low<=high)
	{
		int middle = low + ((high - low) >> 1);
		if (array[middle]>value)
		{
			high = middle - 1;
		}
		else if (array[middle]<value)
		{
			low = middle + 1;
		}
		else
		{
			if (middle == length - 1 || array[middle + 1] != value)
				return middle;
			else
				low = middle + 1;
		}
	}

	return -1;
}

// 第一个大于等于的
int BinarySearchLast(int array[], int length, int value)
{
	int low = 0;
	int high = length - 1;

	while(low<=high)
	{
		int middle = low + ((high - low) >> 1);
		if (array[middle]>=value)
		{
			if (middle == 0 || array[middle-1] < value)
				return middle;
			else
				high = middle - 1;
		}
		else
		{
			low = middle + 1;
		}
	}

	return -1;
}

// 最后一个小于等于的
int BinarySearchLast(int array[], int length, int value)
{
	int low = 0;
	int high = length - 1;

	while(low<=high)
	{
		int middle = low + ((high - low) >> 1);
		if (array[middle]>value)
		{
			low = middle + 1;
		}
		else
		{
			if (middle == length - 1 || array[middle + 1] > value)
				return middle;
			else
				low = middle + 1;
		}
	}

	return -1;
}