#pragma once

#include <eosio/asset.hpp>
#include <eosio/eosio.hpp>
#include <eosio/name.hpp>
#include <eosio/singleton.hpp>
#include <string>
#include <vector>

namespace contract_name
{
    using eosio::check;
    using eosio::contract;
    using eosio::datastream;
    using eosio::name;
    using eosio::print;
    using std::string;

    // Ricardian contracts live in class1-ricardian.cpp
    extern const char* sayhi_ricardian;
    extern const char* sayhialice_ricardian;
    extern const char* ricardian_clause;

    class class1_contract : public contract
    {
       public:
        using eosio::contract::contract;

        class1_contract(name receiver, name code, datastream<const char*> ds) : contract(receiver, code, ds)
        { /* NOP */
        }

        void sayhi();
        void sayhialice(const name& someone);

        // [[eosio::on_notify("eosio.token::transfer")]]
        // void depositandlock( const name& from, const name& to, const asset&
        // quantity, const string& memo);
    };

    // This macro:
    // * Creates a part of the dispatcher
    // * Defines action wrappers which make it easy for other contracts and for test
    // cases to invoke
    //   this contract's actions
    // * Optional: provides the names of actions to the ABI generator. Without this,
    // the ABI
    //   generator will make up names (e.g. arg0, arg1, arg2, ...).
    // * Optional: provides ricardian contracts to the ABI generator. Without this,
    // the ABI generator
    //   will leave the ricardian contracts blank.
}  // namespace contract_name