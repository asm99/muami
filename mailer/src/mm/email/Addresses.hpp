#ifndef ADDRESSES_H
#define ADDRESSES_H

#include <iostream>
#include <sstream>
#include <vector>
#include "Address.hpp"

using namespace std;

class Addresses
{
    private:
        vector<Address*> addrs;

    public:
        Addresses(): addrs() {};
        ~Addresses();

        unsigned int size();
        void add_addresses(string s);
        void dump();
        Address* operator[](unsigned int i);
};

istream& operator>>(istream& is, Addresses* addresses);

#endif /* end of include guard: ADDRESSES_H */
