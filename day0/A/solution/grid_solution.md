作者: fjh

## Solution

找规律计数题。

先考虑所有障碍物1*1的情况。
发现只有一种情况不是理想最短，即两个格子同行或者同列并且中间有障碍物，这样会绕路。
由于题目的性质，其他所有情况都是理想最优。

先求两两格子理想最短距离和。
减去一个矩形障碍物和它外面的格子的两两距离。
多减的要加回来。
最后再加上之前说的那一种绕路情况的距离。

注意分类讨论加起来就可以了，线性复杂度$O(n)$和离散化$O(n\log{n})$。

