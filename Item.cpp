//
// Created by YoungZM on 2023/4/12.
//

#include "Item.h"

std::string Item::GetID() {
    return this->id;
}

std::string Item::GetSenderID() {
    return this->sender_id;
}

std::string Item::GetReceiverID() {
    return this->receiver_id;
}

time_t Item::GetTime() {
    return this->time;
}

std::string Item::GetTimeString() {
    return ctime(&this->time);
}

std::string Item::GetOrigin() {
    return this->origin;
}

std::string Item::GetDestination() {
    return this->destination;
}

bool Item::GetState() {
    return this->state;
}

std::string Item::GetCourier() {
    return this->courier;
}

void Item::SetState() {
    this->state = true;
}