#include <iostream>
#include <string>
using namespace std;

int n, m;

struct maze {
	maze* up = NULL;
	maze* down = NULL;
	maze* left = NULL;
	maze* right = NULL;
	int info = 0; //0 = empty 1 = wall 2 = step
	int wave = 0;
    int x;
    int y;
};
maze* first;
maze* builder;
maze* runner;
maze* escape;

void first_cube()
{
    maze* cube = new maze;
    builder = cube;
    first = cube;
    cube->x = 0;
    cube->y = 0;
}

void first_line()
{
    for (int i = 1; i < m; i++)
    {
        maze* cube = new maze;
        cube->x = i;
        cube->y = 0;
        builder->right = cube;
        cube->left = builder;
        builder = cube;
    }
}

void create_maze()
{
    int a = 1;
    for (int i = 1; i < m; i++)
    {
        a = 1;
        runner = first;
        while (a != i)
        {
            a++;
            runner = runner->down;
        }
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                maze* cube = new maze;
                builder = cube;
                runner->down = builder;
                builder->up = runner;
                builder->x = j;
                builder->y = i;
                runner = runner->right;
            }
            else
            {
                maze* cube = new maze;
                cube->left = builder;   //x
                builder->right = cube;  //x
                builder = cube;
                runner->down = builder; //y
                builder->up = runner;   //y
                builder->x = j;
                builder->y = i;
                runner = runner->right; //next cube
            }
        }
    }
}

void print()
{
    for (int i = 0; i < n; i++)
        cout << " _";
    cout << endl;
    int a = 0;
    for (int i = 0; i < m; i++)
    {
        builder = first;
        while (a != i)
        {
            builder = builder->down;
            a++;
        }
        for (int j = 0; j < n; j++)
        {
            if (builder == runner)
                cout << "|@";
            else if (builder == escape)
                cout << "|X";
            else if (builder->info == 2)
                cout << "|*";
            else if (builder->info == 0)
                cout << "|_";
            else
                cout << "|#";
            builder = builder->right;
        }
        cout << "|" <<endl;
        builder = first;
        a = 0;
    }
}

void wall_create()
{
    builder = first;
    cout << "Input walls coordinates\n";
    cout << "If you entered coordinates where there is already a wall, then this wall will be deleted\n";
    cout << "Enter (-1) to complete input\n";
    int x = 0, y = 0;
    while (x != -1)
    {
        cout << "x: ";
        cin >> x;
        if (x != -1)
        {
            cout << "y: ";
            cin >> y;
            if (x > -1 and y > -1 and x < n and y < m)
            {
                while (x != builder->x)
                    builder = builder->right;
                while (y != builder->y)
                    builder = builder->down;
                if (builder->info == 0)
                    builder->info = 1;
                else
                {
                    cout << "Wall was deleted\n";
                    builder->info = 0;
                }
            }
            else
                cout << "Invalid" << endl;
            builder = first;
        }
        print();
    }
}

void escape_point()
{
    bool c = false;
    cout << "Input point of Exit\n";
    int x, y;
    while (c == false)
    {
        cout << "x: ";
        cin >> x;
        cout << "y: ";
        cin >> y;
        escape = first;
        if (x > -1 and y > -1 and x < n and y < m)
        {
            while (x != escape->x)
                escape = escape->right;
            while (y != escape->y)
                escape = escape->down;
            if (escape->info == 0)
                c = true;
            else
                cout << "Invalid\n";
        }
        else
            cout << "Invalid\n";
    }
    print();
    c = false;
    cout << "Input point of Spawn\n";
    while (c == false)
    {
        cout << "x: ";
        cin >> x;
        cout << "y: ";
        cin >> y;
        runner = first;
        if (x > -1 and y > -1 and x < n and y < m)
        {
            while (x != runner->x)
                runner = runner->right;
            while (y != runner->y)
                runner = runner->down;
            if (runner->info == 0 and runner != escape)
                c = true;
            else
                cout << "Invalid\n";
        }
        else
            cout << "Invalid\n";
    }
    print();
}

void run()
{
    runner = escape;
    for (int i = 0; i < escape->wave; i++)
    {
        if (runner->up != NULL and runner->up->wave < runner->wave and runner->up->info == 0)
                runner = runner->up;
        else if (runner->down != NULL and runner->down->wave < runner->wave and runner->down->info == 0)
                runner = runner->down;
        else if (runner->right != NULL and runner->right->wave < runner->wave and runner->right->info == 0)
                runner = runner->right;
        else if (runner->left != NULL and runner->left->wave < runner->wave and runner->left->info == 0)
                runner = runner->left;
        runner->info = 2;
    }
}

void turns()
{
    int a = 0;
    int lvlwave = 1;
    runner->wave = lvlwave;
    while (escape->wave == 0)
    {
        lvlwave++;
        for (int i = 0; i < m; i++)
        {
            a = 0;
            runner = first;
            while (a != i)
            {
                a++;
                runner = runner->down;
            }
            for (int j = 0; j < n; j++)
            {
                if (runner->wave == lvlwave - 1)
                {
                    if (runner->up != NULL and runner->up->info == 0 and runner->up->wave == 0)
                        runner->up->wave = lvlwave;
                    if (runner->down != NULL and runner->down->info == 0 and runner->down->wave == 0)
                        runner->down->wave = lvlwave;
                    if (runner->left != NULL and runner->left->info == 0 and runner->left->wave == 0)
                        runner->left->wave = lvlwave;
                    if (runner->right != NULL and runner->right->info == 0 and runner->right->wave == 0)
                        runner->right->wave = lvlwave;
                }
                runner = runner->right;
            }
        }
        if (lvlwave > n * m)
        {
            cout << "There's no escape" << endl;
            break;
        }
    }
    cout << "Number of turns for Escape: " << escape->wave << endl;
    if (escape->wave != 0)
        run();
    else
        return;
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
    first_cube();
    first_line();
    create_maze();
    print();
    wall_create();
    escape_point();
    turns();
    print();
	return 0;
}

