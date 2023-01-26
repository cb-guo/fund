#include<iostream>
#include<stdio.h>
using namespace std;

// 中证传媒
// double base = 0.7469;
// double current = 0.7511;

// 恒生科技
// double base = 0.7281;
// double current = 0.7261;

// 纳斯达克100
// double base = 3.8965;
// double base = 3.8965;
// double current = 4.0976;

double base = 1.2440;
double current = 1.3290;

int main() {
    
    if (current < base) {
        printf("上次购买净值: %.4f, 目前净值: %.4f, 下降幅度: -%.2f%%\n", base, current, 100 * (1 - current / base));
    } else if (current > base) {
        printf("上次购买净值: %.4f, 目前净值: %.4f, 上涨幅度: +%.2f%%\n", base, current, 100 * ((current - base) / base));
    } else {
        printf("上次购买净值: %.4f, 目前净值: %.4f, 幅度: 0.00\n", base, current);
    }
}