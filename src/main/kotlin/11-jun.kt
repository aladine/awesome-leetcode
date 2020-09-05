class Solution11Jun {
    private fun swapColor(nums: IntArray, k: Int, l: Int) {
        val tmp = nums[k]
        nums[k] = nums[l]
        nums[l] = tmp
    }

    fun sortColors(nums: IntArray) {
        var l = 0
        var m = 0
        var h = nums.size - 1
        // for (i in 0 until nums.size) 
        while (m <= h) {
            when (nums[m]) {
                0 -> swapColor(nums, m++, l++)
                1 -> m++
                2 -> swapColor(nums, m, h--)
            }
        }
    }
}
