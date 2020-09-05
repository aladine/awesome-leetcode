
class StreamChecker(words: Array<String>) {
    data class Node(var word: String? = null, val childNodes: MutableMap<Char, Node> = mutableMapOf())

    private val root = Node()

    fun insert(word: String) {
        var currentNode = root
        for (char in word) {
            if (currentNode.childNodes[char] == null) {
                currentNode.childNodes[char] = Node()
            }
            currentNode = currentNode.childNodes[char]!!
        }
        currentNode.word = word
    }

    private val maxLen: Int = words.maxBy { it.length }?.length ?: 0
    private var currQuery = ""
    init {
        words.forEach {
            insert(it.reversed())
        }
    }

    fun query(letter: Char): Boolean {
        currQuery = letter+currQuery
        if(currQuery.length > maxLen) currQuery = currQuery.substring(0,maxLen)
//        return currQuery.indices.any { root.search(currQuery.substring(0,it+1)) }
        var currentNode = root
        for (char in currQuery) {
            if (currentNode.childNodes[char] == null) {
                return false
            }
            currentNode = currentNode.childNodes[char]!!
            if(currentNode.word!=null) return true
        }
        return false
    }
//    private val dicts = words.toSet()
//    private val maxLen: Int = words.maxBy { it.length }?.length ?: 0
//    private val kw = ArrayDeque<String>()
//
//    init {
//        kw.add("")
//    }
//
//    fun query(letter: Char): Boolean {
//
//        println("\n\n$letter ${kw.size}")
//        repeat(kw.size){
//            kw.poll()?.let {
//                val newStr = it+letter
//                print(" $newStr")
//                if (newStr.length <= maxLen ){
//
//                    if (dicts.contains(newStr)) return true
//                    kw.addLast(newStr)
//
//                }
//            }
//        }
//        kw.offer("")
//        println("")
//        return false
//    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * var obj = StreamChecker(words)
 * var param_1 = obj.query(letter)
 */
