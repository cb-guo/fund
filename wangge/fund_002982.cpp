#include "../conf/wang_ge.h"

/*
 * 基金名称：广发中证养老产业C
 * 基金代码：002982
 * 购买渠道：支付宝
 * 用途：波段
*/

const std::string fund_name = "广发中证养老产业C";
const std::string fund_code = "002982";
// 购买次数

const int total = 2;
Fund fund_array[total] = {
    {"01", "2022-07-06", 2000, 0.9816 },
    {"02", "2022-07-22", 2000, 0.9423 },
    
};


// 卖出次数
const int total_sell = 3;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-09-19", 2000, 0.8626, "2022-11-04", 0.8957 },
    {"02", "2022-08-02", 2000, 0.8974, "2022-12-06", 0.9371 },
    // 2023
    {"03", "2022-06-09", 2000, 0.9225, "2023-01-13", 0.9663 },

};


int main() {
  cout << "\n" << fund_name << "\n";
  unordered_map<std::string, std::pair<std::string, double> > fund_info = get_fund_info();
  if (fund_info.find(fund_code) == fund_info.end()) {
    return 0;
  }
  std::pair<std::string, double> tmp = fund_info[fund_code];
  std::string current_date = tmp.first;
  double current_jingzhi = tmp.second;
  buy_function(fund_array, total, current_jingzhi, current_date);
  
  // 卖出函数
  if (detail_switch) {
    sell_function(fund_sell_array, total_sell);
  }
}