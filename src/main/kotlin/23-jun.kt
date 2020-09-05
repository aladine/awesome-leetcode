//import java.util.*
//
//class Solution23Jun{
//    fun mergeKLists(lists: Array<ListNode?>): ListNode? {
//        return when {
//            lists.size == 1 -> lists.first()
//            lists.isEmpty() -> null
//            else -> lists.reduce { l1, l2 -> merge2Lists(l1, l2) }
//        }
//    }
//
//     fun merge2Lists(l1: ListNode?, l2: ListNode?): ListNode? {
//        if (l1 == null || l2 == null) {
//            return l1 ?: l2
//        }
//
//        return if (l1.`val` < l2.`val`) {
//            l1.next = merge2Lists(l1.next, l2)
//            l1
//        } else {
//            l2.next = merge2Lists(l1, l2.next)
//            l2
//        }
//    }
//
//    fun mergeKLists2(lists: Array<ListNode?>): ListNode? {
//            val minHeap = PriorityQueue<ListNode?>(compareBy{ it?.`val` })
//            // fill the minHeap
//            for (i in lists.indices) {
//                lists[i]?.let {
//                    minHeap.add(it)
//                }
//            }
//
//            val result = ListNode(0) // dummy head, the result will be its next Node
//            var resultPointer = result
//
//            while(minHeap.isNotEmpty()) {
//                // get current min value
//                val min = minHeap.remove()
//                // add min value to the results
//                resultPointer.next = min
//                resultPointer = resultPointer.next!!
//
//                // remove current min, re-add it to the heap
//                min?.next?.let {
//                    minHeap.add(it)
//                }
//            }
//
//            return result.next
//        }
//    }
//}
