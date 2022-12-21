k=n=int(input())-1
exec("print(' '*n+'%s');"*3%tuple('>|.'))
for i in range(1,n+1):
    h=''.join([chr(j+65) for j in range(i)]);
    print(' '*(n-i)+'/'+h+h[::-1][1:]+'\\')