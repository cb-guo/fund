/**
 * 2022.03.20
 * 压力测试
 */
#include <iostream>
#include <stdio.h>
using namespace std;

// 净值
double val = 1.0;             
double base_money = 1000;         // 原始投放金额

double rat = 1;                    // 百分比
double current_money = base_money; // 每次投放金额
double kk = 5;                     // 金额每次增加5%
	
int len = 2;

int main()
{
    double buy_money = 0.0;
    double sunshi_money = 0.0;
    for (int i=1; i <= len; i++) {
        //buy_money += base_money * 

    /*
	 double jingzhi = val * rat;
	 double maichu_jingzhi = jingzhi + val * kk/100.0;
	 double fene = current_money / jingzhi;
	 double maichu_money = fene * maichu_jingzhi;
	 double profile = maichu_money - current_money;
	 double profile_ratio = profile / current_money;
	 
	 printf("幅度=%.2f, 买入净值=%.4f, 卖出净值=%.4f, 买入数量=%.0f, 买入金额=%.0f, 卖出数量=%.0f, 卖出金额=%.0f, 盈利金额=%.0f, 盈利比例=%.4f\n", 
			rat, jingzhi, maichu_jingzhi, fene, current_money, 
			fene, maichu_money, profile,  profile_ratio);
	 rat =  rat - kk/100.0;
	 current_money = current_money +  base_money * (kk / 100);
     */
   }
   return 0;
}

