// #include <iostream>
// #include <queue>

// using namespace std;
// int main() {
//     // 1. Initialize a queue.
//     queue<int> q;
//     // 2. Push new element.
//     q.push(5);
//     q.push(13);
//     q.push(8);
//     q.push(6);
//     // 3. Check if queue is empty.
//     if (q.empty()) {
//         cout << "Queue is empty!" << endl;
//         return 0;
//     }
//     // 4. Pop an element.
//     q.pop();
//     // 5. Get the first element.
//     cout << "The first element is: " << q.front() << endl;
//     // 6. Get the last element.
//     cout << "The last element is: " << q.back() << endl;
//     // 7. Get the size of the queue.
//     cout << "The size is: " << q.size() << endl;
// }



#include <iostream>
#include <vector>
using namespace std;
class MyStack {
    private:
        vector<int> data;               // store elements
    public:
        /** Insert an element into the stack. */
        void push(int x) {
            data.push_back(x);
        }
        /** Checks whether the queue is empty or not. */
        bool isEmpty() {
            return data.empty();
        }
        /** Get the top item from the queue. */
        int top() {
            return data.back();
        }
        /** Delete an element from the queue. Return true if the operation is successful. */
        bool pop() {
            if (isEmpty()) {
                return false;
            }
            data.pop_back();
            return true;
        }
};

int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    for (int i = 0; i < 4; ++i) {
        if (!s.isEmpty()) {
            cout << s.top() << endl;
        }
        cout << (s.pop() ? "true" : "false") << endl;
    }
}