from random import choice
s = ''
for _ in range(32):
    s = s + choice(('.', '!', '!', '!'))
print(s)