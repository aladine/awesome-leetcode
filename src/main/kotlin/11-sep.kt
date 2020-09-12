import kotlin.math.max

/**
 * https://leetcode.com/explore/featured/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3456/
 */
class Solution11Sep {
    fun maxProduct(nums: IntArray): Int {
        if(nums.isEmpty()) return 0
        var currMinNeg = 0
        var mp = Int.MIN_VALUE
        var lastNum = 1
        for(i in nums.indices){
            var element = nums[i] * lastNum
            if (lastNum==0)
                element = nums[i]
            if(element ==0){
                currMinNeg = 0
                mp = max(mp, element)
            }else if (element> 0){
                mp = max(mp, element)
            }else{
                if(currMinNeg==0) {
                    currMinNeg = element
                    mp = max(mp, element)
                } else mp = max(mp, element/currMinNeg)
            }
            lastNum = element
        }
        return mp
    }
}
