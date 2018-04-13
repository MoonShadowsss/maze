//
//  Point.cpp
//  mazeSolver
//
//  Created by 翟元浩 on 2017/11/6.
//  Copyright © 2017年 翟元浩. All rights reserved.
//

#include "MyPoint.hpp"

MyPoint::MyPoint() {
    row = -1;
    column = -1;
}
MyPoint::MyPoint(int x, int y) {
    row = x;
    column = y;
}
bool MyPoint::operator!=(const MyPoint &point) {
    if (point.column == column && point.row == row) {
        return false;
    }
    return true;
}
bool MyPoint::operator==(const MyPoint &point) {
    if (point.column == column && point.row == row) {
        return true;
    }
    return false;
}
int MyPoint::Row() {
    return row;
}
int MyPoint::Column() {
    return column;
}
void MyPoint::setRow(int x) {
    row = x;
}
void MyPoint::setColumn(int y) {
    column = y;
}
