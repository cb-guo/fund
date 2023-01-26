#include "../conf/long_invest.h"

/*
 * 基金名称：广发中证养老产业A
 * 基金代码：000968
 * 购买渠道：招商银行
 * 用途：长期
*/

const std::string fund_name = "广发中证养老产业A";
const std::string fund_code = "000968";
const int total = 9;

// 次数,日期,金额,净值,第几次购买净值与目前购买净值对比(写0即可,代码计算)
Fund fund_array[total] = {
    {"01", "2022-03-29", 1000, 0.9513 },
    {"02", "2022-04-25", 2000, 0.8553 },
    {"03", "2022-05-09", 1000, 0.8954 },
    {"04", "2022-05-24", 3000, 0.8952 },
    {"05", "2022-06-02", 2000, 0.9322 },

    {"06", "2022-06-08", 2000, 0.9525 },
    {"07", "2022-06-09", 3000, 0.9352 },
    {"08", "2022-09-07", 2000, 0.9067 },
    {"09", "2022-09-19", 2000, 0.8750 },
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