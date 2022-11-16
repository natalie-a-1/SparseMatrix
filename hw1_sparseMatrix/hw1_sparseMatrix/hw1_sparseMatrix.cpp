#include <iostream>
using namespace std;
class matrix {
public:
    void SetEntry(int i, int j, int v);
    int GetEntry(int i, int j); // this is already defined for you.
    int CountNonZero();
    void GetSparseRep();
    int* SparseRow, * SparseCol, * SparseVal;
private:
    int m[3][5];
};
void matrix::SetEntry(int i, int j, int v) {
    m[i][j] = v;
}
int matrix::GetEntry(int i, int j) {
    return m[i][j];
}
int matrix::CountNonZero() {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (m[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}
void matrix::GetSparseRep() {
    int c = CountNonZero();
    SparseRow = new int[c]();
    SparseCol = new int[c]();
    SparseVal = new int[c]();
    
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (m[i][j] != 0) {
                SparseRow[k] = i;
                SparseCol[k] = j;
                SparseVal[k] = m[i][j];
                k++;
            }
        }
    }
}
int main()
{
    matrix x;
    
    int temp, mode;
    cin >> mode; // this controls what to test
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> temp;
            x.SetEntry(i, j, temp);
        }
    }
    switch (mode) {
    
    case 1: // test if inputs are correctly assigned
    
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                cout << x.GetEntry(i, j) << endl;
            }
        }
        break;
    
    case 2: // test if CountNonZero() is correct
        cout << x.CountNonZero() << endl;
        break;
    case 3: // test if GetSparseRep() is correct
        x.GetSparseRep();
        for (int i = 0; i < x.CountNonZero(); i++) {
            cout << x.SparseRow[i] << ' ' << x.SparseCol[i] << ' ' <<
x.SparseVal[i] << endl;
        }
        break;
    }
    return 0;
}
