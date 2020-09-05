class Solution04Sep {
    fun repeatedSubstringPattern(s: String): Boolean {
        val l = s.length
        return (s+s).substring(1,2*l-1).indexOf(s,0) >= 0
    }
}