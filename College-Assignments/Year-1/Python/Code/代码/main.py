# ============================================================
# 函数1：录入学生信息（生产者——自己问键盘要数据，不需要参数）
# ============================================================
def input_students():
    students = []                            # 造一个空列表，准备装所有学生
    while True:                              # 死循环，靠 break 跳出
        name = input("Please enter your name: ")  # 让用户输入姓名
        if name == "":                        # 如果直接按回车（空字符串）
            break                             # 跳出循环，录入结束
        age = input("Please enter your age: ")    # 输入年龄
        score = input("Please enter your score: ") # 输入分数
        stu_id = {'name': name, 'age': age, 'score': score}  # 把三个信息打包成字典
        students.append(stu_id)              # 把这个字典追加到列表末尾
    return students                          # 把装满学生的列表返回给调用者

students_input = input_students()            # ★函数调用：运行 input_students()，
                                             #   返回值（学生列表）存到 students_input
print(students_input)                        # 把原始列表打印出来，看录入结果

# ============================================================
# 函数2：打印学生信息（消费者——需要你传列表给它，它不生产数据）
# ============================================================
def output_students(students):               # students 是参数，接收调用者传进来的列表
    title1 = '+' + '-' * 15 + '+' + '-' * 7 + '+' + '-' * 5 + '+'
    # '-' * 15 意思是把 '-' 这个字符重复 15 次，变成 "---------------"
    # 拼出来就是：+---------------+-------+-----+
    title2 = F"|{'name':^15}|{'age':^7}|{'score':^5}|"
    # f-string 格式化字符串
    # 'name':^15  意思是 "name" 这个字在 15 格宽的格子里居中（^=居中）
    # 拼出来就是：|     name      |  age  |score|
    print(title1)                            # 打印表格顶部边框
    print(title2)                            # 打印表头（name / age / score）
    print(title1)                            # 打印表头和内容之间的分隔线
    for stu in students:                     # 遍历列表，每个 stu 是一个字典
        print(F"|{stu['name']:^15}|{stu['age']:^7}|{stu['score']:^5}|")
        # stu['name']  从字典里取出姓名
        # :^15         在 15 格宽里居中显示
        # 这一行打印的是每个学生的数据行
    print(title1)                            # 打印表格底部边框

output_students(students_input)              # ★函数调用：把 students_input 传进去打印
                                             #   数据流向：students_input → students 参数

# ============================================================
# 函数3：修改学生分数（先找名字，找到了改分数，找不到报 lost）
# ============================================================
def modify_students(students):               # students 接收学生列表
    name = input("Please enter your name: ") # 让用户输入要修改的学生姓名
    for stu in students:                     # 遍历列表，一个一个找
        if stu['name'] == name:              # 如果当前学生的名字匹配
            score = int(input("Please enter your score: "))  # 输入新分数，int() 转成整数
            stu['score'] = score             # 把这个学生的分数改成新值
            return                           # 找到了也改完了，直接结束函数
    print("lost")                            # for 循环跑完都没找到 → 打印 "lost"

modify_students(students_input)              # ★函数调用：传入列表，让用户修改某个学生的分数
                                             #   注意：这里直接改了原列表里的字典，没有返回值
output_students(students_input)              # ★函数调用：再次打印，验证修改是否生效


# ============================================================
# 整个程序的执行流程总结：
#
#   input_students()  ──返回列表──→  students_input
#                                      │
#                          ┌───────────┼───────────┐
#                          │           │           │
#                          ▼           ▼           ▼
#                     print()   output_students  modify_students
#                     (原始打印)  (表格打印)      (修改分数)
#                                                      │
#                                                      ▼
#                                              output_students
#                                              (再次表格打印，看修改结果)
#
# 函数名        括号有没有参数      返不返回值      作用
# ─────────────────────────────────────────────────────────
# input_students     无参数           返回列表       从键盘要数据
# output_students   有参数(students)   不返回         把数据打印成表格
# modify_students   有参数(students)   不返回         修改列表里的数据
# ============================================================
