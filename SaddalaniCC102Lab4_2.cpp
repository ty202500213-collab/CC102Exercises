#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char Choice;

    do {
        double sales[5][4] = {0};
        int salesperson, product;
        double amount;

        cout << "\nEnter sales data (0 to stop)\n";

        while (true) {
            cout << "\nSalesperson (1-4, 0 to stop): ";
            cin >> salesperson;

            if (salesperson == 0)
                break;

            cout << "Product (1-5): ";
            cin >> product;

            cout << "Amount sold: ";
            cin >> amount;

            sales[product - 1][salesperson - 1] += amount;
        }

        // DISPLAY TABLE
        cout << "\nProduct\t";
        for (int j = 0; j < 4; j++)
            cout << "S" << j + 1 << "\t";
        cout << "Total\n";

        double grandTotal = 0;

        for (int i = 0; i < 5; i++) {
            double rowTotal = 0;

            cout << i + 1 << "\t";

            for (int j = 0; j < 4; j++) {
                cout << fixed << setprecision(2)
                     << sales[i][j] << "\t";
                rowTotal += sales[i][j];
            }

            cout << rowTotal << endl;
            grandTotal += rowTotal;
        }

        // COLUMN TOTALS
        cout << "Total\t";
        for (int j = 0; j < 4; j++) {
            double colTotal = 0;
            for (int i = 0; i < 5; i++)
                colTotal += sales[i][j];

            cout << colTotal << "\t";
        }

        cout << grandTotal << endl;

        cout << "\nDo you Want to Repeat? (Y/N): ";
        cin >> Choice;

    } while (Choice == 'y' || Choice == 'Y');

    return 0;
}