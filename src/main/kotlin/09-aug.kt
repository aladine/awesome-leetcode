import java.util.*
typealias Pii = Pair<Int, Int>

class Solution09Aug{
    fun orangesRotting(grid: Array<IntArray>): Int {
        var res = 0
        var totalFresh = 0

        val q: Queue<Pii> = LinkedList<Pii>() //val queue = LinkedList<IntArray>()
        val n= grid.size
        val m = grid[0].size

        for (i in 0 until n) {
            for (j in 0 until m) {
                when(grid[i][j]){
                    1 -> ++totalFresh
                    2 -> q.offer(i to j)
                }
            }
        }

        // if there is no rotten orange, we can return
        if (q.isEmpty() ) return if (totalFresh > 0) -1 else 0

        while (q.isNotEmpty()){
            var hasChanges = false // indicate there is a change in this round
            repeat(q.size) {
                val o = q.poll()
                // check all the adjacent oranges
                for ((i, j) in dirs) {
                    val x = o.first + i
                    val y = o.second + j
                    if (isValid(x, n, y, m) && grid[x][y] == 1) {
                        grid[x][y] = 2
                        q.offer(x to y)
                        --totalFresh
                        hasChanges = true
                    }
                }
            }

            if(hasChanges) res++
        }

        return if (totalFresh>0) -1 else res
    }

    private fun isValid(x: Int, n: Int, y: Int, m: Int) = (x in 0 until n) && (y in 0 until m)

    companion object {
        val dirs = listOf(Pair(0,-1),Pair(0,1),Pair(-1,0),Pair(1,0))
        // val directions = arrayOf(intArrayOf(0, 1), intArrayOf(0, -1), intArrayOf(1, 0), intArrayOf(-1, 0))
    }
}
