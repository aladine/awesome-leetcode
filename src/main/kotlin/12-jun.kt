class RandomizedSet() {
    /** Initialize your data structure here. */
    var m = hashMapOf<Int, Int>() // hashMapOf<Int, Int>()
    var a = arrayListOf<Int>() // 	val list = arrayListOf<Int>()
    // val r = Random(5000)

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    fun insert(v: Int): Boolean {
        if (m.containsKey(v)) return false
        // or         valueIndexMap[`val`]?.let { return false }
        a.plus(v)
        m.set(v, a.size - 1)
        return true
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    fun remove(v: Int): Boolean {
        if (!m.containsKey(v)) return false
        a.set(m[v]!!, a[a.lastIndex])
        m.set(a[a.lastIndex], m[v]!!)
        a.dropLast(1)
        m.remove(v)
        return true
    }

    /** Get a random element from the set. */
    fun getRandom(): Int {
        val index = (Math.random() * a.size).toInt()
        return a.get(index)
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = RandomizedSet()
 * var param_1 = obj.insert(`val`)
 * var param_2 = obj.remove(`val`)
 * var param_3 = obj.getRandom()
 */
