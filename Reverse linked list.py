class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def reverseList(head):
    prev = None
    current = head
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    return prev

def printList(head):
    temp = head
    while temp:
        print(temp.data, end=" ")
        temp = temp.next
    print()

# Input
n = int(input())  # number of nodes
values = list(map(int, input().split()))

head = None
temp = None
for val in values:
    new_node = Node(val)
    if head is None:
        head = new_node
        temp = head
    else:
        temp.next = new_node
        temp = temp.next

head = reverseList(head)
printList(head)
