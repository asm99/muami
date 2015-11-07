/*
 * MELKONIAN Marc - 13410425
 * Addresses.hpp - a collection of Address used in CC or BCC fields
 */

#ifndef ADDRESSES_H
#define ADDRESSES_H

#include <iostream>
#include <sstream>
#include <vector>
#include "Address.hpp"
#include "../debug/debug.hpp"

using namespace std;

class Addresses
{
    private:
        vector<Address*> addrs;

    public:
        Addresses(): addrs() {};
        ~Addresses() {};

        unsigned int size();

        // Setters
        void add_address(Address* a);
        void add_addresses(string s);

        // DEBUG
        void dump();

        // Operators overload
        Address* at(unsigned int i);
        Address* operator[](unsigned int i);
};

istream& operator>>(istream& is, Addresses* addresses);

#endif /* end of include guard: ADDRESSES_H */
