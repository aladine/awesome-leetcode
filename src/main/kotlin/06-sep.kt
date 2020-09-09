class Solution06Sep {
    data class Coor(val x: Int, val y: Int)
    fun largestOverlap(A: Array<IntArray>, B: Array<IntArray>): Int {
        val aOnes= mutableListOf<Coor>()
        val bOnes= mutableListOf<Coor>()
        val vectors= mutableListOf<Coor>()
        val r = A.size
        val c = A[0].size
        for (i in A.indices){
            for (j in A[0].indices){
                if(A[i][j] == 1) aOnes.add(Coor(i,j))
                if(B[i][j] == 1) bOnes.add(Coor(i,j))
            }
        }

        for (i in aOnes){
            for (j in bOnes){
                vectors.add(Coor(j.x-i.x, j.y-i.y))
            }
        }

        if (vectors.isEmpty()) return 0

        return vectors.groupBy { it }.maxBy { it.value.size}!!.value.size
    }
}
