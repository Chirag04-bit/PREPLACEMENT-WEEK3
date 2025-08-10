class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def detectLoop(head):
    slow = head
    fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False

# Create linked list from input
n = int(input("Enter n: "))  # number of nodes
values = list(map(int, input("Enter values: ").split()))  # node values
links = list(map(int, input("Enter links: ").split()))   # next node index (-1 for None)

nodes = [Node(values[i]) for i in range(n)]
for i in range(n):
    if links[i] != -1:
        nodes[i].next = nodes[links[i]]

head = nodes[0] if n > 0 else None

print("Loop Detected" if detectLoop(head) else "No Loop")
