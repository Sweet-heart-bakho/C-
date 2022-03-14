#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

int r = 0;
int g = 0;
int b = 0;
int r1 = 0;
int g1 = 0;
int b1 = 0; 

class shape
{
public:
    virtual void show(HDC hdc)
    {}
};

class point : shape
{
public:
    int x, y;
    COLORREF color;
    point(int x, int y, COLORREF c = RGB (255, 255, 255)) : x(x), y(y), color(c) {}
    void show(HDC hdc)
    {
        SetPixel(hdc, x, y, color);
    }
};

class line : shape
{
    point begin;
    point end;
    COLORREF line_c;
public:
    line(int x1, int y1, int x2, int y2, COLORREF lc = RGB (255, 255, 255)) : begin(x1, y1), end(x2, y2), line_c(lc)
    {}
    void show(HDC hdc)
    {
        SelectObject(hdc, GetStockObject(DC_PEN));
        SetDCPenColor(hdc, line_c);
        MoveToEx(hdc, begin.x, begin.y, 0);
        LineTo(hdc, end.x, end.y);
    }
};

class rectangle : shape
{
    point top_left;
    point bottom_right;
    COLORREF line_c;
    COLORREF back_c;
    bool filled;
public:
    rectangle(int x1, int y1, int x2, int y2, COLORREF lc, COLORREF bc, bool f = false) : top_left(x1, y1), bottom_right(x2, y2), line_c(lc), back_c(bc), filled(f)
    {}
    void show(HDC hdc)
    {
        SelectObject(hdc, GetStockObject(DC_PEN));
        SetDCPenColor(hdc, line_c);
        SetDCBrushColor(hdc, back_c);
        if (filled)
            SelectObject(hdc, GetStockObject(DC_BRUSH));
        else
            SelectObject(hdc, GetStockObject(NULL_BRUSH));
        Rectangle(hdc, top_left.x, top_left.y, bottom_right.x, bottom_right.y);
    }
};

class ellipse : shape
{
    point top_left;
    point bottom_right;
    COLORREF line_c;
    COLORREF back_c;
    bool filled;
public:
    ellipse(int x1, int y1, int x2, int y2, COLORREF lc, COLORREF bc, bool f = false) : top_left(x1, y1), bottom_right(x2, y2), line_c(lc), back_c(bc), filled(f)
    {}
    void show(HDC hdc)
    {
        SelectObject(hdc, GetStockObject(DC_PEN));
        SetDCPenColor(hdc, line_c);
        SetDCBrushColor(hdc, back_c);
        if (filled)
            SelectObject(hdc, GetStockObject(DC_BRUSH));
        else
            SelectObject(hdc, GetStockObject(NULL_BRUSH));
        Ellipse(hdc, top_left.x, top_left.y, bottom_right.x, bottom_right.y);
    }
};

class polyline : shape 
{
    vector<point>p;
    COLORREF line_c;
    COLORREF back_c;
    int size;
    bool filled;
public:
    polyline(int size, vector<point>p, COLORREF lc, COLORREF bc, bool f = false) : size(size), line_c(lc), back_c(bc), filled(f)
    {
        for (int i = 0; i < size; i++)
            this->p.push_back(p[i]);
    }
    void show(HDC hdc)
    {
        SelectObject(hdc, GetStockObject(DC_PEN));
        SetDCPenColor(hdc, line_c);
        SetDCBrushColor(hdc, back_c);
        if (filled)
            SelectObject(hdc, GetStockObject(DC_BRUSH));
        else
            SelectObject(hdc, GetStockObject(NULL_BRUSH));
        POINT* p1 = new POINT[size];
        for (int i = 0; i < size; i++)
        {
            p1[i].x = p[i].x;
            p1[i].y = p[i].y;
        }
        Polygon(hdc, p1, size);
        delete[] p1;
    }
};

class canvas
{
    vector<shape*> figures;
    HWND hWnd;
    HDC hdc;
public:
    canvas()
    {
        hWnd = GetConsoleWindow();
        hdc = GetDC(hWnd);
    }
    ~canvas()
    {
        ReleaseDC(hWnd, hdc);
    }
    void add(shape* s)
    {
        figures.push_back(s);
    }
    void del()
    {
        figures.pop_back();
    }
    void clear()
    {
        figures.clear();
    }
    void show()
    {
        for (size_t i = 0; i < figures.size(); i++)
            figures[i]->show(hdc);
    }
};

