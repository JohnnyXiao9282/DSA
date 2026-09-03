#include <iostream>
#include <stack>

class StackSorter {
private:
    std::stack<int> helper;

    void sort(std::stack<int>& s) {
        while (!s.empty()) {
            int current = s.top();
            s.pop();

            while (!helper.empty() && helper.top() > current) {
                int top = helper.top();
                helper.pop();
                s.push(top);
            }

            helper.push(current);
        }

        while (!helper.empty()) {
            s.push(helper.top());
            helper.pop();
        }
    }

public:
    StackSorter(std::stack<int>& s) {
        sort(s);
    }
};

int main() {
    std::stack<int> s;
    s.push(3); 
    s.push(1); 
    s.push(4); 
    s.push(2);

    StackSorter sorter(s);

    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;

    return 0;
}
