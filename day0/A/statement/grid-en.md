# 【Description】：

F and H are playing games. Today they play with a chessboard of size N*M.
H wants to test F’s ability while F just wants to prove his ability, so F needs your
help.
To increase difficulty, H will first add P rectangular obstacles to the
chessboard. Each obstacle is given by U, D, L, R and all grids from row U to row D
and from column L to column R will become obstacles. To simplify, we call a grid
free grid if it isn’t obstacle. It is guaranteed that every two rectangular obstacles
don’t intersect and each free grid can be reached from another free grid directly
or indirectly. If two free grids have common edge, they can be reached from
each other directly and the distance between them is 1.
Each game, F first chooses one free grid X and H also chooses another free
grid Y, the score of this game(X, Y) is the shortest path between X and Y. F wants
to calculate the total score of all possible games module 109 +7. Two games are
considered different if the chosen two grids are different, i.e. (X, Y) is the same as
(Y, X).

# 【Input Format】：

The first line contains three integers, N(1<=N<=$10^9$), M（ 1 <=N<= 109 ）, P

## （ 0 <=P<= 105 ）.

P lines are followed, each line containing four positive integers, Ui, Di
（1<Ui<=Di<N）, Li, Ri(1<Li<=Ri<M), representing one rectangular obstacle.
For any two different rectangular obstacles i and j, Di+1<Uj or Dj+1<Ui, and



 Ri+1<Lj or Rj+1<Li.




# 【Output Format】：

# Only one integer, the total score module 109 +7.

# 【Sample】：

Input Output
3 3 1
2 2 2 2

## 64

There are 8 cases of distance 1.
There are 8 cases of distance 2.
There are 8 cases of distance 3.
There are 4 cases of distance 4.
So the total score is 64.


