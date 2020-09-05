class Solution17Jun {
    fun solve(board: Array<CharArray>) {
        val R = board.size
        if (R == 0) return
//        val C: Int = board[0].size
    }

    fun findAtLeast(c: IntArray, m: Int): Int {
      if (c.isEmpty()) return 0
      if (m > c.last()) return 0
      if (m <= c.first()) return c.size
      var l = 0
      var h = c.lastIndex
      while (l <h) {
        //
      }
      return h
    }

    fun hIndex(citations: IntArray): Int {
        var ans = -1
        val C = citations.size
        if (C == 0) return 0
        var l = 0
        var h = citations[C - 1]
        while (l < h) {
          val mid = l + (h - l) / 2
          val atLeast = findAtLeast(citations, mid)
          if (mid == atLeast) {
            ans = mid
            l = mid + 1
            continue
          }
          if (mid < atLeast) {
            l = mid + 1
          } else
            h = mid
        }
        if (ans == -1) return l
        return ans
    }
}
