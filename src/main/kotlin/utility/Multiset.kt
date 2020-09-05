package utility

/* A class representing a Mutable MultiSet */
class MultiSet<E> {
    /* List to store distinct values */
    private var values: MutableList<E> = ArrayList()

    /* List to store counts of distinct values */
    private var frequency: MutableList<Int> = ArrayList()

    /* Error Message */
    private val ERROR_MSG = "Count cannot be negative: "

    /**
     * Adds an element to this multiset specified number of times
     *
     * @param element The element to be added
     * @param count The number of times
     * @return The previous count of the element
     */
    fun add(element: E, count: Int): Int {
        require(count >= 0) { ERROR_MSG + count }
        val index = values.indexOf(element)
        var prevCount = 0
        if (index != -1) {
            prevCount = frequency[index]
            frequency[index] = prevCount + count
        } else if (count != 0) {
            values.add(element)
            frequency.add(count)
        }
        return prevCount
    }

    /**
     * Adds specified element to this multiset
     *
     * @param element The element to be added
     * @return true always
     */
    fun add(element: E): Boolean {
        return add(element, 1) >= 0
    }

    /**
     * Adds all elements in the specified collection to this multiset
     *
     * @param c Collection containing elements to be added
     * @return true if all elements are added to this multiset
     */
    fun addAll(c: Collection<E>): Boolean {
        for (element in c) add(element, 1)
        return true
    }

    /**
     * Adds all elements in the specified array to this multiset
     *
     * @param arr An array containing elements to be added
     */
    fun addAll(vararg arr: E) {
        for (element in arr) add(element, 1)
    }

    /**
     * Performs the given action for each element of the Iterable,
     * including duplicates
     *
     * @param action The action to be performed for each element
     */
    fun forEach(action: (E) -> Unit) {
        val all: MutableList<E> = ArrayList()
        for (i in values.indices) for (j in 0 until frequency[i]) all.add(values[i])
        all.forEach(action)
    }

    /**
     * Removes a single occurrence of specified element from this multiset
     *
     * @param element The element to removed
     * @return true if an occurrence was found and removed
     */
    fun remove(element: Any?): Boolean {
        return remove(element, 1) > 0
    }

    /**
     * Removes a specified number of occurrences of the specified element
     * from this multiset
     *
     * @param element The element to removed
     * @param count The number of occurrences to be removed
     * @return The previous count
     */
    fun remove(element: Any?, count: Int): Int {
        require(count >= 0) { ERROR_MSG + count }
        val index = values.indexOf(element)
        if (index == -1) return 0
        val prevCount = frequency[index]
        if (prevCount > count) {
            frequency[index] = prevCount - count
        } else {
            values.removeAt(index)
            frequency.removeAt(index)
        }
        return prevCount
    }

    /**
     * Check if this multiset contains at least one occurrence of the
     * specified element
     *
     * @param element The element to be checked
     * @return true if this multiset contains at least one occurrence
     * of the element
     */
    operator fun contains(element: Any?): Boolean {
        return values.contains(element)
    }

    /**
     * Update the frequency of an element to the specified count or
     * add element to this multiset if not present
     *
     * @param element The element to be updated
     * @param count The new count
     * @return The previous count
     */
    fun setCount(element: E, count: Int): Int {
        require(count >= 0) { ERROR_MSG + count }
        if (count == 0) remove(element)
        val index = values.indexOf(element)
        if (index == -1) return add(element, count)
        val prevCount = frequency[index]
        frequency[index] = count
        return prevCount
    }

    /**
     * Find the frequency of an element in this multiset
     *
     * @param element The element to be counted
     * @return The frequency of the element
     */
    fun count(element: Any?): Int {
        val index = values.indexOf(element)
        return if (index == -1) 0 else frequency[index]
    }

    /**
     * @return A view of the set of distinct elements in this multiset
     */
    fun elementSet(): Set<E> {
        return values.toSet()
    }

    /**
     * @return true if this multiset is empty
     */
    val isEmpty: Boolean
        get() = values.size == 0

    /**
     * @return Total number of elements in this multiset, including duplicates
     */
    fun size(): Int {
        var size = 0
        for (i in frequency) {
            size += i
        }
        return size
    }

    /**
     * @return String representation of this multiset
     */
    override fun toString(): String {
        val sb = StringBuilder("[")
        for (i in values.indices) {
            sb.append(values[i])
            if (frequency[i] > 1) sb.append(" x ").append(frequency[i])
            if (i != values.size - 1) sb.append(", ")
        }
        return sb.append("]").toString()
    }
}
//
//fun main() {
//    val multiset: MultiSet<String?> = MultiSet()
//
//    multiset.add("USA")
//    multiset.add("Japan", 2)
//    multiset.addAll("India", "China")
//    multiset.addAll(listOf("USA", "India", "China", "Japan"))
//    println(multiset)
//
//    multiset.remove("China")
//    multiset.remove("Japan", 2)
//    println(multiset)
//
//    multiset.setCount("USA", 4)
//    multiset.setCount("Japan", 5)
//    multiset.setCount("Mexico", 3)
//    multiset.setCount("China", 0)
//    println(multiset)
//}