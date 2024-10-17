#include <iostream>
#include <stdlib.h>
#include <time.h>
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"
using namespace std;

void displayScore(string name, int player_score, int computer_score) {
    cout << "SCOREBOARD\n";
    cout << name << " : " << player_score << " | Computer : " << computer_score << endl;
}

void displayFinalResult(string name, int player_score, int computer_score) {
    if (player_score > computer_score) {
        cout << GREEN << "\n*******************************************" << RESET << endl;
        cout << GREEN << "*                                         *" << RESET << endl;
        cout << GREEN << "*           Congratulations!              *" << RESET << endl;
        cout << GREEN << "*           You are the winner!           *" << RESET << endl;
        cout << GREEN << "*                                         *" << RESET << endl;
        cout << GREEN << "*******************************************" << RESET << endl; 
    } else if (computer_score > player_score) {
        cout << RED << "\n*******************************************" << RESET << endl;
        cout << RED << "*                                         *" <<  RESET << endl;
        cout << RED << "*                 You Lost!               *" <<  RESET << endl;
        cout << RED << "*            Computer is the winner!      *" <<  RESET << endl;
        cout << RED << "*                                         *" <<  RESET << endl;
        cout << RED << "*******************************************" <<  RESET << endl;
    } else {
        cout <<  "\n*******************************************" << endl;
        cout <<  "*                                         *" << endl;
        cout <<  "*              It's a tie!                *" << endl;
        cout <<  "*                                         *" << endl;
        cout <<  "*******************************************" << endl;
    }
}

int getPlayerChoice() {
    int choice;
    while (true) {
        cout << "Press 1 for Rock, 2 for Paper, and 3 for Scissors: ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 3) {
            cin.clear(); 
            cin.ignore(10000, '\n');
            cout << "Invalid choice. Please try again." << endl;
        } else {
            return choice;
        }
    }
}

int getRounds() {
    int round;
    while (true) {
        cout << "How many rounds do you want to play? ";
        cin >> round;
        if (cin.fail() || round <= 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a positive number." << endl;
        } else {
            return round;
        }
    }
}

int main() {
    int choice, computer, x, player_score = 0, computer_score = 0;
    string name;
    srand(time(NULL));

    // Username
    cout << "Welcome to the Rock Paper Scissors game." << endl;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);

    // Main menu loop
    while (true) {
        cout << "Press 1 to start the game, 2 for rules, and 3 to exit." << endl;
        cin >> x;

        if (x == 1) {
            

            int round = getRounds();

            // Game rounds loop
            for (int i = 0; i < round; i++) {
                cout << "   " << endl;

                // Player's choice
                choice = getPlayerChoice();

                // Computer's choice
                computer = 1 + rand() % 3;
                if (computer == 1) {
                    cout << "Computer's choice = Rock" << endl;
                } else if (computer == 2) {
                    cout << "Computer's choice = Paper" << endl;
                } else {
                    cout << "Computer's choice = Scissors" << endl;
                }

                // Determine round result
                if (choice == computer) {
                    cout << "Round draw." << endl;
                } else if ((choice == 1 && computer == 3) || 
                           (choice == 2 && computer == 1) || 
                           (choice == 3 && computer == 2)) {
                    cout << "You Won." << endl;
                    player_score++;
                } else {
                    cout << "You Lost." << endl;
                    computer_score++;
                }

                // Display current score
                displayScore(name, player_score, computer_score);
            }

            // Display final result
            displayFinalResult(name, player_score, computer_score);
            
            // Play again option
            char play_again;
            cout << "Do you want to play again? (y/n): ";
            cin >> play_again;
            if (play_again == 'n' || play_again == 'N') {
                cout << "Thanks for playing!" << endl;
                break;
            }

        } else if (x == 2) {
            // Display rules
            cout << "   " << endl;
            cout << "Each round is worth 1 point.\nNeither side receives points in case of a tie.\nRock > Scissors\nScissors > Paper\nPaper > Rock" << endl;
            cout << "   " << endl;
        } else if (x == 3) {
            cout << "Exiting..." << endl;
            break;
        } else {
            // Invalid main menu option
            cout << "You made an invalid choice, redirecting to the main menu." << endl;
        }
    }

    return 0;
}

