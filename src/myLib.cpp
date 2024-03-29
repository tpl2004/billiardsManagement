#include "../include/myLib.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

bool checkID(const std::string &id) {
    if(id == "") return false;
    for(const char &c : id) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) continue;
        return false;
    }
    return true;
}

bool checkFullName(const std::string &fullName) {
    if(fullName == "") return false;
    else {
        bool check = false;
        for(const char &c : fullName) {
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                check = true;
                continue;
            }
            else if(c == ' ') continue;
            return false;
        }
        return check;
    }
}

std::string standardize(std::string fullName) {
    std::transform(fullName.begin(), fullName.end(), fullName.begin(), ::tolower);
    std::stringstream ss(fullName);
    std::string tmp;
    std::vector<std::string> v;
    std::string newFullName = "";
    while(ss >> tmp) {
        tmp[0] = std::toupper(tmp[0]);
        v.push_back(tmp);
    }
    for(int i = 0; i < int(v.size()) - 1; i++) {
        newFullName += v[i] + " ";
    }
    return newFullName + v[int(v.size()) - 1];
}

void loadDataIntoServerList(douList<Server> &L) {
    std::ifstream fileInput("data/Staff/Server/Server.txt");
    std::string line;
    while(std::getline(fileInput, line)) {
        std::vector<std::string> s_line;
        std::string atb;
        for(const char &chr : line) {
            if(chr != ';') atb += chr;
            else {
                s_line.push_back(atb);
                atb = "";
            }
        }
        s_line.push_back(atb);
        douList<Server>::insertLast(L, Server(s_line[0], s_line[1], std::stoi(s_line[2]), s_line[3], s_line[4], s_line[5], std::stoi(s_line[6]), std::stoi(s_line[7])));
    }
    fileInput.close();
}

void loadDataIntoManagerList(douList<Manager> &L) {
    std::ifstream fileInput("data/Staff/Manager/Manager.txt");
    std::string line;
    while(std::getline(fileInput, line)) {
        std::vector<std::string> s_line;
        std::string atb;
        for(const char &chr : line) {
            if(chr != ';') atb += chr;
            else {
                s_line.push_back(atb);
                atb = "";
            }
        }
        s_line.push_back(atb);
        douList<Manager>::insertLast(L, Manager(s_line[0], s_line[1], std::stoi(s_line[2]), s_line[3], s_line[4], s_line[5], std::stoi(s_line[6]), s_line[7]));
    }
    fileInput.close();
}


void loadDataIntoSecurityList(douList<Security> &L) {
    std::ifstream fileInput("data/Staff/Security/Security.txt");
    std::string line;
    while(std::getline(fileInput, line)) {
        std::vector<std::string> s_line;
        std::string atb;
        for(const char &chr : line) {
            if(chr != ';') atb += chr;
            else {
                s_line.push_back(atb);
                atb = "";
            }
        }
        s_line.push_back(atb);
        douList<Security>::insertLast(L, Security(s_line[0], s_line[1], std::stoi(s_line[2]), s_line[3], s_line[4], s_line[5], std::stoi(s_line[6]), std::stof(s_line[7]), std::stof(s_line[8])));
    }
    fileInput.close();
}

void loadDataIntoCashierList(douList<Cashier> &L) {
    std::ifstream fileInput("data/Staff/Cashier/Cashier.txt");
    std::string line;
    while(std::getline(fileInput, line)) {
        std::vector<std::string> s_line;
        std::string atb;
        for(const char &chr : line) {
            if(chr != ';') atb += chr;
            else {
                s_line.push_back(atb);
                atb = "";
            }
        }
        s_line.push_back(atb);
        douList<Cashier>::insertLast(L, Cashier(s_line[0], s_line[1], std::stoi(s_line[2]), s_line[3], s_line[4], s_line[5], std::stoi(s_line[6])));
    }
    fileInput.close();
}

