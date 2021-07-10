#include "caro.h"
moto buffer[25][77];
void gano(int x, int y, char c, int mamau = 7)// mau 7 la darkwhite
{
    buffer[y][x].kytu = c;
    buffer[y][x].mau = mamau;
}
void khoi_tao_buffer()
{
    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 77; j++)
            gano(j, i, ' ');
}
void ve_ban_co()
{
    for (int i = 0; i < 25; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < 77; j++)
                if (j % 4 == 0) gano(j, i, 197); // 197 ke dấu cộng, mau mac dinh la 7
                else gano(j, i, 196); //ke ngang
        }
        else
        {
            for (int j = 0; j < 77; j++)
                if (j % 4 == 0) gano(j, i, 179); //ke doc
        }
    }
}
char ban_co[12][19];
void khoi_tao_ban_co()
{
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 19; j++)
            ban_co[i][j] = ' ';
}
void hien_thi(int x, int y)
{
    //reset buffer
    khoi_tao_buffer();
    //ve ban co len buffer
    ve_ban_co();
    //in cac quan co cua ban co len buffer
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 19; j++)
            gano(2 + j * 4, 1 + i * 2, ban_co[i][j]);
    //in con tro len buffer
    gano(x - 1, y, buffer[y][x - 1].kytu, 176);//176 la mau xanh cua con tro
    gano(x, y, buffer[y][x].kytu, 176);
    gano(x + 1, y, buffer[y][x + 1].kytu, 176);
    //in buffer ra console
    gotoXY(0, 0);
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 77; j++)
        {
            TextColor(buffer[i][j].mau);
            putchar(buffer[i][j].kytu);
        }
        if (i < 24) putchar('\n');
    }
}
int dieu_khien(int& x, int& y, int& nguoi)
{
    int key = inputKey();
    if (key == key_Up && y >= 3) { y -= 2; return 1; }
    else if (key == key_Down && y <= 21) { y += 2; return 1; }
    else if (key == key_Left && x >= 6) { x -= 4; return 1; }
    else if (key == key_Right && x <= 70) { x += 4; return 1; }
    else if (key == 'x' && nguoi == 1 && ban_co[(y - 1) / 2][(x - 2) / 4] == ' ')
    {
        ban_co[(y - 1) / 2][(x - 2) / 4] = 'X';
        nguoi = 0;
        return 1;
    }
    else if (key == 'o' && nguoi == 0 && ban_co[(y - 1) / 2][(x - 2) / 4] == ' ')
    {
        ban_co[(y - 1) / 2][(x - 2) / 4] = 'O';
        nguoi = 1;
        return 1;
    }


    return 0;
}
int xet_thang_thua(int x, int y)
{
    int dem, i, j, h, c;
    c = (x - 2) / 4;
    h = (y - 1) / 2;
    if (ban_co[h][c] == ' ') return 2;
    //xet hang ngang
    dem = 0;
    for (j = c; j >= 0; j--)
        if (ban_co[h][j] != ban_co[h][c]) break;
        else dem++;
    for (j = c + 1; j < 19; j++)
        if (ban_co[h][j] != ban_co[h][c]) break;
        else dem++;
    if (dem >= 5)
    {
        if (ban_co[h][c] == 'X') return 1;
        else return 0;
    }
    //xet hang doc
    dem = 0;
    for (int i = h; i >= 0; i--)
        if (ban_co[i][c] != ban_co[h][c]) break;
        else dem++;
    for (i = h + 1; i < 12; i++)
        if (ban_co[i][c] != ban_co[h][c]) break;
        else dem++;
    if (dem >= 5)
    {
        if (ban_co[h][c] == 'X') return 1;
        else return 0;
    }
    //xet duong cheo len
    dem = 0;
    for (i = h, j = c; i >= 0 && j < 19; i--, j++)
        if (ban_co[i][j] != ban_co[h][c]) break;
        else dem++;
    for (i = h + 1, j = c - 1; i < 12, j >= 0; i++, j--)
        if (ban_co[i][j] != ban_co[h][c]) break;
        else dem++;
    if (dem >= 5)
    {
        if (ban_co[h][c] == 'X') return 1;
        else return 0;
    }
    //xet duong cheo xuong
    dem = 0;
    for (i = h, j = c; i < 120 && j < 19; i++, j++)
        if (ban_co[i][j] != ban_co[h][c]) break;
        else dem++;
    for (i = h - 1, j = c - 1; i >= 0, j >= 0; i--, j--)
        if (ban_co[i][j] != ban_co[h][c]) break;
        else dem++;
    if (dem >= 5)
    {
        if (ban_co[h][c] == 'X') return 1;
        else return 0;
    }
    for (i = 0; i < 12; i++)
        for (j = 0; j < 19; j++)
            if (ban_co[i][j] == ' ') return 2;
    return 3;
}

