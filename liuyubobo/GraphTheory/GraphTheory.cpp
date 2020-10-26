/*
图论 Graph Theory

图的分类：
1.无向图 (Undirected Graph)，有向图 (Directed Graph)
2.无权图 (Unweighted Graph)，有权图 (Weighted Graph)

无向图是一种特殊的有向图

简单图 (Simple Graph)：
没有自环边 (self-loop)，没有平行边(parallel-edges)，因为这些条件有时会提升算法的难度

应用：
交通运输、社交网络、互联网、工作安排、脑区活动、程序状态执行

*/

/*
图的表示方式（对于边的表示应该采用的数据结构）：
邻接矩阵 (Adjacency Matrix)，邻接表 (Adjacency Lists)

邻接矩阵：
适合表示稠密图（Dense Graph）

邻接表：
适合表示稀疏图（Sparse Graph）

*/


/**
 * 图的遍历
 * 
 * 深度优先便利：
 * 稀疏图（邻接表）： O(V + E)
 * 稠密图（邻接矩阵）：O(V^2)
 * 
 */
 