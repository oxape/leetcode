# Definition for singly-linked list.
from typing import List


class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        val = l1.val + l2.val
        node = ListNode(val % 10)
        temp_node = node
        next_val = val // 10
        l1 = l1.next
        l2 = l2.next
        while not (l1 is None and l2 is None):
            val = 0
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2 = l2.next
            val = val + next_val
            temp_node.next = ListNode(val % 10, None)
            temp_node = temp_node.next
            next_val = val // 10
        if next_val != 0:
            temp_node.next = ListNode(next_val, None)
        return node
    

    def addTwoNumbersV1(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        left_val = 0
        head = node = None
        while not (l1 is None and l2 is None):
            val = 0
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2 = l2.next
            val = val + left_val
            if node is None:
                head = node = ListNode(val%10)
            else:
                node.next = ListNode(val%10)
                node = node.next
            left_val = val // 10
        if left_val != 0:
            node.next = ListNode(left_val, None)
        return head
    

def construct_list_node(l):
    """
    :type l: list
    :rtype: ListNode
    """
    node = ListNode(l[0])
    temp_node = node
    for num in l[1:]:
        temp_node.next = ListNode(num)
        temp_node = temp_node.next
    return node


def print_list_node(node):
    """
    :type node: list
    """
    results = []
    while node is not None:
        results.append(node.val)
        node = node.next
    print(results)


if __name__ == '__main__':
    case_l1 = construct_list_node([2, 4, 3])
    case_l2 = construct_list_node([5, 6, 4])
    print_list_node(case_l1)
    print_list_node(case_l2)
    result_node = Solution().addTwoNumbersV1(case_l1, case_l2)
    print_list_node(result_node)
