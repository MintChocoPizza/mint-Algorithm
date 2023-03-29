// 삽입 정렬과 비슷함
// 가장 큰 값을 제일 뒤로 보냄
#include <iostream>

using namespace std;

int arr[10] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

void bubbleSort(int *list, int n)
{
    int i, j, temp;
    for(i=n-1; i>0; i--)
    {
        for(j=0; j<i; j++)
        {
            if(list[j] > list[j+1])
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

int main()
{
    int i, j;
    for(i=0; i<10; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    bubbleSort(arr, 10);

    for(i=0; i<10; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}
