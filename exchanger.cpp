#include <iostream>

using namespace std;

int getUserOption() {
    int userSelection;
    cin >> userSelection;
    return userSelection;
}

void printMenu() {
    // 1: Print help
    cout << "1: Print Help" << endl;
    // 2: Print stats
    cout << "2: Print Exchange Stats" << endl;
    // 3: Make an offer
    cout << "3: Make an offer" << endl;
    // 4: Make a bid
    cout << "4: Make a bid" << endl;
    // 5: print wallet
    cout << "5: Print Wallet" << endl;
    // 6: Next time step
    cout << "6: Next Time Step" << endl;
    // 7: Exit
    cout << "7: Exit Program" << endl;

    cout << "=================" << endl;
    cout << "Selection an option 1-7" << endl;

}

void invalidSelectionNotification() {
    cout << "Invalid Selection. Choos 1-7" << endl << endl;
}

void printHelp() {
    cout << "Help - your aim is to use this exchange to purchase and sell various crypto currencies." << endl;
}

void printStats() {
    cout << "Stats Placeholder" << endl << endl;
}

void makeOffer() {
    cout << "Offer PlaceHolder" << endl << endl;
}

void makeBid() {
    cout << "Bid PlaceHolder" << endl<< endl;
}

void printWallet() {
    cout << "Wallet PlaceHolder" << endl << endl;
}

void nextTimeStep() {
    cout << "Continue Placeholder" << endl << endl;
}

/** Processes the user's request by taking in an int that is between 1 and 7 */
void processUserOption(int userOption) {
    enum menOpt {
        INVALID     = 0,
        HELP        = 1,
        STATS       = 2,
        OFFER       = 3,
        BID         = 4,
        WALLET      = 5,
        CONTINUE    = 6,
        EXIT        = 7
    };

    switch (userOption) {
        case menOpt::INVALID: 
            invalidSelectionNotification();
            break;
        case menOpt::HELP:
            printHelp();
            break;
        case menOpt::STATS:
            printStats();
            break;
        case menOpt::OFFER:
            makeOffer();
            break;
        case menOpt::BID:
            makeBid();
            break;
        case menOpt::WALLET:
            printWallet();
            break;
        case menOpt::CONTINUE:
            nextTimeStep();
            break;
        case menOpt::EXIT: // Exit case
            cout << "Exiting..." << endl << endl;
        }
}

int main() {
    int userOption = 1;

    while (userOption != 7) {
        printMenu();
        userOption = getUserOption();
        processUserOption(userOption); 
    }

    return 0;
}
