//
//  Point.hpp
//  mazeSolver
//
//  Created by 翟元浩 on 2017/11/6.
//  Copyright © 2017年 翟元浩. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <iostream>

class MyPoint {
private:
    int row;
    int column;
public:
    int Row();
    int Column();
    void setRow(int x);
    void setColumn(int y);
    MyPoint();
    MyPoint(int x, int y);
    bool operator!=(const MyPoint &point);
    bool operator==(const MyPoint &point);
};


#endif /* Point_hpp */
