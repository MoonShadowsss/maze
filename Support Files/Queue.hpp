//
//  Queue.hpp
//  mazeSolver
//
//  Created by 翟元浩 on 2017/11/8.
//  Copyright © 2017年 翟元浩. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>

template <typename T>
class Queue {
private:
    int length = 0;
    T data[100];
    int rear = 0;
    int top = 0;
public:
    void enQueue(const T d) {
        data[rear++] = d;
        length++;
    }
    T deQueue() {
        if (length > 0) {
            length--;
            return data[top++];
        } else {
            return *new T;
        }
    }
    T getFront() {
        if (length > 0) {
            return data[top];
        } else {
            return *new T;
        }
    }
    int getLength() {
        return length;
    }
    bool isEmpty() {
        return length <= 0;
    }
};

#endif /* Queue_hpp */
