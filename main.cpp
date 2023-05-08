#include "table.hpp"
#include <fstream>

int main() {
    std::string s1, s2;
    std::ifstream in1("twoStrings.txt");

    in1 >> s1 >> s2;

    Table table(s1, s2);
    std::string twoLCS = table.getLCS();
    std::cout << "LCS between two Strings:\n" << twoLCS << "\nLCS Length: " << twoLCS.size() << "\n\nMultiString Table:" << std::endl;

    Table*** matrix;
    int size;
    std::ifstream in2("multiStrings.txt");
    in2 >> size;
    std::string* strings = new std::string[size];

    matrix = new Table**[size];
    for(int i = 0; i < size; i++) {
        matrix[i] = new Table*[size];
        in2 >> strings[i];
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(i >= j)
                matrix[i][j] = nullptr;
            else
                matrix[i][j] = new Table(strings[i], strings[j]);
        }
    }

    //Prints table
    std::cout << " ";
    for(int i = 0; i < size; i++) std::cout << "  " << i+1;
    std::cout << std::endl;
    for(int i = 0; i < size; i++) {
        std::cout << i+1 << " ";
        for(int j = 0; j < size; j++) {
            if(matrix[i][j] == nullptr)
                std::cout << " - ";
            else
                std::cout << matrix[i][j]->getSimilarity();
        }
        std::cout << std::endl;
    }

    //Deletes all pointers

    delete[] strings;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            delete matrix[i][j];
        }
        delete[] matrix[i];
    }
    delete matrix;
}