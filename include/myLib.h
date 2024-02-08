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
#include "date.h"
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

/*Ham sao luu du lieu cua server list vao Server.txt*/
void backupServer(const douList<Server> &server);

/*Ham sao luu du lieu cua manager list vao Manager.txt*/
void backupManager(const douList<Manager> &manager);

/*ham kiem tra mot id da ton tai trong ds phuc vu chua*/
bool idExistInServerList(const douList<Server> &server, std::string id);

/*ham kiem tra mot id da ton tai trong ds quan ly chua*/
bool idExistInManagerList(const douList<Manager> &manager, std::string id);

/*ham kiem tra mot id da ton tai trong ds thu ngan chua*/
bool idExistInCashierList(const douList<Cashier> &cashier, std::string id);

/*ham kiem tra mot id da ton tai trong ds bao ve chua*/
bool idExistInSecurityList(const douList<Security> &security, std::string id);

bool server_age_cmp(node<Server> A, node<Server> B);

bool server_salary_cmp(node<Server> A, node<Server> B);

bool server_startDate_cmp(node<Server> A, node<Server> B);

bool manager_age_cmp(node<Manager> A, node<Manager> B);

bool manager_salary_cmp(node<Manager> A, node<Manager> B);

bool manager_startDate_cmp(node<Manager> A, node<Manager> B);

/*Ham reset so gio lam viec ve 0 cua server list trong chuong trinh*/
void resetHoursOfWork(const douList<Server> &server);

/*Ham reset so gio lam viec ve 0 cua manager list trong chuong trinh*/
void resetHoursOfWork(const douList<Manager> &manager);
