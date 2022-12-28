"""
CONTRIBUTED BY - 
Atharva Mutsaddi
SY COMP
"""

#taking input from the user for value of 'n'
n = eval(input()) 

if(n==1):

    # since number of ways to jump 1 stone = 1
    print(1)

# generating a series, where the ith index contains number of ways to get jump through the ‘i’ stones
else:

    #as one way to jump zero stones, one way to jump  1 stone
    series = [1,1]
    i = 2
    while(i<=n):

        #since number of ways to jump 'i' number of stones = number of ways to jump 'i-1' stones + number of ways to jump 'i-2' stones
        series.append(series[i-1]+series[i-2])
        i = i+1

    #the ans for our question lies at the nth index value of this series
    print(series[n])