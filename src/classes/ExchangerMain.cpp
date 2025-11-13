#include "ExchangerMain.h"

ExchangerMain::ExchangerMain(std::vector<OrderBookEntry> _orders) : orders(_orders) {}

void ExchangerMain::init() {
    int uInput = 1;

    while(uInput >= 1 && uInput <7) {
        printMenu();
        uInput = getUserOption();
        processUserOption(uInput, &orders);
    }

}

int ExchangerMain::getUserOption() {
    int userSelection;
    std::cin >> userSelection;
    return userSelection;
}

void ExchangerMain::printMenu() {
    // 1: Print help
    std::cout << "1: Print Help" << std::endl;
    // 2: Print stats
    std::cout << "2: Print Exchange Stats" << std::endl;
    // 3: Make an offer
    std::cout << "3: Make an offer" << std::endl;
    // 4: Make a bid
    std::cout << "4: Make a bid" << std::endl;
    // 5: print wallet
    std::cout << "5: Print Wallet" << std::endl;
    // 6: Next time step
    std::cout << "6: Next Time Step" << std::endl;
    // 7: Exit
    std::cout << "Any Other Number: Exit Program" << std::endl;

    std::cout << "==============================" << std::endl;
    std::cout << "Selection an option 1-6" << std::endl;

}

/** Processes the user's request by taking in an int that is between 1 and 7 */
void ExchangerMain::processUserOption(int userOption, std::vector<OrderBookEntry> *ptrOrdersLedger) {
    switch (userOption) {
        case menOpt::INVALID: 
            invalidSelectionNotification();
            break;
        case menOpt::HELP:
            printHelp();
            break;
        case menOpt::STATS:
            printStats(ptrOrdersLedger); // Passing by reference
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
            std::cout << "Exiting..." << std::endl << std::endl;
        }
}

void ExchangerMain::invalidSelectionNotification() {
    std::cout << "Invalid Selection. Choos 1-7" << std::endl << std::endl;
}

void ExchangerMain::printHelp() {
    std::cout << "Help - your aim is to use this exchange to purchase and sell various crypto currencies." << std::endl;
}

void ExchangerMain::printStats(std::vector<OrderBookEntry> *ordersLedger) {
    std::cout << "\nNumber of Orders: " << (*ordersLedger).size() << std::endl;
    std::cout << "{" << std::endl;
    for(OrderBookEntry& order: *ordersLedger) {
        std::cout << "\n" << "   Timestamp: " << order.getTimestamp() << std::endl;
        std::cout << "   Products: " << order.getProducts() << std::endl;
        std::cout << "   Type: " << order.getOrderTypeText() << std::endl;
        std::cout << "   Price: "<< order.getPrice() << std::endl;
        std::cout << "   Amount: " << order.getAmount() << std::endl;
    }
    std::cout << "}\n" << std::endl;
}

void ExchangerMain::makeOffer() {
    std::cout << "Offer PlaceHolder" << std::endl << std::endl;
}

void ExchangerMain::makeBid() {
    std::cout << "Bid PlaceHolder" << std::endl<< std::endl;
}

void ExchangerMain::printWallet() {
    std::cout << "Wallet PlaceHolder" << std::endl << std::endl;
}

void ExchangerMain::nextTimeStep() {
    std::cout << "Continue Placeholder" << std::endl << std::endl;
}