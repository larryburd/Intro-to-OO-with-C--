#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Order {
    public:
        double amount;
        double price;
        string timestamp;
        string products;
        string orderType;

        Order(string, string, string, double, double);
};

// Order constructor
Order::Order(string _timestamp, string _products,
             string _orderType, double _amount, double _price) : price(_price), 
             amount(_amount), timestamp(_timestamp), products(_products), 
             orderType(_orderType) {}

// Function prototypes
int getUserOption();
void printMenu();
void processUserOption(int, vector<Order>*);
vector<string> readOrderData();
void processOrderData(vector<string>*, vector<Order>*);

int main() {
    int userOption = 1;
    vector<string> orderDataText = readOrderData();
    vector<Order> orders;
    processOrderData(&orderDataText, &orders);
    while (userOption >= 1 && userOption <= 6) {
        printMenu();
        userOption = getUserOption();
        processUserOption(userOption, &orders); 
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

void processOrderData(vector<string> *ptrOrderDataText, vector<Order> *ptrOrders) {
    vector<string> tempOO; //temporary Order object
    string::size_type n;
    char del = ','; // Delimiter

    for (int i = 0; i < (*ptrOrderDataText).size(); i++) {
        n = (*ptrOrderDataText)[i].find(del);
        
        while(n != string::npos) {
            tempOO.push_back((*ptrOrderDataText)[i].substr(0, n));
            (*ptrOrderDataText)[i].erase(0, n + 1);
            n = (*ptrOrderDataText)[i].find(del);
        }

        if ((*ptrOrderDataText)[i].length() >= 1) {
            // Get the text after the last deliminator
            tempOO.push_back((*ptrOrderDataText)[i]);
        }

        if (tempOO.size() == 5) { // We have the right amount of info
            (*ptrOrders).push_back(Order{tempOO[0], tempOO[1], tempOO[2], stod(tempOO[3]), stod(tempOO[4])});
        } 

        tempOO.clear(); // Reset for next run
    }
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
    cout << "Any Other Number: Exit Program" << endl;

    cout << "==============================" << endl;
    cout << "Selection an option 1-6" << endl;

}

void invalidSelectionNotification() {
    cout << "Invalid Selection. Choos 1-7" << endl << endl;
}

void printHelp() {
    cout << "Help - your aim is to use this exchange to purchase and sell various crypto currencies." << endl;
}

void printStats(vector<Order> *ordersLedger) {
    cout << "\nNumber of Orders: " << (*ordersLedger).size() << endl;
    cout << "{" << endl;
    for(Order& order: *ordersLedger) {
        cout << "\n" << "   Timestamp: " << order.timestamp << endl;
        cout << "   Products: " << order.products << endl;
        cout << "   Type: " << order.orderType << endl;
        cout << "   Price: "<< order.price << endl;
        cout << "   Amount: " << order.amount << endl;
    }
    cout << "}\n" << endl;
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
void processUserOption(int userOption, vector<Order> *ptrOrdersLedger) {
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
            cout << "Exiting..." << endl << endl;
        }
}
//END REGION