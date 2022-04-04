#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <conio.h>
using namespace std;
// TODO Musze sprawdzić game(), set_square(), co zrobić żeby przekazywac informacje o rozmiarze i wartościach x/y head oraz F
enum direction
{
    STOP = 0,
    LEFT,
    DOWN,
    RIGHT,
    UP
};
bool Game_Over;
direction dir;
int x_head, y_head, x_fruit, y_fruit, score;

void game_over();
void square();
void triangle();
void maps();
void menu();
int main();
int game(int a_w, int a_h);
void set_map_square(int a);
int game_x_head(int a_w, int a_h);
int game_y_head(int a_w, int a_h);
int game_x_fruit(int a_w, int a_h);
int game_y_fruit(int a_w, int a_h);
void input();
void logic();

void set_map_square(int a)
{
    int a_w;
    int a_h;
    int view;
    if (a == 1)
    {
        a_w = 20;
        a_h = 15;
        view = 45;
    }
    if (a == 2)
    {
        a_w = 30;
        a_h = 25;
        view = 40;
    }
    if (a == 3)
    {
        a_w = 40;
        a_h = 15;
        view = 35;
    }
    if (a == 4)
    {
        a_w = 60;
        a_h = 25;
        view = 25;
    };
    x_head = game_x_head(a_w, a_h);
    y_head = game_y_head(a_w, a_h);
    x_fruit = game_x_fruit(a_w, a_h);
    y_fruit = game_y_fruit(a_w, a_h);
    int score = 0;
    dir = STOP;
    while (!Game_Over)
    {
        system("CLS");
        cout << setw(view) << setfill(' ');
        for (int i = 0; i < a_w + 2; i++)
            cout << "#";
        cout << endl;
        for (int y = 0; y <= a_h; y++)
        {
            cout << setw(view) << setfill(' ');
            for (int x = 0; x <= a_w; x++)
            {
                if (x == 0)
                    cout << "#";
                if (y == y_head && x == x_head)
                {
                    cout << "O";
                    continue;
                }
                if (y == y_fruit && x == x_fruit)
                {
                    cout << "X";
                    continue;
                }
                if (x == a_w)
                {
                    cout << "#";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
        cout << setw(view) << setfill(' ');
        for (int i = 0; i < a_w + 2; i++)
        {
            cout << "#";
        }
        input();
        logic();
        Sleep(250);
    }
}
void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            dir = UP;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'q':
            Game_Over = true;
            break;
        }
    }
}
void logic()
{
    switch (dir)
    {
    case STOP:
        break;
    case UP:
        y_head--;
        break;
    case LEFT:
        x_head--;
        break;
    case RIGHT:
        x_head++;
        break;
    case DOWN:
        y_head++;
        break;
    default:
        break;
    }
    // if (x_head < 0 || x_head > a_w || y_head < 0 || y_head > a_h)
    //    Game_Over = true;
    // if (x_head == x_fruit && y_head == y_fruit)
    // {
    //     score++;
    //     x_fruit = game_x_fruit(a_w, a_h);
    //     y_fruit = game_y_fruit(a_w, a_h);
    // }
}
void game_over()
{
    system("CLS");
    cout << setw(61) << setfill(' ') << "You lost :(" << endl;
    cout << setw(64) << setfill(' ') << "Your score was: " << score << " \n"
         << endl;
    int choice;
    cout << setw(73) << setfill(' ') << "Would you like to restart the game:" << endl;
    cout << setw(59) << setfill(' ') << "1. Yes" << endl;
    cout << setw(58) << setfill(' ') << "2. No" << endl;
    cout << endl;
    cout << setw(62) << setfill(' ') << "Your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        Game_Over = false;
        system("CLS");
        menu();
        break;
    case 2:
        system("exit");
    default:
        system("CLS");
        cout << setw(68) << setfill(' ') << "Type right value" << endl;
        Sleep(2000);
        game_over();
        break;
    }
}
void square()
{
    system("CLS");
    cout << setw(63) << setfill(' ') << "Choose map size:" << endl;
    cout << setw(59) << setfill(' ') << "1. 20x20" << endl;
    cout << setw(59) << setfill(' ') << "2. 30x30" << endl;
    cout << setw(59) << setfill(' ') << "3. 40x20" << endl;
    cout << setw(59) << setfill(' ') << "4. 60x30" << endl;
    cout << endl;
    int size;
    cout << setw(62) << setfill(' ') << "Your choice: ";
    cin >> size;
    switch (size)
    {
    case 1:
        set_map_square(size);
        break;
    case 2:
        set_map_square(size);
        break;
    case 3:
        set_map_square(size);
        break;
    case 4:
        set_map_square(size);
        break;
    default:
        system("CLS");
        cout << setw(63) << setfill(' ') << "Type right value" << endl;
        Sleep(2000);
        square();
        break;
    }
}
void triangle()
{
}
void maps()
{
    system("CLS");
    cout << setw(63) << setfill(' ') << "Chose your map:" << endl;
    cout << setw(60) << setfill(' ') << "1. Square" << endl;
    cout << setw(61) << setfill(' ') << "2. Triangle" << endl;
    cout << "" << endl;
    int map_choice;
    cout << setw(62) << setfill(' ') << "Your choice: ";
    cin >> map_choice;
    switch (map_choice)
    {
    case 1:
        square();
        break;
    case 2:
        triangle();
        break;
    default:
        system("CLS");
        cout << setw(63) << setfill(' ') << "Type right value" << endl;
        Sleep(2000);
        maps();
        break;
    }
}

void menu()
{
    cout << setw(62) << setfill(' ') << "1. Start game" << endl;
    cout << setw(58) << setfill(' ') << "2. End" << endl;
    cout << "" << endl;
    int menu_choice;
    cout << setw(62) << setfill(' ') << "Your choice: ";
    cin >> menu_choice;
    switch (menu_choice)
    {
    case 1:
        maps();
    case 2:
        break;
    default:
        system("CLS");
        cout << setw(63) << setfill(' ') << "Type right value" << endl;
        Sleep(2000);
        menu();
        break;
    };
}
// int game_x_head(int a_w, int a_h){} NIE DZIAŁA ZWRACANIE PARU ZMIENNYCH Z FUNKCJI WIĘC JEST ROZDZIELONE NA POSZCZEGÓLNE
int game_x_head(int a_w, int a_h) { return a_w / 2; }
int game_y_head(int a_w, int a_h) { return a_h / 2; }
int game_x_fruit(int a_w, int a_h)
{
    unsigned seed = time(0);
    srand(seed);
    return rand() % a_w + 1;
}
int game_y_fruit(int a_w, int a_h)
{
    unsigned seed = time(0);
    srand(seed);
    return rand() % a_h + 1;
}
int main()
{
    Game_Over = false;
    cout << setw(63) << setfill(' ') << "Welcome in Snake!" << endl;
    cout << setw(71) << setfill(' ') << "This game was developed using C++" << endl;
    cout << setw(73) << setfill(' ') << "I hope you enjoy it 'Michal Gorecki'\n\n";
    cout << endl;
    menu();
    game_over();
}
