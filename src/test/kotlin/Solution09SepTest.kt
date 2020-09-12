import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*
import org.junit.jupiter.api.assertAll

internal class Solution09SepTest {

    @Test
    fun compareVersion() {
        val s = Solution09Sep()
        assertAll("compareVersion",
            {assertEquals(1, s.compareVersion("1.0.1", "1"))},
            {assertEquals(-1, s.compareVersion("7.5.2.4", "7.5.3"))},
            {assertEquals(0, s.compareVersion("1.1", "1.001"))},
            {assertEquals(0, s.compareVersion("1.0.0", "1.0"))}
        )
    }
}