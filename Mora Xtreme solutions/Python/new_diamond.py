N,H,M = map(int,input().strip().split())

c=0
container=[[] for i in range(N)]

for i in range(1,N+1):
    if(len(container[c])==M or sum(container[c])+i>H): c+=1  
    container[c].append(i)

print(c+1)
for i in range(c+1):
    print(" ".join(str(x) for x in container[i]))