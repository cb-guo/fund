
# https://zhuanlan.zhihu.com/p/58264923

import smtplib
from email.message import EmailMessage
from email.header import Header
from email.mime.text import MIMEText
from email.mime.image import MIMEImage
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication

# part0 初始化部分
mail_user = 'cbguofighting@163.com'   # 邮箱登录名，
mail_pass = 'DQXOMPFAMSZUYNZI'    # 邮箱登录授权码，可百度获取

sender = 'cbguofighting@163.com'
receviers = ['cbguofighting@163.com']   # 收件人列表,list形式
#chaosong = []                          # 抄送人列表

# 设置邮件对象
msg = MIMEMultipart()
subject = 'fund'
msg['Subject'] = Header(subject, 'utf-8')
msg['From'] = "{}".format(sender)
msg['To'] = ",".join(receviers)
#msg['Cc'] = ",".join(chaosong)

# part1 文本内容
filename = "gcb"
with open(filename) as files:
  aa = files.readlines()
  text_content = ''.join(aa)
  

textApart = MIMEText(text_content, 'plain', 'utf-8')
msg.attach(textApart)

# part6 发送邮件，参数设置
sftp_obj = smtplib.SMTP_SSL(host='smtp.163.com', port = 994)
sftp_obj.login(mail_user, mail_pass)
sftp_obj.sendmail(sender, receviers, msg.as_string())
sftp_obj.quit()
sftp_obj.close()
print("\nThe eamil has been sent successfully")
del msg

