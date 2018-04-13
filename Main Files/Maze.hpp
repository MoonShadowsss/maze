//
//  Maze.hpp
//  mazeSolver
//
//  Created by 翟元浩 on 2017/11/6.
//  Copyright © 2017年 翟元浩. All rights reserved.
//

#ifndef Maze_hpp
#define Maze_hpp
#define WALL 1
#define PATH 0

#include <iostream>
#include "MyPoint.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

class Maze {
private:
    int **maze;
    bool **flag;
    int height;
    int length;
    MyPoint startPoint;
    MyPoint endPoint;
public:
    Maze();
    Maze(void *maze, int height, int length, MyPoint startPoint, MyPoint endPoint);
    MyPoint getAdjacentNotVisitedPoint(MyPoint point);
    void getPathByDFS();
    void getPathByBFS();
    Stack<MyPoint> getBFSStack();
    int Length();
    int Height();
    void reverseAt(int x, int y);
};

#endif /* Maze_hpp */
