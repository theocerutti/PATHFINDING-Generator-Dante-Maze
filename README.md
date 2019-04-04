# Dante Star

Dante Star is a pathfinding and a generator project, it is composed of two parts.  

# Overview  

![ezgif com-gif-maker](https://user-images.githubusercontent.com/44285344/55588953-6456cb80-572f-11e9-92ff-46f52f151fa6.gif)

# Requirements  

- Ncurses - [Download](https://ftp.gnu.org/pub/gnu/ncurses/)  

# Generator

A maze is defined as follow:  
- The ‘X’s represent the walls and the’*’s represent the free spaces.  
- “Start” is in the upper left-hand corner (0;0)  
- “Finish” is in the bottom right-hand corner.  
- Resolution: in order to write the solution in the maze, we use ‘o’ for the solution path. 

To do so with used Prim'z algorithm.  
To run generator:  
```cd generator ; make re ; ./generator x y [perfect]```  
To run graphical generator (bonus):  
```cd generator/bonus/generator ; make re ; ./generator x y [perfect]```  

The [perfect] argument make perfect maze.  

# Solver  

We used A* algorithm for the pathfinding.  
To run solver:  
```cd solver ; make re ; ./solver [map]```  
To run solver bonus:  
```cd solver ; make re ; ./solver [map]```  

# Bonus  

You can run solver and generator at the same time.  
Go to ```cd tournament```  
```chmod 777 generator_solver.sh```  
```./generator_solver.sh [graphical] x y [perfect]```    

The [graphical] argument execute the program with an generating/solving visualisation.  

# Team  

* **Théo Cerutti**
* **Yoan Vessiere**

