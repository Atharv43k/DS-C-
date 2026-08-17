#include <iostream>
using namespace std;

int main()
{
    int i, j, min, temp;
    int arr[7];

    cout << "Enter array elements: ";

    for (i = 0; i < 7; i++)
    {
        cin >> arr[i];
    }

    for (i = 0; i < 6; i++)
    {
        min= i;

        for (j = i + 1; j < 7; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
   
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    cout<<"\nThe minimum element is:"<<arr[0]<<endl;
    
    cout << "\nSorted elements are: ";

    for (i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
