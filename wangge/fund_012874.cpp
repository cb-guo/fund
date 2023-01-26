#include "../conf/wang_ge.h"

/*
 * 基金名称：易方达中证全指证券公司指数C
 * 基金代码：012874
 * 购买渠道：支付宝
 * 用途：波段
*/

const std::string fund_name = "易方达中证全指证券公司指数C";
const std::string fund_code = "012874";
// 购买次数
const int total = 3;
Fund fund_array[total] = {
    {"01", "2022-06-16", 2000, 1.1128 },
    {"02", "2022-06-29", 2000, 1.1117 },
    {"03", "2022-07-05", 2000, 1.0994 },
    
};


// 卖出次数
const int total_sell = 7;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-05-09", 1200, 0.9789, "2022-06-09", 1.0622 },
    {"02", "2022-05-30", 2000, 1.0074, "2022-06-14", 1.1236 },
    {"03", "2022-08-02", 2000, 1.0079, "2022-08-11", 1.0797 },
    {"04", "2022-09-30", 1000, 0.9489, "2022-11-04", 0.9845 },
    {"05", "2022-09-16", 3000, 1.0052, "2022-12-05", 1.0653 },
    // 2023
    {"06", "2022-12-19", 2000, 1.0042, "2023-01-13", 1.0580 },
    {"07", "2022-07-20", 1000, 1.0637, "2023-01-16", 1.0901 },
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