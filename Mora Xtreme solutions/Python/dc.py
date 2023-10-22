scores =[i for i in range(1,21,1)] +[2*i for i in range(1,21,1)]+[50,25]+[3*i for i in range(1,21,1)] 
S =62

#print(scores)

ways =[0]* 200

for i in range(S):
    for j in range(0,S):
        for k in range(20,41):
            ways[scores[i]+scores[j]+scores[k]]+=1
            
for j in range(0,S):
    for k in range(20,41):
        ways[scores[j]+scores[k]]+=1
        #if(scores[j]+scores[k]==4): print(j,k)
        
for k in range(20,41):
    ways[scores[k]]+=1
    
t = int(input().strip()) 

for i in range(t):
    a = int(input().strip())
    if(ways[a]): print(ways[a])
    else: print("NONE")
