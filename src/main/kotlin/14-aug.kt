import kotlin.math.max

class Solution14Aug {
    fun longestPalindrome(s: String): Int {
        var res = 0
        var oddSize = 0
        s.toCharArray().groupBy { it }.values.forEach {
            if(it.size %2 ==0 ) res+=it.size
            else {
                res+=it.size-1
                oddSize = 1
            }
        }
        return res + oddSize
    }
}
