#include <iostream>
#include <cmath>
using namespace std;

class LoanAccount {
private:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int tenureMonths;

public:
    // Default constructor
    LoanAccount() {
        loanID = 0;
        applicantName = "Unknown";
        loanAmount = 0;
        annualInterestRate = 0;
        tenureMonths = 0;
    }

    // Parameterized constructor
    LoanAccount(int id, string name, double amount, double rate, int tenure) {
        loanID = id;
        applicantName = name;

        loanAmount = (amount > 0) ? amount : 0;
        annualInterestRate = (rate >= 0) ? rate : 0;
        tenureMonths = (tenure > 0) ? tenure : 1;
    }

    // EMI calculation
    double calculateEMI() const {
        double monthlyRate = annualInterestRate / (12 * 100);

        if (monthlyRate == 0) {
            return loanAmount / tenureMonths; // simple division case
        }

        double emi = (loanAmount * monthlyRate * pow(1 + monthlyRate, tenureMonths)) /
                     (pow(1 + monthlyRate, tenureMonths) - 1);

        return emi;
    }

    // Display details
    void displayLoanDetails() const {
        cout << "\n--- Loan Details ---\n";
        cout << "Loan ID: " << loanID << endl;
        cout << "Applicant: " << applicantName << endl;
        cout << "Loan Amount: " << loanAmount << endl;
        cout << "Interest Rate: " << annualInterestRate << "%" << endl;
        cout << "Tenure: " << tenureMonths << " months" << endl;
        cout << "Monthly EMI: " << calculateEMI() << endl;
    }
};

int main() {
    // Using parameterized constructor
    LoanAccount loan1(101, "Shrey", 500000, 10.5, 60);

    // Using default constructor
    LoanAccount loan2;

    loan1.displayLoanDetails();
    loan2.displayLoanDetails();

    return 0;
}