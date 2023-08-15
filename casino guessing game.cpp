#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Set the random seed based on the current time
    srand(static_cast<unsigned int>(time(0)));

    const int minNumber = 1;
    const int maxNumber = 100;
    const int initialMoney = 100;
    int playerMoney = initialMoney;

    cout << "Welcome to the Casino Number Guessing Game!" << endl;
    cout << "You have $" << playerMoney << " to start with." << endl;

    char playAgain;

    do {
        int randomNumber = rand() % (maxNumber - minNumber + 1) + minNumber;
        int betAmount;

        cout << "Place your bet (Current balance: $" << playerMoney << "): $";
        cin >> betAmount;

        if (betAmount > playerMoney) {
            cout << "Sorry, you don't have enough money for that bet." << endl;
            cout << "Your current balance: $" << playerMoney << endl;
            continue;
        }

        int playerGuess;
        cout << "Guess a number between " << minNumber << " and " << maxNumber << ": ";
        cin >> playerGuess;

        if (playerGuess == randomNumber) {
            int prize = betAmount * 2;
            playerMoney += prize;
            cout << "Congratulations! You guessed the correct number!" << endl;
            cout << "You won $" << prize << "!" << endl;
        } else {
            playerMoney -= betAmount;
            cout << "Sorry, the correct number was: " << randomNumber << endl;
        }

        cout << "Your current balance: $" << playerMoney << endl;

        if (playerMoney <= 0) {
            cout << "You have run out of money. Game Over!" << endl;
            break;
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing the Casino Number Guessing Game!" << endl;

    return 0;
}

