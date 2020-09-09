import utility.TreeNode

class Solution08Sep {

    fun sumHelper(r: TreeNode?,  v: Int) : Int{
        if(r==null) return 0
        val newV = 2*v+r.`val`
        if(r.left==null && r.right==null) return newV
        return sumHelper(r.left, newV)+sumHelper(r.right, newV)
    }
    fun sumRootToLeaf(root: TreeNode?): Int {
        return sumHelper(root, 0)
    }
}