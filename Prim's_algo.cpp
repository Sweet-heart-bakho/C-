#include <iostream>
#include <vector>

using namespace std;

bool check(vector <int> choosen, int a)
{
    for (int i = 0; i < choosen.size(); i++)
        if (choosen[i] == a)
            return true;
    return false;
}
int back(vector <vector <int>> arr, vector <int> choosen, int min, int n)
{
    int back = 2;
    int min_n = choosen[0];
    while (n != choosen[0])
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[n][j] != 0 and arr[n][j] < min and check(choosen, j) == false)
            {
                min = arr[n][j];
                min_n = n;
            }
        }
        n = choosen[choosen.size() - back];
        back++;
    }
    return min_n;
}
int main()
{
    vector <vector <int>> arr(5, vector<int>(5));
    for (int i = 0; i < arr.size(); i++)
        for (int j = 0; j < arr.size(); j++)
            arr[i][j] = 0;
    arr[0][2] = arr[2][0] = 6;
    arr[0][4] = arr[4][0] = 3;
    arr[2][4] = arr[4][2] = 5;
    arr[1][4] = arr[4][1] = 7;
    arr[1][3] = arr[3][1] = 8;
    cout << " ";
    for (int i = 0; i < arr.size(); i++)
        cout << " " << i;
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << i;
        for (int j = 0; j < arr.size(); j++)
        {
            cout << "|";
            if (i == j)
                cout << "\\";
            else if (arr[i][j] == 0)
                cout << "_";
            else
                cout << arr[i][j];
        }
        cout << endl;
    }
    /*vector <char> letters = { 'A', 'B', 'C', 'D', 'F' };
    vector <vector <int>> graf(arr.size(), vector<int>(letters.size()));
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            arr[i][j] = 0;
    graf[0][0] = 1;
    graf[0][2] = 1;
    graf[1][4] = 1;
    graf[1][2] = -1;
    graf[2][0] = 1;
    graf[2][4] = -1;
    graf[3][4] = 1;
    graf[3][1] = 1;
    graf[4][3] = 1;
    graf[4][1] = -1;
    cout << endl;
    for (int i = 0; i < letters.size(); i++)
        cout << "  " << letters[i];
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << i;
        for (int j = 0; j < letters.size(); j++)
        {
            cout << "|";
            if (graf[i][j] == 0)
                cout << " 0";
            else if (graf[i][j] > 0)
                cout << " " << graf[i][j];
            else
                cout << graf[i][j];
        }
        cout << endl;
    }*/
    int n;
    int min = 99999;
    vector <int> choosen;
    cout << "Choose start: ";
    cin >> n;
    choosen.push_back(n);
    while (choosen.size() < arr.size())
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[n][j] != 0 and arr[n][j] < min and check(choosen, j) == false)
                min = arr[n][j];
        }
        if (min == 99999)
        {
            n = back(arr, choosen, min, n);
            cout << "Going back to: " << n << endl;
            continue;
        }
        cout << "Find min: " << min << endl;
        for (int j = 0; j < 5; j++)
        {
            if (min == arr[n][j])
            {
                min = 99999;
                n = j;
                choosen.push_back(n);
                cout << "Going to: " << j << endl;
            }
        }
    }
    return 0;
}

