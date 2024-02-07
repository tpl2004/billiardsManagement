#include <iostream>
#include "../include/douList.h"
#include "../include/staff.h"
#include "../include/server.h"
#include "../include/manager.h"
#include "../include/security.h"
#include "../include/cashier.h"
#include "../include/infrastructure.h"
#include "../include/poolTable.h"
#include "../include/cue.h"
#include "../include/bill.h"
#include "../include/customer.h"
#include "../include/myLib.h"
#include "../include/date.h"

double Server::salaryPerHour = 0;
double Manager::salaryPerHour = 0;
double Security::salaryPerHour = 0;
double Cashier::salaryPerHour = 0;
double Bill::paymentOfHour = 0;

douList<Server> server;
douList<Manager> manager;
douList<Cashier> cashier;
douList<Security> security;
douList<PoolTable> poolTable;
douList<Cue> cue;
douList<Bill> bill;
douList<Customer> customer;
int main() {
    loadDataIntoServerList(server);
    std::cout << "load into server list success!\n";
    loadDataIntoManagerList(manager);
    std::cout << "load into manager list success!\n";
    loadDataIntoCashierList(cashier);
    std::cout << "load into cashier list success!\n";
    loadDataIntoSecurityList(security);
    std::cout << "load into security list success!\n";
    loadDataIntoPoolTableList(poolTable);
    std::cout << "load into poolTable list success!\n";
    loadDataIntoCueList(cue);
    std::cout << "load into cue list success!\n";
    loadDataIntoBillList(bill);
    std::cout << "load into bill list success!\n";
    loadDataIntoCustomerList(customer);
    std::cout << "load into customer list success!\n";
    synBill_Customer(bill, customer);
    std::cout << "Da dong bo va cap nhat Customer.txt thanh cong!\n";

    std::cout << "CHUONG TRINH QUAN LY BIDA\n";
    while(true) {
        std::cout << "[1] Nhan vien\n";
        std::cout << "[2] Co so vat chat\n";
        std::cout << "[3] Bill\n";
        std::cout << "[4] Khach hang\n";
        std::cout << "[5] exit\n";
        int opt;
        do {
            std::cout << "Nhap tuy chon: ";
            std::cin >> opt;
        } while (opt < 1 or opt > 5);
        if(opt == 1) {
            douList<Server>::show(server);
            std::cout << "---------------------------------------------------\n";
            douList<Manager>::show(manager);
            std::cout << "---------------------------------------------------\n";
            douList<Security>::show(security);
            std::cout << "---------------------------------------------------\n";
            douList<Cashier>::show(cashier);
            std::cout << "---------------------------------------------------\n";
        }
        else if(opt == 2) {
            douList<PoolTable>::show(poolTable);
            std::cout << "---------------------------------------------------\n";
            douList<Cue>::show(cue);
            std::cout << "---------------------------------------------------\n";
        }
        else if(opt == 3) {
            douList<Bill>::show(bill);
        }
        else if(opt == 4) {
            douList<Customer>::show(customer);
        }
        else break;
    }
    return 0;
}
