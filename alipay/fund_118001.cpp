#include "../conf/alipay.h"

/*
 * 基金名称：易方达亚洲精选股票
 * 基金代码：118001
 * 购买渠道：支付宝
 * 用途：长期
*/

const std::string fund_name = "易方达亚洲精选股票";
const std::string fund_code = "118001";

const int total = 3;
// 次数,日期,金额,净值
Fund fund_array[total] = {
    /*{"01", "2021-06-04", 2000, 1.3550 },
    {"02", "2021-06-10", 1000, 1.3290 },
    {"03", "2021-06-21",  100, 1.3100 },
    {"04", "2021-06-28",  500, 1.3560 },
    {"05", "2021-07-11",  200, 1.2830 },

    {"06", "2021-07-19",  200, 1.2930 },
    {"07", "2021-07-26",  300, 1.2150 },
    {"08", "2021-07-27",  200, 1.1480 },
    {"09", "2021-07-28",  100, 1.1660 },
    {"10", "2021-08-12",  200, 1.2180 },

    {"11", "2021-09-15",  100, 1.1950 },
    {"12", "2021-10-28",  100, 1.1900 },
    {"13", "2021-11-01",  100, 1.1940 },
    {"14", "2021-11-11",  200, 1.2010 },
    {"15", "2021-11-19",  200, 1.1890 },
    
    {"16", "2021-12-14",  100, 1.1080 },*/
    {"17", "2022-09-07", 1000, 1.0070 },
    {"18", "2022-09-22", 1000, 0.9440 },
    {"19", "2022-10-13", 1000, 0.8660 },

};


// 买出数据结构
const int total_sell = 3;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-05-10", 1500, 0.9250, "2022-08-19", 1.0370 },
    {"02", "2022-05-26", 2000, 0.9370, "2022-08-25", 1.0700 },
    {"03", "2022-10-24", 1000, 0.7910, "2022-11-16", 0.9880 },
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