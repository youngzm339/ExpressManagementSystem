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
        user_file >> this_user.user_group;
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

void DownloadUsers() {
    std::ofstream user_file;
    user_file.open("UsersDir/Users.config", std::ios::out | std::ios::trunc);
    user_file << loaded_users.size() << std::endl;
    for (auto &this_user: loaded_users) {
        user_file << this_user.id << " ";
        user_file << this_user.name << " ";
        user_file << this_user.password << " ";
        user_file << this_user.balance << " ";
        user_file << this_user.phone_number << " ";
        user_file << this_user.user_group;
        user_file << std::endl;
    }
}

void DownloadItems() {
    std::ofstream item_file;
    item_file.open("ItemsDir/Items.config", std::ios::out | std::ios::trunc);
    item_file << loaded_items.size() << std::endl;
    for (auto &this_item: loaded_items) {
        item_file << this_item.id << " ";
        item_file << this_item.sender_id << " ";
        item_file << this_item.receiver_id << " ";
        item_file << this_item.time << " ";
        item_file << this_item.origin << " ";
        item_file << this_item.destination << " ";
        item_file << this_item.state;
        item_file << std::endl;
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
        if (current_user->GetUserGroup() == "user") {
            while (true) {
                UserPanel();
                std::cout << "Press any key to continue";
                system("pause");
            }
        } else if (current_user->GetUserGroup() == "admin") {
            while (true) {
                AdminPanel();
                std::cout << "Press any key to continue";
                system("pause");
            }
        } else {
            throw "No user group!";
        }
    } else {
        current_user = nullptr;
        throw "Wrong password!";
    }
}

void UserPanel() {
    std::cout << "Welcome to UserPanel" << std::endl;
    std::cout << "Your account has been successfully logged in." << std::endl;
    std::cout << "Your ID: " << current_user->GetID() << std::endl;
    std::cout << "Your Name: " << current_user->GetName() << std::endl;
    std::cout << "Your Balance: " << current_user->GetBalance() << std::endl;
    std::cout << "Your PhoneNumber: " << current_user->GetPhoneNumber() << std::endl;
    std::cout << "Please select your option to continue." << std::endl;
    std::cout << "[1] Check items as sender" << std::endl;
    std::cout << "[2] Check items as receiver" << std::endl;
    std::cout << "[3] Check items as sender (only unaccepted)" << std::endl;
    std::cout << "[4] Check items as receiver (only unaccepted)" << std::endl;
    std::cout << "[5] Send a item" << std::endl;
    std::cout << "[6] Accept a item" << std::endl;
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
        case 6:
            AcceptItem();
            break;
        case 0:
            throw " ";
        default:
            throw "Wrong UserPanel input!";
    }
}

void AdminPanel() {
    std::cout << "Welcome to AdminPanel" << std::endl;
    std::cout << "Please select your option to continue." << std::endl;
    std::cout << "[1] Check item info by item ID" << std::endl;
    std::cout << "[2] Check user info by user ID" << std::endl;
    std::cout << "[3] Check items by user ID" << std::endl;
    std::cout << "[0] Exit" << std::endl;
    std::cout << "Your option:" << std::endl;
    int option;
    std::cin >> option;
    switch (option) {
        case 1:
            CheckItemByItemID();
            break;
        case 2:
            CheckUserByUserID();
            break;
        case 3:
            CheckItemsByUserID();
            break;
        case 0:
            throw " ";
        default:
            throw "Wrong AdminPanel input!";
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
    std::cout << "UserPanel : SendItem" << std::endl;
    std::cout << "Please input Receiver phone number: " << std::endl;
    std::string input_phone_number;
    std::cin >> input_phone_number;
    for (auto &this_user: loaded_users) {
        if (this_user.GetPhoneNumber() == input_phone_number) {
            std::cout << "Receiver founded" << std::endl;
            Item this_item;
            this_item.id = std::to_string(std::stoll(loaded_items.rbegin()->GetID()) + 1);
            this_item.sender_id = current_user->GetID();
            time(&this_item.time);
            this_item.receiver_id = this_user.GetID();
            std::cout << "Please input Origin address: " << std::endl;
            std::cin >> this_item.origin;
            std::cout << "Please input Destination address: " << std::endl;
            std::cin >> this_item.destination;
            this_item.state = false;
            loaded_items.push_back(this_item);
            break;
        }
    }
    std::cout << "-- END SendItem END --" << std::endl;
}

void AcceptItem() {
    std::cout << "UserPanel : AcceptItem" << std::endl;
    CheckReceiverUnaccepted();
    std::cout << "Please input ItemID what you accept: " << std::endl;
    std::string input_item_id;
    std::cin >> input_item_id;
    for (auto &this_item: loaded_items) {
        if (this_item.GetID() == input_item_id) {
            this_item.SetState();
            break;
        }
    }
    std::cout << " -- END AcceptItem END -- " << std::endl;
}

void CheckItemByItemID() {
    std::cout << "AdminPanel : CheckItemByItemID" << std::endl;
    std::cout << "Please input ItemID: " << std::endl;
    std::string input_item_id;
    std::cin >> input_item_id;
    std::cout << "The query results are as follows: " << std::endl;
    for (auto &this_item: loaded_items) {
        if (this_item.GetID() == input_item_id) {
            std::cout << "Item ID: " << this_item.GetID() << std::endl;
            std::cout << "Item sent time: " << this_item.GetTimeString() << std::endl;
            std::cout << "Item Sender ID: " << this_item.GetSenderID() << std::endl;
            std::cout << "Item Receiver ID: " << this_item.GetReceiverID() << std::endl;
            std::cout << "Item Origin: " << this_item.GetOrigin() << std::endl;
            std::cout << "Item Destination: " << this_item.GetDestination() << std::endl;
            std::cout << "Item State: " << this_item.GetState() << std::endl;
            break;
        }
    }
    std::cout << "-- END query results END --" << std::endl;
}

void CheckUserByUserID() {
    std::cout << "AdminPanel : CheckUserByUserID" << std::endl;
    std::cout << "Please input UserID: " << std::endl;
    std::string input_user_id;
    std::cin >> input_user_id;
    std::cout << "The query results are as follows: " << std::endl;
    for (auto &this_user: loaded_users) {
        if (this_user.GetID() == input_user_id) {
            std::cout << "User ID: " << this_user.GetID() << std::endl;
            std::cout << "User Name: " << this_user.GetName() << std::endl;
            std::cout << "User Balance: " << this_user.GetBalance() << std::endl;
            std::cout << "User PhoneNumber: " << this_user.GetPhoneNumber() << std::endl;
            break;
        }
    }
    std::cout << "-- END query results END --" << std::endl;
}

void CheckItemsByUserID() {
    std::cout << "AdminPanel : CheckItemsByUserID" << std::endl;
    std::cout << "Please input UserID: " << std::endl;
    std::string input_user_id;
    std::cin >> input_user_id;
    std::cout << "The query results are as follows: " << std::endl;
    for (auto &this_item: loaded_items) {
        if (this_item.GetSenderID() == input_user_id) {
            std::cout << "Sent Item ID: " << this_item.GetID() << std::endl;
        } else if (this_item.GetReceiverID() == input_user_id) {
            std::cout << "Received Item ID: " << this_item.GetID() << std::endl;
        }
    }
    std::cout << "-- END query results END --" << std::endl;
}