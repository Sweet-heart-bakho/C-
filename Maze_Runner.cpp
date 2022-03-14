#include <iostream>
#include <vector>
using namespace std;

vector <int> maze;
vector <int> way;
vector <int> newe;
int n, m;
int ex, ey;
int ax, ay;
bool win = false;
void move();
bool printh(int i, int j);

void print()
{
    cout << " ";
    for (int i = 0; i < n; i++)
        cout << "#";
    cout << "  x" <<endl;
    for (int i = 0; i < m; i++)
    {
        cout << "#";
        for (int j = 0; j < n; j++)
        {
            if (printh(i, j) == true)
                continue;
            else
                cout << " ";
        }
        cout << "#" << endl;
    }
    cout << " ";
    for (int i = 0; i < n; i++)
        cout << "#";
    cout << endl << "y" << endl;
}
bool printh(int i, int j)
{
    if (j == ax and i == ay)
    {
        cout << "@";
        return true;
    }
    else if (j == ex and i == ey)
    {
        cout << "X";
        return true;
    }
    for (int l = 0; l < way.size(); l = l + 2)
        if (way[l] == j and way[l + 1] == i)
        {
            cout << "*";
            return true;
        }
    for (int l = 0; l < maze.size(); l = l + 2)
        if (maze[l] == j and maze[l + 1] == i)
        {
            cout << "#";
            return true;
        }
    return false;
}
void create()
{
    cout << "Input walls coordinates\n";
    cout << "If you entered coordinates where there is already a wall, then this wall will be deleted\n";
    cout << "Enter (-1) to complete input\n";
    bool c = true;
    int x = 0;
    int y = 0;
    maze.push_back(n + 1);
    maze.push_back(m + 1);
    print();
    while (x != -1)
    {
        cout << "x: ";
        cin >> x;
        if (x != -1)
        {
            cout << "y: ";
            cin >> y;
            if (x >= n or y >= m or x < 0 or y < 0)
            {
                cout << "Invalid\n";
                c = false;
            }
            else for (int i = 0; i < maze.size(); i = i + 2)
                if (maze[i] == x and maze[i + 1] == y)
                {
                    maze.erase(maze.begin() + i);
                    maze.erase(maze.begin() + i);
                    c = false;
                    cout << "Wall was deleted!\n";
                    break;
                }
            if (c == true)
            {
                maze.push_back(x);
                maze.push_back(y);
            }
            c = true;
            print();
        }
    }
}
void exit()
{
    bool c = false;
    cout << "Input point of exit\n";
    while (c == false)
    {
        cout << "x: ";
        cin >> ex;
        cout << "y: ";
        cin >> ey;
        c = true;
        for (int i = 0; i < maze.size(); i = i + 2)
            if (ex == maze[i] and ey == maze[i + 1] or ex >= n or ey >= m or ex < 0 or ey < 0)
            {
                cout << "Invalid\n";
                c = false;
                break;
            }
    }
    print();
}
void spawn()
{
    bool c = false;
    cout << "Input point of spawn\n";
    while (c == false)
    {
        cout << "x: ";
        cin >> ax;
        cout << "y: ";
        cin >> ay;
        c = true;
        for (int i = 0; i < maze.size(); i = i + 2)
            if ((ax == maze[i] and ay == maze[i + 1]) or ax >= n or ay >= m or (ax == ex and ay == ey) or ax < 0 or ay < 0)
            {
                cout << "Invalid\n";
                c = false;
                break;
            }
    }
    way.push_back(ax);
    way.push_back(ay);
    print();
}
void eyeh(int x, int y)
{
    if (x <= -1 or y <= -1 or x >= n or y >= m)
        return;
    for (int i = 0; i < maze.size(); i = i + 2)
        if (x == maze[i] and y == maze[i + 1])
            return;
    for (int i = 0; i < way.size(); i = i + 2)
        if (x == way[i] and y == way[i + 1])
            return;
    for (int i = 0; i < newe.size(); i = i + 2)
        if (x == newe[i] and y == newe[i + 1])
            return;
    newe.push_back(x);
    newe.push_back(y);
    return;
}
void eye()
{
    if (ax + 1 == ex and ay == ey)  //right
    {
        ax = ax + 1;
        way.push_back(ax);
        way.push_back(ay);
        print();
        return;
    }
    else
        eyeh(ax + 1, ay);
    if (ax == ex and ay - 1 == ey)  //up
    {
        ay = ay - 1;
        way.push_back(ax);
        way.push_back(ay);
        print();
        return;
    }
    else
        eyeh(ax, ay - 1);
    if (ax == ex and ay + 1 == ey)  //down
    {
        ay = ay + 1;
        way.push_back(ax);
        way.push_back(ay);
        print();
        return;
    }
    else
        eyeh(ax, ay + 1);
    if (ax - 1 == ex and ay == ey)  //left
    {
        ax = ax - 1;
        way.push_back(ax);
        way.push_back(ay);
        print();
        return;
    }
    else
        eyeh(ax - 1, ay);
    move();
}
void move()
{
    if (newe.size() != 0)
    {
        cout << "move" << endl;
        ay = newe.back();
        newe.pop_back();
        ax = newe.back();
        newe.pop_back();
        cout << ax << " " << ay << " move" << endl;
        way.push_back(ax);
        way.push_back(ay);
        print();
    }
    else if (newe.size() >= 0)
    {
        cout << "There's no escape\n";
        return;
    }
    eye();
}
int main()
{
    cout << "Input size of labyrinth\n";
    cout << "    n\n";
    cout << " _______\n";
    cout << "|       |\n";
    cout << "|       |  m\n";
    cout << "|_______|\n";
    cout << "Input n: ";
    cin >> n;
    cout << "Input m: ";
    cin >> m;
    ax = ex = n + 1;
    ay = ey = m + 1;
    create();
    exit();
    spawn();
    eye();
    for (int i = 0; i < way.size(); i = i + 2)
        cout << way[i] << "." << way[i + 1] << " ";
    return 0;
}

