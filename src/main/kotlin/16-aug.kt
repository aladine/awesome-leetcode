import java.lang.Integer.max

class Solution16Aug {
    fun maxProfit(prices: IntArray): Int {
        val size = prices.size
        val balance = Array<Int>(size + 1) { Int.MIN_VALUE }
        val profit = Array<Int>(size + 1) { 0 }


        for (i in prices.indices) {
            for (j in 1..2) {
                balance[j] = max(profit[j - 1] - prices[i], balance[j]) // whether to buy at prices[i]
                profit[j] = max(balance[j] + prices[i], profit[j]) // whether to sell at prices[i]
            }
        }
        return profit.last()
    }
}
