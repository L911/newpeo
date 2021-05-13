

void Merge(int* array, int p1, int r1, int p2, int r2)
{
    int size = (r1 - p1 + 1) + (r2 - p2 + 2);
    int *temp = new int[size];

    int k = 0;
    int i = p1;
    int j = p2;

    while(i <= r1 && j <= r2)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    int start = i;
    int end = r1;
    if (start >= end)
    {
        start = j;
        end = r2;
    }

    for (; start <= end; start++)
        temp[k++] = array[start];

    for (i = 0; i < size; i ++)
        array[p1 + i] = temp[i];
}


void Merger_Sort(int array[], int p, int r)
{
    if (p >= r)
        return;

    int middle = (p + r) / 2;
    Merger_Sort(array, p, middle);
    Merger_Sort(array, middle + 1, r);

    Merge(array, p, middle, middle + 1, r);
}