#include "../conf/alipay.h"

/*
 * 基金名称：兴全新视野灵活配置定期开放混合
 * 基金代码：001511
 * 购买渠道：支付宝
 * 用途：尽快卖掉
*/

const std::string fund_name = "兴全新视野灵活配置定期开放混合";
const std::string fund_code = "001511";

const int total = 2;
// 次数,日期,金额,净值
Fund fund_array[total] = {
    {"01", "2020-10-29", 3000, 1.7970 },
    {"02", "2021-01-26", 2000, 1.9760 },
    
};

// 买出数据结构
const int total_sell = 3;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2021-04-25", 1000, 1.3910, "2022-07-26", 1.6710 },
    {"02", "2021-04-29", 1000, 1.4750, "2022-07-28", 1.6820 },
    {"03", "2022-10-31", 2000, 1.4270, "2023-01-18", 1.6150 },
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