"""
CODE CONTRIBUTED BY - 
Abhinav Kurule
SY COMP
"""

#taking input
(N,M,NP,LP,RP,BP)=map(int,input().split())
# total number of railings, total beds and total number of persons requiring 1 side of railing are recorded
railings=N*(M+1)
total=N*M
side=RP+LP
k=0
rails=0
# checking if total number of students are less than total number of beds
if side+NP+BP<=total:
#checking if the total number of railings occupied by the students is less than the total number of railings present in the room
    if side+BP*2<=railings:
        print(side+NP+BP)
# if number of students is less than the total number of beds but their railing requirements are higher than the total number of railings in the room.
    else:
        k+=side
        rails+=side
        t=min(BP,(railings-rails)//2)
        k+=t
        if k!=total:
            k+=min(total-k,NP)
        if M%2==0:
            print(k-1)
        else:
            print(k)
    
#if number of students are greater than the total number of beds in the room        
else:
    if side<total:
        k+=side
        rails+=side
        t=min(BP,(railings-rails)//2)
        k+=t
        if k!=total:
            k+=min(total-k,NP)
        print(k)        
    else:
        print(total)