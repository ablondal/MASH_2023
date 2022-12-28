N, M, P = map(int, input().split())

if N % P == 0 and M % P == 0:
    print('YES')
else:
    print('NO')