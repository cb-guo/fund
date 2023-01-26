/**
 * 2022.2.14
 * 版本1: 固定投入份额的情况
 */
#include <iostream>
#include <stdio.h>
using namespace std;

double val = 1;         // 净值
double rat = 1;         // 百分比
double money = 10000;   // 每次投放金额
double kk = 5;          // 金额每次增加5%
	
int main()
{
   for (int i=1; i <= 9; i++) {
	 double jingzhi = val * rat;
	 double fene = money / jingzhi;
	 double maichu_money = fene * (jingzhi + val * kk/100.0);
	 double profile = maichu_money - money;
	 double profile_ratio = profile / money;
	 
	 printf("档位=%.2f, 净值=%.4f, 金额=%.0f, 买入份额=%.0f, 卖出份额=%.0f, 卖出金额=%.0f, 盈利金额=%.0f, 盈利比例=%.4f\n", 
			rat, jingzhi, money, fene, 
			fene, maichu_money, profile,  profile_ratio);
	 rat =  rat - kk/100.0;
   }
   return 0;
}
