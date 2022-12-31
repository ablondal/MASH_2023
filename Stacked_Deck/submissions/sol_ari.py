n, k = map(int, input().split())
L = sorted(map(int, input().split()))

tot = sum([(L[n-i]-L[k-i])**2 for i in range(1, k+1)])
print(tot)