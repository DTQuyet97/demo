#include "caro.h"
using namespace std;

int main()//ham main
{
    int k, kt, nguoi, x, y, van_moi;
    char c;
    PrintCaro2();
    clrscr();
loop:
    
    khoi_tao_ban_co();
    van_moi = 1;
    clrscr();//xóa màn hình
    nguoi = 1;
    x = 42;//đặt tọa độ con trỏ x=2+j*4
    y = 13;//y=1+i*2
    while (1)
    {
        gotoXY(80,0);
        if (nguoi == 1) cout << "Den luot nguoi choi X";
        else cout << "Den luot nguoi choi O";
        hien_thi(x, y);
        if (van_moi) { kt = 2; van_moi = 0; }
        else kt = xet_thang_thua(x, y);
        if (kt == 1)
        {
            gotoXY(30, 7);
            TextColor(14);
            cout << "NGUOI CHOI X THANG!";
            gotoXY(30, 9);
            cout << "choi lai? y:yes  n:no";
            do { c = _getch(); } while (c != 'y' && c != 'n');//_getch() nhap từ bàn phím ký tự
            if (c == 'y') goto loop;
            else goto ketthuc;
        }
        else if (kt == 0)
        {
            gotoXY(30, 7);
            TextColor(14);
            cout << "NGUOI CHOI O THANG!";
            gotoXY(30, 9);
            cout << "choi lai? y:yes  n:no";
            do { c = _getch(); } while (c != 'y' && c != 'n');
            if (c == 'y') goto loop;
            else goto ketthuc;
        }
        else if (kt == 3)
        {
            gotoXY(30, 7);
            TextColor(14);
            cout << "VAN CO NAY HOA!";
            gotoXY(30, 9);
            cout << "choi lai? y:yes  n:no";
            do { c = _getch(); } while (c != 'y' && c != 'n');
            if (c == 'y') goto loop;
            else goto ketthuc;
        }
    loop1:
        k = dieu_khien(x, y, nguoi);
        if (k == 0) goto loop1;
    }
ketthuc:;
    return 0;
}