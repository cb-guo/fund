#include "../conf/long_invest.h"

/*
 * 基金名称：大成中证红利指数A
 * 基金代码：090010
 * 购买渠道：招商银行
 * 用途：长期
*/

const std::string fund_name = "大成中证红利指数A";
const std::string fund_code = "090010";

const int total = 5;

// 次数,日期,金额,净值,第几次购买净值与目前购买净值对比(写0即可,代码计算)
Fund fund_array[total] = {
    {"01", "2021-11-25", 3000, 2.1330 },
    {"02", "2021-12-15", 1000, 2.1010 },
    {"03", "2022-01-26",  500, 2.1050 },
    {"04", "2022-04-25", 1000, 2.0170 },
    {"05", "2022-05-24", 1000, 2.0670 },
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