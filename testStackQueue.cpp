#define CATCH_CONFIG_MAIN
#include <iostream>
#include "cs221util/catch.hpp"
#include "stack.h"
#include "queue.h"
#include "deque.h"
//using namespace cs221util;
using namespace std;

TEST_CASE("Deque", "[weight]=1[part=stack]"){
    cout << "Testing Deque..." << endl;
    Deque<int> deque1;
    vector<int> v1;
    vector<int> v2;
    for(int i = 5; i > 0; i--) {
        v1.push_back(i);
    }
    for(int j = 1; j <= 5; j++){
        deque1.pushR(j);
    }
    cout << deque1.peekR() << endl;
    cout << deque1.peekL() << endl;
    while(!deque1.isEmpty()){
        v2.push_back(deque1.popR());
    }  
    REQUIRE( v1 == v2);
}

TEST_CASE("Deque2", "[weight]=1[part=stack]"){
    cout << "Testing Deque popL..." << endl;
    Deque<int> deque2;
    vector<int> v1;
    vector<int> v2;
    for(int i = 1; i < 5; i++) {
        v1.push_back(i);
    }
    for(int j = 1; j < 5; j++){
        deque2.pushR(j);
    }
    // cout << deque2.peekR() << endl;
    // cout << deque2.peekL() << endl;
    // cout << "test popL" << endl;
    // cout << deque2.popL() << endl;
    // cout << deque2.peekL() << endl;
    // cout << "okay" << endl;
    // cout << deque2.popL() << endl;
    // cout << deque2.peekL() << endl;
    // cout << "pop 3" << endl;
    // cout << deque2.popL() << endl;
    while(!deque2.isEmpty()){
        v2.push_back(deque2.popL());
        // v2.push_back(deque2.popL());
        // v2.push_back(deque2.popL());
        // v2.push_back(deque2.popL());
    }  
    REQUIRE( v1 == v2);
}

TEST_CASE("Deque3", "[weight]=1[part=stack]"){
    cout << "Testing Deque peek functions..." << endl;
    Deque<int> deque3;
    vector<int> v1;
    vector<int> v2;
    for(int i = 5; i > 0; i--) {
        v1.push_back(i);
    }
    for(int j = 1; j <= 5; j++){
        deque3.pushR(j);
    }
    cout << deque3.peekR() << endl;
    cout << deque3.peekL() << endl;
    deque3.popR();
      
    REQUIRE( deque3.peekR() == 4);
    REQUIRE ( deque3.peekL() == 1);
}
TEST_CASE("stack::basic functions","[weight=1][part=stack]"){
    cout << "Testing Stack..." << endl;
    Stack<int> intStack;
    vector<int> result;
    vector<int> expected;
    for (int i = 10; i > 0; i--) {
        expected.push_back(i);
    }
    for (int i = 1; i <= 10; i++) {
        intStack.push(i);
    }
    while (!intStack.isEmpty()) {
        result.push_back(intStack.pop());
    }
    REQUIRE( result == expected);
}
TEST_CASE("queue::basic functions","[weight=1][part=queue]"){
    cout << "Testing Queue... " << endl;
    Queue<int> intQueue;
    vector<int> result;
    vector<int> expected;
    for (int i = 1; i <= 10; i++) {
        expected.push_back(i);
    }
    for (int i = 1; i <= 10; i++) {
        intQueue.enqueue(i);
    }
    while (!intQueue.isEmpty()) {
        result.push_back(intQueue.dequeue());
    }
    REQUIRE( result == expected);
}

