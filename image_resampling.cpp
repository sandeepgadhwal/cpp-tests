
#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>


using namespace std;

int main() 
{
    cout << "Hello from Sandeep";
    cout << endl;

    int rows, cols;
    cout << "Insert number of rows: ";
    cin >> rows;
    cout << "Insert number of cols: ";
    cin >> cols;
    vector<vector<int>> matrix (rows, vector<int> (cols, 0));

    int pixelval;
    int nbytes = 8;
    int maxpixelval = pow(2, nbytes);

    stringstream pixelss;

    // Ascending order
    cout << "\n\nAscending order\n";
    for (int r=0; r<rows; r++){
        for (int c=0; c<cols; c++){
            pixelval = ((r*cols + c)%maxpixelval);
            pixelss << setw(3) << setfill(' ') << pixelval;
            cout << pixelss.str() << " ";
            pixelss.str("");
        }
        cout << "\n";
    }

    // Diagnols
    cout << "\n\nDiagnols\n";
    for (int r=0; r<rows; r++){
        for (int c=0; c<cols; c++){
            cout << ((r==c) | (abs(rows-r)==c)) << " ";
        }
        cout << "\n";
    }

    // Nearest Neighbour Resampling of Diagnols
    cout << "\n\n Nearest Neighbour Resampling of Diagnols\n";
    int maxside = max(rows, cols);
    for (int r=0; r<maxside; r++){
        for (int c=0; c<maxside; c++){
            if ((r==c) | (abs(rows-r-1)==c)){
                int cc = c, rr = r;
                if (cols < rows) {
                    rr = r;
                    cc = round(c*cols/rows);
                } else if (rows < cols){
                    cc = c;
                    rr = round(r*rows/cols);
                }
                matrix[rr][cc] = 1;
            }
        }
    }    
    for (int r=0; r<rows; r++){
        for (int c=0; c<cols; c++){
            cout << matrix[r][c] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
    return 0;
}