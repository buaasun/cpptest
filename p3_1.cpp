//
// Created by 孙承根 on 2017/6/21.
//

#include "Object1.h"

void func1(){
    Object b;

    b.method1();
    cout<<"func1: "<< reinterpret_cast<void*>(&Object::method1)<<endl;
}

