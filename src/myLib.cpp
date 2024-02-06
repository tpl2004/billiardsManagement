#include "../include/myLib.h"
#include <string>
#include <fstream>
#include <vector>
//#include <sstream>
// #include <algorithm>
// #include <cctype>

bool checkID(const std::string &id) {
    for(const char &c : id) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) continue;
        return false;
    }
    return true;
}

bool checkFullName(const std::string &fullName) {
    for(const char &c : fullName) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ') continue;
        return false;
    }
    return true;
}

/*
std::string standardize(std::string fullName) {
    transform(fullName.begin(), fullName.end(), fullName.begin(), ::tolower);
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
*/

std::string standardize(std::string fullName) {
	while(fullName[0] == ' ') fullName.erase(0, 1);
	while(fullName[fullName.length() - 1] == ' ') fullName.erase(fullName[fullName.length() - 1]);
	for(int i = 1; i < fullName.length() - 2; i++) {
		if(fullName[i] == ' ' && fullName[i + 1] == ' ') {
			fullName.erase(i + 1, 1);
			i--;
		}
	}
	return fullName;
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
