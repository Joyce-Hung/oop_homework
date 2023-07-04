#include <iostream>
//可使用'new int' allocator 配置新的記憶體空間

using namespace std;

int maximum(int *arr, int size)
{
    int max=0;
    max=*arr;
    for(int i=0;i<size;i++)
    {
        if(*(arr+i)>max)
        {
            max=*(arr+i);
        }
    }
    return max;
}

int *expand(int *arr, int size)
{
    size*=2;
    for(int i=0;i<size;i++)
    {
        if(i>(size/2-1))
        {
            *(arr+i)=-1;
        }
    }
    return arr;
}

int *concatenate(int *arr1, int *arr2, int size1, int size2)
{
    int len=size1+size2;
    int *ptr1=arr1;
    for(int i=0;i<len;i++)
    {
        if(i>=size1)
        {
            *(arr1+i)=*(arr2+i-size1);
        }
    }
    return ptr1;
}

int main()
{
    int size1, size2;
    cin >> size1 >> size2;
    int arr1[size1], arr2[size2], element;
    for (int i = 0; i < size1; i++)
    {
        cin >> element;
        arr1[i] = element;
    }
    for (int i = 0; i < size2; i++)
    {
        cin >> element;
        arr2[i] = element;
    }

    cout << maximum(arr1, size1) << endl;
    cout << maximum(arr2, size2) << endl;

    int *arr3 = expand(arr1, size1);
    for (int i = 0; i < size1 * 2; i++)
    {
        if (i < size1 * 2 - 1)
            cout << arr3[i] << " ";
        else
            cout << arr3[i];
    }
    cout << endl;

    int *arr4 = concatenate(arr1, arr2, size1, size2);
    for (int i = 0; i < size1 + size2; i++)
    {
        if (i < size1 + size2 - 1)
            cout << arr4[i] << " ";
        else
            cout << arr4[i];
    }
    cout << endl;
}