#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum class OrderBookType {bid, ask};

class OrderBookEntry {
    private:
        double amount;
        double price;
        string timestamp;
        string products;
        OrderBookType orderType;

    public:
        // Constructor prototype
        OrderBookEntry(string, string, OrderBookType, double, double);

        // Getters...there is no need for setters at this point
        double getAmount(){return amount;}
        double getPrice(){return price;}
        string getTimestamp(){return timestamp;}
        string getProducts(){return products;}
        OrderBookType getOrderType(){return orderType;}
};

// Order constructor implementation
OrderBookEntry::OrderBookEntry(string _timestamp, string _products,
             OrderBookType _orderType, double _amount, double _price) : price(_price), 
             amount(_amount), timestamp(_timestamp), products(_products), 
             orderType(_orderType) {}

// Function prototypes
double computeAveragePrice(vector<OrderBookEntry>&);
double computeLowPrice(vector<OrderBookEntry>& );
double computeHighPrice(vector<OrderBookEntry>&);
double computePriceSpread(double, double);
vector<string> readOrderData();
void processOrderData(vector<string>&, vector<OrderBookEntry>&);

int main(int argc, char* argv[]) {
    double lowPrice, highPrice, spread, avgPrice;
    vector<OrderBookEntry> entries;
    vector<string> entryText;

    entryText = readOrderData();
    processOrderData(entryText, entries);

    lowPrice = computeLowPrice(entries);
    highPrice = computeHighPrice(entries);
    avgPrice = computeAveragePrice(entries);
    spread = computePriceSpread(lowPrice, highPrice);

    cout << "Stats for all order entries" << endl;
    cout << "===========================" << endl;
    cout << "Average Price: " << avgPrice << endl;
    cout << "Lowest Price: " << lowPrice << endl;
    cout << "Highest Price: " << highPrice << endl;
    cout << "Price Spread: " << spread << endl;

    return 0;
}



// Function implementations
double computeAveragePrice(vector<OrderBookEntry>& entries) {
    double avgPrice, sum;

    for (OrderBookEntry& e : entries) {
        sum += e.getPrice();
    }

    avgPrice = sum / entries.size();

    return avgPrice;
}

double computeLowPrice(vector<OrderBookEntry>& entries) {
    double lowPrice;

    for (OrderBookEntry& e : entries) {
        if (!lowPrice) {
            lowPrice = e.getPrice();
        } else {
            lowPrice = min(lowPrice, e.getPrice());
        }
    }
    
    return lowPrice;
}

double computeHighPrice(vector<OrderBookEntry>& entries) {
    double highPrice;
    
    for (OrderBookEntry& e : entries) {
        if (!highPrice) {
            highPrice = e.getPrice();
        } else {
            highPrice = max(highPrice, e.getPrice());
        }
    }
    return highPrice;
}

double computePriceSpread(double lowPrice, double highPrice) {
    return highPrice - lowPrice;
}

/** 
 * Creates mock data of crypto orders and returns them as a vector of strings 
 */
vector<string> readOrderData() {
    vector<string> orderData;

    orderData.push_back("2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869");
    orderData.push_back("2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187307,3.467434");
    orderData.push_back("2020/03/17 17:01:24.884492,ETH/BTC,ask,0.02210226,0.086064");

    return orderData;
}

/** 
 * Takes a vector of strings that represent crypto orders and processes them into a vector of OrderBookEntries
 */
void processOrderData(vector<string>& OrderDataText, vector<OrderBookEntry>& entries) {
    string::size_type n;
    OrderBookType oType;
    char del = ','; // Delimiter to sperate the string by

    for (int i = 0; i < (OrderDataText).size(); i++) {
        vector<string> tempOO; //temporary Order object, recreated each iteration
        n = OrderDataText[i].find(del);
        
        while(n != string::npos) {
            if (i == 2) {
                string oTypeText = (OrderDataText)[i];
                if (oTypeText == "bid") {
                    oType = OrderBookType::bid;
                } else {
                    oType = OrderBookType::ask;
                }
            }
            tempOO.push_back(OrderDataText[i].substr(0, n));
            OrderDataText[i].erase(0, n + 1);
            n = OrderDataText[i].find(del);
        }

        // Get the text after the last deliminator
        if (OrderDataText[i].length() >= 1) {
            tempOO.push_back(OrderDataText[i]);
        }

        if (tempOO.size() == 5) { // We have the right amount of info
            entries.push_back(OrderBookEntry{tempOO[0], tempOO[1], oType, stod(tempOO[3]), stod(tempOO[4])});
        } 
    }
}
