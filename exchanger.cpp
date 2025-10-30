#include <iostream>
#include <string>
#include <vector>

using namespace std;



struct Order {
    enum class OrderBookType { bid, ask };
    
    double amount;
    double price;
    string timestamp;
    string products;
    string orderType;
};

// Function declerations
int getUserOption(){}
void printMenu(){}
void processUserOption(int userOption, vector<Order> orderLedger) {}
vector<string> readOrderData(){}
vector<Order> processOrderData(vector<string> orderDataText){}

int main() {
    int userOption = 1;
    vector<string> orderDataText = readOrderData();
    vector<Order> orders = processOrderData(orderDataText);
    while (userOption != 7) {
        printMenu();
        userOption = getUserOption();
        processUserOption(userOption, orders); 
    }

    return 0;
}

// REGION: Function implementations
vector<string> readOrderData() {
    vector<string> orderData;

    orderData.push_back("2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869");
    orderData.push_back("2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187307,3.467434");

    return orderData;
}

vector<Order> processOrderData(vector<string> orderDataText) {
    vector<Order> orders;
    vector<string> tempOrderData;
    Order tempOrder;
    string::size_type n;
    char del = ',';

    for (int i = 0; i < orders.size(); i++) {
        n = orderDataText[i].find(del);
        
        while(n != string::npos) {
            tempOrderData.push_back(orderDataText[i].substr(0, n));
            orderDataText[i].erase(0, n + 1);
            n = orderDataText[i].find(del);
        }

            tempOrder.timestamp = tempOrderData[0];
            tempOrder.products = tempOrderData[1];
            tempOrder.orderType = tempOrderData[2];
            tempOrder.price = stod(tempOrderData[3]);
            tempOrder.amount = stod(tempOrderData[4]);

            orders.push_back(tempOrder);
        }

    return orders;
}

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

void printStats(vector<Order> ordersLedger) {
    cout << "Stats Placeholder" << endl << endl;

    for(Order order: ordersLedger) {
        cout << "\nTimestamp: " << order.timestamp << endl;
        cout << "\nProducts: " << order.products << endl;
        cout << "\nType: " << order.orderType << endl;
        cout << "\nPrice: "<< order.price << endl;
        cout << "\nAmount: " << order.amount << endl;
    }
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
void processUserOption(int userOption, vector<Order> ordersLedger) {
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
            printStats(ordersLedger);
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
//END REGION