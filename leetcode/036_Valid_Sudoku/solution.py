class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
	seen=[]
      	for i,row in enumerate(board):
		for j,c in enumerate(row):
			if c is not '.':
				seen+=[(i,c),(c,j),(int(i/3),int(j/3),c)]
	return len(seen)==len(set(seen))

table=[[".",".",".",".","5",".",".","1","."],[".","4",".","3",".",".",".",".","."],[".",".",".",".",".","3",".",".","1"],["8",".",".",".",".",".",".","2","."],[".",".","2",".","7",".",".",".","."],[".","1","5",".",".",".",".",".","."],[".",".",".",".",".","2",".",".","."],[".","2",".","9",".",".",".",".","."],[".",".","4",".",".",".",".",".","."]]
ss=Solution() 
result=ss.isValidSudoku(table)
print result
