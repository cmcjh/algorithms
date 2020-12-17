#include<iostream>
#include<cstdlib>
using namespace std;

int a[100001]{}, n;
void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void qqs(int lb, int rb)
{
    int left = lb;
    int right = rb;
    if (left >= right)
        return;
   int pivot = rand() % (right - left + 1)+left;//我一开始忘记加left了
    swap(a[lb], a[pivot]);
    while (left < right)
    {
        while (a[right] >= a[lb] && left < right)
        {
            right--;//right先停，说明最终汇合点满足right的退出条件：a[right]<a[1b]，所以这个元素最终分配到base的左侧
        }
        while (a[left] <= a[lb] && left < right)
        {
            left++;
        }
        swap(a[left], (left == right) ? a[lb] : a[right]);
    }
    while ((left - 1)>=0 && (a[left - 1] == a[left]))//这是为了通过最后一个点优化的，因为最后一个测试点有很多重复数据
        left--;
    while ((right + 1) < rb && (a[right] == a[right + 1]))
        right++;
       
        qqs(lb, left - 1);
        qqs(right + 1, rb);
        return;
    
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    qqs(0, n - 1);
    for (int i = 0; i < n-1; i++)
        cout << a[i]<<" ";
    cout << a[n - 1];
    return 0;
}
