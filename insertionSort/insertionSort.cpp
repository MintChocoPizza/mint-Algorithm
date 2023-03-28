// 정렬되어 잇는 자신의 '앞'에 하나씩 비교를 하여 올바른 위치에 '삽입'

#include <cstring>
#include <iostream>

using namespace std;

int arr[6] = {3,7,2,5,1,4};

void insertionSort_1(int *list, int n)
{
    int i, j, remember;
    for(i=1; i<n; i++)
    {
        remember = list[(j=i)];
        while(--j>=0 && remember<list[j])
        {
            list[j+1] = list[j];
        }
        // --j 전위연산자를 사용하여 j+1이 올바른 위치
        list[j+1] = remember;
    }
}

// memcpy()를 사용하여 자료를 당겨 역순으로 수행된다.
void insertionSort_2(int *list, int n)
{
    int i, j, remember;
    i = n-1;
    while(i-- > 0)
    {
        remember = list[(j=i)];
        // j 를 올바른 위치로 옮긴다.
        while(++j<n && remember>list[j]);

        // --j 전위연산자를 사용하여 j+1이 올바른 위치
        // 위치 변화가 없으면 넘어감
        if(--j == i) continue;
        // i+1에서  i부터j만큼(j-i) 한칸 당겨서 remember가 들어갈 자리를 만듬 
        memcpy(list+i, list+i+1, sizeof(*list)*(j-i));
        list[j] = remember;
    }
}

int main()
{
    for(int i=0; i<6; i++)
        cout << arr[i] << ' ';
    cout << endl;

    insertionSort_2(arr, 6);
    
    for(int i=0; i<6; i++)
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}
