//
// Created by YoungZM on 2023/4/12.
//

#include "User.h"

std::string User::GetID() {
    return this->id;
}

std::string User::GetName() {
    return this->name;
}

std::string User::GetPhoneNumber() {
    return this->phone_number;
}

double User::GetBalance() {
    return this->balance;
}

bool User::ChargeBalance(double amount) {
    if (this->balance - amount > 0.0) {
        this->balance -= amount;
        return true;
    } else {
        return false;
    }
}

bool User::CheckPassword(const std::string &input_password) {
    if (input_password == this->password) {
        return true;
    } else {
        return false;
    }
}