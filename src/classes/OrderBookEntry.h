#ifndef ORDER_BOOK_ENTRY
#define ORDER_BOOK_ENTRY

#include <string>
#include "OrderBookType.h"

class OrderBookEntry {
    private:
        double amount, price;
        std::string timestamp, products;
        OrderBookType orderType;

    public:
        OrderBookEntry(double, double, std::string, std::string, OrderBookType);
        double getAmount();
        double getPrice();
        std::string getTimestamp();
        std::string getProducts();
        OrderBookType getOrderType();
        std::string getOrderTypeText();

        void setAmount(double);
        void setPrice(double);
        void setTimestamp(std::string);
        void setProducts(std::string);
        void setOrderType(OrderBookType);
};

#endif