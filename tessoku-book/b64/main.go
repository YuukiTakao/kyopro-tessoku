package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"math"
	"os"
	"strconv"
)

func bufInit() {
	sc.Buffer(make([]byte, 128), 500000)
	sc.Split(bufio.ScanWords)
}

type Edge struct {
	to       int
	priority int
}
type AdjacencyList struct {
	nodes map[int][]Edge
	prev  []int
}

func NewAdlist(v_count int) AdjacencyList {
	g := AdjacencyList{
		nodes: make(map[int][]Edge, v_count),
		prev:  make([]int, v_count+1), // 1 indexed
	}
	return g
}
func (g AdjacencyList) Push(key int, v Edge) {
	g.nodes[key] = append(g.nodes[key], v)
}
func BuildGraph(n, m int) AdjacencyList {
	g := NewAdlist(n)
	for i := 0; i < m; i++ {
		a := scanInt()
		b := scanInt()
		cost := scanInt()
		g.Push(a, Edge{to: b, priority: cost})
		g.Push(b, Edge{to: a, priority: cost})
	}
	return g
}

type Node struct {
	// pq
	id       int
	from     int
	priority int
}
type PriorityQueue []*Node

func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].priority < pq[j].priority
}
func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}
func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(*Node)
	*pq = append(*pq, item)
}
func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil // avoid memory leak
	*pq = old[0 : n-1]
	return item
}
func (g *AdjacencyList) Dijkstra(n, start int) []int {
	pq := new(PriorityQueue)
	heap.Init(pq)
	heap.Push(pq, &Node{id: start, priority: 0, from: -1})
	distances := make([]int, n+start)
	inf := int(math.Pow10(18))
	for i := start; i <= n; i++ {
		distances[i] = inf
		g.prev[i] = -1
	}
	for pq.Len() > 0 {
		node := heap.Pop(pq).(*Node)
		currentId := node.id
		cost := node.priority
		if distances[currentId] <= cost {
			continue
		}
		g.prev[currentId] = node.from
		distances[currentId] = cost
		for _, next := range g.nodes[currentId] {
			heap.Push(pq, &Node{
				id:       next.to,
				from:     currentId,
				priority: next.priority + cost,
			})
		}
	}
	return distances
}
func main() {
	bufInit()
	n := scanInt()
	m := scanInt()

	g := BuildGraph(n, m)
	g.Dijkstra(n, 1)
	g.prev[1] = -1

	ans := make([]int, 0)
	ans = append(ans, n)
	p := g.prev[n]
	ans = append(ans, p)
	for {
		p = g.prev[p]
		if p == -1 {
			break
		}
		ans = append(ans, p)
	}
	for i := len(ans) - 1; i >= 0; i-- {
		fmt.Printf("%d ", ans[i])
	}
	fmt.Printf("\n")
}

var sc = bufio.NewScanner(os.Stdin)

func scanInts(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = scanInt()
	}
	return a
}
func scanInt() int {
	sc.Scan()
	return atoi(sc.Text())
}
func atoi(nStr string) int {
	i, err := strconv.Atoi(nStr)
	if err != nil {
		panic(err)
	}
	return i
}
func scanText() string {
	sc.Scan()
	return sc.Text()
}
