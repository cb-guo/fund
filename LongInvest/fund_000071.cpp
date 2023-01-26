#include "../conf/long_invest.h"

/*
 * 基金名称：华夏恒生ETF联接A(QDll)
 * 基金代码：000071
 * 购买渠道：招商银行
 * 用途：长期
*/

const std::string fund_name = "华夏恒生ETF联接A(QDll)";
const std::string fund_code = "000071";
const int total = 12;

// 次数,日期,金额,净值
Fund fund_array[total] = {
    {"01", "2022-02-28", 1000, 1.2024 },
    {"02", "2022-03-08", 1000, 1.1169 },
    {"03", "2022-03-15", 5000, 0.9842 },
    {"04", "2022-04-25", 1000, 1.0688 },
    {"05", "2022-05-10", 2000, 1.0888 },
    
    {"06", "2022-05-12", 2000, 1.0779 },
    {"07", "2022-06-13", 2000, 1.1683 },
    {"08", "2022-08-23", 3000, 1.1143 },
    {"09", "2022-09-19", 5000, 1.0790 },
    {"10", "2022-09-23", 5000, 1.0500 },
    
    {"11", "2022-10-10", 5000, 1.0223 },
    {"12", "2022-10-24", 5000, 0.9079 },
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