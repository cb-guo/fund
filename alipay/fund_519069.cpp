#include "../conf/alipay.h"

/*
 * 基金名称：汇添富价值精选混合A
 * 基金代码：519069
 * 购买渠道：支付宝
 * 用途：尽快卖掉
*/

const std::string fund_name = "汇添富价值精选混合A";
const std::string fund_code = "519069";

const int total = 4;
// 次数,日期,金额,净值
Fund fund_array[total] = {
    /*{"01", "2021-01-28",  600, 4.1560 },
    {"02", "2021-03-08",  100, 3.7990 },
    {"03", "2021-03-09",  100, 3.7040 },
    {"04", "2021-03-15",  100, 3.7770 },
    {"05", "2021-03-23",  100, 3.7340 },

    {"06", "2021-03-24",  100, 3.6630 },
    {"07", "2021-04-12",  100, 3.6660 },
    {"08", "2021-06-16",  100, 3.8950 },
    {"09", "2021-06-17",  100, 3.9030 },
    {"10", "2021-09-15",  100, 3.6460 },*/
    
    {"11", "2022-03-15",  500, 2.9410 },
    {"12", "2022-03-28",  500, 3.0140 },
    {"13", "2022-08-24", 1000, 2.9400 },
    {"14", "2022-10-19", 1000, 2.7300 },
};


// 买出数据结构
const int total_sell = 2;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-04-25",  500, 2.8470, "2022-08-22", 3.0140 },
    {"02", "2022-05-09",  500, 2.8490, "2022-08-22", 3.0140 },
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