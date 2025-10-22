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

     N=argc-1;
    a = new int[N];

    /* Convert to numbers*/
    for(int i=0;i<N;i++){
      a[i]=atoi(argv[i+1]);
    }

    
    cout<<"Before sorting:" << endl;
    display(a,N);
    
    //sort(a,N); replace
    cout<<"After sorting:" << endl << "Sorting method: ";
    sort(type,a,N);
    display(a,N);
    
    delete []a;
    return 0;
}
