class Solution07Sep {
    fun wordPattern(pattern: String, str: String): Boolean {
        val tokens = str.split(" ")
        if (tokens.size != pattern.length) return false

        val m = mutableMapOf<Char, String>()
        for (i in pattern.indices) {
            val c = pattern[i]
            if (m.containsKey(c)) {
                if (m[c] != tokens[i]) return false
            } else m[c] = tokens[i]
        }
        return tokens.groupBy { it }.size == m.size
    }
}