#include <iostream>
#include <vector>
using namespace std;

int main()
{
    bool check = true;
    int n;
    int a;
    vector <int> arr;
    cout << "Input your Massive lenght: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "[" << i << "] ";
        cin >> a;
        arr.push_back(a);
    }
    for (int i = 0; i < arr.size() - 1; i++)
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            for (int j = i; j > 0; j--)
                if (arr[j] < arr[j - 1])
                    swap(arr[j], arr[j - 1]);
        }
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}
