#include <iostream>
#include <vector>

using namespace std;

int division(vector<int>& list, int left, int right)
{
    int base = list[left];
    while (left < right)
    {
        while (left<right && list[right]>base)
            right--;
        list[left] = list[right];

        while (left < right && list[left] <= base)
            left++;
        list[right] = list[left];
    }
    list[right] = base;
    return left;
}

void quicksort(vector<int>& list, int left, int right)
{
    if (left < right)//函数递归本身在循环，这里不能用while，而要用if。只是效果可以类比while
    //大概递归函数都要做这种事情，才能懂得什么时候停下来。或者用return。
    {
        int cut = division(list, left, right);
        quicksort(list, left, cut - 1);
        quicksort(list, cut + 1, right);
    }
}


int main()
{
    int b[10000]{};
    int temp;
    int count = 0;
    while (cin>>temp)
    {
        b[count] = temp;
        count += 1;
    }
    vector<int>list(b, b+count);//注意这里没有减一，因为vector的定义是左闭右开的
    quicksort(list, 0, count-1);//这里要减一，因为这里是闭的
    for (int i = 0; i < count; i++)
        cout << list[i]<<endl;
    
    return 0;

}
