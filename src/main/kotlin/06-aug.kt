class WordDictionary() {

    /** Initialize your data structure here. */
    data class Node(var word: String? = null, val childNodes : MutableMap<Char, Node> = mutableMapOf())
    private val root = Node()
    
    /** Adds a word into the data structure. */
    fun addWord(word: String) {
        var curr = root
        for(c in word){
            if (curr.childNodes[c] == null) {
                curr.childNodes[c] = Node()
            }
            curr = curr.childNodes[c]!!
        }
        curr.word = word
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
   fun search(word: String): Boolean {
        return searchPos(word, 0, root)
   }

    fun searchPos(word: String, pos: Int, n: Node): Boolean {
        if(pos == word.length) return n.word != null

        val char = word[pos]
        if(char == '.'){
            for(i in 'a'..'z'){
                n.childNodes[i]?.let {
                    if(searchPos(word, pos+1, it)) return true
                }
            }
            return false
        }
            if (n.childNodes[char] == null) {
                return false
            }


        return searchPos(word, pos+1, n.childNodes[char]!!)
    }

}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * var obj = WordDictionary()
 * obj.addWord(word)
 * var param_2 = obj.search(word)
 */

class AugSolution {
    fun findDuplicates(nums: IntArray): List<Int> {
        return nums.groupBy { it }.filter { it.value.size == 2 }.keys.toList()
    }
}