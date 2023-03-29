# Insertion Sort

## 간단한 개념
* 정렬되어 있는 자신의 앞에 하나씩 비교를 하여 올바른 위치에 '삽입'<br/>
![img](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)

### 구현 1
* '삽입' 공간을 만들기 위하여 한칸씩 뒤로 밀리고 있다.
```c++
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
```

### 구현 2
* memcpy()를 사용하여 i+1부터 j까지 한번에 당겨 '삽입' 공간을 만들고 있다.
```c++
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
```
