#include <cstdlib>
#include <iostream>
#include <string>
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

double Server::salaryPerHour = 50000;
double Manager::salaryPerHour = 100000;
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

    while(true) {
        std::cout << "CHUONG TRINH QUAN LY BIDA\n";
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
        system("cls");
        if(opt == 1) {
            while(true) {
                std::cout << "NHAN VIEN\n";
                std::cout << "[1] Phuc vu\n";
                std::cout << "[2] Quan ly\n";
                std::cout << "[3] Thu ngan\n";
                std::cout << "[4] Bao ve\n";
                std::cout << "[5] back\n";
                do {
                    std::cout << "Nhap tuy chon: ";
                    std::cin >> opt;
                } while(opt < 1 or opt > 5);
                system("cls");
                if(opt == 1){
                    while(true) {
                        std::cout << "PHUC VU\n";
                        std::cout << "[1] Hien thi danh sach\n";
                        std::cout << "[2] Them\n";
                        std::cout << "[3] Sua\n";
                        std::cout << "[4] Xoa\n";
                        std::cout << "[5] Tim kiem\n";
                        std::cout << "[6] Sap xep\n";
                        std::cout << "[7] Hien thi bang luong tai thoi diem da luu\n";
                        std::cout << "[8] Sao luu\n";//sao luu danh sach chuong trinh vao file data/Staff/Server/Server.txt
                        std::cout << "[9] Sao luu va tao ban backup\n";//sao luu danh sach chuong trinh vao file data/Staff/Server/Server.txt va vao file khac
                        std::cout << "[10] reset so gio lam viec\n";//Dua so gio lam viec ve 0 cua server list trong chuong trinh
                        std::cout << "[11] back\n";
                        do {
                            std::cout << "Nhap tuy chon: ";
                            std::cin >> opt;
                        } while(opt < 1 or opt > 11);
                        system("cls");
                        if(opt == 1) {
                            char ans;
                            do {
                                std::cout << "Dao nguoc?(Y/N): ";
                                std::cin >> ans;
                            } while(ans != 'Y' and ans != 'y' and ans != 'N' and ans != 'n');
                            (ans == 'N' or ans == 'n')? douList<Server>::show(server) : douList<Server>::show(server, true);
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 2) {
                            Server tmp;
                            std::cin.ignore();
                            tmp.input();
                            if(tmp.getID() == "") std::cout << "Them that bai!!!\n";
                            else if(idExistInServerList(server, tmp.getID())) std::cout << "Them that bai!!!\n";
                            else if(idExistInManagerList(manager, tmp.getID())) std::cout << "Them that bai!!!\n";
                            else if(idExistInCashierList(cashier, tmp.getID())) std::cout << "Them that bai!!!\n";
                            else if(idExistInSecurityList(security, tmp.getID())) std::cout << "Them that bai!!!\n";
                            else {
                                douList<Server>::insertLast(server, tmp);
                                std::cout << "Da them thanh cong!!!\n";
                            }
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 3) {
                            std::cin.ignore();
                            std::string id;
                            do {
                                std::cout << "Nhap ID: ";
                                std::getline(std::cin, id);
                            } while(checkID(id)==false or idExistInServerList(server, id)==false);
                            for(node<Server> *tmp = server.head; tmp != NULL; tmp = tmp->next) {
                                if(tmp->data.getID() == id) {
                                    tmp->data.show();
                                    tmp->data.input();
                                    break;
                                }
                            }
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 4) {
                            std::cin.ignore();
                            std::string id;
                            do {
                                std::cout << "Nhap ID: ";
                                std::getline(std::cin, id);
                            } while(checkID(id)==false or idExistInServerList(server, id)==false);
                            int del_pos = 0;
                            for(node<Server> *tmp = server.head; tmp != NULL; tmp = tmp->next, del_pos++) {
                                if(tmp->data.getID() == id) {
                                    douList<Server>::del(server, del_pos);
                                    break;
                                }
                            }
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 5) {
                            std::cout << "[1] Tim kiem theo id\n";
                            std::cout << "[2] Tim kiem theo ho ten\n";
                            std::cout << "[3] Tim kiem theo tuoi\n";
                            do {
                                std::cout << "Nhap tuy chon: ";
                                std::cin >> opt;
                            } while(opt < 1 or opt > 3);
                            if(opt == 1) {
                                std::cout << "Nhap ID: ";
                                std::string id;
                                std::cin.ignore();
                                std::getline(std::cin, id);
                                for(node<Server> *tmp = server.head; tmp != NULL; tmp = tmp->next) {
                                    if(tmp->data.getID().find(id) != std::string::npos) {
                                        tmp->data.show();
                                    }
                                }
                            }
                            else if(opt == 2) {
                                std::cout << "Nhap ho ten: ";
                                std::string fname;
                                std::cin.ignore();
                                std::getline(std::cin, fname);
                                for(node<Server> *tmp = server.head; tmp != NULL; tmp = tmp->next) {
                                    if(tmp->data.getFullName().find(fname) != std::string::npos) {
                                        tmp->data.show();
                                    }
                                }
                            }
                            else {
                                std::cout << "Nhap tuoi: ";
                                int age;
                                std::cin >> age;
                                for(node<Server> *tmp = server.head; tmp != NULL; tmp = tmp->next) {
                                    if(tmp->data.getAge() == age) {
                                        tmp->data.show();
                                    }
                                }
                            }
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 6) {
                            std::cout << "[1] Sap xep theo ten\n";
                            std::cout << "[2] Sap xep theo tuoi(tang dan)\n";
                            std::cout << "[3] sap xep theo luong(giam dan)\n";
                            std::cout << "[4] sap xep theo ngay bat dau lam viec(giam dan)\n";
                            do {
                                std::cout << "Nhap tuy chon: ";
                                std::cin >> opt;
                            }while (opt < 1 or opt > 4);
                            if(opt == 1) {
                                std::cout << "Tinh nang dang duoc phat trien!!!\n";
                            }
                            else if(opt == 2) {
                                douList<Server>::sort(server, server_age_cmp);
                                std::cout << "Da sap xep thanh cong\n";
                            }
                            else if(opt == 3) {
                                douList<Server>::sort(server, server_salary_cmp);
                                std::cout << "Da sap xep thanh cong\n";
                            }
                            else {
                                douList<Server>::sort(server, server_startDate_cmp);
                                std::cout << "Da sap xep thanh cong\n";
                            }
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 7) {
                            std::cout << "Tinh nang nay chua ranh de lam!!!\n";
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 8) {
                            backupServer(server);
                            std::cout << "Da sao luu thanh cong!!!\n";
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 9) {
                            std::cout << "Dua 50k roi lam cho!!!\n";
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 10) {
                            resetHoursOfWork(server);
                            std::cout << "Da reset so gio lam viec thanh cong!!!\n";
                            system("pause");
                            system("cls");
                        }
                        else break;
                    }
                }
                else if(opt == 2) {                   
                    while(true) {
                        std::cout << "QUAN LY\n";
                        std::cout << "[1] Hien thi danh sach\n";
                        std::cout << "[2] Them\n";
                        std::cout << "[3] Sua\n";
                        std::cout << "[4] Xoa\n";
                        std::cout << "[5] Tim kiem\n";
                        std::cout << "[6] Sap xep\n";
                        std::cout << "[7] Hien thi bang luong tai thoi diem da luu\n";
                        std::cout << "[8] Sao luu\n";//sao luu danh sach chuong trinh vao file data/Staff/Server/Server.txt
                        std::cout << "[9] Sao luu va tao ban backup\n";//sao luu danh sach chuong trinh vao file data/Staff/Server/Server.txt va vao file khac
                        std::cout << "[10] reset so gio lam viec\n";//Dua so gio lam viec ve 0 cua server list trong chuong trinh
                        std::cout << "[11] back\n";
                        do {
                            std::cout << "Nhap tuy chon: ";
                            std::cin >> opt;
                        } while(opt < 1 or opt > 11);
                        system("cls");
                        if(opt == 1) {
                            char ans;
                            do {
                                std::cout << "Dao nguoc?(Y/N): ";
                                std::cin >> ans;
                            } while(ans != 'Y' and ans != 'y' and ans != 'N' and ans != 'n');
                            (ans == 'N' or ans == 'n')? douList<Manager>::show(manager) : douList<Manager>::show(manager, true);
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 2) {
                            Manager tmp;
                            std::cin.ignore();
                            tmp.input();
                            if(tmp.getID() == "") std::cout << "Them that bai!!!\n";
                            else if(idExistInServerList(server, tmp.getID())) std::cout << "Them that bai!!!\n";
                            else if(idExistInManagerList(manager, tmp.getID())) std::cout << "Them that bai!!!\n";
                            else if(idExistInCashierList(cashier, tmp.getID())) std::cout << "Them that bai!!!\n";
                            else if(idExistInSecurityList(security, tmp.getID())) std::cout << "Them that bai!!!\n";
                            else {
                                douList<Manager>::insertLast(manager, tmp);
                                std::cout << "Da them thanh cong!!!\n";
                            }
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 3) {
                            std::cin.ignore();
                            std::string id;
                            do {
                                std::cout << "Nhap ID: ";
                                std::getline(std::cin, id);
                            } while(checkID(id)==false or idExistInManagerList(manager, id)==false);
                            for(node<Manager> *tmp = manager.head; tmp != NULL; tmp = tmp->next) {
                                if(tmp->data.getID() == id) {
                                    tmp->data.show();
                                    tmp->data.input();
                                    break;
                                }
                            }
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 4) {
                            std::cin.ignore();
                            std::string id;
                            do {
                                std::cout << "Nhap ID: ";
                                std::getline(std::cin, id);
                            } while(checkID(id)==false or idExistInManagerList(manager, id)==false);
                            int del_pos = 0;
                            for(node<Manager> *tmp = manager.head; tmp != NULL; tmp = tmp->next, del_pos++) {
                                if(tmp->data.getID() == id) {
                                    douList<Manager>::del(manager, del_pos);
                                    break;
                                }
                            }
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 5) {
                            std::cout << "[1] Tim kiem theo id\n";
                            std::cout << "[2] Tim kiem theo ho ten\n";
                            std::cout << "[3] Tim kiem theo tuoi\n";
                            do {
                                std::cout << "Nhap tuy chon: ";
                                std::cin >> opt;
                            } while(opt < 1 or opt > 3);
                            if(opt == 1) {
                                std::cout << "Nhap ID: ";
                                std::string id;
                                std::cin.ignore();
                                std::getline(std::cin, id);
                                for(node<Manager> *tmp = manager.head; tmp != NULL; tmp = tmp->next) {
                                    if(tmp->data.getID().find(id) != std::string::npos) {
                                        tmp->data.show();
                                    }
                                }
                            }
                            else if(opt == 2) {
                                std::cout << "Nhap ho ten: ";
                                std::string fname;
                                std::cin.ignore();
                                std::getline(std::cin, fname);
                                for(node<Manager> *tmp = manager.head; tmp != NULL; tmp = tmp->next) {
                                    if(tmp->data.getFullName().find(fname) != std::string::npos) {
                                        tmp->data.show();
                                    }
                                }
                            }
                            else {
                                std::cout << "Nhap tuoi: ";
                                int age;
                                std::cin >> age;
                                for(node<Manager> *tmp = manager.head; tmp != NULL; tmp = tmp->next) {
                                    if(tmp->data.getAge() == age) {
                                        tmp->data.show();
                                    }
                                }
                            }
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 6) {
                            std::cout << "[1] Sap xep theo ten\n";
                            std::cout << "[2] Sap xep theo tuoi(tang dan)\n";
                            std::cout << "[3] sap xep theo luong(giam dan)\n";
                            std::cout << "[4] sap xep theo ngay bat dau lam viec(giam dan)\n";
                            do {
                                std::cout << "Nhap tuy chon: ";
                                std::cin >> opt;
                            }while (opt < 1 or opt > 4);
                            if(opt == 1) {
                                std::cout << "Tinh nang dang duoc phat trien!!!\n";
                            }
                            else if(opt == 2) {
                                douList<Manager>::sort(manager, manager_age_cmp);
                                std::cout << "Da sap xep thanh cong\n";
                            }
                            else if(opt == 3) {
                                douList<Manager>::sort(manager, manager_salary_cmp);
                                std::cout << "Da sap xep thanh cong\n";
                            }
                            else {
                                douList<Manager>::sort(manager, manager_startDate_cmp);
                                std::cout << "Da sap xep thanh cong\n";
                            }
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 7) {
                            std::cout << "Tinh nang nay chua ranh de lam!!!\n";
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 8) {
                            backupManager(manager);
                            std::cout << "Da sao luu thanh cong!!!\n";
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 9) {
                            std::cout << "Dua 50k roi lam cho!!!\n";
                            system("pause");
                            system("cls");
                        }
                        else if(opt == 10) {
                            resetHoursOfWork(manager);
                            std::cout << "Da reset so gio lam viec thanh cong!!!\n";
                            system("pause");
                            system("cls");
                        }
                        else break;
                    }
                }
                else if(opt == 3) {}
                else if(opt == 4) {}
                else break;
            }
        }
        else if(opt == 2) {}
        else if(opt == 3) {}
        else if(opt == 4) {}
        else break;
    }
    return 0;
}
