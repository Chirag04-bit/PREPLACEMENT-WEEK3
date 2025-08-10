class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def getNthFromLast(head, n):
    first = head
    second = head

    # Move first pointer n steps ahead
    for _ in range(n):
        if first is None:
            return -1
        first = first.next

    # Move both until first reaches the end
    while first:
        first = first.next
        second = second.next

    return second.data if second else -1

# Create linked list from user input
size = int(input("Enter number of elements: "))
values = list(map(int, input("Enter the elements:").split()))
n = int(input("Enter n: "))

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

print(getNthFromLast(head, n))
