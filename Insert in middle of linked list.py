class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def insertInMiddle(head, x):
    slow = head
    fast = head
    while fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next
    newNode = Node(x)
    newNode.next = slow.next
    slow.next = newNode
    return head

def printList(node):
    while node:
        print(node.data, end=" ")
        node = node.next

head = Node(1)
head.next = Node(2)
head.next.next = Node(4)
head = insertInMiddle(head, 3)
printList(head)
