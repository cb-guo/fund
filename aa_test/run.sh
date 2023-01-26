#!/bin/bash
# 为避免在文件夹生成太多目标文件，所以目标文件用 target_ 做前缀

# demo 分析
g++ test.cpp -o target_test
./target_test
# 所有基金的 上次购买价格 与 目前价格对比分析
#g++ total_compare.cpp -o target_total_compare

# 清空目标文件
rm -rf target_*