void loadDataIntoPoolTableList(douList<PoolTable> &L) {
    std::ifstream fileInput("data/Infrastructure/PoolTable/PoolTable.txt");
    std::string line;
    while(std::getline(fileInput, line)) {
        std::vector<std::string> s_line;
        std::string atb;
        for(const char &chr : line) {
            if(chr != ';') atb += chr;
            else {
                s_line.push_back(atb);
                atb = "";
            }
        }
        s_line.push_back(atb);
        douList<PoolTable>::insertLast(L, PoolTable(s_line[0], s_line[1], std::stod(s_line[2]), s_line[3], s_line[4], s_line[5], std::stof(s_line[6]), std::stof(s_line[7])));
    }
    fileInput.close();
}

void loadDataIntoCueList(douList<Cue> &L) {
    std::ifstream fileInput("data/Infrastructure/Cue/Cue.txt");
    std::string line;
    while(std::getline(fileInput, line)) {
        std::vector<std::string> s_line;
        std::string atb;
        for(const char &chr : line) {
            if(chr != ';') atb += chr;
            else {
                s_line.push_back(atb);
                atb = "";
            }
        }
        s_line.push_back(atb);
        douList<Cue>::insertLast(L, Cue(s_line[0], s_line[1], std::stod(s_line[2]), s_line[3], s_line[4], s_line[5]));
    }
    fileInput.close();
}


void loadDataIntoBillList(douList<Bill> &L) {
    std::ifstream fileInput("data/Bill/Bill.txt");
    std::string line;
    while(std::getline(fileInput, line)) {
        std::vector<std::string> s_line;
        std::string atb;
        for(const char &chr : line) {
            if(chr != ';') atb += chr;
            else {
                s_line.push_back(atb);
                atb = "";
            }
        }
        s_line.push_back(atb);
        douList<Bill>::insertLast(L, Bill(s_line[0], s_line[1], s_line[2], std::stof(s_line[3]), s_line[4]));
    } 
    fileInput.close();
}

void loadDataIntoCustomerList(douList<Customer> &L) {
    std::ifstream fileInput("data/Customer/Customer.txt");
    std::string line;
    while(std::getline(fileInput, line)) {
        std::vector<std::string> s_line;
        std::string atb;
        for(const char &chr : line) {
            if(chr != ';') atb += chr;
            else {
                s_line.push_back(atb);
                atb = "";
            }
        }
        s_line.push_back(atb);
        douList<Customer>::insertLast(L, Customer(s_line[0], s_line[1], std::stoi(s_line[2])));
    }
    fileInput.close();
}

void synBill_Customer(douList<Bill> &bill, douList<Customer> &customer) {
    //Them khach hang trong Bill vao ds khach hang neu khach hang chua co trong ds khach hang
    for(node<Bill> *b_tmp = bill.head; b_tmp != NULL; b_tmp = b_tmp->next) {
        bool exist = false;
        for(node<Customer> *c_tmp = customer.head; c_tmp != NULL; c_tmp = c_tmp->next) {
            if(b_tmp->data.getIDOfCustomer() == c_tmp->data.getID()) {
                exist = true;
                break;
            }
        }
        if(!exist) {
            Customer tmp;
            tmp.setID(b_tmp->data.getIDOfCustomer());
            douList<Customer>::insertLast(customer, tmp);
        }
    }
    //Xoa cac khach hang trong ds khach hang neu khach hang khong co trong ds Bill
    std::vector<int> del_pos;
    int pos = 0;
    for(node<Customer> *c_tmp = customer.head; c_tmp != NULL;c_tmp = c_tmp->next, pos++) {
        bool exist = false;
        for(node<Bill> *b_tmp = bill.head; b_tmp != NULL;b_tmp = b_tmp->next) {
            if(c_tmp->data.getID() == b_tmp->data.getIDOfCustomer()) {
                exist = true;
                break;
            }
        }
        if(!exist) {
            del_pos.push_back(pos);
        }
    }
    for(int &elm : del_pos) {
        douList<Customer>::del(customer, elm);
    }
    //Cap nhat Customer.txt
    backupCustomer(customer);
}

