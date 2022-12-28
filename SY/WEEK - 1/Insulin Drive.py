"""
CODE CONTIBUTED BY - Sahil Sanjay Gavankar
SY ENTC
"""


D,R=map(int,input().split())
ages=input().split()

#Typecasting each element to int type and creating its list:
ages=[int (i) for i in ages]

#Creating 2 empty lists to separate the two different groups of villagers:
on_verge=[]
diabetic=[]

#Appending each villager to its respective group:
for i in range(D):
    if ages[i]<=9 or ages[i]>=80:
        on_verge.append(ages[i])
    else:
        diabetic.append(ages[i])

#Calculation logic for minimum required days for each group:
a=len(on_verge)//R
remain1=0
if len(on_verge)%R !=0:
    remain1+=1
    
b=len(diabetic)//R
remain2=0
if len(diabetic)%R !=0:
    remain2+=1
    
#Final output:   
days=a+b+remain1+remain2
print(days)
