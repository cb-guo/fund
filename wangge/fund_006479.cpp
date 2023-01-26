
#include "../conf/wang_ge.h"

/*
 * 基金名称：广发纳斯达克100指数C
 * 基金代码：006479
 * 购买渠道：支付宝
 * 用途：波段
*/

const std::string fund_name = "纳斯达克100C";
const std::string fund_code = "006479";
// 购买次数
const int total = 3;
Fund fund_array[total] = {
    {"01", "2022-11-10", 2000, 3.5902 },
    {"02", "2022-12-19", 2000, 3.3152 },
    {"03", "2023-01-03", 2000, 3.2374 },
};


// 卖出次数
const int total_sell = 6;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-01-20", 1000, 4.1350, "2022-03-29", 4.2801 },
    {"02", "2022-01-24",  500, 4.0335, "2022-03-29", 4.2801 },
    {"03", "2022-01-27",  300, 3.8965, "2022-03-29", 4.2801 },
    {"04", "2022-05-25", 1000, 3.4339, "2022-06-01", 3.6218 },
    {"05", "2022-06-13", 2000, 3.2752, "2022-07-08", 3.5105 },
    
    {"06", "2022-05-20", 1000, 3.4481, "2022-07-29", 3.7623 },
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

  if (detail_switch) {
    sell_function(fund_sell_array, total_sell);
  }
   
}