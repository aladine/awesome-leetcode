package algoexpert

fun hasSingleCycle(array: List<Int>): Boolean {
    val times = array.size
    val m = MutableList<Int>(times) {0}
    var start = 0
    repeat(2*times){
        m[start] = m[start]+1
        start = (start+ array[start]) % times
        if(start<0) start+=times
    }

    return m.all { it == 2 }
}


fun isPalindrome(string: String): Boolean {
    return string.replace("""[\W]+""","").let { it==it.reversed() }
}

fun rightSmallerThan(array: List<Int>): List<Int> {
    // Write your code here.
//    val res = ArrayList<Int>()
//    val curr = ArrayList<Int>()
//    for(i in array.size-1 downTo 0){
//        val d = array[i]
//
//    }
    TODO("right smaller than")
}