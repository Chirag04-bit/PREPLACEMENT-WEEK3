class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def detectAndRemoveLoop(head):
    slow = head
    fast = head

    # Detect loop using Floyd's Cycle Detection
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            removeLoop(head, slow)
            return True
    return False

def removeLoop(head, loop_node):
    ptr1 = head
    while True:
        ptr2 = loop_node
        while ptr2.next != loop_node and ptr2.next != ptr1:
            ptr2 = ptr2.next
        if ptr2.next == ptr1:
            break
        ptr1 = ptr1.next
    ptr2.next = None  # Remove loop

def printList(head):
    count = 0
    temp = head
    while temp and count < 100:  # Safety limit to avoid infinite loop
        print(temp.data, end=" ")
        temp = temp.next
        count += 1
    print()

# Input
n = int(input())  # number of nodes
values = list(map(int, input().split()))  # node values
links = list(map(int, input().split()))   # next node index (-1 for None)

nodes = [Node(values[i]) for i in range(n)]
for i in range(n):
    if links[i] != -1:
        nodes[i].next = nodes[links[i]]

head = nodes[0] if n > 0 else None

if detectAndRemoveLoop(head):
    print("Loop Detected and Removed")
else:
    print("No Loop Found")

printList(head)