void cubes()
{
    HWND hWnd = GetConsoleWindow();
    HDC hdc = GetDC(hWnd);
    SelectObject(hdc, GetStockObject(DC_PEN));
    SelectObject(hdc, GetStockObject(DC_BRUSH));
    SetDCPenColor(hdc, RGB(255, 0, 0));//red
    SetDCBrushColor(hdc, RGB(255, 0, 0));
    Rectangle(hdc, 150, 20, 160, 30);
    SetDCPenColor(hdc, RGB(0, 255, 0));//green
    SetDCBrushColor(hdc, RGB(0, 255, 0));
    Rectangle(hdc, 150, 35, 160, 45);
    SetDCPenColor(hdc, RGB(0, 0, 255));//blue
    SetDCBrushColor(hdc, RGB(0, 0, 255));
    Rectangle(hdc, 150, 50, 160, 60);
    SetDCPenColor(hdc, RGB(255, 115, 0));//orange
    SetDCBrushColor(hdc, RGB(255, 115, 0));
    Rectangle(hdc, 150, 65, 160, 75);
    SetDCPenColor(hdc, RGB(255, 255, 255));//white
    SetDCBrushColor(hdc, RGB(255, 255, 255));
    Rectangle(hdc, 150, 80, 160, 90);
    SetDCPenColor(hdc, RGB(255, 46, 248));//pink
    SetDCBrushColor(hdc, RGB(255, 46, 248));
    Rectangle(hdc, 150, 95, 160, 105);
    SetDCPenColor(hdc, RGB(255, 255, 0));//yellow
    SetDCBrushColor(hdc, RGB(255, 255, 0));
    Rectangle(hdc, 150, 110, 160, 120);
    SetDCPenColor(hdc, RGB(0, 255, 255));//cyan
    SetDCBrushColor(hdc, RGB(0, 255, 255));
    Rectangle(hdc, 150, 125, 160, 135);
}

void colors()
{
    int n;
    system("cls");
    cout << "Choose color: ";
    cout << "\n1. Red\n"; //255 0 0
    cout << "2. Green\n"; // 0 255 0
    cout << "3. Blue\n"; // 0 0 255
    cout << "4. Orange\n"; // 255 115 0
    cout << "5. White\n"; // 255 255 255
    cout << "6. Pink\n"; //255 46 248
    cout << "7. Yellow\n"; // 255 255 0
    cout << "8. Cyan\n"; // 0 255 255
    cubes();
    cin >> n;
    switch (n)
    {
    case 1:
        r = 255; g = 0; b = 0;
        break;
    case 2:
        r = 0; g = 255; b = 0;
        break;
    case 3:
        r = 0; g = 0; b = 255;
        break;
    case 4:
        r = 255; g = 115; b = 0;
        break;
    case 5:
        r = 255; g = 255; b = 255;
        break;
    case 6:
        r = 255; g = 46; b = 248;
        break;
    case 7:
        r = 255; g = 255; b = 0;
        break;
    case 8:
        r = 0; g = 255; b = 255;
        break;
    default:
        r = 0; g = 0; b = 0;
        break;
    }
}

void colorsf()
{
    int n;
    system("cls");
    cout << "Choose color: ";
    cout << "\n1. Red\n"; //255 0 0
    cout << "2. Green\n"; // 0 255 0
    cout << "3. Blue\n"; // 0 0 255
    cout << "4. Orange\n"; // 255 115 0
    cout << "5. White\n"; // 255 255 255
    cout << "6. Pink\n"; //255 46 248
    cout << "7. Yellow\n"; // 255 255 0
    cout << "8. Cyan\n"; // 0 255 255
    cubes();
    cin >> n;
    switch (n)
    {
    case 1:
        r1 = 255; g1 = 0; b1 = 0;
        break;
    case 2:
        r1 = 0; g1 = 255; b1 = 0;
        break;
    case 3:
        r1 = 0; g1 = 0; b1 = 255;
        break;
    case 4:
        r1 = 255; g1 = 115; b1 = 0;
        break;
    case 5:
        r1 = 255; g1 = 255; b1 = 255;
        break;
    case 6:
        r1 = 255; g1 = 46; b1 = 248;
        break;
    case 7:
        r1 = 255; g1 = 255; b1 = 0;
        break;
    case 8:
        r1 = 0; g1 = 255; b1 = 255;
        break;
    default:
        r1 = 0; g1 = 0; b1 = 0;
        break;
    }
}

