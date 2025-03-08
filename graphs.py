from collections import deque
from sys import stdin

input = stdin.readline

def bfs(graph, root):
    vis = [False] * len(graph)
    level = [0] * n
    queue = deque()
    queue.appendleft(root)
    vis[root] = True
    while (len(queue) > 0):
        node = queue[-1]
        queue.pop()
        #print(f"Current Node: {node + 1}; Level: {level[node]}")
        for next in graph[node]:
            if not vis[next]:
                queue.appendleft(next)
                vis[next] = True
                level[next] = level[node] + 1
    return level

def diameter(graph, root):
    level = bfs(graph, root)
    extreme = level.index(max(level))
    level = bfs(graph, extreme)
    print(f"Diameter: {max(level)}")
    '''
    level = dfs(graph, root)
    extreme = level.index(max(level))
    level = dfs(graph, extreme)
    print(f"Diameter: {max(level)}")
    '''

def dfs(graph, root):
    vis = [False] * n
    level = [0] * n
    stack = deque()
    stack.append(root)
    vis[root] = True
    while (len(stack) > 0):
        node = stack[-1]
        stack.pop()
        print(f"Current Node: {node + 1}; Level: {level[node]}")
        for next in graph[node]:
            if not vis[next]:
                stack.append(next)
                vis[next] = True
                level[next] = level[node] + 1
    return level

def dfs_recursive(graph, vis, level, root):
    print(f"Current Node: {root + 1}; Level: {level[root]}")
    for next in graph[root]:
        if not vis[next]:
            vis[next] = True
            level[next] = level[root] + 1
            dfs_recursive(graph, vis, level, next)

(n, m) = map(int, input().split())
graph = [[] for i in range(n)]
for i in range(m):
    (u, v) = map(int, input().split())
    u -= 1
    v -= 1
    graph[u].append(v)
    graph[v].append(u)
#diameter(graph, 0)
#bfs(graph, 0)
#dfs(graph, 0)
vis = [False] * n
vis[0] = True
level = [0] * n
#dfs_recursive(graph, vis, level, 0)
