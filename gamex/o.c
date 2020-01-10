#include <stdio.h>
#include<windows.h>
#include <stdio.h>

#include <conio.h>
char a[100][100]= {' '};
void gotoxy(int x, int y);
void broad(int rol, int col);
int chieu(int m,int n,int p,int q,char t, int dem,int x,int y);
int check(char t,int x,int y);
void play();
int main()
{

    printf(" GAME X O \t w a s d de di chuyen X, O de danh dau \t E de thoat\n");
    broad(20,20);
    gotoxy(1,2);
    int x=1,y=2;
    char hitc;
    int Game_Over=0;
    while (!Game_Over)
    {
        hitc=getch();
        switch (hitc)
        {
        case 'w':
            y=y-1;
            gotoxy(x,y);
            break;
        case 'a':
            x=x-1;
            gotoxy(x,y);
            break;
        case 's':
            y=y+1;
            gotoxy(x,y);
            break;
        case 'd':
            x=x+1;
            gotoxy(x,y);
            break;
        case 'o':
            a[x-1][y-2]='O';
            gotoxy(x,y);
            printf("O");
            Game_Over=check('O',x-1,y-2);
            if (Game_Over)
            {gotoxy(26,14);
            printf("O win");
            }
            gotoxy(x,y);
            break;
        case 'x':
            a[x-1][y-2]='X';
            gotoxy(x,y);
            printf("X");
            Game_Over=check('X',x-1,y-2);
            if (Game_Over)
            {
            gotoxy(26,14);
            printf("X win");
            }
            gotoxy(x,y);
            break;
        case 'e':
            Game_Over=1;
        default :
            break;
        }
    }
    while (!kbhit());
}
void gotoxy(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void broad(int x,int y)
{
    for (int i=0; i<x+2; i++)
    {
        for (int j=0; j<y+2; j++)
        {
            if ((i==0)||(i==x+2-1)||(j==0)||(j==y+2-1))
            {
                printf("#") ;
            }
            else
                printf(" ");
        }
        printf("\n");
    }

}
int chieu(int m,int n,int p, int q,char t,int dem,int x, int y )
{
    int xx=x,yy=y, i=1;
    while (a[xx+m*i][yy+n*i]==t)
    {
        dem++;
        i++;
    }
    while (a[xx+p*i][yy+q*i]==t)
    {
        dem++;
        i++;
    }
    return dem;
}
int check(char t,int x,int y)
{
    // doc
    int dem=1;
    dem=chieu(1,1,-1,-1,t,dem,x,y);
    if (dem>=5){return 1;}
    // ngang
    dem=1;
    dem=chieu(1,-1,-1,1,t,dem,x,y);
    if (dem>=5){return 1;}
    // cheo
    dem=1;
    dem=chieu(1,0,-1,0,t,dem,x,y);
    if (dem>=5){return 1;}
    // chia
    dem=1;
    dem=chieu(0,1,0,-1,t,dem,x,y);
    if (dem>=5){return 1;}
    return 0;
}
