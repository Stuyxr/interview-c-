str1 = input()
str2 = input()
res = 0
while True:
    last = 0
    flag = False
    for i in range(len(str2)):
        vis = False
        for j in range(last, len(str1)):
            if str2[i] == str1[j]:
                vis = True
                break
        if vis:
            str1 = str1[:j] + '_' + str1[j+1:]
            last = j
        else:
            flag = True
            break
    if flag:
        break
    res += 1
print(res)