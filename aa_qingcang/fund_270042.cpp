#include "../conf/alipay.h"

/*
 * 基金名称：广发纳斯达克100指数A
 * 基金代码：270042
 * 购买渠道：支付宝
 * 用途：及时卖出
*/

const std::string fund_name = "广发纳斯达克100指数A";
const int total = 11;

// 次数,日期,金额,净值,第几次购买净值与目前购买净值对比(写0即可,代码计算)
Fund fund_array[total] = {
    {"01", "2021-06-21",  200, 4.0204 },
    {"02", "2021-09-22",  100, 4.3341 },
    {"03", "2021-09-23",  100, 4.3765 },
    {"04", "2021-09-24",  100, 4.3708 },
    {"05", "2021-10-11",  100, 4.1880 },

    {"06", "2021-10-13",  100, 4.2105 },
    {"07", "2021-10-14",  100, 4.2769 },
    {"08", "2021-10-15",  100, 4.3027 },
    {"09", "2022-05-11",  500, 3.5250 },
    {"10", "2022-05-20",  600, 3.4799 },

    {"11", "2022-06-30", 1000, 3.3638 },
};


// 买出数据结构
const int total_sell = 1;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"第一次", "2020-xx-xx", 0, 0, "2022-xx-xx", 2},
};


int main() {
  cout << "\n" << fund_name << "\n";
  cout << "买入记录\n" ;
  printf("%s, 净值:%.4f\n", current_date.c_str(), current_jingzhi_270042);
  buy_function(fund_array, total, current_jingzhi_270042);
  
}