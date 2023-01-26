#include "../conf/wang_ge.h"

/*
 * 基金名称：广发中证传媒ETF联接C
 * 基金代码：004753
 * 购买渠道：支付宝
 * 用途：波段
*/

const std::string fund_name = "广发中证传媒ETF联接C";
const std::string fund_code = "004753";

const int total = 6;
Fund fund_array[total] = {
    {"01", "2022-02-15", 1000, 0.7469 },
    {"02", "2022-02-24", 1050, 0.7039 },
    {"03", "2022-03-08", 1100, 0.6667 },
    {"04", "2022-04-13", 1150, 0.6373 },
    {"05", "2022-06-13", 2000, 0.6308 },

    {"06", "2022-07-05", 3000, 0.6312 },
    
};


// 卖出次数
const int total_sell = 13;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-03-15", 1150, 0.6153, "2022-03-17", 0.6645 },
    {"02", "2022-04-25", 1250, 0.5584, "2022-04-29", 0.5985 },
    {"03", "2022-05-06", 1300, 0.5821, "2022-05-31", 0.6252 },
    {"04", "2022-05-24", 2000, 0.5883, "2022-06-01", 0.6261 },
    {"05", "2022-05-18", 2000, 0.5973, "2022-07-21", 0.6300 },

    {"06", "2022-08-02", 5000, 0.5927, "2022-08-11", 0.6194 },
    {"07", "2022-09-30", 1000, 0.5394, "2022-11-07", 0.5685 },
    {"08", "2022-09-22", 1000, 0.5614, "2022-11-15", 0.5905 },
    {"09", "2022-09-16", 3000, 0.5742, "2022-11-17", 0.6133 },
    // 2023
    {"10", "2022-09-07", 2000, 0.5953, "2023-01-04", 0.6324 },
    {"11", "2022-09-01", 3000, 0.6043, "2023-01-05", 0.6412 },
    {"12", "2022-04-21", 1200, 0.6049, "2023-01-10", 0.6446 },
    {"13", "2022-08-29", 2000, 0.6107, "2023-01-16", 0.6405 },
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