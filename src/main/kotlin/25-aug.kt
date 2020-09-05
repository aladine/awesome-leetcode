import kotlin.math.*

class Solution25Aug {
    fun mincostTickets(days: IntArray, costs: IntArray): Int {
        val daySet = days.toSet()

        val costDay = costs[0]
        val costWeek = costs[1]
        val costMonth = costs[2]
        val n = 366

        val expenses = Array<Int>(n) { 0 } // IntArray(n + 1)
        for (d in 1 until 366){
            if(!daySet.contains(d)){
                if(d!=0) expenses[d] = expenses[d-1]
                else expenses[0] = 0
                continue
            }
            expenses[d] = min(min(expenses[d-1] + costDay, expenses[max(0, d - 7)]+costWeek), expenses[max(0, d - 30)] +costMonth)
        }
        return expenses.last()
    }
}
