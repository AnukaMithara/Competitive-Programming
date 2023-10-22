n = input()
n= int(n)
grid = [[0]*(2*n-1+4) for i in range(2*n-1+4)]

for i in range(0,2*n-1):
    for j in range(0,2*n-1):
        if(i+j+2>n):
            grid[i+2][j+2] = max(abs(i-n+1),abs(j-n+1))+1

        if(j>n-1):
            grid[i+2][j+2] = grid[i+2][2*n-2-j+2]

        if(i>n-1):
            grid[i+2][j+2] = grid[2*n-2-i+2][j+2]

grid[n-3+2][0]=grid[n-3+2][-1]=n+2
grid[n-3+2][1]=grid[n-3+2][-2]=n+1
grid[n-3+2][2]=grid[n-3+2][-3]=n
grid[n-3+2][3]=grid[n-3+2][-4]=n-1
grid[n-2+2][1]=grid[n-2+2][-2]=n+1
grid[n-2+2][2]=grid[n-2+2][-3]=n


for i in range(0,2*n-1+4):
    for j in range(0,2*n-1+4):
        if(grid[i][j]==0):
            print("00",end=" ")
        elif(grid[i][j]>9):
            print(grid[i][j],end=" ")
        else:
            print("",grid[i][j],end=" ")
    print("\n",end='')
