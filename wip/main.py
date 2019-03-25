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
                if a[i] == cur_c or abs(i - cur_r) == abs(a[i] - cur_c):
                    return False
            return True

        cur_r, cur_c = 0, 0
        while cur_r < n:
            while cur_c < n:
                if _valid(cur_r, cur_c, a):  # if cur_r, cur_c without confilcts
                    a[cur_r] = cur_c
                    cur_c = 0
                    break
                else:  # bt
                    cur_c += 1
            if a[cur_r] == -1:  # if fail when hit the boundary
                if cur_r != 0:
                    cur_r -= 1
                    cur_c = a[cur_r] + 1
                    a[cur_r] = -1
                    continue # this line
                else:
                    print('FAILED')
                    break
            if cur_r == n - 1:  # get an solution
                solutions.append(a)
                cur_c = a[cur_r] + 1
                a[cur_r] = -1
                continue
            cur_r += 1
        return solutions


if __name__ == '__main__':
    s = Solution()
    rst = s.solveNQueens(8)
    print(len(rst))
