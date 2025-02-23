import itertools

# Function to handle logical AND gate
def and_gate(a, b):
    return a and b

# Function to handle logical OR gate
def or_gate(a, b):
    return a or b

# Function to handle logical NOT gate
def not_gate(a):
    return not a

# Generate all combinations of Boolean values for n variables using itertools
def generate_boolean_combinations(n):
    return list(itertools.product([False, True], repeat=n))

# Function to evaluate Boolean operations for each combination
def evaluate_boolean_operations(n):
    combinations = generate_boolean_combinations(n)
    
    for combination in combinations:
        # Apply AND gate first
        and_result = combination[0]
        for i in range(1, len(combination)):
            and_result = and_gate(and_result, combination[i])

        # Apply NOT gates for each variable (in order)
        not_results = [not_gate(var) for var in combination]
        
        # Apply OR gate for intermediate steps (but without using the AND result directly)
        intermediate_or_result = not_results[0]
        for i in range(1, len(not_results)):
            intermediate_or_result = or_gate(intermediate_or_result, not_results[i])
        
        # The last OR gate connects the intermediate OR result and the AND result
        last_or_result = or_gate(intermediate_or_result, and_result)
        
        # The final output should combine:
        # "Last AND result" ∨ "Intermediate OR result before the last OR gate"
        final_output = or_gate(and_result, intermediate_or_result)
        
        # Display the results
        print(f"\nCombination: {' '.join(map(str, combination))}")
        print(f"AND Result: {and_result}")
        print(f"NOT Results: {' '.join(map(str, not_results))}")
        print(f"Intermediate OR Result (Without AND): {intermediate_or_result}")
        print(f"Last OR Result (Combining Intermediate OR & AND): {last_or_result}")
        print(f"Final Output (Last AND Result ∨ Intermediate OR): {final_output}")

# Main function to test the formulas and Boolean operations
def main():
    while True:
        n = int(input("Enter the number of Boolean variables: "))
        
        # Evaluate Boolean operations for each combination of Boolean values
        evaluate_boolean_operations(n)
        
        # Ask if the user wants to continue
        choice = input("\nDo you want to run again? (y/n): ").strip().lower()
        if choice != 'y':
            break


# Run the program
if __name__ == "__main__":
    main()
