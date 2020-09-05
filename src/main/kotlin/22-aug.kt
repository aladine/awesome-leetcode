class Solution(rects: Array<IntArray>) {
    private var totalPoints:Int = 0
    private var prefixSum : List<Int> = mutableListOf()
    private var rectangles:List<IntArray>  = mutableListOf()

    init {
        val areas = rects.map { (it[2]-it[0]+1)*(it[3]-it[1]+1) }
        totalPoints = areas.sum()
        rectangles = rects.toList()
        prefixSum = prefixSumsFunctional(areas)
        println(prefixSum)
    }

    fun prefixSumsFunctional(numbers:List<Int>): List<Int>{
        return     generateSequence(numbers.fold(Any() to 0) { stack, value ->
            stack to stack.second + value
        }) { it.first as Pair<Any, Int> }
            .map { it.second }
            .take(numbers.size)
            .toList().asReversed()
    }
    fun pick(): IntArray {
        val index = (Math.random() * totalPoints).toInt()
        var i = 0
        while (i < prefixSum.size){
           if(index < prefixSum[i]) break
            i++
        }

        var currIdx = index
        if(i!=0) currIdx = index - prefixSum[i-1]
        val r = rectangles[i]
        val width = r[3] - r[1]+1
        val x = r[0]+currIdx / width
        val y = r[1]+currIdx % width
        return intArrayOf(x, y)
    }
}
