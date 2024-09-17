#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> josephus(int n, int m) {
    std::vector<int> people;
    for (int i = 1; i <= n; ++i) {
        people.push_back(i);
    }

    std::vector<int> result;
    int index = 0;
    while (!people.empty()) {
        index = (index + m - 1) % people.size(); 
        result.push_back(people[index]);
        people.erase(people.begin() + index); 
    }

    return result;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> specified(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> specified[i];
    }

    for (int m = 1; m <= n; ++m) {
        std::vector<int> result = josephus(n, m);
        std::vector<int> last_k(result.end() - k, result.end());
        
        if (last_k == specified) {
            std::cout << m << std::endl;
            return 0;
        }
    }
    std::cout << 0 << std::endl; 
    return 0;
}