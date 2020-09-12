class Solution12Sep {
    private fun backtrack(idx: Int, array: IntArray, k: Int, n: Int, result: MutableList<List<Int>>){
        if(idx== k){
            if (n==0) result.add(array.toList())
            return
        }

        val minPossible = if (idx == 0) 1 else array[idx-1]+1
        val maxPossible =  8+k-idx
        // idx: 0, 1, .. k-1
        // maxPossible:   9
        if(idx!= 0 && array[idx-1]==9){
            return
        }
        if(minPossible > maxPossible) return

         for (i in minPossible..maxPossible){
             array[idx] = i
             backtrack(idx+1, array, k, n-i, result)
         }
    }

    fun combinationSum3(k: Int, n: Int): List<List<Int>> {
        val res = mutableListOf<List<Int>>()
        val arr = IntArray(k)
        backtrack(0, arr, k ,n ,res)
        return res.toList()
    }
}
