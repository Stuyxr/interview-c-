class Node:
    def __init__(self, val, idx):
        self.val = val
        self.children = []
        self.idx = idx

id2node = {}
res = []
def dfs(idx, cur, target):
    if cur == target:
        res.append(id2node[idx].val)
        return
    for child in id2node[idx].children:
        dfs(id2node[child].idx, cur + 1, target)


def main():
    n = int(input())
    for i in range(n):
        lines = input().split(' ')
        val = int(lines[0])
        node = Node(val, i)
        for j in range(1, len(lines)):
            try:
                node.children.append(int(lines[j]))
            except:
                pass
        id2node[i] = node
    query = input().split(' ')
    x = int(query[0])
    dfs(0, 0, x)
    y = int(query[-1])
    if y >= len(res):
        print('{}')
    else:
        print('{' + str(res[y]) + '}')
if __name__ == "__main__":
    main()
"""
6
10    1    2
-21   3    4
23    5
14
35
66
1     1

14
0 1 2 3 4 5 6
-11 5 6 7 8
113 9 10 11
24 12
35
66 13
77
88
99
101
102
103
25
104
2 5
"""