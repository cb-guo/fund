#include "../conf/long_invest.h"

/*
 * 基金名称：广发中证全指信息技术ETF联接A
 * 基金代码：000942
 * 购买渠道：招商银行
 * 用途：长期
*/

const std::string fund_name = "广发中证全指信息技术ETF联接A";
const std::string fund_code = "000942";
const int total = 10;

// 次数,日期,金额,净值,第几次购买净值与目前购买净值对比(写0即可,代码计算)
Fund fund_array[total] = {
    {"01", "2022-04-06", 1000, 1.0708 },
    {"02", "2022-04-15", 1000, 1.0000 },
    {"03", "2022-04-25", 1000, 0.9008 },
    {"04", "2022-04-26", 1000, 0.8734 },
    {"05", "2022-05-24", 2000, 0.9576 },

    {"06", "2022-06-08", 3000, 1.0453 },
    {"07", "2022-06-09", 3000, 1.0155 },
    {"08", "2022-06-14", 1000, 1.0180 },
    {"09", "2022-09-22", 2000, 0.9602 },
    {"10", "2022-09-30", 2000, 0.9077 },
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