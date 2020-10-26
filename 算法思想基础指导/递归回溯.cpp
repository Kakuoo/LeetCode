/* 搜索回溯的不同写法
- 先进入下一个状态再判断合法性
- 先判断下一个状态的合法性再进入

第一种写法代码会更简洁，而且不用考虑dfs(0,0)搜索入口的状态

第二种写法递归调用会少一点，效率会高？（不太清楚）但是要考虑搜索入口的状态

以leetcode 212题为例：

两种写法的区别主要在于下述代码块在函数体中放置的位置
if (x < 0 || x >= board.size() ||
            y < 0 || y >= board[0].size())
            return;

第一种写法的搜索入口
dfs(board，root, i, j);

第二种写法的搜索入口
string curr_word(1, board[i][j]);
visited[i][j] = 1;
dfs(board, curr_word, i, j);
visited[i][j] = 0;

第一种写法逻辑确实清晰很多，递归边界直接用if return就可以，增减逻辑都方便

*/
