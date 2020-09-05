import org.hamcrest.CoreMatchers
import org.hamcrest.MatcherAssert.assertThat
import org.junit.jupiter.api.Test

internal class Solution05SepTest {

    @Test
    fun partitionLabels() {
        val s = Solution05Sep()
        assertThat(s.partitionLabels("ababcbacadefegdehijhklij"), CoreMatchers.hasItems(9,7,8))
    }
}