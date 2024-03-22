#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>

using namespace std;

int main()  
{
    std::map<std::string, std::string> relationships;
    int strings;
    std::vector<std::string> relatives;

    std::ifstream in("relate.txt");
    if (in.is_open()) {
        int x;
        while (in >> x) {
            strings = x;
        }
    }
    in.close();
    
    relatives.reserve(strings);
    std::ifstream in1("relate.txt");
    if (in1.is_open()) {
        std::string parent;
        std::string son;
        in1.seekg(3, ios::beg);
        while (in1 >> son >> parent) {
            relationships[son] = parent;
            if (std::find(relatives.begin(), relatives.end(), son) == relatives.end()) {
                relatives.push_back(son);
            }
            if (std::find(relatives.begin(), relatives.end(), parent) == relatives.end()) {
                relatives.push_back(parent);
            }
        }
    }
    in1.close();

    std::sort(relatives.begin(), relatives.end());
    for (std::string member : relatives) {
        int counter = 0;
        std::string rel = member;
        while (relationships[rel] != "") {
            counter++;
            rel = relationships[rel];
        }
        std::cout << member << " " << counter << "\n";
    }
    return 0;
}