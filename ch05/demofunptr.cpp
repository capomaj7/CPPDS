// ���ӹ���ָ�뺯����ָ�뺯����Ϊ�βε�
// ָ�뺯����Ϊ�β��ò�ͬ�Ĺ���ʹ֮����ͨ��
#include <iostream>
#include<string.h>
using namespace std;
template <class T> //ʹ�ú���ģ��
void sort(T a[], int size, bool (*f)(T, T))
{
    bool flag; //����ð������ǰ����ð��
    int i, j;
    for (i = 1; i < size; ++i)
    {
        flag = false;
        for (j = 0; j < size - i; ++j)
            if (f(a[j + 1], a[j])) //�ú���f(T,T)����ʾ�������
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
//�������
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
