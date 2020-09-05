import org.junit.jupiter.api.AfterEach
import org.junit.jupiter.api.BeforeEach
import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class Solution18AugTest {

    @BeforeEach
    fun setUp() {
        println("run setup")
    }

    @AfterEach
    fun tearDown() {
        println("run teardown")
    }

    @Test
    fun numsSameConsecDiff() {
        val s = Solution18Aug()
        assertArrayEquals(intArrayOf(181,292,707,818,929), s.numsSameConsecDiff(3,7))
        assertArrayEquals(intArrayOf(0,1,2,3,4,5,6,7,8,9), s.numsSameConsecDiff(1,0))
        assertArrayEquals(intArrayOf(11,22,33,44,55,66,77,88,99), s.numsSameConsecDiff(2,0))
    }
}