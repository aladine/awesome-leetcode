class Solution18Aug {
    private fun helper(pos: Int, lastDigit: Int, currNum: Int, n: Int, k: Int, res: MutableList<Int>): Unit {
        if (pos == n) {
            res.add(currNum)
            return
        }
        if (k == 0) {
            helper(pos + 1, lastDigit, 10 * currNum + lastDigit, n, k, res)
            return
        }
        if (lastDigit + k in 0..9) {
            helper(pos + 1, lastDigit + k, 10 * currNum + lastDigit + k, n, k, res)
        }
        if (lastDigit - k in 0..9) {
            helper(pos + 1, lastDigit - k, 10 * currNum + lastDigit - k, n, k, res)
        }
    }

    fun numsSameConsecDiff(n: Int, k: Int): IntArray {
        if (n == 1) return intArrayOf(0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
        val res = mutableListOf<Int>()
        for (i in 1..9) {
            helper(1, i, i, n, k, res)
        }
        return res.toIntArray()
    }
}