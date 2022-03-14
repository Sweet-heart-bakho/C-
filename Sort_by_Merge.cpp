#include <iostream>
#include <vector>
using namespace std;
vector <int> sliyanie(vector <int> v1, vector <int> v2, vector <int> v3)
{
    int i = 0; //v1
    int j = 0; //v2
    v3.clear();
    while (i + j < v1.size() + v2.size())
    {
        if (v1[i] > v2[j])
        {
            v3.push_back(v2[j]);
            j++;
        }
        else
        {
            v3.push_back(v1[i]);
            i++;
        }
        if (i >= v1.size())
            while (j < v2.size())
            {
                v3.push_back(v2[j]);
                j++;
            }
        if (j >= v2.size())
            while (i < v1.size())
            {
                v3.push_back(v1[i]);
                i++;
            }
    }
    return v3;
}
vector <int> help(vector <int> v, vector <int> iz, int n, int e)
{
    for (n; n < e; n++)
        v.push_back(iz[n]);
    return v;
}
vector <int> lomay(vector <int> arr)
{
    if (arr.size() < 3)
        return arr;
    vector <int> arr1 = help(arr1, arr, 0, arr.size() / 2);
    vector <int> arr2 = help(arr2, arr, arr.size() / 2, arr.size());
    arr1 = lomay(arr1);
    if (arr1.size() < 3)
        if (arr1[0] > arr1[arr1.size() - 1])
            swap(arr1[0], arr1[arr1.size() - 1]);
    if (arr2.size() < 3)
        if (arr2[0] > arr2[arr2.size() - 1])
            swap(arr2[0], arr2[arr2.size() - 1]);
    arr2 = lomay(arr2);
    arr = sliyanie(arr1, arr2, arr);
    return arr;
}
int main()
{
    int a;
    int n;
    vector <int> arr;
    cout << "Input array lenght: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    arr = lomay(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}

