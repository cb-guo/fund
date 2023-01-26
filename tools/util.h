#include <iostream>
#include <stdio.h>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

// 基金买入数据结构
// 辅助进行网格操作
typedef struct FundStruct {
    std::string number; // 第几次购买
    std::string date;   // 日期
    double money;       // 金额
    double jingzhi;     // 净值
    double cmp;         
} Fund;

void compare_ratio(Fund *fund, const double &current_jingzhi) {
    // 第几次购买净值与目前购买净值对比
    double cmp = 0.0;
    double &jingzhi = fund->jingzhi;
    if (current_jingzhi < jingzhi) {
        cmp = 100 * (1 - current_jingzhi / jingzhi);
        /*printf("%s, 买入时间:%s, 买入净值:%.4f, 份额:%7.2f, 买入金额:%4.0f, 预估卖出金额: %7.2f, 下降: -%.2f%%\n", \
                fund->number.c_str(), fund->date.c_str(), fund->jingzhi, fund->money/fund->jingzhi, fund->money,
                current_jingzhi * (fund->money/fund->jingzhi), cmp); */
        printf("%s, %s, %.4f, 份额:%7.2f, 买入:%4.0f, 卖出:%7.2f, -%.2f%%\n", \
                fund->number.c_str(), fund->date.c_str(), fund->jingzhi, fund->money/fund->jingzhi, fund->money,
                current_jingzhi * (fund->money/fund->jingzhi), cmp);
    } else if (current_jingzhi >= jingzhi) {
        cmp = 100 * ((current_jingzhi - jingzhi) / jingzhi);
        /*printf("%s, 买入时间:%s, 买入净值:%.4f, 份额:%7.2f, 买入金额:%4.0f, 预估卖出金额: %7.2f, 上涨: +%.2f%%\n", \
               fund->number.c_str(), fund->date.c_str(), fund->jingzhi, fund->money/fund->jingzhi, fund->money,
               current_jingzhi * (fund->money/fund->jingzhi), cmp); */
        printf("%s, %s, %.4f, 份额:%7.2f, 买入:%4.0f, 卖出:%7.2f, +%.2f%%\n", \
               fund->number.c_str(), fund->date.c_str(), fund->jingzhi, fund->money/fund->jingzhi, fund->money,
               current_jingzhi * (fund->money/fund->jingzhi), cmp);
    }
}


void buy_function(Fund *fund_array, const int &total_buy, const double &current_jingzhi, std::string& current_date) {
    printf("%s, 净值:%.4f\n", current_date.c_str(), current_jingzhi);
    double total_fene = 0.0;
    double total_money = 0.0;
    double current_money = 0.0;

    // 总份额，总金额，目前金额，亏损幅度
    for (int i = 0; i < total_buy; i++) {
        compare_ratio(fund_array + i, current_jingzhi);
        total_fene += (fund_array + i)->money / (fund_array + i)->jingzhi;
        total_money += (fund_array + i)->money;
    }
    current_money = total_fene * current_jingzhi;
    printf("总份额: %7.2f, 购买金额: %4.0f, 目前金额: %7.2f, 幅度：%.2f%%\n\n", 
            total_fene, total_money, current_money, 100.0 * (current_money/total_money));
}



// 基金卖出数据结构, 用于记录
typedef struct FundSellStruct {
    std::string number;     // 第几次购买
    std::string buy_date;   // 买入时间
    double buy_money;       // 买入金额
    double buy_jingzhi;     // 买入净值

    std::string sell_date;  // 卖出时间
    double sell_jingzhi;    // 卖出净值
} FundSell;


void sell_function(FundSell *fund_sell_array, const int &total_sell) {
    cout << "--- 卖出记录:\n" ;
    FundSell *fund_sell = nullptr;
    double total_sell_money = 0.0;
    for (int i = 0; i < total_sell; i++) {
        fund_sell = fund_sell_array + i;
        double fene = fund_sell->buy_money/fund_sell->buy_jingzhi;
        double bonus = fund_sell->sell_jingzhi * fene - fund_sell->buy_money;
        printf("%s, 买入时间:%s, 买入金额:%.2f, 买入净值:%.4f, 买入份额:%.2f\n",
            fund_sell->number.c_str(), fund_sell->buy_date.c_str(), fund_sell->buy_money, fund_sell->buy_jingzhi, fene);
        printf("    卖出时间:%s, 卖出金额:%.2f, 卖出净值:%.4f, 卖出份额:%.2f\n", 
            fund_sell->sell_date.c_str(), fund_sell->sell_jingzhi * fene, fund_sell->sell_jingzhi, fene);
        printf("    盈利金额:%.2f, 盈利比例:%.2f%%\n", bonus, 100 * (bonus/fund_sell->buy_money));
        // 波段总收益
        total_sell_money += bonus;
    }
    printf("波段总收益: %.2f\n\n", total_sell_money);
}


// 读取基金净值数据
const std::string filename = "../fund.txt";
unordered_map<std::string, std::pair<std::string, double> > get_fund_info() {
    vector<std::string> vec;
    unordered_map<std::string, std::pair<std::string, double> > fund_info;
    
    ifstream ifs;
    ifs.open(filename, ios::in);
    char buf[1024] = {0};
    while (ifs >> buf){
        vec.clear();
        char *tmp = strtok(buf, ",");
        while (tmp) {
            vec.push_back(std::string(tmp));
            tmp = strtok(NULL, ",");
        }
        fund_info[vec[1]] = std::make_pair(vec[0], std::stod(vec[2]));
    }
    ifs.close();
    //cout << "006381: " << fund_info["006381"] << endl;
    return fund_info;
}