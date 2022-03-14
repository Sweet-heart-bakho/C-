#include <iostream>
#include <vector>
using namespace std;

vector <int> arr;

void shell(int n, int begin, int end)
{
    while (begin + end < arr.size())
    {
        cout << arr[begin] << " > " << arr[begin + end] << endl;
        if (arr[begin] > arr[begin + end])
            swap(arr[begin], arr[begin + end]);
        begin++;
    }
    if (n % 2 != 0)
    cout << endl;
    if (n == 1)
    {
        return;
    }
    shell(n / 2, 0, n / 2);
}

int main()
{
    bool check = true;
    int n;
    int a;
    cout << "Input your Massive lenght: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "[" << i << "] ";
        cin >> a;
        arr.push_back(a);
    }
    a = 0;
    if (n % 2 != 0)
        a = 1;
    shell(n / 2, 0, n / 2);
    shell(1, 0, 1);
    if (a and arr[0] > arr[1])
        swap(arr[0], arr[1]);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}
