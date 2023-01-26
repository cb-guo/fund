#include "../conf/wang_ge.h"
/*
 * 基金名称：天弘恒生科技指数(QDLL)C
 * 基金代码：012349
 * 购买渠道：支付宝
 * 用途：波段
*/

const std::string fund_name = "天弘恒生科技指数(QDLL)C";
const std::string fund_code = "012349";

// 买入次数
const int total = 7;
// 次数,买入时间,买入金额,买入净值
Fund fund_array[total] = {
    {"01", "2022-02-14",  500, 0.7281 },
    {"02", "2022-02-22",  525, 0.6919 },
    {"03", "2022-06-13", 1000, 0.6476 },
    {"04", "2022-06-29", 2000, 0.6892 },
    {"05", "2022-07-06", 1000, 0.6754 },

    {"06", "2022-07-11", 2000, 0.6483 },
    // 2023
    {"07", "2023-01-16", 2000, 0.6304 },
    
};

// 卖出次数
const int total_sell = 26;
// 次数,买入时间,买入金额,买入净值,卖出时间,卖出净值
FundSell fund_sell_array[total_sell] = {
    {"01", "2022-03-15",  625, 0.4720, "2022-03-16", 0.5702 },
    {"02", "2022-03-11",  600, 0.5652, "2022-03-22", 0.6202 },
    {"03", "2022-03-07",  575, 0.6019, "2022-03-23", 0.6312 },
    {"04", "2022-03-25",  575, 0.5860, "2022-03-30", 0.6149 },
    {"05", "2022-04-25", 1200, 0.5193, "2022-04-29", 0.6177 },

    {"06", "2022-05-10", 1000, 0.5492, "2022-05-17", 0.6045 },
    {"07", "2022-04-11", 1000, 0.5598, "2022-05-17", 0.6045 },
    {"08", "2022-05-19", 1200, 0.5779, "2022-05-30", 0.6110 },
    {"09", "2022-05-24", 3000, 0.5630, "2022-05-30", 0.6110 },
    {"10", "2022-03-25", 1000, 0.5860, "2022-05-31", 0.6246 },

    {"11", "2022-04-08", 1000, 0.5895, "2022-06-06", 0.6422 },
    {"12", "2022-06-22", 1500, 0.6401, "2022-06-24", 0.6789 },
    {"13", "2022-03-03",  550, 0.6518, "2022-06-27", 0.7062 },
    {"14", "2022-08-10", 3000, 0.5933, "2022-08-11", 0.6113 },
    {"15", "2022-08-24", 3000, 0.5788, "2022-08-25", 0.6137 },

    {"16", "2022-10-24", 1000, 0.4268, "2022-10-31", 0.4361 },
    {"17", "2022-10-20", 2000, 0.4729, "2022-11-04", 0.5006 },
    {"18", "2022-11-09",  970, 0.4985, "2022-11-11", 0.5275 },
    {"19", "2022-11-09", 1030, 0.4985, "2022-11-14", 0.5289 },
    {"20", "2022-09-30", 1000, 0.5205, "2022-11-15", 0.5638 },

    {"21", "2022-09-22", 1000, 0.5421, "2022-12-01", 0.5750 },
    {"22", "2022-09-14", 3000, 0.5756, "2022-12-05", 0.6257 },
    {"23", "2022-09-19", 2000, 0.5540, "2022-12-05", 0.6257 },
    {"24", "2022-08-02", 3000, 0.5948, "2022-12-09", 0.6358 },
    // 2023
    {"25", "2022-09-01", 2000, 0.6069, "2023-01-04", 0.6368 },
    {"26", "2022-07-29", 2000, 0.6117, "2023-01-05", 0.6445 },
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