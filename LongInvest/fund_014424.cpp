#include "../conf/long_invest.h"

/*
 * 基金名称：博时恒生医疗保健ETF联接A
 * 基金代码：014424
 * 购买渠道：支付宝
 * 用途：长期
*/

const std::string fund_name = "博时恒生医疗保健ETF联接A";
const std::string fund_code = "014424";

const int total = 0;
// 次数,日期,金额,净值
Fund fund_array[total] = {
    //{"01", "2022-06-13", 2000, 0.000 },
  
};


// 买出数据结构
const int total_sell = 3;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-09-19", 3000, 0.7609, "2022-11-14", 0.9165 },
    {"02", "2022-06-13", 2000, 0.8235, "2023-01-04", 1.0010 },
    {"03", "2022-06-29", 1000, 0.9272, "2023-01-04", 1.0010 },
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