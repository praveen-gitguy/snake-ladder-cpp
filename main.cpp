#include <iostream>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <windows.h>

using namespace std;

int dic(int d);
void result();
void load();
void ladder();
void snake();

int gotoxy(int x, int y)
{
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int dic(int d)
{
    if (d == 1)
    {
        gotoxy(76, 12);
        cout << "+---------+\n";
        gotoxy(76, 13);
        cout << "|         |\n";
        gotoxy(76, 14);
        cout << "|   (-)   |\n";
        gotoxy(76, 15);
        cout << "|         |\n";
        gotoxy(76, 16);
        cout << "+---------+\n";
    }
    if (d == 2)
    {
        gotoxy(76, 12);
        cout << "+---------+\n";
        gotoxy(76, 13);
        cout << "|(-)      |\n";
        gotoxy(76, 14);
        cout << "|         |\n";
        gotoxy(76, 15);
        cout << "|      (-)|\n";
        gotoxy(76, 16);
        cout << "+---------+\n";
    }
    if (d == 3)
    {
        gotoxy(76, 12);
        cout << "+---------+\n";
        gotoxy(76, 13);
        cout << "|      (-)|\n";
        gotoxy(76, 14);
        cout << "|   (-)   |\n";
        gotoxy(76, 15);
        cout << "|(-)      |\n";
        gotoxy(76, 16);
        cout << "+---------+\n";
    }
    if (d == 4)
    {
        gotoxy(76, 12);
        cout << "+---------+\n";
        gotoxy(76, 13);
        cout << "|(-)   (-)|\n";
        gotoxy(76, 14);
        cout << "|         |\n";
        gotoxy(76, 15);
        cout << "|(-)   (-)|\n";
        gotoxy(76, 16);
        cout << "+---------+\n";
    }
    if (d == 5)
    {
        gotoxy(76, 12);
        cout << "+---------+\n";
        gotoxy(76, 13);
        cout << "|(-)   (-)|\n";
        gotoxy(76, 14);
        cout << "|   (-)   |\n";
        gotoxy(76, 15);
        cout << "|(-)   (-)|\n";
        gotoxy(76, 16);
        cout << "+---------+\n";
    }
    if (d == 6)
    {
        gotoxy(76, 12);
        cout << "+---------+\n";
        gotoxy(76, 13);
        cout << "|(-)   (-)|\n";
        gotoxy(76, 14);
        cout << "|(-)   (-)|\n";
        gotoxy(76, 15);
        cout << "|(-)   (-)|\n";
        gotoxy(76, 16);
        cout << "+---------+\n";
    }
}

void result()
{
    ifstream in;
    in.open("gamedata.dat");
    if (!in)
    {
        cout << "File is not available";
        exit(1);
    }
    char ch;
    ch = in.get();

    while (!in.eof())
    {

        cout << ch;
        ch = in.get();
    }
    in.close();
}

void load()
{
    gotoxy(47, 5);
    cout << "Snake & Ladder";
    gotoxy(47, 25);
    cout << "Created by Praveen Kumar";
    gotoxy(40, 15);
    cout << "Please wait while game is loading";
    for (int l = 0; l <= 5; l++)
    {
        //char l1=(char)219;
        //cout<<l1;
        cout << " . ";
        Sleep(1000);
    }

    system("cls");
}

void snake() //snake color effect
{
    for (int s = 0; s < 3; s++)
    {
        system("color 40");
        Sleep(100);
        system("color f0");
        Sleep(100);
        system("color 40");
    }
}

void ladder() //ladder color effect
{
    for (int l = 0; l < 3; l++)
    {
        system("color 20");
        Sleep(100);
        system("color f0");
        Sleep(100);
        system("color 20");
    }
}

class game
{
public:
    int randomfunc(int &score)
    {
        int random;
        random = rand() % 6 + 1;
        gotoxy(45, 12);
        cout << "Your number on dice is " << random << endl;
        dic(random);
        if (score < 100)
        {
            if (score == 0 && random != 6)
            {
                gotoxy(50, 17);
                cout << "Try Again";
            }
            else if (score == 0 && random == 6)
            {
                score = 1;
            }
            else if (score < 100)
            {
                score = random + score;
            }
            if (score > 100)
            {
                score = score - random;
                gotoxy(50, 18);
                cout << "Try again";
            }
        }

        switch (score)
        {
        case 98:
            score = 28;
            gotoxy(45, 18);
            snake();
            cout << "you ran into a snake! (98-28)" << endl;
            break;
        case 95:
            score = 24;
            gotoxy(45, 18);
            snake();
            cout << "you ran into a snake! (95-24)" << endl;
            break;
        case 92:
            score = 51;
            gotoxy(45, 18);
            snake();
            cout << "you ran into a snake! (92-51)" << endl;
            break;
        case 83:
            score = 19;
            gotoxy(45, 18);
            snake();
            cout << "you ran into a snake! (83-19)" << endl;
            break;

        case 69:
            score = 33;
            gotoxy(45, 18);
            snake();
            cout << "you ran into a snake! (69-33)" << endl;
            break;
        case 64:
            score = 36;
            gotoxy(45, 18);
            snake();
            cout << "you ran into a snake! (64-36)" << endl;
            break;
        case 59:
            score = 17;
            gotoxy(45, 18);
            snake();
            cout << "you ran into a snake! (59-17)" << endl;
            break;
        case 55:
            score = 7;
            gotoxy(45, 18);
            snake();
            cout << "you ran into a snake! (55-7)" << endl;
            break;

        case 8:
            score = 26;
            gotoxy(45, 18);
            ladder();
            cout << "You got ladder (8-26)" << endl;
            break;
        case 21:
            score = 82;
            gotoxy(45, 18);
            ladder();
            cout << "you got ladder (21-82)" << endl;
            break;
        case 43:
            score = 77;
            gotoxy(45, 18);
            ladder();
            cout << "You got ladder (43-77)" << endl;
            break;
        case 50:
            score = 91;
            gotoxy(45, 18);
            ladder();
            cout << "You got ladder (50-91)" << endl;
            break;
        case 54:
            score = 93;
            gotoxy(45, 18);
            ladder();
            cout << "You got ladder  (54-93)" << endl;
            break;
        case 62:
            score = 96;
            gotoxy(45, 18);
            ladder();
            cout << "You got ladder (62-96)" << endl;
            break;
        case 80:
            score = 100;
            gotoxy(45, 18);
            ladder();
            cout << "You got ladder (80-100)" << endl;
        }
    }
};

class player : public game
{
public:
    int p1_score = 0, p2_score = 0;
    string player1, player2;

    player()
    {
        srand(time(0));
        gotoxy(40, 10);
        cout << "Enter the name of player 1 : ";
        cin >> player1;
        gotoxy(40, 12);
        cout << "Enter the name of player 2 : ";
        cin >> player2;
        system("cls");
        gotoxy(35, 10);
        cout << "The position of player1 and player2 is 0 initially" << endl;
        getch();
        system("cls");
        displayScore();

        while (p1_score < 100 && p2_score < 100)
        {
            system("color f0");
            gotoxy(40, 10);
            cout << "'" << player1 << "'"
                 << " it is your turn press enter to throw dice. " << endl;
            cin.get();
            randomfunc(p1_score);
            gotoxy(45, 14);
            cout << "Your score is " << p1_score << endl;
            getch();
            system("cls");
            displayScore(); //scoreboard

            system("color e0");
            gotoxy(40, 10);
            cout << "'" << player2 << "'"
                 << " it is your turn press enter to throw dice." << endl;
            cin.get();
            randomfunc(p2_score);
            gotoxy(45, 14);
            cout << "Your score is " << p2_score << endl;
            getch();
            system("cls");
            displayScore(); //scoreboard
        }
        ofstream f1; //file handling
        f1.open("gamedata.dat");
        if (p1_score > p2_score)
        {
            f1 << player1 << " won the game "
               << "with score of " << p1_score << endl;
            f1 << "Score of " << player2 << " was " << p2_score;
        }
        if (p2_score > p1_score)
        {
            f1 << player2 << " won the game "
               << "with score of " << p2_score << endl;
            f1 << "Score of " << player1 << " was " << p1_score;
        }
        if (p1_score == p2_score)
        {
            f1 << "That was a draw" << endl;
        }
        f1.close();

        system("color b0");
        if (p1_score > p2_score)
        {
            gotoxy(40, 10);
            cout << player1 << " won the game "
                 << "with score of " << p1_score << endl;
            gotoxy(40, 12);
            cout << player2 << " you lost the game ";
        }
        if (p2_score > p1_score)
        {
            gotoxy(40, 10);
            cout << player2 << " won the game "
                 << "with score of " << p2_score << endl;
            gotoxy(40, 12);
            cout << player1 << " you lost the game";
        }
        if (p1_score == p2_score)
        {
            gotoxy(40, 10);
            cout << "It's a draw" << endl;
            gotoxy(40, 12);
            cout << player1 << "&" << player2 << " you both were awesome";
        }
    }
    void displayScore() //scoreBoard
    {
        gotoxy(52, 1);
        cout << "SCORE BOARD";
        gotoxy(52, 3);
        cout << player1 << " : " << p1_score;
        gotoxy(52, 5);
        cout << player2 << " : " << p2_score;
        cout << "\n----------------------------------------------------------------------------------------------------------------------";
    }
};

int main()
{
    system("color 04");
    int i;
    getch();
    load(); //loading screen
    system("color a0");
    gotoxy(46, 3);
    cout << "MENU" << endl;
    gotoxy(40, 4);
    cout << "Select an option" << endl;
    gotoxy(40, 6);
    cout << "1.Play";
    gotoxy(40, 7);
    cout << "2.Result";
    gotoxy(40, 8);
    cout << "3.Exit";
    gotoxy(40, 12);
    cin >> i;
    system("cls");
    switch (i)
    {
    case 1:
    {

        player p;
        getch();
        system("cls");
        gotoxy(45, 10);
        cout << "Choose one ";
        gotoxy(45, 13);
        cout << "1.Replay";
        gotoxy(45, 15);
        cout << "2.Go to MENU";
        int c;
        gotoxy(45, 18);
        cin >> c;
        system("cls");
        switch (c)
        {
        case 1:
        {
            player p;
            getch();
            system("cls");
            gotoxy(45, 10);
            cout << "Game Over";
            gotoxy(45, 15);
            cout << "Press Enter to GO to MENU";
            getch();
            system("cls");
            main();
        }
        case 2:
        {
            system("cls");
            main();
        }
        }
    }

    case 2:
    {
        gotoxy(40, 1);
        result(); //showing previous result
        gotoxy(45, 18);
        cout << "Press Enter to go to MENU";
        getch();
        system("cls");
        main();
    }

    case 3:
    {

        gotoxy(40, 15);
        system("color 04");
        cout << "We will feel glad to see you later!";
        Sleep(4000);
        exit(0);
    }

    default:
    {
        cout << "Invalid option";
        gotoxy(50, 18);
        system("color f4");
        cout << "Click Enter to go to MENU";
        getch();
        system("cls");
        main();
    }
    }
    getch();
}
