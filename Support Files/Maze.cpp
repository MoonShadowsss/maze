//
//  Maze.cpp
//  mazeSolver
//
//  Created by 翟元浩 on 2017/11/6.
//  Copyright © 2017年 翟元浩. All rights reserved.
//

#include "Maze.hpp"

Maze::Maze(){
}
Maze::Maze(void *maze, int height, int length, MyPoint startPoint, MyPoint endPoint) {
    if (length <= 0 || height <= 0) {
        std::cout<<"Invalid length or height"<<std::endl;
        return;
    } else {
        this->height = height;
        this->length = length;
        this->maze = new int *[height];
        this->flag = new bool *[height];
        for (int i = 0; i < height; i++) {
            this->maze[i] = (int*)maze + i * length;
            this->flag[i] = new bool[length];
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < length; j++) {
                flag[i][j] = *((int*)maze + i * height + j);
            }
        }
        this->startPoint = startPoint;
        this->endPoint = endPoint;
    }
}
MyPoint Maze::getAdjacentNotVisitedPoint(MyPoint point) {
    MyPoint tem = *new MyPoint(-1, -1);
    if (point.Row() - 1 >= 0 && flag[point.Row() - 1][point.Column()] == false) {
        tem.setRow(point.Row() - 1);
        tem.setColumn(point.Column());
    } else if (point.Column() - 1 >= 0 && flag[point.Row()][point.Column() - 1] == false) {
        tem.setRow(point.Row());
        tem.setColumn(point.Column() - 1);
    } else if (point.Row() + 1 < height && flag[point.Row() + 1][point.Column()] == false) {
        tem.setRow(point.Row() + 1);
        tem.setColumn(point.Column());
    } else if (point.Column() + 1 < length && flag[point.Row()][point.Column() + 1] == false) {
        tem.setRow(point.Row());
        tem.setColumn(point.Column() + 1);
    }
    return tem;
}
Stack<MyPoint> Maze::getBFSStack() {
    if (maze[startPoint.Row()][startPoint.Column()] == WALL || maze[endPoint.Row()][endPoint.Column()] == WALL) {
        std::cout<<"Invalid Start Point or End Point!"<<std::endl;
        return *new Stack<MyPoint>;
    }
    MyPoint **mark = new MyPoint *[height];
    for (int i = 0; i < height; i++) {
        mark[i] = new MyPoint[length];
    }
    Queue<MyPoint> pointQueue;
    pointQueue.enQueue(startPoint);
    mark[startPoint.Row()][startPoint.Column()] = startPoint;
    while (!pointQueue.isEmpty()) {
        MyPoint frontPoint = pointQueue.deQueue();
        if (frontPoint.Row() - 1 >= 0 && maze[frontPoint.Row() - 1][frontPoint.Column()] == PATH) {
            if (mark[frontPoint.Row() - 1][frontPoint.Column()] == MyPoint()) {
                mark[frontPoint.Row() - 1][frontPoint.Column()] = frontPoint;
                pointQueue.enQueue(MyPoint(frontPoint.Row() - 1, frontPoint.Column()));
                if (MyPoint(frontPoint.Row() - 1, frontPoint.Column()) == endPoint) {
                    break;
                }
            }
        }
        if (frontPoint.Row() + 1 < height && maze[frontPoint.Row() + 1][frontPoint.Column()] == PATH) {
            if (mark[frontPoint.Row() + 1][frontPoint.Column()] == MyPoint()) {
                mark[frontPoint.Row() + 1][frontPoint.Column()] = frontPoint;
                pointQueue.enQueue(MyPoint(frontPoint.Row() + 1, frontPoint.Column()));
                if (MyPoint(frontPoint.Row() + 1, frontPoint.Column()) == endPoint) {
                    break;
                }
            }
        }
        if (frontPoint.Column() - 1 >= 0 && maze[frontPoint.Row()][frontPoint.Column() - 1] == PATH) {
            if (mark[frontPoint.Row()][frontPoint.Column() - 1] == MyPoint()) {
                mark[frontPoint.Row()][frontPoint.Column() - 1] = frontPoint;
                pointQueue.enQueue(MyPoint(frontPoint.Row(), frontPoint.Column() - 1));
                if (MyPoint(frontPoint.Row(), frontPoint.Column() - 1) == endPoint) {
                    break;
                }
            }
        }
        if (frontPoint.Column() + 1 < length && maze[frontPoint.Row()][frontPoint.Column() + 1] == PATH) {
            if (mark[frontPoint.Row()][frontPoint.Column() + 1] == MyPoint()) {
                mark[frontPoint.Row()][frontPoint.Column() + 1] = frontPoint;
                pointQueue.enQueue(MyPoint(frontPoint.Row(), frontPoint.Column() + 1));
                if (MyPoint(frontPoint.Row(), frontPoint.Column() + 1) == endPoint) {
                    break;
                }
            }
        }
    }
    Stack<MyPoint> pointStack;
    if (!pointQueue.isEmpty()) {
        int row = endPoint.Row();
        int col = endPoint.Column();
        pointStack.push(endPoint);
        while (mark[row][col] != startPoint) {
            int tRow = row;
            int tCol = col;
            row = mark[tRow][tCol].Row();
            col = mark[tRow][tCol].Column();
            pointStack.push(MyPoint(row, col));
        }
        pointStack.push(startPoint);
    }
    return pointStack;
}

int Maze::Length() {
    return length;
}

int Maze::Height() {
    return height;
}

void Maze::reverseAt(int x, int y) {
    if (maze[y][x] == 1) {
        maze[y][x] = 0;
    } else {
        maze[y][x] = 1;
    }
}