void PrintCaro2()
{
    int x = 25, y = 0;
    Sleep(200);
    TextColor(12);
    gotoXY(x, y);				   cout << "ooooooooooooo";
    gotoXY(x - 3, y + 1);			cout << "oooooooooooooooo";
    gotoXY(x - 5, y + 2);    cout << "oooooooooooooooooo";
    gotoXY(x - 6, y + 3);   cout << "ooooooooooooooooooo";
    gotoXY(x - 7, y + 4);  cout << "ooooooo";
    gotoXY(x - 8, y + 5); cout << "ooooooo";
    gotoXY(x - 8, y + 6); cout << "ooooooo";
    gotoXY(x - 8, y + 7); cout << "ooooooo";
    gotoXY(x - 8, y + 8); cout << "ooooooo";
    gotoXY(x - 8, y + 9); cout << "ooooooo";
    gotoXY(x - 8, y + 10); cout << "ooooooo";
    gotoXY(x - 7, y + 11); cout << "ooooooo";
    gotoXY(x - 6, y + 12);  cout << "ooooooooooooooooooo";
    gotoXY(x - 5, y + 13);   cout << "oooooooooooooooooo";
    gotoXY(x - 3, y + 14);		cout << "oooooooooooooooo";
    gotoXY(x, y + 15);			   cout << "ooooooooooooo";
    Sleep(200);
    TextColor(12);
    gotoXY(x - 4 + 22, y + 4);				    cout << "ooooooooooo";
    gotoXY(x - 4 + 22 - 2, y + 5);		      cout << "ooooooooooooooo";
    gotoXY(x - 4 + 22 - 3, y + 6);		     cout << "ooooooooooooooooo";
    gotoXY(x - 4 + 22 - 3, y + 7);			 cout << "ooooooooooooooooo";
    gotoXY(x - 4 + 22 - 3, y + 8);			 cout << "oooooo     oooooo";
    gotoXY(x - 4 + 22 - 3, y + 9);			 cout << "oooooo     oooooo";
    gotoXY(x - 4 + 22 - 3, y + 10);		 cout << "oooooo     oooooo";
    gotoXY(x - 4 + 22 - 3, y + 11);		 cout << "ooooooooooooooooo";
    gotoXY(x - 4 + 22 - 3, y + 12);		 cout << "oooooo     oooooo";
    gotoXY(x - 4 + 22 - 3, y + 13);		 cout << "oooooo     oooooo";
    gotoXY(x - 4 + 22 - 3, y + 14);		 cout << "oooooo     oooooo";
    gotoXY(x - 4 + 22 - 3, y + 15);		 cout << "oooooo     oooooo";
    Sleep(200);
    TextColor(12);

    gotoXY(x + 33, y + 4);			cout << "ooooo   ooooooooo";
    gotoXY(x + 33, y + 5);			cout << "oooooooooooooooooo";
    gotoXY(x + 33, y + 6);			cout << "ooooooooooooooooooo";
    gotoXY(x + 33, y + 7);			cout << "oooooooooooooooooooo";
    gotoXY(x + 1 + 33, y + 8);			 cout << "ooooooo     ooooooo";
    gotoXY(x + 1 + 33, y + 9);			 cout << "ooooooo     ooooooo";
    gotoXY(x + 1 + 33, y + 10);		 cout << "ooooooo";
    gotoXY(x + 1 + 33, y + 11);		 cout << "ooooooo";
    gotoXY(x + 1 + 33, y + 12);		 cout << "ooooooo";
    gotoXY(x + 1 + 33, y + 13);		 cout << "ooooooo";
    gotoXY(x + 1 + 33, y + 14);		 cout << "ooooooo";
    gotoXY(x + 1 + 33, y + 15);		 cout << "ooooooo";
    Sleep(200);
    TextColor(12);
    gotoXY(x + 57, y + 4);					cout << "ooooooooooo";
    gotoXY(x + 57 - 2, y + 5);			  cout << "ooooooooooooooo";
    gotoXY(x + 57 - 3, y + 6);			 cout << "ooooooooooooooooo";
    gotoXY(x + 57 - 3, y + 7);			 cout << "ooooooooooooooooo";
    gotoXY(x + 57 - 3, y + 8);			 cout << "oooooo     oooooo";
    gotoXY(x + 57 - 3, y + 9);			 cout << "oooooo     oooooo";
    gotoXY(x + 57 - 3, y + 10);		 cout << "oooooo     oooooo";
    gotoXY(x + 57 - 3, y + 11);		 cout << "oooooo     oooooo";
    gotoXY(x + 57 - 3, y + 12);		 cout << "ooooooooooooooooo";
    gotoXY(x + 57 - 3, y + 13);		 cout << "ooooooooooooooooo";
    gotoXY(x + 57 - 2, y + 14);		  cout << "ooooooooooooooo";
    gotoXY(x + 57, y + 15);				cout << "ooooooooooo";
    TextColor(12);
    Sleep(200);

}