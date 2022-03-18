# UVa 540 - Team Queue
# Queue simulation
from collections import deque


class TeamQueue:
    def __init__(self, num_teams):
        self.order = deque()
        self.q_teams = [deque() for _ in range(num_teams)]
        self.team_dict = {}
    
    def create(self, t, elements):
        for x in elements:
            self.team_dict[x] = t

    def enqueue(self, x):
        t = self.team_dict[x]
        self.q_teams[t].append(x)
        if t in set(self.order):
            pass
        else:
            self.order.append(t)

    def dequeue(self):
        x = self.q_teams[self.order[0]].popleft()
        if len(self.q_teams[self.order[0]]) == 0:
            self.order.popleft()
        
        return x


tc = 1

while True:
    num_teams = int(input())
    if num_teams == 0:
        break

    print('Scenario #{}'.format(tc))

    tq = TeamQueue(num_teams)

    for t in range(num_teams):
        inputs = input().split(' ')
        tq.create(t, inputs[1:])

    while True:
        op = input().split(' ')
        if op[0] == 'STOP':
            break
        elif op[0] == 'ENQUEUE':
            x = op[1]
            tq.enqueue(x)
        else:
            print(tq.dequeue())
    
    print()
    tc += 1
