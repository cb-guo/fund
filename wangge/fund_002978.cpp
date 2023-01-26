#include "../conf/wang_ge.h"

/*
 * 基金名称：广发中证全指医药卫生ETF联接C 
 * 基金代码：002978
 * 购买渠道：支付宝
 * 用途：波段
*/

const std::string fund_name = "广发中证全指医药卫生ETF联接C";
const std::string fund_code = "002978";

const int total = 5;
Fund fund_array[total] = {
    {"01", "2022-01-21", 1000, 1.0902 },
    {"02", "2022-01-24", 1500, 1.0815 },
    {"03", "2022-01-25",  500, 1.0537 },
    {"04", "2022-01-27",  200, 1.0216 },
    {"05", "2022-01-28",  300, 1.0202 },
    
};


// 买出数据结构
const int total_sell = 10;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-06-02", 2000, 0.9272, "2022-06-24", 1.0148 },
    {"02", "2022-05-24", 2000, 0.9136, "2022-06-24", 1.0148 },
    {"03", "2022-05-18", 1500, 0.9307, "2022-06-27", 1.0258 },
    {"04", "2022-04-21",  500, 0.9401, "2022-06-27", 1.0258 },
    {"05", "2022-08-02", 2000, 0.9377, "2022-08-11", 0.9787 },

    {"06", "2022-09-19", 2000, 0.8729, "2022-10-14", 0.9395 },
    {"07", "2022-09-22", 2000, 0.8459, "2022-10-14", 0.9395 },
    {"08", "2022-09-14", 2000, 0.9180, "2022-11-02", 0.9686 },
    {"09", "2022-08-19", 2000, 0.9471, "2022-11-04", 0.9808 },
    // 2023
    {"10", "2022-12-19", 2000, 0.9578, "2023-01-13", 1.0104 },
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