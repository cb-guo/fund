#include "../conf/wang_ge.h"

/*
 * 基金名称：广发信息技术联接C
 * 基金代码：002974
 * 购买渠道：支付宝
 * 用途：波段
*/

const std::string fund_name = "广发信息技术联接C";
const std::string fund_code = "002974";

// 购买次数
const int total = 2;
Fund fund_array[total] = {
    {"01", "2022-08-24", 2000, 1.0384 },
    {"02", "2022-08-31", 2000, 1.0050 },
   
};

// 卖出次数
const int total_sell = 11;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-04-25", 1000, 0.8921, "2022-05-11", 0.9539 },
    {"02", "2022-05-24", 1500, 0.9481, "2022-06-02", 1.0171 },
    {"03", "2022-05-13", 1500, 0.9543, "2022-06-06", 1.0459 },
    {"04", "2022-04-11", 1000, 0.9890, "2022-07-08", 1.0470 },
    {"05", "2022-06-09", 2000, 1.0053, "2022-08-05", 1.0891 },

    {"06", "2022-07-05", 3000, 1.0380, "2022-08-08", 1.0926 },
    {"07", "2022-04-06", 1000, 1.0605, "2022-08-11", 1.1136 },
    {"08", "2022-10-10", 3000, 0.8645, "2022-10-19", 0.9338 },
    {"09", "2022-09-23", 1000, 0.9300, "2022-10-31", 0.9689 },
    {"10", "2022-09-19", 2000, 0.9594, "2022-11-04", 1.0082 },
    // 2023
    {"11", "2022-12-19", 2000, 0.9590, "2023-01-17", 1.0039 },
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