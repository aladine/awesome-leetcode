import org.junit.jupiter.api.Assertions.*
import org.junit.jupiter.api.Test
import org.junit.jupiter.api.assertAll

internal class Solution25AugTest{

    @Test
    fun testMincostTickets(){
        val s = Solution25Aug()
        assertAll( "minCostTickets",
            {assertEquals(11, s.mincostTickets(intArrayOf(1,4,6,7,8,20), intArrayOf(2,7,15)))},
            {assertEquals(17, s.mincostTickets(intArrayOf(1,2,3,4,5,6,7,8,9,10,30,31), intArrayOf(2,7,15)))}
        )
    }
}