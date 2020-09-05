
class CombinationIterator(characters: String, combinationLength: Int) {
    private var counter = 0
    private val allCombs: MutableList<String> = mutableListOf()
    private val n = combinationLength
    init {
        for (i in 0 until (1 shl characters.length)){
            if (countOneBits(i) == n){
                var cand = ""
                for (j in characters.indices){
                    if ( (i shr j) % 2 != 0){
                        cand += characters[j]
                    }
                }
                allCombs.add(cand)
            }
        }
        allCombs.sort()
    }

    private fun countOneBits(i: Int): Int {
        var res = 0
        var tmp = i
        while(tmp > 0){
            if(tmp%2==1) res++
            tmp /= 2
        }
        return res
    }

    fun next(): String {
        if(!hasNext()) return ""
        counter++
        return allCombs[counter-1]
    }

    fun hasNext(): Boolean = counter != allCombs.size
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * var obj = CombinationIterator(characters, combinationLength)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */

/* lass CombinationIterator(
    private val characters: String,
    private val combinationLength: Int
) {

    private val maxIndex: Int = characters.length - 1
    private var odometer = IntArray(combinationLength) { it }
    private var next: String? = null

    init {
        setNext(true)
    }

    fun next(): String? {
        val current: String? = next
        setNext()
        return current
    }

    fun hasNext(): Boolean = next != null

    private fun setNext(first: Boolean = false) {
        next = when (first || rollOdometer()) {
            true -> kotlin.runCatching {
                odometer.map { characters[it] }
                    .joinToString("") { it.toString() }
            }.getOrNull()
            else -> null
        }
    }

    private fun rollOdometer(position: Int = combinationLength - 1): Boolean {
        val currentMile: Int = odometer[position]
        if (position == 0 && currentMile == characters.length - combinationLength) {
            return false
        }
        if (currentMile == maxIndex - (odometer.size - 1 - position)) {
            rollOdometer(position - 1).also {
                if (it) {
                    odometer[position] = odometer[position - 1] + 1
                }
                return it
            }
        } else {
            odometer[position] = currentMile + 1
            return true
        }
    }
}*/