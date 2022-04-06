#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "windows.h"
#include <ctime>
#include "conio.h"
using namespace std;

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
int x_head, y_head, x_fruit, y_fruit, score, x_tail[100], y_tail[100];

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
int logic(int a_w, int a_h);
int X_tail();
int Y_tail();

void set_map_square(int a)
{
    int a_w, a_h, view;
    switch (a)
    {
    case 1:
        a_w = 20;
        a_h = 15;
        view = 45;
        break;
    case 2:
        a_w = 30;
        a_h = 25;
        view = 40;
        break;
    case 3:
        a_w = 40;
        a_h = 15;
        view = 35;
        break;
    case 4:
        a_w = 60;
        a_h = 25;
        view = 25;
        break;
    }
    x_head = game_x_head(a_w, a_h);
    y_head = game_y_head(a_w, a_h);
    x_fruit = game_x_fruit(a_w, a_h);
    y_fruit = game_y_fruit(a_w, a_h);
    score = 0;
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
                    bool tail = false;
                    for (int i = 0; i < score; i++)

                        if (x_tail[i] == x && y_tail[i] == y)
                        {
                            tail = true;
                            cout << "o";
                        }
                    if (!tail)
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
        score = logic(a_w, a_h);
        cout << endl;
        cout << setw(65) << setfill(' ') << "Your actual score: " << score << endl;
        Sleep(200);
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
int logic(int a_w, int a_h)
{
    int prev_x = x_tail[0];
    int prev_y = y_tail[0];
    int prev2_x, prev2_y;
    x_tail[0] = x_head;
    y_tail[0] = y_head;
    for (int i = 1; i < score; i++)
    {
        prev2_x = x_tail[i];
        prev2_y = y_tail[i];
        x_tail[i] = prev_x;
        y_tail[i] = prev_y;
        prev_x = prev2_x;
        prev_y = prev2_y;
    }
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
    if (x_head < 0 || x_head >= a_w || y_head < 0 || y_head > a_h)
        Game_Over = true;
    if (x_head == x_fruit && y_head == y_fruit)
    {
        score++;
        x_fruit = game_x_fruit(a_w, a_h);
        y_fruit = game_y_fruit(a_w, a_h);
        for (int i = 0; i < score; i++)
        {
            x_tail[i];
            y_tail[i];
        }
    }
    return score;
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
        system("EXIT");
        break;
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
        system("EXIT");
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
    return rand() % a_w;
}
int game_y_fruit(int a_w, int a_h)
{
    unsigned seed = time(0);
    srand(seed);
    return rand() % a_h;
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
