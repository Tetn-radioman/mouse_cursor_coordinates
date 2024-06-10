#if       _WIN32_WINNT < 0x0500
#undef  _WIN32_WINNT
#define _WIN32_WINNT   0x0502
#endif
//попробуйте без первых четырех строк. Если работает - можете 
//спокойно их убрать.

#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int main()
{
    cout << "Place, the cursor in the upper left corner, after 10 seconds the zero coordinates will be calibrated." << endl;
    Sleep(10000);//за десять секунд нужно успеть передвинуть программу в нужное место (вправо) и 
    //отвести макимально в верхний левый угол курсор мыши

    RECT r;
    POINT p;
    HWND wh = GetConsoleWindow();
    COORD c = { 1,1 };

    int i = 0,x = 0, y = 0;

    while (i <= 30) {
        GetWindowRect(wh, &r);
        GetCursorPos(&p);
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
        x = p.x - r.left;
        y = p.y - r.top;
        cout << x << ":" << y << "    ";
        i++;
    }

    //постоянный вывод координат с учётом погрешности

    while (1) {
        GetWindowRect(wh, &r);
        GetCursorPos(&p);
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
        cout << (p.x - r.left) + x * -1 << ":" << (p.y - r.top) + y * -1 << "    ";
    }
}