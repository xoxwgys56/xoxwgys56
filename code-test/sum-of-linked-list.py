from __future__ import annotations
from typing import Optional


class ListNode:
    """Definition for singly-linked list."""

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self) -> str:
        return f"<ListNode {self.val} {self.next}>"

    def __eq__(self, node: ListNode) -> bool:
        _node = self
        while node.next:
            if _node.val != node.val:
                return False

            node = node.next
            _node = _node.next

            if not (node and _node):
                return False

        return True


class Solution:
    @staticmethod
    def addTwoNumbers(
        l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        def get_sum_of_list(list_node: ListNode):
            cnt = 1
            n = 0
            while list_node.next:
                n += list_node.val * cnt
                cnt = cnt * 10
                list_node = list_node.next
            n += list_node.val * cnt

            return n

        result_sum = get_sum_of_list(l1) + get_sum_of_list(l2)

        if not result_sum:
            return ListNode(0)

        cnt = 10
        arr = []
        while result_sum > 0:
            num = result_sum % cnt
            arr.append(num)
            result_sum = result_sum // cnt

        head_node = None
        for n in reversed(arr):
            _l1 = ListNode(n, head_node)
            head_node = _l1

        return head_node


def get_list_node(arr: list) -> Optional[ListNode]:
    head_node = None
    for n in reversed(arr):
        _l1 = ListNode(n, head_node)
        head_node = _l1

    return head_node


if __name__ == "__main__":
    # assert Solution.addTwoNumbers(
    #     get_list_node([2, 4, 3]), get_list_node([5, 6, 4])
    # ) == get_list_node([7, 0, 8])

    assert Solution.addTwoNumbers(
        get_list_node([0, 0, 0, 0, 0, 1]), get_list_node([0, 0, 0, 0, 0, 1])
    ) == get_list_node([0, 0, 0, 0, 0, 2])

    assert Solution.addTwoNumbers(
        get_list_node([0]), get_list_node([0])
    ) == get_list_node([0])
