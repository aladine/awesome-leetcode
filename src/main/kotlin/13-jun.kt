class Solution13jun {
    fun largestDivisibleSubset(nums: IntArray): List<Int> {
        if (nums.isEmpty()) return emptyList()

        var l = Array(nums.size) { _ -> 1 }
        nums.sort()
        var maxSoFar = 0
        var maxIndex: Int = -1
        for ((i, v) in nums.withIndex()) {
            // or for i in nums.indices
            for (j in 0 until i)
                if (v % nums[j] == 0 && l[i] < l[j] + 1)
                    l[i] = l[j] + 1
            if (maxSoFar < l[i]) {
                maxSoFar = l[i]
                maxIndex = i
            }
        }

        val ans = Array<Int>(maxSoFar) { -1 }
        var c = 0
        while (maxIndex >= 0) {
            ans.set(c++, nums[maxIndex])
            var hasChange = false
            for (j in maxIndex - 1 downTo 0) {
                if (nums[maxIndex] % nums[j] == 0 && l[maxIndex] == l[j] + 1) {
                    maxIndex = j
                    hasChange = true
                    break
                }
            }
            if (!hasChange) break
        }

        return ans.toList()
    }
    // add an array to store the preList of pair(i,j)
}
