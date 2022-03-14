#include <iostream>
#include <vector>
using namespace std;

class base {
public:
    virtual void show() {};
};

template <class T> class point2d {
protected:
    T x, y;
public:
    point2d(T x, T y) : x(x), y(y) {};
};

template <class T> class tz
{
protected:
    T z;
public:
    tz(T z) : z(z){}
};

template <class T> class ht
{
public:
    T h;
    ht(T h1) : h(h1) {}
};

template <class T> class point3dh : public point2d<T>, public tz<T>, public ht<T>, base
{
public:
    point3dh(T x, T y, T z, T h) : point2d<T>(x, y), tz<T>(z), ht<T>(h) {}
    void show()
    {
        cout << "x: " << this->x / this->h << " |y: " << this->y/this->h << " |z: " << this->z/this->h << endl;
    }
};

int main()
{
    vector <base*> tochki;
    int menu = 1;
    int x, y, z, h;
    short sx, sy, sz, sh;
    double dx, dy, dz, dh;
    float fx, fy, fz, fh;
    long lx, ly, lz, lh;
    while (menu != 0)
    {
        cout << "1. Create\n";
        cout << "2. Show\n";
        cin >> menu;
        if (menu == 1)
        {
            cout << "1. Int\n2. Short\n3. Double\n4. Float\n5. Long\nChoose: ";
            cin >> menu;
            if (menu == 1)
            {
                cout << "Enter x: ";
                cin >> x;
                cout << "Enter y: ";
                cin >> y;
                cout << "Enter z: ";
                cin >> z;
                cout << "Enter h: ";
                cin >> h;
                if (h == 0)
                {
                    cout << "H cant be 0\nEnter h: ";
                    while (h == 0)
                        cin >> h;
                }
                point3dh <int>* a = new point3dh <int>(x, y, z, h);
                tochki.push_back((base*)a);
            }
            else if (menu == 2)
            {
                cout << "Enter x: ";
                cin >> sx;
                cout << "Enter y: ";
                cin >> sy;
                cout << "Enter z: ";
                cin >> sz;
                cout << "Enter h: ";
                cin >> sh;
                if (sh == 0)
                {
                    cout << "H cant be 0\nEnter h: ";
                    while (sh == 0)
                        cin >> sh;
                }
                point3dh <short>* a = new point3dh <short>(sx, sy, sz, sh);
                tochki.push_back((base*)a);
            }
            else if (menu == 3)
            {
                cout << "Enter x: ";
                cin >> dx;
                cout << "Enter y: ";
                cin >> dy;
                cout << "Enter z: ";
                cin >> dz;
                cout << "Enter h: ";
                cin >> dh;
                if (dh == 0)
                {
                    cout << "H cant be 0\nEnter h: ";
                    while (dh == 0)
                        cin >> dh;
                }
                point3dh <double>* a = new point3dh <double>(dx, dy, dz, dh);
                tochki.push_back((base*)a);
            }
            else if (menu == 4)
            {
                cout << "Enter x: ";
                cin >> fx;
                cout << "Enter y: ";
                cin >> fy;
                cout << "Enter z: ";
                cin >> fz;
                cout << "Enter h: ";
                cin >> fh;
                if (fh == 0)
                {
                    cout << "H cant be 0\nEnter h: ";
                    while (fh == 0)
                        cin >> fh;
                }
                point3dh <float>* a = new point3dh <float>(fx, fy, fz, fh);
                tochki.push_back((base*)a);
            }
            else if (menu == 5)
            {
                cout << "Enter x: ";
                cin >> lx;
                cout << "Enter y: ";
                cin >> ly;
                cout << "Enter z: ";
                cin >> lz;
                cout << "Enter h: ";
                cin >> lh;
                if (lh == 0)
                {
                    cout << "H cant be 0\nEnter h: ";
                    while (lh == 0)
                        cin >> lh;
                }
                point3dh <long> *a = new point3dh <long>(lx, ly, lz, lh);
                tochki.push_back((base*)a);
            }
        }
        else if (menu == 2)
        {

            for (int i = 0; i < tochki.size(); i++)
                tochki[i]->show();

        }
    }
    return 0;
}
