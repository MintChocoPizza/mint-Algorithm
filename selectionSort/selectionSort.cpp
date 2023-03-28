// 선택 알고리즘
// 자리를 '선택' 하고 정렬되지 않은 '모든 데이터를 확인'하여
// 자리에 딱 맞는 데이터를 '선택'하여 자리에 넣음

// 가장 작은것을 제일 앞으로 swap하고, 그것을 n-1까지 반복한다.

// 장점: 자료의 크기에 따라 수행 시간이 일정함
// 단점: 매우 느림

#include <iostream>

#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

using namespace std;

int arr[8] = {9,1,6,8,4,3,2,0};

void selectionSort(int *list, int n)
{
    int i, j, indexMin, temp;
    for(i=0; i<n-1; i++)
    {
        indexMin = i;
        for(j=i+1; j<n; j++)
        {
            if(list[j] < list[indexMin])
            {
                indexMin = j;
            }
        }
        SWAP(list[i], list[indexMin], temp);
    }
}

int main()
{
    for(int i=0; i<8; i++)
        cout << arr[i] << ' ';
    cout << endl;

    selectionSort(arr, 8);

    for(int i=0; i<8; i++)
        cout << arr[i] << ' ';
    cout << endl;
}
