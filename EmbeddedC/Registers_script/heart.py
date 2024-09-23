n = 16  # Ensure n is even
m = n + 1  # Columns
print("\n\n\n\n")
# Loop for the upper part (half heart)
for i in range(n // 2 - 1):
    for j in range(m // 2 + 1):  # Only loop through half the columns
        # Condition for printing stars to the upper left
        if i == n // 2 - 2 and j == 0:
            print("*", end=" ")
        elif (i + j == n // 2 - 3 and j <= m // 4) or \
             (j - i == m // 2 - n // 2 + 3 and j > m // 4):
            print("*", end=" ")
        else:
            print(" ", end=" ")
    print()

# Loop for the lower part (half heart)
for i in range(n // 2 - 1, n):
    for j in range(m // 2 + 1):  # Only loop through half the columns
        # Condition for printing stars for the lower left
        if i - j == n // 2 - 1:
            print('*', end=" ")
        # Condition for printing "GFG" in the middle of the lower part

        else:
            print(' ', end=" ")
    print()
print("\n\n\n\n")