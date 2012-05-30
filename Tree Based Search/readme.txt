HIT3002 AI Assignment 1

Bug:
With Java, the object is copy by reference, so when we make a action to a 'currentState' and return to nextState, the 'nextState' and 'currentState' are both point to same memory allocation. I cannot use BFS to extend all available action. For DFS, we can search the all of node to reach the deepest level, but we cannot avoid duplicate state. Both search algorithm will perform a infinite loop. 

Algorithm: DFS, BFS
IDE: Netbeans 7.1.1
Source Directory: ./src/
Reference:

BFS vs DFS http://www.programmerinterview.com/index.php/data-structures/dfs-vs-bfs/
Best-first search, http://www.cs.princeton.edu/courses/archive/spr08/cos226/assignments/8puzzle.html
Russell & Norvig, P 2003, Artificial Intelligence: A modern approach, 2nd edn, Pearson Education, New Jersey, US.
Patel,A 2012, Amit¡¯s Game Programming Site, <http://theory.stanford.edu/~amitp/GameProgramming/>, viewed on 19th April 2012