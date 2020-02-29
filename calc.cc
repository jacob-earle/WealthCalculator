#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int main(int argc, char * argv[]){
    //Initializing variables
    double principle, interest_rate, income, income_appreciation;
    int years, compounding_periods, deposits;
    //Reading inputs
    cout << "Principle amount in dollars: ";
    //verifying that a double was input
    while(!(cin >> principle)){
        string str;
        cin.clear();
        getline( cin, str);
        cout << str << " is not a number.\n";
    }
    //verifying that principle is a non-negative number
    if(principle < 0){
        cout << "Principle must be a non-negative number. Exiting.\n";
        exit(0);
    }

    //Same process for interest_rate
    cout << "Expected annual appreciation (as a decimal): ";
    while(!(cin >> interest_rate)){
        string str;
        cin.clear();
        getline( cin, str);
        cout << str << " is not a number.\n";
    }
    
    //Annual deposits
    cout << "Total annual contribution amount: ";
    while(!(cin >> income)){
        string str;
        cin.clear();
        getline( cin, str);
        cout << str << " is not a number.\n";
    }
    if( income < 0){
        cout << "Annual deposits must be a non-negative number. Exiting.\n";
        exit(0);
    }

    //income_appreciation
    cout << "Expect rate of deposit growth (how much more do you plan to contribute each year?): ";
    while(!(cin >> income_appreciation)){
        string str;
        cin.clear();
        getline( cin, str);
        cout << str << " is not a number.\n";
    }

    //number of years
    cout << "Number of years investing: ";
    while(!(cin >> years)){
        string str;
        cin.clear();
        getline( cin, str);
        cout << str << " is not an integer.\n";
    }
    if(years < 1){
        cout << "You must input at least 1 year. Exiting.\n";
        exit(0);
    }

    //compounding periods
    cout << "Compounding periods per year: ";
    while(!(cin >> compounding_periods)){
        string str;
        cin.clear();
        getline( cin, str);
        cout << str << " is not an integer.\n";
    }
    if(compounding_periods < 1){
        cout << "There must be at least one compounding period per year. Exiting.\n";
        exit(0);
    }
    
    //annual deposits
    cout << "Number of contributions per year: ";
    while(!(cin >> deposits)){
        string str;
        cin.clear();
        getline( cin, str);
        cout << str << " is not a number.\n";
    }
    if(deposits < 1){
        cout << "Number of contributions must be at least one. Exiting.\n";
        exit(0);
    }
    return 0;
}
