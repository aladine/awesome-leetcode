class Solution01Aug {
    fun detectCapitalUse(word: String): Boolean {
        if(word.first().isUpperCase()){
            return word.all { it.isUpperCase() } || word.substring(1).all { it.isLowerCase() }
        }

        return word.all {it.isLowerCase()}
    }
}