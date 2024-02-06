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
    loadDataIntoManagerList(manager);
    loadDataIntoCashierList(cashier);
    loadDataIntoSecurityList(security);
    loadDataIntoPoolTableList(poolTable);
    loadDataIntoCueList(cue);
    loadDataIntoBillList(bill);
    loadDataIntoCustomerList(customer);
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

        }
        else if(opt == 2) {

        }
        else if(opt == 3) {

        }
        else if(opt == 4) {

        }
        else break;
    }
    return 0;
}
