#include <iostream>

using namespace std;

int sum_of_ten_nat_numbers() {
    int sum = 0;

    for(int i=1; i<=10; i++) {
        sum += i;
    }

    return sum;
}

int main() {
    cout << "We will print out the sum of the first 10 natural numbers." << endl;
    cout << "----------------------------------------------------------" << endl;

    int sum = sum_of_ten_nat_numbers();
    string sum_string = to_string(sum);

    cout << "The sum is: " << sum << endl;
    return 0;
}

