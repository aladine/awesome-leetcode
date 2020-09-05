class Solution11Aug {
    fun hIndex(citations: IntArray): Int {
        when (citations.size) {
            0 -> return 0
            1 -> return if (citations[0] == 0) 0 else 1
            else -> {
                val n = citations.size
                citations.sort()
                // check n
                if(citations[0]>=n) return n;
                for (i in 1 until n) {
                    // try n-i
                    if (citations[i]>=n-i) return n-i
                }
                return 0
            }
        }
    }
}