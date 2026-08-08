import requests
url = "https://code.claude.com/docs/en/overview"
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/150.0.0.0 Safari/537.36 Edg/150.0.0.0'}
res = requests.get(url,headers=headers)
print(F'内容:{res.text}')
print(F'状态码：{res.status_code}')
res.encoding = 'utf-8'
print(F'编码方式:{res.encoding}')
print(F'{res.request.headers}')