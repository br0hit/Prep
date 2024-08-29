matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]] 
result = [[row for row in matrix if sum(row) % 2 == 0] for i in range(len(matrix[0]))]
print(result)