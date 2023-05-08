#include "table.hpp"

Table::Table(std::string s1, std::string s2) {
    //Sets bigger string to X and small string to Y
    if(s1.size() > s2.size()) {
        xString = s1;
        yString = s2;
    }
    else {
        xString = s2;
        yString = s1;
    }

    xSize = xString.size();
    ySize = yString.size();

    FillTable();
}

void Table::FillTable() {
    //Initializes 2D array for Table
    c = new int*[xSize+1];
    for(int i = 0; i <= xSize; i++) {
        c[i] = new int[ySize+1];
    }

    //Runs through each character combo
    for(int i = 0; i <= xSize; i++) {
        for(int j = 0; j <= ySize; j++) {
            //If i or j is 0, c value is set to 0
            if(i == 0 || j == 0) {
                c[i][j] = 0;
            }
            //If there is a match, c value incr. by 1 and Saves biggest match
            else if(xString[i-1] == yString[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                if(c[i][j] > c[bigX][bigY]) {
                    bigX = i;
                    bigY = j;
                }
            }
            else {
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }
}

int Table::max(int x, int y) {
    if(x >= y)
        return x;
    else 
        return y;
}

void Table::Print() {    
    for(int i = 0; i <= xSize; i++) {
        for(int j = 0; j <= ySize; j++) {
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::string Table::getLCS() {
    std::string LCS = "";

    //Backtracks from biggest match to find LCS
    while(bigX > 0 && bigY > 0) {
        if(xString[bigX-1] == yString[bigY-1]) {
            LCS = xString[bigX-1] + LCS;
            --bigX, --bigY;
        }
        else if(c[bigX-1][bigY] >= c[bigX][bigY-1]) {
            bigX--;
        }
        else
            bigY--;

    }

    return LCS;
}

std::string Table::getSimilarity() {
    double percent = double(ySize) / double(xSize);
    double lcsPercent = double(getLCS().size()) / double(ySize);

    if(percent >= 0.9 && lcsPercent >= 0.9) {
        return " H ";
    }
    else if(percent >= 0.8 && lcsPercent >= 0.8) {
        return " M ";
    }
    else if(percent >= 0.6 && lcsPercent >= 0.5) {
        return " L ";
    }
    else
        return " D ";
}