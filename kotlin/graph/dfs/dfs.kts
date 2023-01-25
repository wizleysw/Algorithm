// https://www.acmicpc.net/problem/24479
// dfs

typealias Edges = Array<MutableList<Int>>

var V: Int = 0
var E: Int = 0

var S: Int = 0

var visited = intArrayOf()
var visitedCnt = 0

fun dfs(edges: Edges, currVertex: Int) {
    visitedCnt = visitedCnt.plus(1)
    visited[currVertex] = visitedCnt

    edges[currVertex].forEach { nextVertex ->
        if (visited[nextVertex] == 0) {
            dfs(edges, nextVertex)
        }
    }
}

fun main() {
    runCatching {
        val input = readln().split(" ").map { it.toInt() }

        V = input[0]
        E = input[1]
        S = input[2] - 1

        visited = IntArray(V)

        val edges = Edges(V) {
            mutableListOf()
        }

        repeat(E) {
            with(readln().split(" ").map { it.toInt() - 1 }) {
                val u = first()
                val v = last()

                edges[u].add(v)
                edges[v].add(u)
            }
        }

        edges.forEach {
            it.sort()
        }

        dfs(edges, S)

        visited.forEach {
            println(it)
        }
    }

}