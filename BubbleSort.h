
template<typename T>
void BubbleSort(T* array, int n)
{
    for (int i = 0;i < n; i ++)
    {
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                T temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;

                flag = true;
            }
        }

        if (!flag)
            break;
    }
}