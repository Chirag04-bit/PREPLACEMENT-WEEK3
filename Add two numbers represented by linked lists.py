class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def addTwoLists(first, second):
    carry = 0
    result_head = None
    result_tail = None

    while first or second or carry:
        val1 = first.data if first else 0
        val2 = second.data if second else 0
        total = val1 + val2 + carry

        carry = total // 10
        digit = total % 10
        new_node = Node(digit)

        if result_head is None:
            result_head = new_node
            result_tail = result_head
        else:
            result_tail.next = new_node
            result_tail = result_tail.next

        if first:
            first = first.next
        if second:
            second = second.next

    return result_head

def printList(head):
    temp = head
    while temp:
        print(temp.data, end=" ")
        temp = temp.next
    print()

# Input first number
n1 = int(input())  
list1 = list(map(int, input().split()))
head1 = None
temp = None
for val in list1:
    node = Node(val)
    if head1 is None:
        head1 = node
        temp = head1
    else:
        temp.next = node
        temp = temp.next

# Input second number
n2 = int(input())  
list2 = list(map(int, input().split()))
head2 = None
temp = None
for val in list2:
    node = Node(val)
    if head2 is None:
        head2 = node
        temp = head2
    else:
        temp.next = node
        temp = temp.next

result = addTwoLists(head1, head2)
printList(result)
