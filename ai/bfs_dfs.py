graph = {
    "S": ["A", "B"],
    "A": ["C", "D"],
    "B": ["G", "H"],
    "C": ["E", "F"],
    "D": [],
    "G": ["I"],
    "H": [],
    "E": ["K"],
    "F": [],
    "I": [],
    "K": [],
}

visited = []
queue = []


def bfs(visited, graph, node):
    visited.append(node)
    queue.append(node)
    while queue:
        P = queue.pop(0)
        print(P, end=" ")
        for neighbour in graph[P]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)


avisit = set()


def dfs(avisit, graph, node):
    if node not in avisit:
        print(node, end=" ")
        avisit.add(node)
        for neighbour in graph[node]:
            dfs(avisit, graph, neighbour)


print("Breadth first search")
bfs(visited, graph, "S")

print("\nDepth first search")
dfs(avisit, graph, "S")
