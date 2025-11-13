#include <iostream>
#include <string>
#include <vector>
#include "classes/OrderBookEntry.h"
#include "classes/OrderBookType.h"
#include "classes/ExchangerMain.h"

std::vector<std::string> readOrderData();
void processOrderData(std::vector<std::string>*, std::vector<OrderBookEntry>*);
OrderBookType stoobt(std::string);

int main() {
    std::vector<std::string> orderDataText = readOrderData();
    std::vector<OrderBookEntry> orders;
    
    processOrderData(&orderDataText, &orders);
    ExchangerMain main(orders);

    main.init();

    return 0;
}

// REGION: Function implementations
std::vector<std::string> readOrderData() {
    std::vector<std::string> orderData;

    orderData.push_back("2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869");
    orderData.push_back("2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187307,3.467434");

    return orderData;
}

void processOrderData(std::vector<std::string> *ptrOrderDataText, std::vector<OrderBookEntry> *ptrOrders) {
    std::vector<std::string> tempOO; //temporary Order object
    std::string::size_type n;
    OrderBookType orderType;
    char del = ','; // Delimiter

    for (int i = 0; i < (*ptrOrderDataText).size(); i++) {
        n = (*ptrOrderDataText)[i].find(del);
        
        while(n != std::string::npos) {
            tempOO.push_back((*ptrOrderDataText)[i].substr(0, n));
            (*ptrOrderDataText)[i].erase(0, n + 1);
            n = (*ptrOrderDataText)[i].find(del);
        }

        if ((*ptrOrderDataText)[i].length() >= 1) {
            // Get the text after the last deliminator
            tempOO.push_back((*ptrOrderDataText)[i]);
        }

        if (tempOO.size() == 5) { // We have the right amount of info
            orderType = stoobt(tempOO[2]);
            // (*ptrOrders).push_back(OrderBookEntry{tempOO[0], tempOO[1], orderType, 
            //                                       stod(tempOO[3]), stod(tempOO[4])});
            (*ptrOrders).push_back(OrderBookEntry{
                stod(tempOO[3]), stod(tempOO[4]), tempOO[0], tempOO[1], orderType
            });
        } 

        tempOO.clear(); // Reset for next run
    }
}

/**
 * Transforms a string of value "ask" or "bid" to the corrisponding OrderBookType value
 */
OrderBookType stoobt(std::string orderTypeText) {
    if (orderTypeText == "bid") {
        return OrderBookType::bid;
    } else if (orderTypeText == "ask"){
        return OrderBookType::ask;
    } else {
        return OrderBookType::error;
    }
}