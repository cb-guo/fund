
#include "../conf/wang_ge.h"

/*
 * 基金名称：招商中证白酒指数C
 * 基金代码：012414
 * 购买渠道：支付宝
 * 用途：波段
*/

const std::string fund_name = "招商中证白酒指数C";
const std::string fund_code = "012414";
// 购买次数
const int total = 0;
Fund fund_array[total] = {
    //{"01", "2022-00-00", 2000, 1.0186 },
    
};

// 卖出次数
const int total_sell = 8;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-03-28", 1000, 0.9961, "2022-04-14", 1.0908 },
    {"02", "2022-05-09", 1500, 1.0272, "2022-05-20", 1.0877 },
    {"03", "2022-05-25", 2000, 1.0465, "2022-06-07", 1.1408 },
    {"04", "2022-10-27", 2000, 0.9042, "2022-11-02", 0.9634 },
    {"05", "2022-10-24", 2000, 0.9497, "2022-11-04", 0.9933 },

    {"06", "2022-11-09", 1000, 0.9649, "2022-11-15", 1.0252 },
    {"07", "2022-11-09", 1000, 0.9649, "2022-11-16", 1.0270 },
    {"08", "2022-10-19", 2000, 1.0186, "2022-12-06", 1.0978 },
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