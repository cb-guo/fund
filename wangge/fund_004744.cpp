#include "../conf/wang_ge.h"

/*
 * 基金名称：易方达创业板ETF联接C 
 * 基金代码：004744
 * 购买渠道：支付宝
 * 用途：波段
*/

const std::string fund_name = "易方达创业板ETF联接C";
const std::string fund_code = "004744";
// 购买次数
const int total = 8;

Fund fund_array[total] = {
    {"01", "2022-01-20",  500, 3.0329 },
    {"02", "2022-01-21",  500, 3.0035 },
    {"03", "2022-01-25",  500, 2.9472 },
    {"04", "2022-01-27",  200, 2.8832 },
    {"05", "2022-01-28",  200, 2.8851 },

    {"06", "2022-06-29",  500, 2.7557 },
    {"07", "2022-08-24",  500, 2.6706 },
    {"08", "2022-08-31", 1000, 2.5682 },

};

// 卖出次数
const int total_sell = 6;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-05-09", 1000, 2.2400, "2022-05-11", 2.3518 },
    {"02", "2022-05-24", 1000, 2.3270, "2022-06-06", 2.5523 },
    {"03", "2022-05-13",  860, 2.3634, "2022-06-07", 2.5521 },
    {"04", "2022-04-11",  500, 2.4616, "2022-06-17", 2.6502 },
    {"05", "2022-04-06",  500, 2.6233, "2022-06-24", 2.8075 },

    {"06", "2022-09-15", 2000, 2.4293, "2023-01-16", 2.5332 },
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