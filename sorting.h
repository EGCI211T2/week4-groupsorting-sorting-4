void display (int *a, int N);
void swap(int *a,int *b);
void bubbleSort(int *a, int N);
void selectionSort(int *a,int N);
void insertion(int *a,int N);
void display(int *a,int N);
void doubleSelection(int *a,int N);
void sort (int x, int *a, int N);
int sort_type(string x);

#if 0 //for stat testing
void sort_stat(int x, int *a, int N);

void sort_stat (int x, int *a, int N)
{
    switch (x) 
    {
        case 1:
            //cout << "insertion sort" << endl;
            insertion(a,N);
            break;
        case 2:
            //cout << "bubble sort" << endl;
            bubbleSort(a,N);
            break;

        case 3:
            //cout << "selection sort" << endl;
            selectionSort(a,N);
            break;

        case 4:
            //cout << "double selection sort" << endl;
            doubleSelection(a,N);
            break;

        default:
            cout << "Please choose another sorting method" << endl;
            break;
    }
    
}
#endif

void sort (int x, int *a, int N)
{
    switch (x) 
    {
        case 1:
            //cout << "insertion sort" << endl;
            insertion(a,N);
            break;
        case 2:
            //cout << "bubble sort" << endl;
            bubbleSort(a,N);
            break;

        case 3:
            //cout << "selection sort" << endl;
            selectionSort(a,N);
            break;

        case 4:
            //cout << "double selection sort" << endl;
            doubleSelection(a,N);
            break;

        default:
            cout << "Please choose another sorting method" << endl;
            break;
    }
    
}

int sort_type(string x)
{
    int n;
    string sortType = x;
    if (sortType == "insertion")
    {
        n = 1;
    }
    else if (sortType == "bubble")
    {
        n = 2;
    }
    else if (sortType == "selection")
    {
        n = 3;
    }
    else if (sortType == "doubleselection")
    {
        n = 4;
    }
    else 
    n = 0;

    return n;
}

void display(int *a, int N) {
    for (int i = 0; i < N; i++){
        cout<<std::setw(5)<<a[i];
    }
    cout<<endl;
    
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int data[], int length) {
    int i, j, minIndex;
    //int c=0; for stat testing
    for (i = 0; i < length - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < length; j++) {
            if (data[j] > data[minIndex])
                minIndex = j;
        }
        swap(&data[i], &data[minIndex]);
        display(data, length);  //comment for stat testing
        //c++;
    }
    //cout<<"moves: "<<c<<endl; //for stat testing
}

void doubleSelection(int a[], int length) {
    int left = 0, right = length - 1;
    //int c=0; for stat testing
    while (left < right) {
        int minI = left, maxI = left;
        for (int i = left; i <= right; i++) {
            if (a[i] > a[minI])
                minI = i;
            if (a[i] < a[maxI])
                maxI = i;
        }

        swap(&a[left], &a[minI]);
        
        if (maxI == left){
          maxI = minI;
        }
            
        swap(&a[right], &a[maxI]);

        left++;
        right--;

        display(a, length);  //comment for stat testing
        //c++;
    }
    //cout<<"moves: "<<c<<endl; //for stat testing
}

void insertion(int a[], int n) {
    //int c=0; for stat testing
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        display(a, n); //comment for stat testing
        //c++;
    }
    //cout<<"moves: "<<c<<endl; for stat testing
}

void bubbleSort(int a[], int n) { //finished with formating
    int c=0;
    for (int j = 0; j < n - 1; j++) {
        int sorted = 1;
        for (int i = 0; i < n - 1 - j; i++) {
            if (a[i] < a[i + 1]) {
                swap(&a[i], &a[i + 1]);
                sorted = 0;
                display(a, n); //comment for stat testing
                //c++;
            }
        }
        if (sorted) break;
    }
    //cout<<"moves: "<<c<<endl; //for stat testing
}


