//
// Created by YoungZM on 2023/4/12.
//

#ifndef EXPRESSMANAGEMENTSYSTEM_METHOD_H
#define EXPRESSMANAGEMENTSYSTEM_METHOD_H

#include "User.h"
#include "Item.h"

void LoadUsers();

void LoadItems();

void DownloadUsers();

void DownloadItems();

void LoginPanel();

void UserPanel();

void AdminPanel();

void CourierPanel();

void CheckSender();

void CheckReceiver();

void CheckSenderUnaccepted();

void CheckReceiverUnaccepted();

void SendItem();

void AcceptItem();

void CheckItemByItemID();

void CheckUserByUserID();

void CheckItemsByUserID();

void CheckItemsCourier();

void CheckItemsCourierUnaccepted();

void AcceptItemCourier();

#endif //EXPRESSMANAGEMENTSYSTEM_METHOD_H
