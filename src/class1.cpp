#include <eosio/eosio.hpp>
#include <eosio/name.hpp>
#include <string>

#include "class1.hpp"

using namespace eosio;
using std::string;
using namespace contract_name;

void class1_contract::sayhi()
{
    print("Hi");
}

void class1_contract::sayhialice(const name& someone)
{
    check(someone == "alice"_n, "You may only say hi to Alice!");
    print("Hi, Alice!");
}
