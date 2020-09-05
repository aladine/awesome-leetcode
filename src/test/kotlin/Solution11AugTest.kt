import org.junit.Test

class Solution11AugTest {

    @Test
    fun testHIndex(){
        val s = Solution11Aug()
        assert(s.hIndex(intArrayOf(0)) == 0)
        assert(s.hIndex(intArrayOf(3, 0, 6, 1, 5)) == 3)
        assert(s.hIndex(intArrayOf(1)) == 1)
        assert(s.hIndex(intArrayOf(11, 15)) == 2)
        assert(s.hIndex(intArrayOf(1, 2)) == 1)
        assert(s.hIndex(intArrayOf(2)) == 1)
    }
}