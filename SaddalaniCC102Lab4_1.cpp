#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char again;

    do {
        int students, quizzes;

        cout << "Enter number of students: ";
        cin >> students;

        cout << "Enter number of quizzes: ";
        cin >> quizzes;

        int scores[100][100];

        // INPUT SCORES
        for (int i = 0; i < students; i++) {
            cout << "\nStudent " << i + 1 << " scores:\n";
            for (int j = 0; j < quizzes; j++) {
                cin >> scores[i][j];
            }
        }

        // DISPLAY TABLE HEADER
        cout << "\nStudent\t";
        for (int j = 0; j < quizzes; j++)
            cout << "Q" << j + 1 << "\t";
        cout << "Average\n";

        // COMPUTE + DISPLAY
        for (int i = 0; i < students; i++) {
            float sum = 0;

            cout << i + 1 << "\t";

            for (int j = 0; j < quizzes; j++) {
                cout << scores[i][j] << "\t";
                sum += scores[i][j];
            }

            cout << fixed << setprecision(2)
                 << sum / quizzes << endl;
        }

        cout << "\nCalculate Again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}