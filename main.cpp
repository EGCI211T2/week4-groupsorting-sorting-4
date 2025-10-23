#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <chrono>

using namespace std;
#include "sorting.h"

int main(int argc, char *argv[]) 
{
    int i,N;
    int type = 0;
    int *a = nullptr;

    //below is code for statistics
    int* ptrarr[6];   // same pointer array you already use

    // 1. Sorted Large (20000)
    ptrarr[0] = new int[20000];
    for(int i = 0; i < 20000; i++) ptrarr[0][i] = i + 1;

    // 2. Sorted Small (5000)
    ptrarr[1] = new int[5000];
    for(int i = 0; i < 5000; i++) ptrarr[1][i] = i + 1;

    // 3. Reverse Large (20000)
    ptrarr[2] = new int[20000];
    for(int i = 0; i < 20000; i++) ptrarr[2][i] = 20000 - i;

    // 4. Reverse Small (5000)
    ptrarr[3] = new int[5000];
    for(int i = 0; i < 5000; i++) ptrarr[3][i] = 5000 - i;

    // 5. Random Large (20000)
    ptrarr[4] = new int[20000];
    for(int i = 0; i < 20000; i++) ptrarr[4][i] = rand() % 101; // 0–100 random

    // 6. Random Small (5000)
    ptrarr[5] = new int[5000];
    for(int i = 0; i < 5000; i++) ptrarr[5][i] = rand() % 101;


    int dummy[5] = {3,1,4,2,5};
    sort_stat(1, dummy, 5); // warm-up
    cout<<"Ignore Warm up above"<<endl;

    for(int i=1;i<=4;i++){
    
      for(int j=0;j<6;j++){
        int size=(j%2==0 ? 20000:5000);

        //clones the array
        int*datacpy=new int[size];
        for(int k=0;k<size;k++){
          datacpy[k]=ptrarr[j][k];
        }
      
        //starts timer
        auto start=chrono::high_resolution_clock::now();

        sort_stat(i,datacpy,size);

        //ends timer
        auto end=chrono::high_resolution_clock::now();

        //calcs the duration
        auto duration=chrono::duration_cast<chrono::milliseconds>(end-start);
        cout << "Time taken to sort " <<i<<setw(4)<<j<<": "<< duration.count() << " milliseconds\n";

        delete[] datacpy;
      }
    }

    /*
    type = sort_type(argv[1]);

    N=argc-2;
    a = new int[N];
    */
    /* Convert to numbers
    for(int i=0;i<N;i++){
      a[i]=atoi(argv[i+2]);
    }
    */

    //sort(type,a,N);
    
    //delete []a;
    for (int k = 0; k < 6; k++) {
    delete[] ptrarr[k];
    }
    return 0;
}
