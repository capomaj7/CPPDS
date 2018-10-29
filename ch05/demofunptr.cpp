// 例子关于指针函数，指针函数做为形参的
// 指针函数作为形参用不同的规则使之更加通用
#include <iostream>
#include<string.h>
using namespace std;
template <class T> //使用函数模板
void sort(T a[], int size, bool (*f)(T, T))
{
    bool flag; //用于冒泡中提前结束冒泡
    int i, j;
    for (i = 1; i < size; ++i)
    {
        flag = false;
        for (j = 0; j < size - i; ++j)
            if (f(a[j + 1], a[j])) //用函数f(T,T)来表示排序规则
            {
                T tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                flag = true;
            }
        if (!flag)
            break;
    }
}
//排序规则
bool decreaseInt(int x, int y) { return y < x; }
bool increaseString(char *x, char *y) { return strcmp(x, y) < 0; }
int main()
{
    int a[] = {3, 1, 4, 2, 5, 8, 6, 7, 0, 9}, i;
    char *b[] = {"aaa", "bbb", "fff", "ttt", "hhh", "ddd", "ggg", "www", "rrr", "vvv"};
    sort(a, 10, decreaseInt);
    for (i = 0; i < 10; ++i)
        cout << a[i] << "\t";
    cout << endl;
    sort(b, 10, increaseString);
    for (i = 0; i < 10; ++i)
        cout << b[i] << "\t";
    cout << endl;
    return 0;
}
