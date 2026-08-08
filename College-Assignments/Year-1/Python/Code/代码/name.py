name = input('输入姓名')
ps = eval(input('输入平时成绩占比:'))
qm = eval(input('输入期末成绩占比'))
chinese_ps = eval(input('输入语文平时成绩'))
chinese_qm = eval(input('输入语文期末成绩'))
math_ps = eval(input('输入数学平时成绩'))
math_qm = eval(input('输入数学期末成绩'))
english_ps = eval(input('输入英语平时成绩'))
english_qm = eval(input('输入英语期末成绩'))
chinese_cj = chinese_ps * ps + chinese_qm * qm
math_cj = math_ps * ps + math_qm * qm
english_cj = english_ps * ps + english_qm * qm
total1 = chinese_cj + math_cj + english_cj

total2=int(total1)
chinese2=int(chinese_cj)
math2=int(math_cj)
english2=int(english_cj)

title1 = '+' + '-' * 12 + '+' + '-' * 15 + '+' + '-' * 15 + '+' + '-' * 15 + '+' + '-' * 15 + '+'
title2 = '|' + 'name' .center(12) + '|' + 'chinese' .center(15) + '|' + 'math' .center(15) + '|' + 'english' .center(15) + '|' + 'total'.center(15) + '|'
title4 = F"|{name:^12}|{chinese2:^15}|{math2:^15}|{english2:^15}|{total2:^15}|"

print(title1)
print(title2)
print(title1)
print(title4)
print(title1)


