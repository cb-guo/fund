
#include "../conf/wang_ge.h"

/*
 * 基金名称：广发金融地产指数C
 * 基金代码：002979
 * 购买渠道：支付宝
 * 用途：波段
*/

const std::string fund_name = "广发金融地产指数C";
const std::string fund_code = "002979";
// 购买次数
const int total = 0;
Fund fund_array[total] = {
    //{"01", "2022-05-16", 2000, 0.9426 },
  
};

// 卖出次数
const int total_sell = 5;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-05-24", 1000, 0.9358, "2022-09-09", 0.9697 },
    {"02", "2022-08-02", 1000, 0.9176, "2022-09-09", 0.9697 },
    {"03", "2022-10-26", 2000, 0.8557, "2022-11-14", 0.9183 },
    {"04", "2022-05-16", 2000, 0.9426, "2022-12-05", 0.9807 },
    {"05", "2022-06-02", 1000, 0.9429, "2022-12-05", 0.9807 },
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