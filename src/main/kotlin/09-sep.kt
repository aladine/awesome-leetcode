class Solution09Sep {
    fun compareVersion(version1: String, version2: String): Int {
        val tokens1 = version1.split(".").map { it.toInt() }.toMutableList()
        val tokens2 = version2.split(".").map { it.toInt() }.toMutableList()
        if (tokens1.size < tokens2.size){
            repeat(tokens2.size-tokens1.size){
                tokens1.add(0)
            }
        }
        if (tokens1.size > tokens2.size){
            repeat(tokens1.size-tokens2.size){
                tokens2.add(0)
            }
        }
        for (i in tokens1.indices){
            when{
                tokens1[i] < tokens2[i] -> return -1
                tokens1[i] > tokens2[i] -> return 1
            }
        }
        return 0
    }
}