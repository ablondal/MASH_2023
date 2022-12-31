state = input()

# We can't do DP on the total number of strings of soldiers of length 32,
# because there are too many.
# So instead, we reduce the state to the sorted lengths of lineups (adjascent lines)
# of soldiers.

# Remember that a winning state is one that can reach a losing state
# and a losing state is one that reaches only winning states.
# (Reach means to get to in one move)
state_dict = {}

def is_winning_state(lineup_lens):
    if lineup_lens in state_dict:
        return state_dict[lineup_lens]
    if len(lineup_lens) == 0: # No lineups of length 2 or more
        return 0
    for l in lineup_lens:
        for i in range(l): # Remove the ith soldier from the lineup
            newstate = [a for a in lineup_lens]
            newstate.remove(l)
            if i > 1:
                newstate.append(i)
            if l-i-1 > 1:
                newstate.append(l-i-1)
            newstate = tuple(sorted(newstate))
            if not is_winning_state(newstate): # It is a losing state
                state_dict[lineup_lens] = True
                return True
    state_dict[lineup_lens] = False
    return False # We have found no losing states to move to

state = sorted([len(a) for a in state.split('.') if len(a) > 1])
state = tuple(state)
if is_winning_state(state):
    print('Bob')
else:
    print('Alice')

            
