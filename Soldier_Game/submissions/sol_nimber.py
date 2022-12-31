state = input()

# Calculate the nimber of a line of soldiers of length n
# 0 is a losing state
# If a state can reach states 0, 1, ..., k, then it has nimber k+1.
# Finally, the solution reduces to a game of nim on the nimbers of
# each disconnected line.
# Remember, we see if player 1 wins nim by seeing if the xor of the nimbers
# is non-zero.
nimber = [0, 0] # 0 and 1 soldier are both losses.
for n in range(2, 33):
    states_reached = set()
    for i in range(1, n+1): # Try removing the ith soldier from the lineup
        newstate = nimber[i-1] ^ nimber[n-i]
        states_reached.add(newstate)
    # Calculate the nimber
    new_nimber = 0
    while new_nimber in states_reached:
        new_nimber += 1
    nimber.append(new_nimber)
    # print(n, new_nimber)

lines = state.split('.') # Split soldiers into lines
tot_nimber = 0
for line in lines:
    if len(line) > 1:
        tot_nimber = tot_nimber ^ nimber[len(line)]

if tot_nimber==0:
    print('Alice')
else:
    print('Bob')