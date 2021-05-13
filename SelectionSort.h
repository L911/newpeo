
template<typename T>
void SelectionSort(T array[], int n)
{
	int i, j, minIdx;

	for (i = 0; i < n; i ++)
	{
		minIdx = i;
		for (j = i + 1; j < n; j ++)
		{
			if (array[j]< array[minIdx])
				minIdx = j;
		}

		T temp = array[i];
		array[i] = array[minIdx];
		array[minIdx] = temp;
	}
}