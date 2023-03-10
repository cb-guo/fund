#include "../conf/alipay.h"

/*
 * 基金名称：景顺长城新兴成长混合
 * 基金代码：260108
 * 购买渠道：支付宝
 * 用途：长期
*/

const std::string fund_name = "景顺长城新兴成长混合";
const std::string fund_code = "260108";

const int total = 1;
// 次数,日期,金额,净值
Fund fund_array[total] = {
    /*{"01", "2020-12-29",  500, 3.1640 },
    {"02", "2021-01-28",  300, 3.2090 },
    {"03", "2021-02-22",  300, 3.3110 },
    {"04", "2021-03-01",  200, 3.1250 },
    {"05", "2021-03-02",  200, 3.0460 },

    {"06", "2021-03-08",  100, 2.7670 },
    {"07", "2021-03-15",  100, 2.7780 },
    {"08", "2021-03-19",  100, 2.8380 },
    {"09", "2021-03-22",  100, 2.8410 },
    {"10", "2021-03-23",  100, 2.8410 },

    {"11", "2021-04-09",  100, 2.9960 },
    {"12", "2021-05-10",  100, 3.0080 },
    {"13", "2021-06-08",  100, 3.2610 },
    {"14", "2021-06-15",  100, 3.2320 },
    {"15", "2021-06-16",  200, 3.1580 },

    {"16", "2021-06-18",  100, 3.1580 },
    {"17", "2021-06-21",  100, 3.1510 },
    {"18", "2021-06-23",  200, 3.1590 },
    {"19", "2021-07-06",  200, 3.0770 },
    {"20", "2021-07-23",  200, 3.0360 },

    {"21", "2021-07-26",  300, 2.8840 },
    {"22", "2021-07-29",  100, 2.8360 },
    {"23", "2021-07-30",  200, 2.7130 },
    {"24", "2021-08-12",  200, 2.7750 },
    {"25", "2021-08-18",  100, 2.6600 },

    {"26", "2021-08-20",  100, 2.4930 },
    {"27", "2021-09-15",  200, 2.5640 },
    {"28", "2021-09-22",  100, 2.6370 },
    {"29", "2021-10-18",  100, 2.8000 },
    {"30", "2021-10-27",  100, 2.7660 },

    {"31", "2021-11-02",  100, 2.7210 },
    {"32", "2021-11-10",  100, 2.7040 },*/
    {"33", "2021-11-12",  100, 2.6910 },

};


// 买出数据结构
const int total_sell = 7;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-03-15",  500, 2.1560, "2022-04-14", 2.3510 },
    {"02", "2022-03-28",  500, 2.1830, "2022-04-15", 2.3580 },
    {"03", "2022-04-25",  500, 2.2120, "2022-04-29", 2.3340 },
    {"04", "2022-05-06",  500, 2.2440, "2022-08-22", 2.3590 },
    {"05", "2022-05-19", 1000, 2.2260, "2022-08-22", 2.3590 },

    {"06", "2022-10-26", 2000, 2.1030, "2023-01-06", 2.4870 },
    {"07", "2022-08-24", 1000, 2.3090, "2023-01-16", 2.6380 },
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