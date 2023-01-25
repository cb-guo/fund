# -*- coding: UTF-8 -*-
import requests
from bs4 import BeautifulSoup
import re
import numpy as np
import pandas as pd
import json
import datetime

# 抓取网页
def get_url(url, params=None, proxies=None):
    rsp = requests.get(url, params=params, proxies=proxies)
    rsp.raise_for_status()
    return rsp.text

# 从网页抓取数据
def get_fund_data(code,per=10,sdate='',edate='',proxies=None):
    url = 'http://fund.eastmoney.com/f10/F10DataApi.aspx'
    params = {'type': 'lsjz', 'code': code, 'page':1,'per': per, 'sdate': sdate, 'edate': edate}
    html = get_url(url, params, proxies)
    soup = BeautifulSoup(html, 'html.parser')
    # 获取总页数
    pattern=re.compile(r'pages:(.*),')
    result=re.search(pattern,html).group(1)
    pages=int(result)
    # 获取表头
    heads = []
    for head in soup.findAll("th"):
        heads.append(head.contents[0])
    # 数据存取列表
    records = []

    # 从第1页开始抓取所有页面数据
    page=1
    while page<=pages:
        params = {'type': 'lsjz', 'code': code, 'page':page,'per': per, 'sdate': sdate, 'edate': edate}
        html = get_url(url, params, proxies)
        soup = BeautifulSoup(html, 'html.parser')
        # 获取数据
        for row in soup.findAll("tbody")[0].findAll("tr"):
            row_records = []
            for record in row.findAll('td'):
                val = record.contents
                # 处理空值
                if val == []:
                    row_records.append(np.nan)
                else:
                    row_records.append(val[0])
            # 记录数据
            records.append(row_records)
        # 下一页
        page=page+1
    # 数据整理到dataframe
    np_records = np.array(records)
    data= pd.DataFrame()
    for col,col_name in enumerate(heads):
        data[col_name] = np_records[:,col]
    return data


fund_info = {
    "006381": "华夏恒生ETF联接(QDll)C",
    "012349": "天弘恒生科技指数(QDLL)C",
    "004753": "广发中证传媒ETF联接C",
    "002978": "广发中证全指医药卫生ETF联接C",
    "012874": "易方达中证全指证券公司指数C",
    "002974": "广发信息技术联接C",
    "004744": "易方达创业板ETF联接C",
    #"002979": "广发金融地产指数C",
    "002982": "广发中证养老产业C",
    #"012414": "招商中证白酒指数C",
    "006479": "广发纳斯达克100ETF联接(QDll)C",

    "090010": "大成中证红利指数A",
    "160119": "南方中证500ETF联接A",
    "110020": "易方达沪深300ETF联接A",
    "000968": "广发中证养老产业A",
    "000942": "广发中证全指信息技术ETF联接A",
    "502010": "易方达中证全指证券公司指数A",
    "001469": "广发中证全指金融地产ETF联接A",
    "001180": "广发中证全指医药卫生ETF联接A",

    "270042": "广发纳斯达克100指数A",
    "050025": "博时标普500ETF联接A类",
    "000071": "华夏恒生ETF联接A",
    "012348": "天弘恒生科技指数A",
    "164906": "交银海外中国互联网指数",
    #"014424": "博时恒生医疗保健ETF联接A",

    "005827": "易方达蓝筹精选混合",
    "260108": "景顺长城新兴成长混合",
    "161005": "富国天惠成长混合A",
    "519069": "汇添富价值精选混合A",
    "001511": "兴全新视野灵活配置定期开放混合",
    "118001": "易方达亚洲精选股票",
    "110003": "易方达上证50指数增强A",
    "001717": "工银瑞信前沿医疗股票A",
}

'''
end_date = '2022-08-26'
mid_date = datetime.datetime.strptime(end_date, "%Y-%m-%d")
start_date = (mid_date + datetime.timedelta(days=-3)).strftime("%Y-%m-%d")
#start_date = '2022-08-23'
'''
end_date = datetime.date.today()
start_date = end_date - datetime.timedelta(days=5)

# 主程序
if __name__ == "__main__":
    filename = 'fund.txt'
    with open(filename, 'w') as file_object:
        for key, val in fund_info.items():
            data=get_fund_data(key, per=5, sdate=start_date, edate=end_date)
            data['净值日期']=pd.to_datetime(data['净值日期'],format='%Y-%m-%d')
            data['单位净值']= data['单位净值'].astype(float)
            date_arr = data['净值日期']
            jingzhi_arr = data['单位净值']
            file_object.write('{},{},{:.4f},{}\n'.format(date_arr[0].strftime("%Y-%m-%d"),key,jingzhi_arr[0],val))


