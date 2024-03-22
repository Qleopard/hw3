#include <iostream>
#include <cmath>
#include <vector>
#include <list>

using namespace std;

template<typename Cont> void print(Cont cont, std::string s) {
    int counter = 0;
    int len = cont.size()-1;
    for (auto it = cont.begin(); it != cont.end(); ++it, ++counter) {
        if (len == counter) {
            std::cout << *it << "\n";
            break;
        }
        else {
            std::cout << *it << s;
        }
    }    
}

void search(std::vector<std::list<int>> codes, int fi, int x) {
    int j = -1;
    for(int i = 0; i < x; i++) {
        for(int num : codes[i]) {
            if (num == fi) {
                j = i;
            }
        }
    }
    if (j == -1) {
        std::cout << "Not found";
    }  
    else {
        std::cout << "Index: " << j;
    }
}

std::vector<std::list<int>> hashing(std::vector<int> numbers, int x) {
    std::vector<std::list<int>> codes(x);
    for(int num = 0; num < numbers.size(); num++) {
        int z = numbers[num]%x;
        codes[z].push_front(numbers[num]);
    }
    return codes;
};

int main()  
{
    int x = 17;
    std::vector<int> numbers = {11, 0, 612, 43, 98, 4};
    std::vector<std::list<int>> codes = hashing(numbers, x);
    for (int i = 0; i < x; i++) {
        print(codes[i], ", ");
    }
    search(codes, 0, x);
    return 0;
}