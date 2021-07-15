p=int(input("Enter number of plants : "))
f=int(input("Enter number of friends : "))

plants=[int(x) for x in input().split()]
temp_plants=list()
sum=0
j=1
plants=sorted(plants,reverse=True)
print(plants)
indicator=0
sum=0
for i in range(0,len(plants),1):
    if(indicator==f):
        j+=1
        indicator=0
    sum=sum+(0+j)*plants[i]
    indicator+=1
print(sum)
