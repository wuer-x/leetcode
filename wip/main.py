class Solution(object):
    def __init__(self):
        pass

    def valid(cur_r, cur_c):
        pass

    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        a = [-1] * n  # cur solution
        solutions = []  # all solutions

        def _valid(cur_r, cur_c, a):
            # same columns
            for i in range(cur_r):
                if a[i] == cur_c:  #same columns
                    return False
                if a[cur_r - i] == cur_c - i:
                    return False
                if a[cur_r - i] == cur_c + i:
                    return False
            print(cur_r, cur_c, a)
            return True

        cur_r, cur_c = 0, 0
        while (cur_r < n):
            while (cur_c < n):
                if _valid(cur_r, cur_c, a):  # if cur_r, cur_c without confilcts
                    a[cur_r] = cur_c
                    cur_r += 1
                    cur_c = 0
                    break

                else:  # bt
                    cur_c += 1
            if a[cur_r] == -1:  # if fail when hit the boundary
                if cur_r != 0:
                    cur_r -= 1
                    cur_c = a[cur_r] + 1
                    a[cur_r] = -1
                else:
                    print('FAILED')
                    return
            elif cur_r == n - 1:  # get an solution
                print(a)
                solutions.append(a)


if __name__ == '__main__':
    s = Solution()
    s.solveNQueens(4)
