#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

//function to find the greatest common divisor of integers a and b using Euclid's Algorithm
//a is assumed to be greater than or equal to b
int gcd(int a, int b){
    return b==0 ? a : gcd(b, a % b);
}

//this function will find the lowest common multiple of a and b using the gcd function defined above
int lcm(int a, int b){
    //ordering the numbers
    int max, min;
    if(a > b){
        max = a;
        min = b;
    }
    else{
        max = b;
        min = a;
    }
    int greatest_factor = gcd(max, min);
    return max / greatest_factor * min;
}

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
    cout << "Expect rate of deposit growth (how much more do you plan to contribute each year, as a percent in decimal form?): ";
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
        cout << str << " is not an integer.\n";
    }
    if(deposits < 1){
        cout << "Number of contributions must be at least one. Exiting.\n";
        exit(0);
    }

    //now, we will begin the process of calculating the appreciation of the wealth
    //we will first calculate the value the period interest rate and the amount of money invested in each deposit
    double period_rate = interest_rate / compounding_periods;
    double period_deposit = income / deposits;
    //now, we will synchronize the depositing and compounding periods using their lowest common multiple
    int sync_rate = lcm(deposits, compounding_periods);
    int deposit_sync_factor = sync_rate / deposits; 
    int compounding_sync_factor = sync_rate / compounding_periods;
    //defining an array to contain the amount of money at the end of each year
    double wealth[years + 1];
    wealth[0] = principle;
    //initializing a variable to contain our current value
    double current_value = principle;
    int deposit_counter, compound_period_counter;
    //this loop will track the value of the wealth every year
    for(int year = 1; year <= years; year ++){
        //in this loop, we will replicate the effect of compounding periods and income deposits
        deposit_counter  = deposit_sync_factor;
        compound_period_counter = compounding_sync_factor;
        while((deposit_counter <= sync_rate) || (compound_period_counter <= sync_rate) ){
            if(compound_period_counter <= deposit_counter){
                //compounding wealth for one period
                current_value *= (1 + period_rate);
                compound_period_counter += compounding_sync_factor;
            }
            else{
                //depositing income for one period
                current_value += period_deposit;
                deposit_counter += deposit_sync_factor;
            }
        }
        
        //we have finished all of the compounding and deposit periods for the year, so we will updat e the array and then account for growing income 
        wealth[year] = current_value;
        period_deposit *= (1 + income_appreciation);
    }

    //now we will print the results
    for(int i = 0; i <= years; i ++){
        //setting precision settings
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        //outputting wealth in that year
        cout << "Value in year " << setw(2) << i << ": " << setw(15) << wealth[i] << endl;
    }
    return 0;
}
