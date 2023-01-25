#!/bin/bash
# 为避免在文件夹生成太多目标文件，所以目标文件用 target_ 做前缀

#python3 fund_data.py
cd wangge

# ------------------------
# 华夏恒生ETF联接(QDll)C
g++ fund_006381.cpp -o target_006381
# 天弘恒生科技指数(QDLL)C
g++ fund_012349.cpp -o target_012349
# 广发中证传媒ETF联接C
g++ fund_004753.cpp -o target_004753
./target_006381 && ./target_012349  && ./target_004753

echo "--------------------------"
# 广发中证全指医药卫生ETF联接C
g++ fund_002978.cpp -o target_002978
# 易方达中证全指证券公司指数C
g++ fund_012874.cpp -o target_012874
# 广发信息技术联接C
g++ fund_002974.cpp -o target_002974
./target_002978 && ./target_012874 && ./target_002974

echo "--------------------------"
# 易方达创业板ETF联接C
g++ fund_004744.cpp -o target_004744
# 广发中证养老产业C
g++ fund_002982.cpp -o target_002982
./target_004744 && ./target_002982


# 纳指100
g++ fund_006479.cpp -o target_006479
./target_006479

# 清空目标文件
rm -rf target_*
#rm -rf ../fund.txt


# 广发金融地产指数C  2022.12.5清仓
#g++ fund_002979.cpp -o target_002979
#./target_002979
# 招商中证白酒指数C  2022.12.6清仓
#g++ fund_012414.cpp -o target_012414
#./target_012414

