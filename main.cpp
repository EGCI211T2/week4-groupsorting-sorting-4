#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;
#include "sorting.h"

int main(int argc, char *argv[]) 
{
    int i,N;
    int type = 0;
    int *a = nullptr;

    type = sort_type(argv[1]);

    N=argc-2;
    a = new int[N];

    /* Convert to numbers*/
    for(int i=0;i<N;i++){
      a[i]=atoi(argv[i+2]);
    }

    sort(type,a,N);
    
    delete []a;
    return 0;
}
