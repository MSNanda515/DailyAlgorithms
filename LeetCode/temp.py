rows = 30  # You can adjust this to fit your needs
current_number = 1

# Loop through each row
for i in range(1, rows + 1):
    # Loop through each column in the current row
    for j in range(1, i + 1):
        # Print the current number
        # print(current_number, end=" ")
        current_number += 1

    # Move to the next line after finishing a row
    print()

# Print the last column for each row
for i in range(1, rows + 1):
    last_column_number = i * (i + 1) // 2
    print(f"Last column for row {i}: {last_column_number}")