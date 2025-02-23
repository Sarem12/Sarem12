#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to calculate the number of gates in Y Tree given n (number of variables)
int calculate_gates(int n)
{
    return n * n + 1;
}

// Function to handle logical AND gate
bool and_gate(bool a, bool b)
{
    return a && b;
}

// Function to handle logical OR gate
bool or_gate(bool a, bool b)
{
    return a || b;
}

// Function to handle logical NOT gate
bool not_gate(bool a)
{
    return !a;
}

// Function to evaluate Boolean operations for each combination
void evaluate_boolean_operations(int n)
{
    int total_combinations = pow(2, n);

    // Iterate over all combinations
    for (int i = 0; i < total_combinations; ++i)
    {
        vector<bool> combination;

        // Generate current combination dynamically using bitwise operations
        for (int j = 0; j < n; ++j)
        {
            combination.push_back((i & (1 << (n - j - 1))) > 0);
        }

        // Apply AND gate first
        bool and_result = combination[0];
        for (size_t i = 1; i < combination.size(); ++i)
        {
            and_result = and_gate(and_result, combination[i]);
        }

        // Apply NOT gates for each variable (in order)
        vector<bool> not_results;
        for (bool var : combination)
        {
            not_results.push_back(not_gate(var));
        }

        // Apply OR gate for intermediate steps (but without using the AND result directly)
        bool intermediate_or_result = not_results[0];
        for (size_t i = 1; i < not_results.size(); ++i)
        {
            intermediate_or_result = or_gate(intermediate_or_result, not_results[i]);
        }

        // The last OR gate connects the intermediate OR result and the AND result
        bool last_or_result = or_gate(intermediate_or_result, and_result);

        // The final output should combine:
        // "Last AND result" ∨ "Intermediate OR result before the last OR gate"
        bool final_output = or_gate(and_result, intermediate_or_result);

        // Display the results
        cout << "\nCombination: ";
        for (bool val : combination)
        {
            cout << val << " ";
        }
        cout << "\nAND Result: " << and_result;
        cout << "\nNOT Results: ";
        for (bool val : not_results)
        {
            cout << val << " ";
        }
        cout << "\nIntermediate OR Result (Without AND): " << intermediate_or_result;
        cout << "\nLast OR Result (Combining Intermediate OR & AND): " << last_or_result;
        cout << "\nFinal Output (Last AND Result ∨ Intermediate OR): " << final_output << endl;
    }
}

// Main function to test the formulas and Boolean operations
int main()
{
    char choice;
    do
    {
        int n;
        cout << "Enter the number of Boolean variables: ";
        cin >> n;

        // Evaluate Boolean operations for each combination of Boolean values
        evaluate_boolean_operations(n);

        // Ask if the user wants to continue
        cout << "\nDo you want to run again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}
