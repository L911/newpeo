
template<typename T>
void InsertSort(T* array, int n)
{
    for (int i = 1; i < n; i ++)
    {
        int j = i-1;
        T value = array[i];
        for(; j >=0; j--)
        {
            if (array[j] > value)
            {
                array[j + 1] = array[j];
            }
            else
            {
                break;
            }
        }

        array[j+1] = value;
    }
}
