class Solution10Aug {
    fun titleToNumber(s: String): Int {
        if (s.length == 1) {
            return s[0]-'A'+1
        }
        return s.last()-'A'+1 + 26*titleToNumber(s.substring(0,s.length-1))
    }
}
