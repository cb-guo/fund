#include "../conf/long_invest.h"

/*
 * 基金名称：广发中证传媒ETF联接C
 * 基金代码：004753
 * 购买渠道：招商银行
 * 用途：波段
*/

const std::string fund_name = "广发中证传媒ETF联接C";
const std::string fund_code = "004753";

const int total = 13;
Fund fund_array[total] = {
    {"01", "2022-04-25", 2000, 0.5584 },
    {"02", "2022-05-12", 2000, 0.5955 },
    {"03", "2022-05-19", 2000, 0.5962 },
    {"04", "2022-05-24", 3000, 0.5883 },
    {"05", "2022-06-02", 2000, 0.6252 },

    {"06", "2022-06-07", 3000, 0.6346 },
    {"07", "2022-06-09", 2000, 0.6317 },
    {"08", "2022-06-14", 1000, 0.6285 },
    {"09", "2022-07-06", 2000, 0.6208 },
    {"10", "2022-07-13", 2000, 0.6139 },

    {"11", "2022-08-02", 5000, 0.5927 },
    {"12", "2022-09-19", 5000, 0.5645 },
    {"13", "2022-10-25", 3000, 0.5170 },
};


// 卖出次数
const int total_sell = 1;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-03-15", 0, 0, "2022-xx-xx", 0 },
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