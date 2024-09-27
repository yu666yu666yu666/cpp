#include <iostream>
#include <vector>

void gen(int n) {
    std::vector<int> prevRow; 

    for (int i = 0; i < n; ++i) {
        std::vector<int> row; 
        row.push_back(1); 

        if (i > 0) {
            for (int j = 1; j < i; ++j) {
                row.push_back(prevRow[j - 1] + prevRow[j]);
            }
            row.push_back(1); 
        }

        for (int num : row) {
            std::cout << num << " "; 
        }
        std::cout << std::endl; 

        prevRow = row;
    }
}

int main() {
    int n;
    std::cin >> n;
    if (n > 0 && n < 30)
        gen(n);
    return 0;
}