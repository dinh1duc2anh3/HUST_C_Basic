from collections import deque

def find_exit(maze, start, end):
    rows, cols = len(maze), len(maze[0])
    visited = [[False] * cols for _ in range(rows)]
    queue = deque([(start[0], start[1], [])])

    while queue:
        current_row, current_col, path = queue.popleft()

        if (current_row, current_col) == end:
            return path + [(current_row, current_col)]

        if 0 <= current_row < rows and 0 <= current_col < cols and maze[current_row][current_col] == 0 and not visited[current_row][current_col]:
            visited[current_row][current_col] = True

            # Lên
            queue.append((current_row - 1, current_col, path + [(current_row, current_col)]))
            # Xuống
            queue.append((current_row + 1, current_col, path + [(current_row, current_col)]))
            # Sang trái
            queue.append((current_row, current_col - 1, path + [(current_row, current_col)]))
            # Sang phải
            queue.append((current_row, current_col + 1, path + [(current_row, current_col)]))

    return None  # Không tìm thấy đường thoát

# Ví dụ sử dụng:
maze = [
    [0, 1, 0, 0, 0],
    [0, 1, 0, 1, 0],
    [0, 0, 0, 1, 0],
    [0, 1, 0, 0, 0],
    [0, 0, 0, 1, 0]
]

start = (0, 0)
end = (4, 4)

result = find_exit(maze, start, end)
if result:
    print("Đường thoát:", result)
else:
    print("Không tìm thấy đường thoát.")
