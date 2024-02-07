#pragma once
#include "douList.h"
#include "server.h"
#include "manager.h"
#include "security.h"
#include "cashier.h"
#include "bill.h"
#include "customer.h"
#include "poolTable.h"
#include "cue.h"
#include <string>

/*kiem tra tinh hop le cua id*/
bool checkID(const std::string &id);

/*kiem tra tinh hop le cua ho ten*/
bool checkFullName(const std::string &fullName);

/*chuan hoa*/
std::string standardize(std::string fullName);

void loadDataIntoServerList(douList<Server> &L);

void loadDataIntoManagerList(douList<Manager> &L);

void loadDataIntoSecurityList(douList<Security> &L);

void loadDataIntoCashierList(douList<Cashier> &L);

void loadDataIntoPoolTableList(douList<PoolTable> &L);

void loadDataIntoCueList(douList<Cue> &L);

void loadDataIntoBillList(douList<Bill> &L);

void loadDataIntoCustomerList(douList<Customer> &L);

void synBill_Customer(douList<Bill> &bill, douList<Customer> &customer);

/*Ham sao luu du lieu cua customer list vao Customer.txt*/
void backupCustomer(const douList<Customer> &customer);
