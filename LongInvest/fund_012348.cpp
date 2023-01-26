#include "../conf/long_invest.h"

/*
 * 基金名称：天弘恒生科技指数A
 * 基金代码：012348
 * 购买渠道：招商银行
 * 用途：长期
*/

const std::string fund_name = "天弘恒生科技指数A";
const std::string fund_code = "012348";

const int total = 11;
// 次数,日期,金额,净值
Fund fund_array[total] = {
    {"01", "2022-02-15", 1000, 0.7290 },
    {"02", "2022-03-02", 2000, 0.6775 },
    {"03", "2022-03-09", 1000, 0.5823 },
    {"04", "2022-03-15", 1000, 0.4726 },
    {"05", "2022-04-25", 1000, 0.5202 },

    {"06", "2022-05-10", 1000, 0.5501 },
    {"07", "2022-05-12", 2000, 0.5454 },
    {"08", "2022-05-24", 1000, 0.5640 },
    {"09", "2022-09-23", 3000, 0.5318 },
    {"10", "2022-10-10", 2000, 0.5144 },
    {"11", "2022-10-24", 5000, 0.4279 },
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