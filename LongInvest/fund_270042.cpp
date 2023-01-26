#include "../conf/long_invest.h"

/*
 * 基金名称：广发纳斯达克100指数A(QDll)
 * 基金代码：270042
 * 购买渠道：招商银行
 * 用途：长期
*/

const std::string fund_name = "广发纳斯达克100指数A(QDll)";
const std::string fund_code = "270042";

const int total = 12;
// 次数,日期,金额,净值
Fund fund_array[total] = {
    {"01", "2021-12-01", 2000, 4.6274 },
    {"02", "2021-12-09", 1000, 4.5983 },
    {"03", "2022-01-13",  500, 4.4588 },
    {"04", "2022-01-21",  500, 4.2313 },
    {"05", "2022-01-24",  500, 4.1665 },

    {"06", "2022-01-26",  500, 4.0644 },
    {"07", "2022-01-28",  500, 3.9671 },
    {"08", "2022-05-11", 1000, 3.5250 },
    {"09", "2022-05-26", 1000, 3.5766 },
    {"10", "2022-10-14", 2000, 3.2868 },

    {"11", "2022-12-28", 2000, 3.2280 },
    // 2023
    {"12", "2023-01-12", 2000, 3.3709 },

};


// 买出数据结构
const int total_sell = 2;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-07-01", 1000, 3.3743, "2022-08-19", 3.9194 },
    {"02", "2022-05-20", 1000, 3.4799, "2022-08-23", 3.8383 },
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