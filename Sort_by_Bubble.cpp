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
  {
    for (int j = 0; j < arr.size() - 1 - i; j++)
    {
      check = true;
      cout << arr[j] << " " << arr[j+1] << endl;
      if (arr[j] > arr[j+1])  //если 1 элемент больше 2
      {
        check = false;
      swap(arr[j], arr[j+1]);
      }
    }
    if (check == true)
    break;
  }
  for (int i = 0; i < arr.size(); i++)
  cout << arr[i] << " ";
  return 0;
}