void backupCustomer(const douList<Customer> &customer) {
    std::ofstream fileOut("data/Customer/Customer.txt");
    for(node<Customer> *tmp = customer.head; tmp != NULL; tmp = tmp->next) {
        fileOut << tmp->data.getID() << ";" << tmp->data.getFullName() << ";" << tmp->data.getAge() << "\n";
    }
    fileOut.close();
}

void backupServer(const douList<Server> &server) {
    std::ofstream fileOut("data/Staff/Server/Server.txt");
    for(node<Server> *tmp = server.head; tmp != NULL; tmp = tmp->next) {
        fileOut << tmp->data.getID() << ";"
            << tmp->data.getFullName() << ";"
            << tmp->data.getAge() << ";"
            << tmp->data.getSex() << ";"
            << tmp->data.getAddress() << ";"
            << tmp->data.getStartDate().getDate() << ";"
            << tmp->data.getHoursOfWork() << ";"
            << tmp->data.getServiceArea() << "\n";
    }
    fileOut.close();
}

void backupManager(const douList<Manager> &manager) {
    std::ofstream fileOut("data/Staff/Manager/Manager.txt");
    for(node<Manager> *tmp = manager.head; tmp != NULL; tmp = tmp->next) {
        fileOut << tmp->data.getID() << ";"
            << tmp->data.getFullName() << ";"
            << tmp->data.getAge() << ";"
            << tmp->data.getSex() << ";"
            << tmp->data.getAddress() << ";"
            << tmp->data.getStartDate().getDate() << ";"
            << tmp->data.getHoursOfWork() << ";"
            << tmp->data.getPosition() << "\n";
    }
    fileOut.close();
}

bool idExistInServerList(const douList<Server> &server, std::string id) {
    bool exist = false;
    for(node<Server> *tmp = server.head; tmp != NULL; tmp = tmp->next) {
        if(id == tmp->data.getID()) {
            exist = true;
            break;
        }
    }
    return exist;
}

bool idExistInManagerList(const douList<Manager> &manager, std::string id) {
    bool exist = false;
    for(node<Manager> *tmp = manager.head; tmp != NULL; tmp = tmp->next) {
        if(id == tmp->data.getID()) {
            exist = true;
            break;
        }
    }
    return exist;
}

bool idExistInCashierList(const douList<Cashier> &cashier, std::string id) {
    bool exist = false;
    for(node<Cashier> *tmp = cashier.head; tmp != NULL; tmp = tmp->next) {
        if(id == tmp->data.getID()) {
            exist = true;
            break;
        }
    }
    return exist;
}

bool idExistInSecurityList(const douList<Security> &security, std::string id) {
    bool exist = false;
    for(node<Security> *tmp = security.head; tmp != NULL; tmp = tmp->next) {
        if(id == tmp->data.getID()) {
            exist = true;
            break;
        }
    }
    return exist;
}

bool server_age_cmp(node<Server> A, node<Server> B) {
    return A.data.getAge() > B.data.getAge();
}

bool server_salary_cmp(node<Server> A, node<Server> B) {
    return A.data.getSalary() < B.data.getSalary();
}

bool server_startDate_cmp(node<Server> A, node<Server> B) {
    Date tmp1 = A.data.getStartDate();
    Date tmp2 = B.data.getStartDate();
    return tmp2 > tmp1;
}

bool manager_age_cmp(node<Manager> A, node<Manager> B) {
    return A.data.getAge() > B.data.getAge();
}

bool manager_salary_cmp(node<Manager> A, node<Manager> B) {
    return A.data.getSalary() < B.data.getSalary();
}

bool manager_startDate_cmp(node<Manager> A, node<Manager> B) {
    Date tmp1 = A.data.getStartDate();
    Date tmp2 = B.data.getStartDate();
    return tmp2 > tmp1;
}

void resetHoursOfWork(const douList<Server> &server) {
    for(node<Server> *tmp = server.head; tmp != NULL; tmp = tmp->next) {
        tmp->data.setHoursOfWork(0);
    }
}

void resetHoursOfWork(const douList<Manager> &manager) {
    for(node<Manager> * tmp = manager.head; tmp != NULL; tmp = tmp->next) {
        tmp->data.setHoursOfWork(0);
    }
}
