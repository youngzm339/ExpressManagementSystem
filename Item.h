//
// Created by YoungZM on 2023/4/12.
//

#ifndef EXPRESSMANAGEMENTSYSTEM_ITEM_H
#define EXPRESSMANAGEMENTSYSTEM_ITEM_H

#include <string>
#include <ctime>

class Item {
private:
    std::string id;
    std::string sender_id;
    std::string receiver_id;
    time_t time;
    std::string origin;
    std::string destination;
    bool state;
    std::string courier;
public:
    std::string GetID();

    std::string GetSenderID();

    std::string GetReceiverID();

    time_t GetTime();

    std::string GetTimeString();

    std::string GetOrigin();

    std::string GetDestination();

    bool GetState();

    std::string GetCourier();

    void SetState();

    friend void LoadItems();

    friend void DownloadItems();

    friend void SendItem();
};

#endif //EXPRESSMANAGEMENTSYSTEM_ITEM_H
