class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def search(head, key):
    current = head
    while current:
        if current.data == key:
            print("Found")
            return
        current = current.next
    print("Not Found")

# Create linked list from user input
n = int(input("Enter number of elements: "))
values = list(map(int, input("Enter Elements: ").split()))

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

key = int(input("Enter value to search: "))
search(head, key)
