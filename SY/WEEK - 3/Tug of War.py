"""
CONTRIBUTED BY - 
Mohit Apte
SY COMP
"""

N, P, PSY = map(int, input().split())
PFY = list(map(int, input().split()))
num = 0  # Variable to store the newly added players
# Checking Case 1. i.e. if the second years students already satisfy the minimum person requirement

if PSY >= P:
    print("YES")
else:
    dict = {}
    for i in range(N):  # Iterating through every group of first year students
        if PFY[i] in dict:  # Checking the existence of given element in dictinary
            # If yes, adding one to it (In order to keep a count of that element)
            dict[PFY[i]] += 1
        else:
            # If not present in dictionary, we create a key, and set it as one.
            dict[PFY[i]] = 1
        if dict[PFY[i]] % 2 == 0:  # If the count of the group is divisible by two, a group of two has been found and can be put in the
            num += 2*PFY[i]  # tug of war game (On both sides).
    if (num+PSY) >= P:  # Checking the final condition whether the minimum people requirement has been satisfied
        print("YES")
    else:
        print("NO")