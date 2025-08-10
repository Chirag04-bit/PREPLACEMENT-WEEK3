class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def deleteNode(head, position):
    if head is None:
        return head
    if position == 0:
        return head.next
    temp = head
    for _ in range(position - 1):
        if temp is None:
            return head
        temp = temp.next
    if temp is None or temp.next is None:
        return head
    temp.next = temp.next.next
    return head

def printList(node):
    while node:
        print(node.data, end=" ")
        node = node.next

head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head = deleteNode(head, 2)
printList(head)
