"""
CODE CONTRIBUTED BY - Sahil Sanjay Gavankar
SY ENTC
"""

#Required Inputs:
S,D,K=map(int,input().split())
N=list(map(int,input().rstrip().split()))

#Empty list to append voting ID of barred students:
l=[]

#Check whether a single ID is found more than once:
#If YES Check whether he is student or Developer:
#If the voter is student then append his ID to the empty list:
for i in range(K):
    for j in range(i+1,K):
        if N[i]==N[j]:
            if N[i]<=S:
                l.append(N[i])

#Typecasting to 'sets' in order to avoid repeated values:
p=set(l)

#Sorting the set in order to get increasing number of voter ID's:
p=sorted(p)

#Desired Output:
print(len(p),*list(p))
