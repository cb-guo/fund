#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct total_fund{
    std::string fund_name;
    double cmp;  // 上次购买价格与目前价格对比
    double before_buy_price;
    double current_price;
} Fund;

const int fund_number = 3;
Fund fund_array[fund_number] = {
    {"中证500", 0, 1, 1.5},
    {"中证600", 0, 1, 2},
    {"中证700", 0, 2, 1}
};

void compare_ratio(Fund *fund) {
    double &cmp = fund->cmp;
    double &before_buy_price = fund->before_buy_price;
    double &current_price = fund->current_price;
    if (current_price < before_buy_price) {
        cmp = 100 * (1 - current_price / before_buy_price);
        cmp = -1 * cmp;
    } else if (current_price > before_buy_price) {
        cmp = 100 * ((current_price - before_buy_price) / before_buy_price);
    } else {
        cmp = 0;
    }
}

bool compare(Fund fund1, Fund fund2) {
    return fund1.cmp > fund2.cmp;
}

int main() {
  cout << "\n" ;
  for (int i=0; i<fund_number; ++i) {
    compare_ratio(&fund_array[i]);
  }
  std::sort(fund_array, fund_array + fund_number, compare);
  for (int i=0; i<fund_number; ++i) {
    std::string &fund_name = fund_array[i].fund_name;
    double &cmp = fund_array[i].cmp;
    double &before_buy_price = fund_array[i].before_buy_price;
    double &current_price = fund_array[i].current_price;
    if (fund_array[i].cmp < 0.0) {
      printf("基金名称：%s, 下降:%.2f%%,  上次购买价格:%.4f, 目前价格:%.4f\n", fund_name.c_str(), cmp, before_buy_price, current_price);
    } else if (fund_array[i].cmp >= 0.0) {
      printf("基金名称：%s, 上涨:%.2f%%,  上次购买价格:%.4f, 目前价格:%.4f\n", fund_name.c_str(), cmp, before_buy_price, current_price);
    }
  }
  cout << "\n" ;
}