int main()
{
    canvas c;
    system("cls");
    int x1, y1, x2, y2, menu = 1;
    char a;
    vector <point> poi;
    bool foll = false;
    cout << "Welcome to Paint in C++" << endl;
    cout << "                               " << endl;
    cout << "    ___________  ___________________________________________  ______   _______ __                 " << endl;
    cout << "    __  ____/\\ \\/ /__/    /__  ____/___  __ \\ __   __ \\__  / / /__  | / /__  //_/         " << endl;
    cout << "    _  /     __  / _/ __ \\ __  __/  __  /_/ / _   /_/ / / / / /__   |/ /__    /          " << endl;
    cout << "    / /___   _/ / _/ /_/ / _  /___  _  _, _/ _   ____/ / /_/ / _  /|  / _  /\\ \\             " << endl;
    cout << "    \\____/  /__/  /_____/  /_____/  /_/ |_|  /_/       \\____/  /_/ |_/  /_/  \\_\\                   " << endl;
    cin >> a;
    while (menu != 0)
    {
        system("cls");
        cout << "1. Set Point" << endl;
        cout << "2. Draw Line" << endl;
        cout << "3. Draw Rectangle" << endl;
        cout << "4. Draw Ellipse" << endl;
        cout << "5. Draw Polyline" << endl;
        cout << "6. Show Figures" << endl;
        cout << "7. Delete Last Figure" << endl;
        cout << "8. Delete all Figures" << endl;
        cout << "0. Exit with Deleting all Figures" << endl;
        cin >> menu;
        if (menu == 0)
            c.clear();
        switch (menu)
        {
        case 1:
            system("cls");
            cout << "Input point coordinates\nx: ";
            cin >> x1;
            cout << "y: ";
            cin >> y1;
            colors();
            c.add((shape*)new point(x1, y1, RGB(r, g, b))); // добавление точки
            break;
        case 2:
            system("cls");
            cout << "(x1,y1)---------------(x2,y2)" << endl;
            cout << "Input your Line coordinates\nx1: ";
            cin >> x1;
            cout << "y1: ";
            cin >> y1;
            cout << "x2: ";
            cin >> x2;
            cout << "y2: ";
            cin >> y2;
            colors();
            c.add((shape*)new line(x1, y1, x2, y2, RGB(r, g, b)));
            break;
        case 3:
            system("cls");
            cout << " (x1,y1)_________\n       |         |\n       |_________|\n                 (x2,y2)\n";
            cout << "Input Rectangle coordinates\nx1: ";
            cin >> x1;
            cout << "y1: ";
            cin >> y1;
            cout << "x2: ";
            cin >> x2;
            cout << "y2: ";
            cin >> y2;
            colors();
            system("cls");
            cout << "Do you want fill rectangle?:\n1. Yes\t2. No" << endl;
            cin >> menu;
            if (menu == 1)
            {
                foll = true;
                colorsf();
            }
            else
                foll = false;
            c.add((shape*)new rectangle(x1, y1, x2, y2, RGB(r, g, b), RGB(r1, g1, b1), foll));
            break;
        case 4:
            system("cls");
            cout << " (x1,y1)_________\n       |         |\n       |_________|\n                 (x2,y2)\n";
            cout << "Input Ellipse coordinates\nx1: ";
            cin >> x1;
            cout << "y1: ";
            cin >> y1;
            cout << "x2: ";
            cin >> x2;
            cout << "y2: ";
            cin >> y2;
            colors();
            system("cls");
            cout << "Do you want fill ellipse?:\n1. Yes\t2. No" << endl;
            cin >> menu;
            if (menu == 1)
            {
                foll = true;
                colorsf();
            }
            else
                foll = false;
            c.add((shape*)new ellipse(x1, y1, x2, y2, RGB(r, g, b), RGB(r1, g1, b1), foll));
            break;
        case 5:
            system("cls");
            cout << "Input Polygon size: ";
            cin >> x1;
            for (int i = 0; i < x1; i++)
            {
                cout << "Input coordinates: ";
                cout << "x" << i << ": ";
                cin >> x2;
                cout << "y" << i << ": ";
                cin >> y2;
                poi.push_back(point(x2, y2, RGB(0, 0, 0)));
            }
            colors();
            system("cls");
            cout << "Do you want fill polyline?:\n1. Yes\t2. No" << endl;
            cin >> menu;
            if (menu == 1)
            {
                foll = true;
                colorsf();
            }
            else
                foll = false;
            c.add((shape*)new polyline(poi.size(), poi, RGB(r, g, b), RGB(r1, g1, b1), foll));
            break;
        case 6:
            system("cls");
            c.show();
            cin >> a;
            break;
        case 7:
            system("cls");
            c.del();
            break;
        case 8:
            system("cls");
            c.clear();
            break;
        }
    }
    return 0;
}
