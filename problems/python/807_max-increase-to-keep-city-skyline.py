
class Solution:
    def maxIncreaseKeepingSkyline(self, grid) -> int:
        n = len(grid)
        rows_max = [0] * n
        columns_max = [0] * n
        for row in range(n):
            for column in range(n):
                if columns_max[row] < grid[row][column]:
                    columns_max[row] = grid[row][column]
                if rows_max[column] < grid[row][column]:
                    rows_max[column] = grid[row][column]
        diff = 0
        for row in range(n):
            for column in range(n):
                if columns_max[row] < rows_max[column]:
                    if grid[row][column] < columns_max[row]:
                        diff += columns_max[row]-grid[row][column]
                else:
                    if grid[row][column] < rows_max[column]:
                        diff += rows_max[column]-grid[row][column]
        return diff

if __name__ == '__main__':
    grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
    print(Solution().maxIncreaseKeepingSkyline(grid))
