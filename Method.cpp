//
// Created by YoungZM on 2023/4/12.
//

#include <iostream>
#include <fstream>
#include "Method.h"

std::vector<User> loaded_users;
std::vector<Item> loaded_items;

void LoadUsers() {
    std::ifstream user_file;
    user_file.open("UsersDir/Users.config", std::ios::in);
    int sum;
    user_file >> sum;
    if (sum <= 0) {
        throw "Nothing in config file or config file has been broken!";
    }
    while (sum--) {
        User this_user;
        user_file >> this_user.id;
        user_file >> this_user.name;
        user_file >> this_user.password;
        user_file >> this_user.balance;
        user_file >> this_user.phone_number;
        loaded_users.push_back(this_user);
    }
}

void LoadItems() {
    std::ifstream item_file;
    item_file.open("ItemsDir/Items.config", std::ios::in);
    int sum;
    item_file >> sum;
    if (sum <= 0) {
        throw "Nothing in config file or config file has been broken!";
    }
    while (sum--) {
        Item this_item;
        item_file >> this_item.id;
        item_file >> this_item.sender_id;
        item_file >> this_item.receiver_id;
        item_file >> this_item.time;
        item_file >> this_item.origin;
        item_file >> this_item.destination;
        item_file >> this_item.state;
        loaded_items.push_back(this_item);
    }
}

User *current_user = nullptr;

void LoginPanel() {
    std::cout << "Welcome to LoginPanel" << std::endl;
    std::cout << "Please input your ID && password to login in." << std::endl;
    std::cout << "ID: " << std::endl;
    std::string input_id;
    std::cin >> input_id;
    for (auto &this_user: loaded_users) {
        if (this_user.GetID() == input_id) {
            current_user = &this_user;
        }
    }
    if (current_user == nullptr) {
        throw "No user founded!";
    }
    std::cout << "Password: " << std::endl;
    std::string input_password;
    std::cin >> input_password;
    if (current_user->CheckPassword(input_password)) {
        while (true) {
            UserPanel();
        }
    } else {
        current_user = nullptr;
        throw "Wrong password!";
    }
}

void UserPanel() {
    std::cout << "Welcome to UserPanel" << std::endl;
    std::cout << "Please select your option to continue." << std::endl;
    std::cout << "[1] Check items as sender" << std::endl;
    std::cout << "[2] Check items as receiver" << std::endl;
    std::cout << "[3] Check items as sender (only unaccepted)" << std::endl;
    std::cout << "[4] Check items as receiver (only unaccepted)" << std::endl;
    std::cout << "[5] Send a item" << std::endl;
    std::cout << "[0] Exit" << std::endl;
    std::cout << "Your option:" << std::endl;
    int option;
    std::cin >> option;
    switch (option) {
        case 1:
            CheckSender();
            break;
        case 2:
            CheckReceiver();
            break;
        case 3:
            CheckSenderUnaccepted();
            break;
        case 4:
            CheckReceiverUnaccepted();
            break;
        case 5:
            SendItem();
            break;
        case 0:
            throw " ";
        default:
            throw "Wrong UserPanel input";
    }
}

void CheckSender() {
    std::cout << "The query results are as follows: " << std::endl;
    for (auto &this_item: loaded_items) {
        if (this_item.GetSenderID() == current_user->GetID()) {
            std::cout << "Item ID: " << this_item.GetID() << std::endl;
            std::cout << "Item sent time: " << this_item.GetTimeString() << std::endl;
            std::cout << "Item Sender ID: " << this_item.GetSenderID() << std::endl;
            std::cout << "Item Receiver ID: " << this_item.GetReceiverID() << std::endl;
            std::cout << "Item Origin: " << this_item.GetOrigin() << std::endl;
            std::cout << "Item Destination: " << this_item.GetDestination() << std::endl;
            std::cout << "Item State: " << this_item.GetState() << std::endl;
        }
    }
    std::cout << "-- END query results END --" << std::endl;
}

void CheckReceiver() {
    std::cout << "The query results are as follows: " << std::endl;
    for (auto &this_item: loaded_items) {
        if (this_item.GetReceiverID() == current_user->GetID()) {
            std::cout << "Item ID: " << this_item.GetID() << std::endl;
            std::cout << "Item sent time: " << this_item.GetTimeString() << std::endl;
            std::cout << "Item Sender ID: " << this_item.GetSenderID() << std::endl;
            std::cout << "Item Receiver ID: " << this_item.GetReceiverID() << std::endl;
            std::cout << "Item Origin: " << this_item.GetOrigin() << std::endl;
            std::cout << "Item Destination: " << this_item.GetDestination() << std::endl;
            std::cout << "Item State: " << this_item.GetState() << std::endl;
        }
    }
    std::cout << "-- END query results END --" << std::endl;
}

void CheckSenderUnaccepted() {
    std::cout << "The query results are as follows: " << std::endl;
    for (auto &this_item: loaded_items) {
        if (this_item.GetSenderID() == current_user->GetID() && !this_item.GetState()) {
            std::cout << "Item ID: " << this_item.GetID() << std::endl;
            std::cout << "Item sent time: " << this_item.GetTimeString() << std::endl;
            std::cout << "Item Sender ID: " << this_item.GetSenderID() << std::endl;
            std::cout << "Item Receiver ID: " << this_item.GetReceiverID() << std::endl;
            std::cout << "Item Origin: " << this_item.GetOrigin() << std::endl;
            std::cout << "Item Destination: " << this_item.GetDestination() << std::endl;
            std::cout << "Item State: " << this_item.GetState() << std::endl;
        }
    }
    std::cout << "-- END query results END --" << std::endl;
}

void CheckReceiverUnaccepted() {
    std::cout << "The query results are as follows: " << std::endl;
    for (auto &this_item: loaded_items) {
        if (this_item.GetReceiverID() == current_user->GetID() && !this_item.GetState()) {
            std::cout << "Item ID: " << this_item.GetID() << std::endl;
            std::cout << "Item sent time: " << this_item.GetTimeString() << std::endl;
            std::cout << "Item Sender ID: " << this_item.GetSenderID() << std::endl;
            std::cout << "Item Receiver ID: " << this_item.GetReceiverID() << std::endl;
            std::cout << "Item Origin: " << this_item.GetOrigin() << std::endl;
            std::cout << "Item Destination: " << this_item.GetDestination() << std::endl;
            std::cout << "Item State: " << this_item.GetState() << std::endl;
        }
    }
    std::cout << "-- END query results END --" << std::endl;
}

void SendItem() {

}