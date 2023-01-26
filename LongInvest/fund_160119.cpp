#include "../conf/long_invest.h"

/*
 * 基金名称：南方中证500ETF联接A
 * 基金代码：160119
 * 购买渠道：招商银行
 * 用途：长期
*/

const std::string fund_name = "南方中证500ETF联接A";
const std::string fund_code = "160119";

const int total = 9;
// 次数,日期,金额,净值
Fund fund_array[total] = {
    {"01", "2021-11-25", 2000, 1.9115 },
    {"02", "2021-12-08", 1000, 1.8997 },
    {"03", "2021-12-30", 1000, 1.9080 },
    {"04", "2022-01-21",  500, 1.8616 },
    {"05", "2022-01-26",  500, 1.7832 },
    
    {"06", "2022-02-07",  500, 1.7421 },
    {"07", "2022-04-21", 1000, 1.5371 },
    {"08", "2022-04-26", 1000, 1.4036 },
    {"09", "2022-05-24", 2000, 1.5385 },
};


// 买出数据结构
const int total_sell = 1;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"第一次", "2020-xx-xx", 0, 0, "2022-xx-xx", 2},
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