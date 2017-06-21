//
// Created by 孙承根 on 2017/6/21.
//

#include "Object2.h"

void func2(){
    Object b;

    b.method1();
    cout<<"func2: "<< reinterpret_cast<void*>(&Object::method1)<<endl;
}

