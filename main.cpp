#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

class Game
{
private:
    int user;
    int comp;

public:
    Game()
    {
        printASCII("art/logo.txt");
        user = 0;
        comp = 0;
    }

    ~Game()
    {
        printASCII("art/Thank_you.txt");
    }

    int getUserScore()
    {
        return user;
    }
    int getCompScore()
    {
        return comp;
    }

    void printASCII(string fileName)
    {
        string line = "";
        fstream inFile;
        inFile.open(fileName);
        if (inFile.is_open())
        {
            while (getline(inFile, line))
            {
                cout << line << endl;
            }
        }
        else
        {
            cout << "File Failed to load. " << endl;
            cout << "No displayed." << endl;
        }
        inFile.close();
    }

    int randomIntNumber(int num)
    {
        int randint;
        srand(time(0));
        randint = rand() % num + 1;
        return randint;
    }

    void display_choice(int users_choice, int computer_choice)
    {
        cout << "Your Choose " << users_choice << " is:" << endl;
        if (users_choice == 1)
        {
            printASCII("art/rock.txt");
        }
        else if (users_choice == 2)
        {
            printASCII("art/paper.txt");
        }
        else
        {
            printASCII("art/scissors.txt");
        }

        cout << "Computer Choose " << computer_choice << " is:" << endl;
        if (computer_choice == 1)
        {
            printASCII("art/rock.txt");
        }
        else if (computer_choice == 2)
        {
            printASCII("art/paper.txt");
        }
        else
        {
            printASCII("art/scissors.txt");
        }
    }

    void winner(int users_choice, int computer_choice)
    {
        if ((users_choice == 1 and computer_choice == 3) or (users_choice == 2 and computer_choice == 1) or (users_choice == 3 and computer_choice == 2))
        {
            printASCII("art/win.txt");
            user++;
        }
        else if ((users_choice == 1 and computer_choice == 1) or (users_choice == 2 and computer_choice == 2) or (users_choice == 3 and computer_choice == 3))
        {
            printASCII("art/draw.txt");
            comp++;
            user++;
        }
        else
        {
            printASCII("art/lose.txt");
            comp++;
        }
    }
};

int main()
{
    int users_choice, computer_choice;
    bool play;
    Game g;

    try
    {
        play = true;
        while (play)
        {
            int user_score, comp_score;
            user_score = g.getUserScore();
            comp_score = g.getCompScore();

            if (user_score == 0 and comp_score == 0)
            {
                cout << endl;
            }
            else
            {
                cout << "Your score = " << user_score << endl;
                cout << "Computer score = " << comp_score << endl;
            }

            cout << "What do you choose? Type 1 for Rock ,2 for Paper , 3 for Scissors or 4 for stop the game. \nEnter the your choose = ";
            cin >> users_choice;
            if (users_choice >= 1 && users_choice <= 3)
            {
                computer_choice = g.randomIntNumber(3);

                g.display_choice(users_choice, computer_choice);

                g.winner(users_choice, computer_choice);
            }
            else if (users_choice == 4)
            {
                play = false;
                if (user_score > comp_score)
                {
                    g.printASCII("art/user_win.txt");
                }
                else if (user_score == comp_score)
                {
                    g.printASCII("art/game_draw.txt");
                }
                else
                {
                    g.printASCII("art/comp_win.txt");
                }
            }
            else
            {
                throw users_choice;
            }
        }
    }
    catch (...)
    {
        cout << "Invalid choice" << endl;
    }

    return 0;
}