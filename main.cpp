#include <iostream>

using namespace std;

void ziehung(int anzahl) {
    int max_range = 50;
    int i = 0;
    unsigned int lottozahlen[6];
    bool flag = false;

    srand(time(NULL));

    do {

        flag = false;
        int randnum = rand() % max_range + 1;
        if (i > 0) {
            for (int k = i-1; k >= 0; k--) {
                if (lottozahlen[k] == randnum) {
                    flag = true;
                }
            }
            if (!flag) {
                lottozahlen[i] = randnum;
                i++;
            }
        }
        else {
            lottozahlen[i] = randnum;
            i = 1;
        }

    } while (i < anzahl);




    for (int h = 0; h < 6; h++) {
        cout << lottozahlen[h] << "  ";
    }
}


int main() {

    ziehung(6);


    return 0;
}