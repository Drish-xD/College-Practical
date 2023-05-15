from queue import PriorityQueue

def best_first_search(graph, start_node, goal_node, heuristic):
    queue = PriorityQueue()
    visited = set()

    # Add the start node to the queue with its heuristic value
    queue.put((heuristic[start_node], start_node))

    while not queue.empty():
        _, current_node = queue.get()

        # Check if the current node is the goal node
        if current_node == goal_node:
            return True

        # Mark the current node as visited
        visited.add(current_node)

        # Add the unvisited neighboring nodes to the queue
        neighbors = graph[current_node]
        for neighbor in neighbors:
            if neighbor not in visited:
                queue.put((heuristic[neighbor], neighbor))

    # Goal node not found
    return False

# Example usage
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
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

found = best_first_search(graph, start_node, goal_node, heuristic)

if found:
    print("Goal node found!")
else:
    print("Goal node not found.")
