
class Solution14Jun {
    fun findCheapestPrice(n: Int, flights: Array<IntArray>, src: Int, dst: Int, K: Int): Int {
        val adjList: HashMap<Int, HashSet<Pair<Int, Int>>> = HashMap()
        for (f in flights) {
            adjList
                .computeIfAbsent(f[0]) { HashSet() }
                .add(Pair<Int, Int>(f[1], f[2]))
        }
        var costs = Array(n, { _ -> -1 })
        costs[src] = 0
        val queue = mutableListOf<Int>()
        queue.add(src)
        var steps = K + 1
        while (!queue.isEmpty()) {
            // println("Step: $steps")
            if (steps-- == 0) return costs[dst]
            val currSize = queue.size
            //  println("size $currSize")
            val tmp = costs.clone()
            (0 until currSize).forEach {
                val v = queue.removeAt(0)
                println("process $v")
                adjList.get(v)?.let {
                    for ((vertex, price) in it) {
                        println("vertex $vertex, price $price")
                        queue.add(vertex)
                        if ((tmp[vertex] == -1) || tmp[vertex] > costs[v] + price)
                        tmp[vertex] = costs[v] + price
                    }
                }
            }
            costs = tmp
        }
        return costs[dst]
    }
}
/*
 fun findCheapestPrice(n: Int, flights: Array<IntArray>, src: Int, dst: Int, k: Int): Int {
        // reorganize flights, ordered by index of departure city
        val cities = mutableListOf<MutableList<IntArray>>()
        for (i in 0 until n) {
            cities.add(mutableListOf<IntArray>())
        }
        for (flight in flights) {
            cities[flight[0]].add(flight)
        }
        var res = -1
        // create a queue of [current location, cost so far, number of stops so far] IntArray states
        val queue = LinkedList<IntArray>()
        queue.add(intArrayOf(src, 0, 0))
        while (!queue.isEmpty()) {
            val state = queue.poll()
            if (res == -1 || state[1] < res) {
                if (state[0] == dst) {
                    // if we're at the destination, update the best total cost (res).
                    res = state[1]
                } else if (state[2] <= k) {
                    // if we can still take another flight, add all flights from the current city.
                    for (flight in cities[state[0]]) {
                        queue.add(intArrayOf(flight[1], state[1] + flight[2], state[2] + 1))
                    }
                }
            }
        }
        return res
    } */
