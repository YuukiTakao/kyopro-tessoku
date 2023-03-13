package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"math"
	"os"
	"strconv"
)

type PQType *AlType
type PriorityQueue []PQType // Item

func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].priority < pq[j].priority
}
func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}
func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(PQType)
	item.index = n
	*pq = append(*pq, item)
}
func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil  // avoid memory leak
	item.index = -1 // for safety
	*pq = old[0 : n-1]
	return item
}
func (pq *PriorityQueue) update(item PQType, value int, priority int) {
	item.value = value
	item.priority = priority
	heap.Fix(pq, item.index)
}

type AlType struct {
	// a int
	// pq
	value    int
	priority int
	index    int
}
type AdjacencyList struct {
	all     map[int][]AlType
	paths   [][]int
	path    []int
	visited []bool
}

func NewAdlist(v_count int) AdjacencyList {
	al := AdjacencyList{
		all:     make(map[int][]AlType, v_count),
		paths:   make([][]int, 0, 2),
		path:    make([]int, 0, 2),
		visited: make([]bool, v_count+1), // 1 indexed
	}
	return al
}
func (al AdjacencyList) Push(key int, v AlType) {
	al.all[key] = append(al.all[key], v)
}

func main() {
	bufInit()
	n := scanInt()
	m := scanInt()

	al := NewAdlist(n)
	for i := 1; i <= m; i++ {
		a := scanInt()
		b := scanInt()
		c := scanInt()
		al.Push(a, AlType{value: b, priority: c})
		al.Push(b, AlType{value: a, priority: c})
	}

	current := make([]int, n+1)
	inf := int(math.Pow10(18))
	for i := 1; i <= n; i++ {
		current[i] = inf
	}
	current[1] = 0
	decided := make([]bool, n+1)
	pq := PriorityQueue{}
	heap.Push(&pq, &AlType{value: 1, priority: 0, index: 0})
	for pq.Len() > 0 {
		v := heap.Pop(&pq).(*AlType)
		pos := v.value
		if decided[pos] {
			continue
		}
		decided[pos] = true
		for i := 0; i < len(al.all[pos]); i++ {
			next := al.all[pos][i].value
			cost := al.all[pos][i].priority
			if current[next] > current[pos]+cost {
				current[next] = current[pos] + cost
			}
			heap.Push(&pq, &AlType{value: next, priority: current[next]})
		}
	}
	for i := 1; i <= n; i++ {
		if current[i] == inf {
			fmt.Printf("%d\n", -1)
		} else {
			fmt.Printf("%d\n", current[i])
		}
	}
}
func bufInit() {
	sc.Buffer(make([]byte, 128), 500000)
	sc.Split(bufio.ScanWords)
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
