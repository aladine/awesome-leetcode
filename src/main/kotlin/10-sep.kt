import kotlin.math.abs

/**
 * https://leetcode.com/explore/featured/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3455/
 */
class Solution10Sep {
    fun getHint(secret: String, guess: String): String {
        var bulls = 0
        var cows = 2*secret.length
        val m = mutableMapOf<Char, Int>() // or IntArray(10) since there are 10 digits
        for (i in secret.indices){
            m[secret[i]] = m.getOrDefault(secret[i], 0 )+1
            m[guess[i]] = m.getOrDefault(guess[i], 0 )-1

            if(secret[i] == guess[i]) {
                bulls++
            }
        }
        cows -= m.values.map { abs(it) }.sum()
        cows /= 2


        return "${bulls}A${cows-bulls}B"
    }
}