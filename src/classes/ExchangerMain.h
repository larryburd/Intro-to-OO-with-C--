#pragma once

#include "OrderBookType.h"
#include "OrderBookEntry.h"
#include <string>
#include <vector>
#include <iostream>


class ExchangerMain {

    private:
        std::vector<OrderBookEntry> orders;
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

        void printMenu();
        int getUserOption();
        void processUserOption(int, std::vector<OrderBookEntry>*);
        void invalidSelectionNotification();
        void printHelp();
        void printStats(std::vector<OrderBookEntry>*);
        void makeOffer();
        void makeBid();
        void printWallet();
        void nextTimeStep();
    
    public:
        ExchangerMain(std::vector<OrderBookEntry>);
        void init();

};