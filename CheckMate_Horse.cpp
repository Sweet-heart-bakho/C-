#include <iostream>
#include <vector>
using namespace std;

int n;
int x = 0;
int y = 0;
vector <int> best_way;
vector <int> pos;

void push()
{
    pos.push_back(x);
    pos.push_back(y);
}
void dl()   //down left
{
    x--;
    y = y + 2;
    push();
}
void dr()   //down right
{
    y = y + 2;
    x++;
    push();

}
void rd()   //right down
{
    x = x + 2;
    y++;
    push();

}
void ru()   //right up
{
    x = x + 2;
    y--;
    push();

}
void ur()   //up right
{
    x++;
    y = y - 2;
    push();

}
void ul()   //up left
{
    y = y - 2;
    x--;
    push();

}
void lu()   //left up
{
    x = x - 2;
    y--;
    push();
}
void ld()   //left down
{
    x = x - 2;
    y++;
    push();
}
struct turns
{
    turns* up_left = NULL;     //1
    turns* up_right = NULL;    //2
    turns* down_left = NULL;   //3
    turns* down_right = NULL;  //4
    turns* right_up = NULL;    //5
    turns* right_down = NULL;  //6
    turns* left_up = NULL;     //7
    turns* left_down = NULL;   //8
    turns* predok = NULL;
    bool up_left_b = true;
    bool up_right_b = true;
    bool right_up_b = true;
    bool right_down_b = true;
    bool down_right_b = true;
    bool down_left_b = true;
    bool left_up_b = true;
    bool left_down_b = true;
    int x;
    int y;
    int depth = 0;
};
turns* horse;
turns* close_way;
int printh(int i, int j)
{
    if (i == y and j == x)
        return 1;
    for (int l = 0; l < pos.size(); l = l + 2)
        if (pos[l + 1] == i and pos[l] == j)
            return 2;
    return 0;
}
void print()
{
    cout << "\n ";
    for (int i = 0; i < n; i++)
        cout << " " << i;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i;
        for (int j = 0; j < n; j++)
        {
            if (printh(i, j) == 1)
                cout << "|&";
            else if (printh(i, j) == 2)
                cout << "|*";
            else
                cout << "|_";
        }
        cout << "|" << endl;
    }
}
bool check(int k, int l)
{
    for (int i = 0; i < pos.size(); i = i + 2)
    {
        if (x + k == pos[i] and y + l == pos[i + 1] or x + k <= -1 or x + k >= n or y + l <= -1 or y + l >= n)
        {
            return true;
        }
    }
    return false;
}
void move()
{
    turns* first_turn = new turns;
    first_turn->x = 0;
    first_turn->y = 0;
    horse = first_turn;
    horse->depth = 1;
    while (horse->depth > 1 or horse->left_down_b == true)
    {
        //print();
        if (horse->left_up_b == true and check(-2, -1) == false)    //left_up
        {
            horse->left_up_b = false;                  //close way
            turns* new_turn = new turns;                //create new node
            horse->left_up = new_turn;                  //line up with new node
            new_turn->predok = horse;                   //line up wuth new node
            new_turn->depth = horse->depth + 1;         //check depth
            new_turn->x = x - 2;                        //check coord
            new_turn->y = y - 1;                        //check ccord
            lu();                                       //remember coord
            horse = new_turn;                           //replace horse
            continue;
        }
        else
            horse->left_up_b = false;
        if (horse->down_left_b == true and check(-1, +2) == false)    //down_left
        {
            horse->down_left_b = false;                  //close way
            turns* new_turn = new turns;                //create new node
            horse->down_left = new_turn;                  //line up with new node
            new_turn->predok = horse;                   //line up wuth new node
            new_turn->depth = horse->depth + 1;         //check depth
            new_turn->x = x - 1;                        //check coord
            new_turn->y = y + 2;                        //check ccord
            dl();                                       //remember coord
            horse = new_turn;                           //replace horse
            continue;
        }
        else
            horse->down_left_b = false;
        if (horse->down_right_b == true and check(+1, +2) == false)    //down_right
        {
            horse->down_right_b = false;                  //close way
            turns* new_turn = new turns;                //create new node
            horse->down_right = new_turn;                  //line up with new node
            new_turn->predok = horse;                   //line up wuth new node
            new_turn->depth = horse->depth + 1;         //check depth
            new_turn->x = x + 1;                        //check coord
            new_turn->y = y + 2;                        //check ccord
            dr();                                       //remember coord
            horse = new_turn;                           //replace horse
            continue;
        }
        else
            horse->down_right_b = false;
        if (horse->up_right_b == true and check(+1, -2) == false)    //up_right
        {
            horse->up_right_b = false;                  //close way
            turns* new_turn = new turns;                //create new node
            horse->up_right = new_turn;                  //line up with new node
            new_turn->predok = horse;                   //line up wuth new node
            new_turn->depth = horse->depth + 1;         //check depth
            new_turn->x = x + 1;                        //check coord
            new_turn->y = y - 2;                        //check ccord
            ur();                                       //remember coord
            horse = new_turn;                           //replace horse
            continue;
        }
        else
            horse->up_right_b = false;
        if (horse->right_up_b == true and check(+2, -1) == false)    //right_up
        {
            horse->right_up_b = false;                  //close way
            turns* new_turn = new turns;                //create new node
            horse->right_up = new_turn;                  //line up with new node
            new_turn->predok = horse;                   //line up wuth new node
            new_turn->depth = horse->depth + 1;         //check depth
            new_turn->x = x + 2;                        //check coord
            new_turn->y = y - 1;                        //check ccord
            ru();                                       //remember coord
            horse = new_turn;                           //replace horse
            continue;
        }
        else
            horse->right_up_b = false;
        if (horse->up_left_b == true and check(-1, -2) == false)    //up_left
        {
            horse->up_left_b = false;                   //close way
            turns* new_turn = new turns;                //create new node
            horse->up_left = new_turn;                  //line up with new node
            new_turn->predok = horse;                   //line up wuth new node
            new_turn->depth = horse->depth + 1;         //check depth
            new_turn->x = x - 1;                        //check coord
            new_turn->y = y - 2;                        //check ccord
            ul();                                       //remember coord
            horse = new_turn;                           //replace horse
            continue;
        }
        else
            horse->up_left_b = false;
        if (horse->right_down_b == true and check(+2, +1) == false)    //right_down
        {
            horse->right_down_b = false;                  //close way
            turns* new_turn = new turns;                //create new node
            horse->right_down = new_turn;                  //line up with new node
            new_turn->predok = horse;                   //line up wuth new node
            new_turn->depth = horse->depth + 1;         //check depth
            new_turn->x = x + 2;                        //check coord
            new_turn->y = y + 1;                        //check ccord
            rd();                                       //remember coord
            horse = new_turn;                           //replace horse
            continue;
        }
        else
            horse->right_down_b = false;
        if (horse->left_down_b == true and check(-2, +1) == false)    //left_down
        {
            horse->left_down_b = false;                  //close way
            turns* new_turn = new turns;                //create new node
            horse->left_down = new_turn;                  //line up with new node
            new_turn->predok = horse;                   //line up wuth new node
            new_turn->depth = horse->depth + 1;         //check depth
            new_turn->x = x - 2;                        //check coord
            new_turn->y = y + 1;                        //check ccord
            ld();                                       //remember coord
            horse = new_turn;                           //replace horse
            continue;
        }
        else
            horse->left_down_b = false;
        if (horse->depth == n * n)
            break;
        else
        {
            if (pos.size() > best_way.size())
                best_way = pos;
            if (horse->predok != NULL)
            {
                close_way = horse;
                horse = horse->predok;
                pos.pop_back();
                pos.pop_back();
                x = horse->x;
                y = horse->y;
                delete close_way;
            }
            else
                break;
        }
    }
}
int main()
{
    int u = 0;
    cout << "Minimum size of desk 3, Maximum 8\n";
    cout << "Horse will be on point A.1\n";
    cout << "Input size of desk: ";
    cin >> n;
    cout << endl;
    pos.push_back(x);   //first coordinates
    pos.push_back(y);   //first coordinates
    print();
    move();
    if (pos.size() > best_way.size())
        best_way = pos;
    cout << "\n Best way print:";
    pos.clear();
    while (pos.size() < best_way.size())
    {
        x = best_way[u];
        y = best_way[u + 1];
        pos.push_back(best_way[u]);
        pos.push_back(best_way[u + 1]);
        cout << "\n ";
        for (int i = 0; i < n; i++)
            cout << " " << i;
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i;
            for (int j = 0; j < n; j++)
            {
                if (printh(i, j) == 1)
                    cout << "|&";
                else if (printh(i, j) == 2)
                    cout << "|*";
                else
                    cout << "|_";
            }
            cout << "|" << endl;
        }
        u = u + 2;
    }
    cout << endl;
    if ((best_way.size() / 2) == (n * n) - 1)
        cout << "Good!\nCode of movies: ";
    for (int i = 0; i < best_way.size(); i = i + 2)
        cout << best_way[i] << "." << best_way[i + 1] << " ";
    cout << "\nNumber of moves = " << best_way.size() / 2;
    return 0;
}
