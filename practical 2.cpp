//bubble sort
#include <iostream>
using namespace std;

int main() {
    int n, a[10];
    cout << "enter the no. of elements:";
    cin >> n;
    cout << "enter the elements:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    cout << "sorted array:";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}


////insertion sort
//#include <iostream>
//using namespace std;
//
//int main() {
//    int n, a[10];
//    cout << "enter the no. of elements:";
//    cin >> n;
//    cout << "enter the elements:";
//    for (int i = 0; i < n; i++)
//        cin >> a[i];
//    for (int i = 1; i < n; i++) {
//        int key = a[i];
//        int j = i - 1;
//        while (j >= 0 && a[j] > key) {
//            a[j + 1] = a[j];
//            j--;
//        }
//        a[j + 1] = key;
//    }
//    cout << "sorted array:";
//    for (int i = 0; i < n; i++)
//        cout << a[i] << " ";
//    return 0;
//}


////selection sort
//#include <iostream>
//using namespace std;
//
//int main() {
//    int n, a[10];
//    cout << "enter the no. of elements:";
//    cin >> n;
//    cout << "enter the elements:";
//    for (int i = 0; i < n; i++)
//        cin >> a[i];
//    for (int i=0; i<n-1; i++){
//        int min=i;
//        for(int j=i+1; j<n; j++){
//            if(a[j]<a[min])
//            min=j;
//        }
//        int temp=a[i];
//        a[i]=a[min];
//        a[min]=temp;
//    }
//        cout << "sorted array:";
//    for (int i = 0; i < n; i++)
//        cout << a[i] << " ";
//    return 0;
//}


