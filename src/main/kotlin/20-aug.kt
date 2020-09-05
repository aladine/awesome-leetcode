import utility.ListNode

class Solution20Aug {
    fun sortArrayByParity(A: IntArray): IntArray {
        return A.sortedBy { it%2 }.toIntArray()
    }

    fun reorderList(head: ListNode?) {
        if (head?.next == null) return
        var slow: ListNode = head
        var fast: ListNode = head
        while(fast.next != null && fast.next?.next != null){
            slow = slow.next!!
            fast = fast.next?.next!!
        }

        // reverse the last half
        var prev: ListNode? = null
        var curr = slow.next
        var nnext = curr?.next
        while(curr!= null){
            curr.next = prev
            prev = curr
            curr = nnext
            if(nnext!=null) nnext = nnext.next
        }
        slow.next = prev

        // merge 2 lists
        var p1 = head
        var p2 = slow.next
        var rcurr: ListNode?
        var lcurr: ListNode?
        while(p1 != slow){
            lcurr = p1?.next
            rcurr = p2?.next
            p1?.next = p2
            p2?.next = lcurr
            p1 = lcurr
            p2 = rcurr
        }
        slow.next = p2
    }
}
/*var curr = head

        val stack = ArrayDeque<ListNode>()
        while (curr != null) {
            stack.push(curr)
            curr = curr.next
        }

        curr = head

        val mid = (stack.size)/2
        var count = 0
        while (count < mid) {
            val tmp = curr?.next
            val node = stack.pop()
            curr?.next = node
            curr?.next?.next = tmp
            curr = tmp
            count++
        }

        curr?.next = null*/