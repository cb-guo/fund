#include "../conf/long_invest.h"

/*
 * 基金名称：博时标普500ETF联接A类QDll
 * 基金代码：050025
 * 购买渠道：招商银行
 * 用途：长期
*/

const std::string fund_name = "博时标普500ETF联接A类QDll";
const std::string fund_code = "050025";

const int total = 8;
// 次数,日期,金额,净值
Fund fund_array[total] = {
    {"01", "2021-12-01", 1000, 3.3375 },
    {"02", "2021-12-09",  500, 3.3535 },
    {"03", "2022-01-13",  500, 3.3705 },
    {"04", "2022-01-21",  500, 3.2447 },
    {"05", "2022-01-24",  500, 3.2024 },

    {"06", "2022-01-26",  500, 3.1489 },
    {"07", "2022-05-20", 1000, 2.9600 },
    {"08", "2022-10-14", 2000, 2.8661 },
};


// 买出数据结构
const int total_sell = 1;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-06-21", 1000, 2.8372, "2022-08-23", 3.1691 },
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