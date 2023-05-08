#include <iostream>
#include <string>

class Table {
    private:
        std::string xString, yString;
        int xSize, ySize;
        int bigX=0, bigY=0;
        int** c;
    public:
        Table(std::string, std::string);
        void FillTable();
        int max(int, int);
        std::string getLCS();
        std::string getSimilarity();
        void Print();
};