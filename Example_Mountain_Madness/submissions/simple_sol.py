a = int(input())

print(' '*(a-1)+'>')
print(' '*(a-1)+'|')
print(' '*(a-1)+'.')
for i in range(1,a):
	h=''.join([chr(j+ord('A')) for j in range(i)])
	print(' '*(a-1-i)+'/'+h+h[::-1][1:]+'\\')