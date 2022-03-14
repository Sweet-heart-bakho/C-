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
  for (int i = 0; i < arr.size(); i++)
  {
    n = arr[i];
    for (int j = i; j < arr.size(); j++)
    {
      if (arr[n] > arr[j])
      n = j;
    }
    swap(arr[n], arr[i]);
  }
  for (int i = 0; i < arr.size(); i++)
  cout << arr[i] << " ";
  return 0;
}

