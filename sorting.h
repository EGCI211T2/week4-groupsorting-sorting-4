void display (int *a, int N);
void swap(int *a,int *b);
void bubbleSort(int *a, int N);
void selectionSort(int *a,int N);
void insertion(int *a,int N);
void display(int *a,int N);
void doubleSelection(int *a,int N);
void sort (int x, int *a, int N);
int sort_type(string x);

void sort (int x, int *a, int N)
{
    switch (x) 
    {
        case 1:
            cout << "insertion sort" << endl;
            insertion(a,N);
            break;
        case 2:
            cout << "bubble sort" << endl;
            bubbleSort(a,N);
            break;

        case 3:
            cout << "selection sort" << endl;
            selectionSort(a,N);
            break;

        case 4:
            cout << "double selection sort" << endl;
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
    if (sortType == "insert")
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
    for (int i = 1; i < N; i++)
        cout << a[i] << endl;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int data[], int length) {
    int i, j, minIndex;
    for (i = 0; i < length - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < length; j++) {
            if (data[j] < data[minIndex])
                minIndex = j;
        }
        swap(&data[i], &data[minIndex]);
        //display(data, length);
    }
}

void doubleSelection(int a[], int length) {
    int left = 0, right = length - 1;
    while (left < right) {
        int minI = left, maxI = left;
        for (int i = left; i <= right; i++) {
            if (a[i] < a[minI])
                minI = i;
            if (a[i] > a[maxI])
                maxI = i;
        }

        swap(&a[left], &a[minI]);
        
        if (maxI == left){
          maxI = minI;
        }
            
        swap(&a[right], &a[maxI]);

        left++;
        right--;

        //display(a, length);
    }
}

void insertion(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        //display(a, n);
    }
}

void bubbleSort(int a[], int n) {
    for (int j = 0; j < n - 1; j++) {
        int sorted = 1;
        for (int i = 0; i < n - 1 - j; i++) {
            if (a[i] > a[i + 1]) {
                swap(&a[i], &a[i + 1]);
                sorted = 0;
            }
        }
        //display(a, n);
        if (sorted) break;
    }
}


