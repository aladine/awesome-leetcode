class Solution02Aug{
    fun isPowerOfFour(num: Int): Boolean {
        return when{
            num <= 0 -> false
            num == 1 -> true
            num and num - 1 != 0 -> false
            num % 4 != 0 -> false
            else -> isPowerOfFour(num shr 2)
        }
    }
}
