//
// Created by YoungZM on 2023/4/12.
//

#ifndef EXPRESSMANAGEMENTSYSTEM_USER_H
#define EXPRESSMANAGEMENTSYSTEM_USER_H

#include <vector>
#include "string"

class User {
private:
    std::string id;
    std::string name;
    std::string password;
    std::string phone_number;
    double balance;
    std::vector<std::string> send_items_id;
    std::vector<std::string> receive_items_id;
public:
    std::string GetID();

    std::string GetName();

    std::string GetPhoneNumber();

    double GetBalance();

    bool ChargeBalance(double amount);

    bool CheckPassword(const std::string &input_password);

    friend void LoadUsers();
};

#endif //EXPRESSMANAGEMENTSYSTEM_USER_H
