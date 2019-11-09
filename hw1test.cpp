#include "ArgumentManager.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

class kiwi {
    private:

        int size;
        int ripe_kiwi;
        int rotten_kiwi;
        int **farm;

        void count_ripe();
        void count_rotten();
        bool is_harvested(int r);

    public:

        kiwi(ifstream &inFile);
        ~kiwi();
        void grow();
        void end_of_day();
        int getSize();
        int getRotten();
        int getRipe();
        void result(ofstream &outFile);
};


kiwi::kiwi(ifstream &inFile) {

    ripe_kiwi = 0;
    rotten_kiwi = 0;

    inFile >> size;

    farm = new int *[size];

    for (int i = 0; i < size; i++) {
        farm[i] = new int [size];
    }

    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            inFile >> farm[r][c];
        }
    }
}

void kiwi::count_ripe() {

    for (int r = 0; r < size; r++) {

        if (this->is_harvested(r) == true) {        //only count if the row is harvested

            for (int c = 0; c < size; c++) {

                if (farm[r][c] >= 6 && farm[r][c] <= 8) {

                    ripe_kiwi++;
                    
                }
            }
        }
        
    }
}

void kiwi::count_rotten() {

    for (int r = 0; r < size; r++) {

        if (this->is_harvested(r) == true) {           //only count if the row is harvested

            for (int c = 0; c < size; c++) {

                if (farm[r][c] > 8) {

                    rotten_kiwi++;
                
                }
            }
        }
        
    }
}

bool kiwi::is_harvested(int r) {

    int half = size / 2;
    int count = 0;
    bool value = false;

    for (int c = 0; c < size; c++) {

        if (farm[r][c] >= 6 && farm[r][c] <= 8 || farm[r][c] > 8) {     //count both ripe and rotten kiwi
            count++;
        }

    }

    if  (count >= half) {                   //if the total number of ripe and rotten kiwi is equal or greater then half the row,
                                           //then row can be harvested
        value = true;
    }

    return value;
}

void kiwi::grow() {

    for (int r = 0; r < size; r++) {           //increment every kiwi to one day old

        for (int c = 0; c < size; c++) {

            farm[r][c]++;

        }

    }
}

void kiwi::end_of_day() {

    this->count_rotten();
    this->count_ripe();

    for (int r = 0; r < size; r++) {
        
        if (this->is_harvested(r) == true) {

            for (int c = 0; c < size; c++) {

                farm[r][c] = 0;

            }
        }

    }
    
}

void kiwi::result(ofstream &outFile) {

    for (int r = 0; r < size; r++) {

        for (int c = 0; c < size; c++) {

            stringstream ss;
            ss << farm[r][c];
            outFile << ss.str() << " ";

        }

        outFile << endl;

    }

    outFile << endl;

    outFile << "Harvested kiwis: " << ripe_kiwi << endl;
    outFile << "Rotten kiwis: " << rotten_kiwi << endl;

}

int kiwi::getSize() {
    return size;
}

int kiwi::getRotten() {
    return rotten_kiwi;
}

int kiwi::getRipe() {
    return ripe_kiwi;
}

kiwi::~kiwi() {
    delete[] farm;
}


int main() {
    ifstream inFile("input1.txt");
    //inFile.open("input1.txt");

    if (!inFile.is_open()) {
        cout << "the input file is not opened." << endl;
    }

    kiwi patch(inFile);

    //from day 1 to day 6
    for (int i = 0; i < 6; i++) {
        patch.end_of_day();
        patch.grow();
    }

    //day 7
    patch.end_of_day();

    inFile.close();

    ofstream outFile("classKIWI_output.txt");
    //outFile.open("classKIWI_output.txt");

    if (!outFile.is_open()) {
        cout << "Output file is not opened." << endl;
    }

    patch.result(outFile);
    outFile.close();

    return 0;

}
