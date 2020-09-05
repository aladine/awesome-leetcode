class Solution28Aug {
    fun findRightInterval(intervals: Array<IntArray>): IntArray {
        val ans: MutableList<Int> = MutableList<Int>(intervals.size) {-1}
        val newIntervals = intervals.withIndex().map { c ->
            intArrayOf(c.index, c.value[0])
        }.sortedBy { it[1] }
        for(i in newIntervals.size-1 downTo 0){
            val ele = newIntervals[i]
            for(j in i+1 until newIntervals.size){
                val idx = newIntervals[j][0]
                if (intervals[ele[0]][1] <= intervals[idx][0]){
                    ans[ele[0]] = idx
                    break
                }
            }
        }
        return ans.toIntArray()


    }
}

/*val ret = IntArray(intervals.size) { -1 }
        val intervalsSorted = ArrayList<IntArray>()
        //start,index
        for (i in intervals.indices) {
            intervalsSorted.add(intArrayOf(intervals[i][0], i))
        }
        intervalsSorted.sortWith(Comparator<IntArray> { o1, o2 ->
            if (o1[0] < o2[0]) {
                -1
            } else if (o1[0] > o2[0]) {
                1
            } else {
                if (o1[1] < o2[1]) {
                    -1
                } else {
                    1
                }
            }
        })
        for (i in intervals.indices) {
            var start = 0
            var end = intervals.size - 1
            var findIndex = -1
            while (start <= end) {
                val mid = (start + end) / 2
                if (intervalsSorted[mid][0] < intervals[i][1]) {
                    start = mid + 1
                } else if (intervalsSorted[mid][0] >= intervals[i][1]) {
                    if (intervalsSorted[mid][1] != i) {
                        end = mid - 1
                        findIndex = intervalsSorted[mid][1]
                    } else {
                        start = mid + 1
                    }
                }
            }
            ret[i] = findIndex
        }
        return ret
    }
*/