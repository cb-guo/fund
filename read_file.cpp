#include<iostream>
#include<fstream>
#include<unordered_map>
#include<vector>
using namespace std;

const std::string filename = "fund.txt";

int main() {
    vector<std::string> vec;
    unordered_map<std::string, std::pair<std::string, double> > fund_info;
    
    ifstream ifs;
    ifs.open(filename, ios::in);
    char buf[1024] = {0};
    while (ifs >> buf){
        vec.clear();
        char *tmp = strtok(buf, ",");
        while (tmp) {
            vec.push_back(std::string(tmp));
            tmp = strtok(NULL, ",");
        }
        fund_info[vec[1]] = std::make_pair(vec[0], std::stod(vec[2]));
    }
    ifs.close();

    std::pair<std::string, double> tmp = fund_info["164906"];
    cout << tmp.first << endl;
    cout << tmp.second << endl;
    //cout << "006381: " << fund_info["006381"] << endl;
    
    return 0;
    
}

