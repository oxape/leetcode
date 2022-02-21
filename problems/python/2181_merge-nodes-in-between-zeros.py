'''
Author: your name
Date: 2022-02-21 09:30:29
LastEditTime: 2022-02-21 15:32:45
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: /leetcode/problems/python/6013_merge-nodes-in-between-zeros.py
'''
from re import I
from typing import *

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prevNode = None
        lastZeroNode = head
        currentNode = head.next
        while True:
            if currentNode.val != 0:
                lastZeroNode.val += currentNode.val
            else:
                prevNode = lastZeroNode
                lastZeroNode.next = currentNode
                lastZeroNode = currentNode
            currentNode = currentNode.next
            # 后续没有节点时，其实这里根据题目假设，可以直接判断currentNode.val == 0 and currentNode == None
            if currentNode is None:
                # 最后一个节点为val为0时去除
                if lastZeroNode.val == 0:
                    prevNode.next = None
                else:
                    lastZeroNode.next = None
                break
        return head


if __name__ == '__main__':
    nums = [0,3,1,0,4,5,2,0]
    last_node = None
    head = None
    for e in nums:
        tmp = ListNode(e, None)
        if last_node is None:
            head = tmp
            last_node = head
        else:
            last_node.next = tmp
            last_node = tmp
    node = Solution().mergeNodes(head)
    while True:
        if node == None:
            break
        print(node.val)
        node = node.next
