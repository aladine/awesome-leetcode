import java.lang.Math.max
import java.util.ArrayDeque
import utility.TreeNode

class Solution05Sep {
    fun partitionLabels(s: String): List<Int> {
        val ed = Array<Int>(26) { -1 }
        val res = mutableListOf<Int>()
        for ((i, c) in s.toCharArray().withIndex()) {
            ed[c - 'a'] = i
        }
        var curr = -1
        for (i in s.indices) {
            curr = max(curr, ed[s[i] - 'a'])
            if (curr == i) {
                res.add(i + 1)
                curr = -1
            }
        }

        for (i in res.size - 1 downTo 1) {
            res[i] = res[i] - res[i - 1]
        }

        return res.toList()
    }


    fun traverseTree(r: TreeNode?): List<Int>{
        if(r==null) return emptyList()

        val l = mutableListOf<Int>()
        val st = ArrayDeque<TreeNode>() //         val stack: Stack<TreeNode> = Stack()
        st.push(r)
        while(st.isNotEmpty()){
            val ele = st.poll()!!
            l.add(ele.`val`)
            if (ele.left!=null) st.push(ele.left!!)
            if (ele.right!=null) st.push(ele.right!!)
        }

        return l.toList()
    }

    fun getAllElements(root1: TreeNode?, root2: TreeNode?): List<Int> {
        return traverseTree(root1).plus(traverseTree(root2)).sorted()
    }
}