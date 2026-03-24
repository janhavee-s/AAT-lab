//// String Matching
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//    string text, pattern;
//
//    cout << "Enter text: ";
//    cin >> text;
//
//    cout << "Enter pattern: ";
//    cin >> pattern;
//
//    int n = text.length();
//    int m = pattern.length();
//    bool found = false;
//
//    for(int i = 0; i <= n - m; i++) {
//        int j;
//        for(j = 0; j < m; j++) {
//            if(text[i + j] != pattern[j])
//                break;
//        }
//        if(j == m) {
//            cout << "Pattern found at position " << i << endl;
//            found = true;
//        }
//    }
//
//    if(!found)
//        cout << "Pattern not found";
//
//    return 0;
//}
//
//
//// Subset Sum Problem
//#include <iostream>
//using namespace std;
//
//int n, target;
//int arr[10];
//
//void subsetSum(int index, int sum) {
//    if(sum == target) {
//        cout << "Subset found\n";
//        return;
//    }
//
//    if(index == n || sum > target)
//        return;
//
//    subsetSum(index + 1, sum + arr[index]);
//    subsetSum(index + 1, sum);
//}
//
//int main() {
//    cout << "Enter number of elements: ";
//    cin >> n;
//
//    cout << "Enter elements:\n";
//    for(int i = 0; i < n; i++)
//        cin >> arr[i];
//
//    cout << "Enter target sum: ";
//    cin >> target;
//
//    subsetSum(0, 0);
//    return 0;
//}


// 8-Queens Problem
#include <iostream>
using namespace std;

int board[8][8] = {0};

bool isSafe(int row, int col) {
    for(int i = 0; i < col; i++)
        if(board[row][i])
            return false;

    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return false;

    for(int i = row, j = col; i < 8 && j >= 0; i++, j--)
        if(board[i][j])
            return false;

    return true;
}

bool solve(int col) {
    if(col >= 8)
        return true;

    for(int i = 0; i < 8; i++) {
        if(isSafe(i, col)) {
            board[i][col] = 1;

            if(solve(col + 1))
                return true;

            board[i][col] = 0;
        }
    }
    return false;
}

int main() {
    if(solve(0)) {
        cout << "One solution:\n";
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists";
    }
    return 0;
}


