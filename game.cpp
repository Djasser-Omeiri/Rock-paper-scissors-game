#include <iostream>
#include <cmath>
#include <windows.h>
#include <cstdlib>
using namespace std;
enum Game
{
    Paper = 1,
    Scissors = 2,
    Rock = 3
};
struct roundresult
{
    string playerchoice;
    string computerchoice;
    string thewinner;
};
struct gameresult
{
    short userwon = 0;
    short computerwon = 0;
    short drawtimes = 0;
    string finalwinner;
};
short randomnumberf(short from, short to)
{
    short randnumber = rand() % (to - from + 1) + from;
    return randnumber;
}
short numberofrounds()
{
    short rounds;
    cout << "How many rounds you wanna play from 1 to 10?\n";
    cin >> rounds;
    return rounds;
}
Game choosingf()
{
    short number;
    do
    {
        cout << "\nYOUR CHOICE : [1]:Paper ,[2]:Scissors ,[3]:Rock\n";
        cin >> number;
    } while (number > 3 || number < 1);
    return (Game)number;
}
Game computerchooserandomely()
{
    return (Game)randomnumberf(1, 3);
}
void roundresultmessage(roundresult roundinfo, short roundnumber)
{
    cout << "\n--------------Round[" << roundnumber << "]--------------\n";
    cout << "User choice: " << roundinfo.playerchoice;
    cout << "\nComputer choice: " << roundinfo.computerchoice;
    cout << "\nThe winner is: " << roundinfo.thewinner;
    cout << "\n------------------------------------\n";
}
void comparing_computer_and_user_inputround(roundresult &roundinfo, gameresult &gameinfo)
{
    Game userchoice = choosingf();
    Game computerchoice = computerchooserandomely();
    if (computerchoice == userchoice)
    {
        system("color 6F"); // turn screen to Yellow
        gameinfo.drawtimes++;
        roundinfo.thewinner = "[No Winner]";
    }
    else if ((computerchoice == Game::Paper && userchoice == Game::Rock) ||
             (computerchoice == Game::Rock && userchoice == Game::Scissors) ||
             (computerchoice == Game::Scissors && userchoice == Game::Paper))
    {
        system("color 4F");
        cout << "\a";
        gameinfo.computerwon++; // turn screen to Red
        roundinfo.thewinner = "The Computer ";
    }
    else if ((computerchoice == Game::Paper && userchoice == Game::Scissors) ||
             (computerchoice == Game::Rock && userchoice == Game::Paper) ||
             (computerchoice == Game::Scissors && userchoice == Game::Rock))
    {
        system("color 2F"); // turn screen to Green
        roundinfo.thewinner = "The user ";
        gameinfo.userwon++;
    }
    if (computerchoice == Paper)
    {
        roundinfo.computerchoice = "Paper";
    }
    else if (computerchoice == Rock)
    {
        roundinfo.computerchoice = "Rock";
    }
    else if (computerchoice == Scissors)
    {
        roundinfo.computerchoice = "Scissors";
    }
    if (userchoice == Paper)
    {
        roundinfo.playerchoice = "Paper";
    }
    else if (userchoice == Rock)
    {
        roundinfo.playerchoice = "Rock";
    }
    else if (userchoice == Scissors)
    {
        roundinfo.playerchoice = "Scissors";
    }
}
void roundnumbermessage(short i)
{
    cout << "\n----------------------Round[" << i << "]----------------------\n";
}
void gameresultmessage(gameresult gameinfo, short roundnumber)
{
    cout << "                             --------------------------------------------------------------------------------\n";
    cout << "                                                                 +++ G a m e  O v e r +++\n";
    cout << "                             --------------------------------------------------------------------------------\n\n";
    cout << "                             -------------------------------- [Game Results] --------------------------------\n";
    cout << "                             Game Rounds         : " << roundnumber << endl;
    cout << "                             User won times      : " << gameinfo.userwon << "\n";
    cout << "                             Computer won times  : " << gameinfo.computerwon << "\n";
    cout << "                             Draw times          : " << gameinfo.drawtimes << "\n";
    cout << "                             Final Winner        : " << gameinfo.finalwinner << "\n";
    cout << "                             --------------------------------------------------------------------------------\n";
}
void comparinggameresults(gameresult &gameinfo)
{
    if (gameinfo.userwon > gameinfo.computerwon)
    {
        gameinfo.finalwinner = " The user ";
    }
    else if (gameinfo.userwon < gameinfo.computerwon)
    {
        gameinfo.finalwinner = " The computer ";
    }
    else
    {
        gameinfo.finalwinner = " No winner";
    }
}
void startgame()
{
    char repeatgame = 'y';
    do
    {
        roundresult round;
        gameresult game;
        system("cls");
        system("color 0F"); // reset screen
        short n = numberofrounds();
        for (short i = 0; i < n; i++)
        {
            roundnumbermessage(i + 1);
            comparing_computer_and_user_inputround(round, game);
            roundresultmessage(round, i + 1);
        }
        comparinggameresults(game);
        gameresultmessage(game, n);

        cout << "Do u want to play again?[y]:YES ,[n]:NO \n";
        cin >> repeatgame;
    } while (repeatgame == 'y' || repeatgame == 'Y');
}
int main()
{
    srand((unsigned)time(NULL));
    startgame();
    return 0;
}
