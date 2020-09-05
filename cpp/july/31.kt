class Solution {
    fun climbStairs(n: Int): Int {
        var a = 1
        var b = 2
        if(n==1) return 1
        if(n==2) return 2
        repeat(n-2){
            a, b = b, a + b
        }
        return b
}
