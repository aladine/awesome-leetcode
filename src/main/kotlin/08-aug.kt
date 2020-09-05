
class Solution08Aug {
    private var ans = 0
    private fun pathSumHelper(root: TreeNode, sum: Int, s: MutableMap<Int,Int>){
        val v = root.`val`
        val newS = mutableMapOf<Int,Int>()
        s.forEach {
            newS[it.key+v] = it.value
        }

        newS[v] = newS.getOrDefault(v, 0)+ 1
        if(newS.contains(sum)) {
            ans+= newS[sum]!!
            if(newS[sum]==1) newS.remove(sum)
            else newS[sum] = newS[sum]!!-1
        }
        root.left?.let{
            pathSumHelper(it, sum, newS)
        }
        root.right?.let{
            pathSumHelper(it, sum, newS)
        }
    }

    //  Path Sum III
    fun pathSum(root: TreeNode?, sum: Int): Int {
        if(root==null) return 0
        val sumSet = mutableMapOf<Int,Int>()
        ans = 0
        pathSumHelper(root, sum, sumSet)

        return ans
    }
}
//
//fun main() {
//    val s = Solution08Aug()
//    s.pathSum()
//[0,0,-3,3,2,null,11,3,-3,null,1]
//0
//}

/*
fun pathSum(root: TreeNode?, sum: Int): Int {
    val preSum: HashMap<Int?, Int?> = HashMap<Any?, Any?>()
    preSum[0] = 1
    return helper(root, 0, sum, preSum)
}

fun helper(root: TreeNode?, currSum: Int, target: Int, preSum: HashMap<Int?, Int>): Int {
    var currSum = currSum
    if (root == null) {
        return 0
    }
    currSum += root.`val`
    var res = preSum.getOrDefault(currSum - target, 0)
    preSum[currSum] = preSum.getOrDefault(currSum, 0) + 1
    res += helper(root.left, currSum, target, preSum) + helper(root.right, currSum, target, preSum)
    preSum[currSum] = preSum[currSum]!! - 1
    return res
}*/

/*
fun pathSum(root: TreeNode?, target: Int): Int {
        val sumPath = mutableMapOf(0 to 1)
        fun pathSumHelper(node: TreeNode?, currentSum: Int): Int {
            node ?: return 0
            val sum = currentSum + node.`val`
            var totalPath = sumPath[sum - target] ?: 0
            sumPath.compute(sum) { _, value -> (value ?: 0) + 1 }
            totalPath += pathSumHelper(node.left, sum) + pathSumHelper(node.right, sum)
            sumPath.compute(sum) { _, value -> (value ?: 1) - 1 }
            return totalPath
        }
        return pathSumHelper(root, 0)
    }
*/

/*
private fun preorder(node: TreeNode?, sum: Int, target: Int) {
        if(node == null) return
        var currSum = sum + node.`val`
        if(currSum == target) count++
        if(map.contains(currSum - target)) {
            count += map[currSum - target]!!
        }
        map[currSum] = map.getOrDefault(currSum, 0) + 1
        preorder(node.left, currSum, target)
        preorder(node.right, currSum, target)
        map[currSum] = map[currSum]!! - 1
    }
*/
