/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
import java.util.*


class Aug07Solution {

    var offset = 0
    fun dfs(n: TreeNode?, x: Int, y: Int, map: HashMap<Int,ArrayList<Pair<Int,Int>>>){
        if(n==null) return
        offset = minOf(x, offset)
        val l = map.getOrDefault(x,ArrayList<Pair<Int,Int>>())
        l.add(Pair(y, n.`val`))
        map[x] = l
        n.left?.let {
           dfs(it, x-1, y+1, map)
       }
       n.right?.let {
           dfs(it, x+1, y+1, map)
       }
    }
    fun verticalTraversal(root: TreeNode?): List<List<Int>> {
        if (root == null) return emptyList()
        val map = HashMap<Int,ArrayList<Pair<Int,Int>>>()
        dfs(root,0,0,map)
        val res = Array<List<Int>>(map.size) {listOf<Int>()}

        for(entry in map.entries) {
            res[entry.key-offset] = entry.value.sortedWith(Comparator{t1,t2 ->
                if(t1.first==t2.first) t1.second-t2.second else t1.first-t2.first}).map{it.second}.toList()
        }
        return res.toList()
    }



//    fun verticalTraversal(root: TreeNode?): List<List<Int>> {
//        if (root == null) return emptyList()
//        val m : SortedMap<Int, Array<Int>> = TreeMap<Int, Array<Int>>()
//        val curr: Queue<Pair<TreeNode, Int>> = LinkedList<Pair<TreeNode, Int>>()
//        curr.offer(Pair(root, 0))
//        while (curr.isNotEmpty()){
//           val tmpMap: MutableMap<Int, MutableList<Int>> = mutableMapOf()
//            repeat(curr.size){
//               val ele = curr.poll()!!
//               val rank = ele.second
//               val node = ele.first
//               if(!tmpMap.containsKey(rank)) tmpMap[rank] = emptyArray()
//               tmpMap[rank]?.plus(node.`val`)
//               node.left?.let {
//                   curr.offer(Pair(it, rank-1))
//               }
//               node.right?.let {
//                   curr.offer(Pair(it, rank+1))
//               }
//           }
//           tmpMap.forEach { (t, u) ->
//               val v: Array<Int> = m.getOrDefault(t, emptyArray())
////               println(v.size)
////               println(u.size)
//               for (el in u) v.plus(el)
//               print(v.size)
//               m[t] = v
//           }
//        }
//        return m.map { it.value.toList() }.toList()
//    }
}

class TreeNode(var `val`: Int) {
        var left: TreeNode? = null
       var right: TreeNode? = null
     }
