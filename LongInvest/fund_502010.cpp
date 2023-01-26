#include "../conf/long_invest.h"

/*
 * 基金名称：易方达中证全指证券公司指数A
 * 基金代码：502010
 * 购买渠道：招商银行
 * 用途：波段
*/

const std::string fund_name = "易方达中证全指证券公司指数A";
const std::string fund_code = "502010";

const int total = 6;
Fund fund_array[total] = {
    {"01", "2022-05-09", 2000, 0.9820 },
    {"02", "2022-05-12", 2000, 1.0016 },
    {"03", "2022-05-19", 2000, 1.0049 },
    {"04", "2022-05-24", 3000, 0.9977 },
    {"05", "2022-06-07", 3000, 1.0492 },
    
    {"06", "2022-10-10", 3000, 0.9441 },
};


// 卖出次数
const int total_sell = 1;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-03-15", 0, 0, "2022-xx-xx", 0 },
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
    //sell_function(fund_sell_array, total_sell);
  }

}