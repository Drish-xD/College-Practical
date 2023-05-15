from queue import PriorityQueue

def a_star_search(graph, start_node, goal_node, heuristic, cost):
    queue = PriorityQueue()
    visited = set()
    g_score = {node: float('inf') for node in graph}
    g_score[start_node] = 0
    f_score = {node: float('inf') for node in graph}
    f_score[start_node] = heuristic[start_node]

    # Add the start node to the queue with its f-score
    queue.put((f_score[start_node], start_node))

    while not queue.empty():
        _, current_node = queue.get()

        # Check if the current node is the goal node
        if current_node == goal_node:
            return True

        # Mark the current node as visited
        visited.add(current_node)

        # Process each neighbor of the current node
        neighbors = graph[current_node]
        for neighbor in neighbors:
            if neighbor in visited:
                continue

            # Calculate the tentative g-score for the neighbor
            tentative_g_score = g_score[current_node] + cost[current_node][neighbor]

            if tentative_g_score < g_score[neighbor]:
                # Update the g-score and f-score for the neighbor
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = g_score[neighbor] + heuristic[neighbor]
                queue.put((f_score[neighbor], neighbor))

    # Goal node not found
    return False

# Example usage
graph = {
    'A': {'B': 5, 'C': 3},
    'B': {'D': 2, 'E': 4},
    'C': {'F': 6},
    'D': {},
    'E': {'F': 1},
    'F': {}
}

start_node = 'A'
goal_node = 'F'

heuristic = {
    'A': 4,
    'B': 3,
    'C': 2,
    'D': 5,
    'E': 2,
    'F': 0
}

cost = {
    'A': {'B': 5, 'C': 3},
    'B': {'D': 2, 'E': 4},
    'C': {'F': 6},
    'D': {},
    'E': {'F': 1},
    'F': {}
}

found = a_star_search(graph, start_node, goal_node, heuristic, cost)

if found:
    print("Goal node found!")
else:
    print("Goal node not found.")
