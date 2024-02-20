#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;

    pq.push(10); // O(logN) due to insertion (add as leaf node, then rise to correct position)
    pq.push(20);
    pq.push(30);
    pq.push(5);
    pq.push(1);

    std::cout << "The pq contains in order: ";
    while(!pq.empty()){
        std::cout << pq.top() << " "; // O(1) largest value is always at the top of the heap
        pq.pop(); // O(logN) removing min value could require rearranging the one branch of the tree
    }
    std::cout << std::endl;

    return 0;
}