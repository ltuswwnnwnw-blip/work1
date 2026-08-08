price_table = {
    "01": {"first_weight": 13, "continue_weight": 3},  
    "02": {"first_weight": 12, "continue_weight": 2},  
    "03": {"first_weight": 14, "continue_weight": 4}   
}

area_code = input("请输入地区编号（华东01/华南02/华北03）：")
weight = float(input("请输入快递重量（kg）："))

if area_code not in price_table:
    print("地区编号输入错误！")
else:
    first = price_table[area_code]["first_weight"]
    cont = price_table[area_code]["continue_weight"]
    
    if weight <= 2:
        cost = first
    else:
        cost = first + (weight - 2) * cont
    
    print(f"快递费用为：{cost:.2f} 元")