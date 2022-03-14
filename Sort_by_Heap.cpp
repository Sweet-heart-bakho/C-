#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <int> arr;
//a - down
//b - up
//              1[1]              0
//b       4[2]       9[3]         1
//a     5[4]   6    7   8          2

int print()
{
    int a = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (i >= pow(2, a))
        {
            cout << endl;
            a++;
        }
        cout << arr[i] << " ";
    }
    cout << endl;
    return a;
}
void check(int b, int a, int n)
{
    if (arr[b] < arr[a])
        swap(arr[b], arr[a]);
    if (a + 1 <= n and arr[b] < arr[a + 1])
        swap(arr[b], arr[a + 1]);
}
void kucha(int b, int a, int n)
{
    for (int i = a; i < n and i < pow(2, a); i = i + 2)
    {
        check(b, i, n);
        b++;
    }
}
int main()
{
    int a;
    int n;
    cout << "Input array lenght: ";
    cin >> n;
    arr.push_back(0);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    a = print(); a--;
    for (int j = n; j > 1; j--)
    {
        for (int i = 0; i < a; i++)
        {
            kucha(pow(2, a - 1 - i), pow(2, a - i), j);
            print();
        }
        swap(arr[1], arr[j]);
        cout << "placed " << arr[j] << endl;
        print();
    }
    for (int i = 1; i < arr.size(); i++)
        cout << arr[i] << " ";
}

