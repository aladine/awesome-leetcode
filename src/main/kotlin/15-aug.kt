import java.util.*

class Solution15Aug {
    fun eraseOverlapIntervals(intervals: Array<IntArray>): Int {
        intervals.sortBy { a -> a[0] } // intervals.sortBy { it[0] }
        val st :Stack<IntArray>  = Stack<IntArray>()
        for (interval in intervals){
            if (st.isEmpty()) {
                st.push(interval)
                continue
            }
            val ele = st.peek()!!

            if(ele[1] <= interval[0]) {
                st.push(interval)
                continue
            }

            if (ele[1] >= interval[1]){
                st.pop()
                st.push(interval)
            }
        }

        return intervals.size - st.size
    }
    // OR: keep track of the last end is enough:
    // var prevEnd = intervals.getOrNull(0)?.get(1) ?: return 0
}
