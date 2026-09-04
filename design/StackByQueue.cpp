#include <iostream>
#include <queue>

class MyStack {
private:
    std::queue<int> q;

    void move() {
        if (this->empty()) {
            return;
        }

        int size = this->q.size();

        for (int i = 0; i < size - 1; i++) {
            int front = this->q.front();
            this->q.pop();
            this->q.push(front);
        }
    }

public:
    MyStack() {
    }
    
    void push(int x) {
        this->q.push(x);
    }
    
    int pop() {
        move();
        int front = this->q.front();
        this->q.pop();
        return front;
    }
    
    int top() {
        move();
        int front = this->q.front();
        this->q.pop();
        this->q.push(front);
        return front;
    }
    
    bool empty() {
        return this->q.empty();
    }
};



int main() {
    MyStack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "top(): " << stack.top() << " (expected 3)" << std::endl;
    std::cout << "pop(): " << stack.pop() << " (expected 3)" << std::endl;
    std::cout << "pop(): " << stack.pop() << " (expected 2)" << std::endl;
    std::cout << "empty(): " << stack.empty() << " (expected 0)" << std::endl;
    std::cout << "pop(): " << stack.pop() << " (expected 1)" << std::endl;
    std::cout << "empty(): " << stack.empty() << " (expected 1)" << std::endl;

    return 0;
}