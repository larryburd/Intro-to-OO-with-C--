#include <string>
#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry(double _price, double _amount, 
                               std::string _timestamp, std::string _products, 
                               OrderBookType _orderType) 
                               : price(_price), amount(_amount), 
                               timestamp(_timestamp), products(_products), 
                               orderType(_orderType) {

}

double OrderBookEntry::getAmount() {
    return amount;
}

double OrderBookEntry::getPrice(){
    return price;
}

std::string OrderBookEntry::getTimestamp(){
    return timestamp;
}

std::string OrderBookEntry::getProducts() {
    return products;
}

OrderBookType OrderBookEntry::getOrderType() {
    return orderType;
}

std::string OrderBookEntry::getOrderTypeText() {
    if (orderType == OrderBookType::bid) {
        return "bid";
    } else {
        return "ask";
    }
}

void OrderBookEntry::setAmount(double val) {
    amount = val;
}

void OrderBookEntry::setPrice(double val) {
    price = val;
}

void OrderBookEntry::setTimestamp(std::string val) {
    timestamp = val;
}

void OrderBookEntry::setProducts(std::string val) {
    products = val;
}

void OrderBookEntry::setOrderType(OrderBookType val) {
    orderType = val;
}