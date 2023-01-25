#!/bin/bash

if [ $1 == "yes" ]; then
    python3 fund_data.py
fi

sh run_wangge.sh > gcb
sh run_long_invest.sh >> gcb
sh run_alipay.sh >> gcb

if [ $2 == "yes" ]; then
    python3 send_mail.py
fi 
