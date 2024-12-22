#include <iostream>
#include <string>
using namespace std;

// Function to convert a number into words based on the Indian numbering system
string convertToIndianWords(int n) {
    string ones[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                      "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    string tens[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    string thousands[] = { "", "Thousand", "Lakh", "Crore" };

    if (n == 0)
        return "Zero";

    string result = "";

    int crore = n / 10000000;  // Extract Crore
    n %= 10000000;
    int lakh = n / 100000;  // Extract Lakh
    n %= 100000;
    int thousand = n / 1000;  // Extract Thousand
    n %= 1000;
    int hundred = n / 100;  // Extract Hundred
    n %= 100;

    // Convert Crore part
    if (crore > 0) {
        result += convertToIndianWords(crore) + " Crore ";
    }
    // Convert Lakh part
    if (lakh > 0) {
        result += convertToIndianWords(lakh) + " Lakh ";
    }
    // Convert Thousand part
    if (thousand > 0) {
        result += convertToIndianWords(thousand) + " Thousand ";
    }
    // Convert Hundred part
    if (hundred > 0) {
        result += convertToIndianWords(hundred) + " Hundred ";
    }
    // Convert Tens and Ones part
    if (n > 0) {
        if (n < 20) {
            result += ones[n];
        } else {
            result += tens[n / 10] + " " + ones[n % 10];
        }
    }

    return result;
}

int main() {
    float principal, interestRate = 7.0, interest;
    int timeInYears, timeInMonths;

    // Taking input from the user
    cout << "Enter the principal amount: ";
    cin >> principal;

    // Convert the principal amount into Indian words
    int principalInt = static_cast<int>(principal);  // Convert the floating-point value to int
    string principalInWords = convertToIndianWords(principalInt);
    
    // Display the principal amount in words
    cout << "The principal amount in words: " << principalInWords << endl;

    // Calculate interest for 1 year
    timeInYears = 1;
    interest = (principal * interestRate * timeInYears) / 100;
    int interestInt = static_cast<int>(interest);  // Convert interest to an integer for word conversion
    string interestInWords = convertToIndianWords(interestInt);

    // Display interest for 1 year in both numbers and words
    cout << "Interest for 1 year: " << interest << " (" << interestInWords << ")\n";

    // Calculate interest for 1 month
    timeInMonths = 1;
    interest = (principal * interestRate * (timeInMonths / 12.0)) / 100;  // Convert months to years
    interestInt = static_cast<int>(interest);  // Convert interest to an integer for word conversion
    interestInWords = convertToIndianWords(interestInt);

    // Display interest for 1 month in both numbers and words
    cout << "Interest for 1 month: " << interest << " (" << interestInWords << ")\n";

    return 0;
}
