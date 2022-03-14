#include <iostream>
#include <string>
using namespace std;

//Наша структура
struct node
{
    int balance = 0;
    int info;
    int pr = 0;
    node* l, * r, * p;
};

int a = 0;
node* tree = NULL;
node* head = NULL;
node* pred = NULL;
node* b = NULL;
node* bl = NULL;
node* br = NULL;
int depth = 0;

void push(int a, node** t)
{
    if ((*t) == NULL)                   //Если дерева не существует
        if (head == NULL)
        {
            (*t) = new node;
            (*t)->info = a;
            (*t)->l = (*t)->r = NULL;
            head = (*t);
            head->p = head;
            b = head;
            return;
        }
        else
        {
            (*t) = new node;
            (*t)->info = a;
            (*t)->l = (*t)->r = NULL;
            (*t)->p = pred;
            return;
        }
    pred = (*t);                        //Предок
                                        //Дерево есть
    if (a > (*t)->info)
    {
        (*t)->balance++;
        if ((*t)->balance == 2)
            b = (*t);
        push(a, &(*t)->r);         //Если аргумент а больше чем текущий элемент, кладем его вправо
    }
    else
    {
        (*t)->balance--;
        if ((*t)->balance == -2)
            b = (*t);
        push(a, &(*t)->l);         //Иначе кладем его влево
    }
}

void print(node* t, int u)
{
    if (t == NULL)
    {
        return;
    }
    else
    {
        print(t->l, ++u);                   //С помощью рекурсивного посещаем левое поддерево
        if (depth < u)
            depth = u;
        cout << "\t";
        for (int i = 0; i < u - 1; ++i)
            cout << "| ";
        if (t->l == NULL and t->r == NULL)
            a++;
        cout << t->info << "  predok: " << t->p->info << " balance: " << t->balance << endl;            //И показываем элемент
        u--;
    }
    print(t->r, ++u);                       //С помощью рекурсии посещаем правое поддерево
}

void balan()
{
    if (b->balance == 2)
    {
        if (b->p->balance == 2 && b != head) //scenario 1
        {
            b = b->p;
            bl = b->l;
            br = b->r;         //должен стать головой
            swap(b->info, br->info);
            b->r = br->r;
            b->l = br;
            br->r = NULL;
            br->l = bl;
            b->r->p = b;
            bl->p = br;
            br->p = b;
            br->balance = -1;
            b->balance = 0;
        }
        else if (b->r->balance == 1) //scenario 3
        {
            br = b->r;         //должен стать головой
            swap(b->info, br->info);
            b->r = br->r;
            b->l = br;
            br->r = NULL;
            br->p = b;
            b->r->p = b;
            br->balance = 0;
            b->balance = 0;
        }
        else if (b->r->balance == -1) //scenario 5
        {
            br = b->r;
            bl = br->l;         //должен стать головой
            swap(b->info, bl->info);
            b->l = bl;
            br->l = NULL;
            bl->p = b;
            b->balance = 0;
            br->balance = 0;
        }
        if (b == head)
            b->p = head;
        cout << "Tree was rebalanced\n";
    }
    if (b->balance == -2)
    {
        if (b->p->balance == -2 && b != head) //scenario 2
        {
            b = b->p;
            bl = b->l;
            br = b->r;         //должен стать головой
            swap(b->info, bl->info);
            b->l = bl->l;
            b->r = bl;
            bl->l = NULL;
            bl->r = br;
            br->p = bl;
            bl->p = b;
            b->l->p = b;
            bl->balance = 1;
            b->balance = 0;
        }
        if (b->l->balance == -1) //scenario 4
        {
            bl = b->l;         //должен стать головой
            swap(b->info, bl->info);
            b->l = bl->l;
            b->r = bl;
            bl->l = NULL;
            bl->p = b;
            b->l->p = b;
            b->balance = 0;
            bl->balance = 0;
        }
        if (b->l->balance == 1) //scenario 6
        {
            bl = b->l;
            br = bl->r;         //должен стать головой
            swap(b->info, br->info);
            b->r = br;
            bl->r = NULL;
            br->p = b;
            b->balance = 0;
            bl->balance = 0;
        }
        if (b == head)
            b->p = head;
        cout << "Tree was rebalanced\n";
    }
}

void del(int a, node* t, char s)
{
    if (t == NULL)
    {
        cout << "There is no such key\n";
        return;
    }
    //cout << t->info << endl;
    if (a == head->info)
    {
        if (head->l == NULL and head->r == NULL)
        {
            delete head;
            head = NULL;
            tree = head;
        }
        else if (head->l == NULL)
        {
            pred = head;
            head = head->r;
            head->p = head;
            head->l = NULL;
            tree = head;
            delete pred;
        }
        else if (head->r == NULL)
        {
            pred = head;
            head = head->l;
            head->p = head;
            head->r = NULL;
            tree = head;
            delete pred;
        }
        else
        {
            pred = head->r;
            while (pred->l != NULL)
                pred = pred->l;
            swap(pred->info, head->info);
            pred->p->l = NULL;
            head->p = head;
            tree = head;
            delete pred;
        }
        return;
    }
    if (a == t->info)
    {
        if (t->l == NULL and t->r == NULL)
        {
            if (s == 'r')
                t->p->r = NULL;
            else
                t->p->l = NULL;
            delete t;
        }
        else if (t->l != NULL or t->r != NULL)
        {
            if (s == 'r')
            {
                t->p->r = t->r;
                t->r->p = t->p;
            }
            else
            {
                t->p->l = t->l;
                t->l->p = t->p;
            }
            delete t;
        }
        else
        {
            if (s == 'l')
            {
                pred = t->r;
                while (pred->l != NULL)
                    pred = pred->l;
                pred->p->l = NULL;
                swap(t->info, pred->info);
            }
            else
            {
                pred = t->l;
                while (pred->r != NULL)
                    pred = pred->r;
                pred->p->r = NULL;
                swap(t->info, pred->info);
            }
            delete pred;
        }
        return;
    }
    if (a > t->info)
        del(a, t->r, 'r');
    else
        del(a, t->l, 'l');
}

int main()
{
    int menu = 1;
    int n;
    while (menu != 0)
    {
        cout << "1. Add key" << endl;
        cout << "2. Delete key" << endl;
        cout << "3. Show Tree" << endl;
        cout << "4. Balance" << endl;
        cout << "0. Exit" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << "Input your key: ";
            cin >> n;
            push(n, &tree);
            balan();
            break;
        case 2:
            cout << "Input key which you want delete: ";
            cin >> n;
            del(n, tree, 'l');
            break;
        case 3:
            if (head == NULL)
            {
                cout << "tree is empty\n";
            }
            else
            {
                depth = 0;
                cout << "Your tree\nHead is " << head->info << endl;
                print(tree, 0);
                cout << "Depth:  ";
                for (int i = 1; i <= depth; i++)
                    cout << i << " ";
                cout << endl;
                cout << "Numer of leaves in tree: " << a << endl;
                a = 0;
            }
            break;
        case 4:
            balan();
            break;
        }
    }
    return 0;
}

