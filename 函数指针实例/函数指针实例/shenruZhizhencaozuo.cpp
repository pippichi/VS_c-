//
// Created by QYF on 2019/7/25.
//
#include <iostream>
using namespace std;

int main(){
    int num = 0x01020304;
    //int 长度为4
    int *p = &num;
    printf("*p: %#x\n",*p);
    //short 长度为2
    short *p1 = reinterpret_cast<short *>(&num);
    printf("*p1: %#x\n",*p1);
    //char 长度为1
    char *p2 = reinterpret_cast<char *>(&num);
    printf("*p2: %#x\n",*p2);
}
