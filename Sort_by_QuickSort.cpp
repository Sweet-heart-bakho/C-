#include <iostream>
#include <vector>
using namespace std;
vector <int> arr;
void print(int begin, int end)
{
    for (int i = begin; i < end; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void fast_lomay(int begin, int end)
{
    int first = begin;
    int last = end;
    int mid = (first + last) / 2;
    do
    {
        while (arr[first] < arr[mid])
            first++;
        while (arr[last] > arr[mid])
            last--;
        swap(arr[first], arr[last]);
        first++;
        last--;
        print(begin, end);
    } while (first < last);
    if (begin < last)
        fast_lomay(begin, last);
    if (first < end)
        fast_lomay(first, end);
}
int main()
{
    int a;
    int n;
    cout << "Input array lenght: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    print(0, n);
    fast_lomay(0, n - 1);
    print(0, n);
    return 0;
}
