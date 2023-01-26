#include "../conf/alipay.h"

/*
 * 基金名称：交银海外中国互联网指数 
 * 基金代码：164906
 * 购买渠道：支付宝
 * 用途：波段
*/

const std::string fund_name = "交银海外中国互联网指数";
const std::string fund_code = "164906";

const int total = 4;
Fund fund_array[total] = {
    {"01", "2022-01-28", 1000, 1.0050 },
    {"02", "2022-03-07", 1000, 0.8550 },
    {"03", "2022-10-24",  500, 0.6480 },
    {"04", "2022-10-28",  500, 0.6660 },
};


// 买出数据结构
const int total_sell = 1;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"第一次", "2020-10-10", 1000, 1, "2022-08-11", 2},
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