import kotlin.math.sqrt

class Solution17Aug{
    fun distributeCandies(candies: Int, num_people: Int): IntArray {
        val ans = IntArray(num_people){0}
        val m = sqrt(8*candies.toFloat()+1)
        val mm = ((m-1)/2).toInt()
        for (i in 0 until mm){
            ans[i% num_people] += i+1
        }
        ans[mm % num_people] += candies - mm * (mm + 1) / 2;
        return ans;
    }
}