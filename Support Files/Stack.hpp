//
//  Stack.hpp
//  BinarySearchTree
//
//  Created by 翟元浩 on 2017/10/23.
//  Copyright © 2017年 翟元浩. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>

template<typename T>
class Stack {
private:
    int length = 0;
    T data[100];
public:
    void push(const T d) {
        data[length++] = d;
    };
    T pop() {
        if (length > 0) {
            return data[length--];
        } else {
            return *new T;
        }
//        if (length > 0) {
//            length--;
//        }
//        return;
    };
    T getTop() {
        if (length > 0) {
            return data[length - 1];
        } else {
            return *new T;
        }
    };
    bool isEmpty() {
        return length <= 0;
    };
    int getLength() {
        return length;
    };
    void reverse() {
        for (int i = 0; i < length / 2; i++) {
            T tem = data[i];
            data[i] = data[length - 1 - i];
            data[length - 1 - i] = tem;
        }
    }
};
#endif /* Stack_hpp */
