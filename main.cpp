#include <iostream>
#include <cstdlib>

using namespace std;
#include "sorting.h"



int main(int argc, char * argv[]) 
{
 
  cout<<"argc is "<<argc<<endl;
    int i,N;

    N=argc-1;
    int* a = new int[N];

    int type = sort_type(argv[1]);
  
    for(i=1;i<argc;i++){
        cout<<"argv[" << i<< "]" <<argv[i]<<endl;
    }

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
