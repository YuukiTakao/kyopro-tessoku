package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func isLteMiddle(a []int, n, k, middle int) bool {
	sum := 0
	for i := 0; i < n; i++ {
		sum += middle / a[i]
	}
	if sum >= k {
		return true
	} else {
		return false
	}
}

func main() {
	sc.Buffer(make([]byte, 128), 500000)
	sc.Split(bufio.ScanWords)
	n := scanInt()
	k := scanInt()
	// fmt.Printf("%d %d\n", n, k)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = scanInt()
	}

	left := 1
	right := int(math.Pow10(10))
	for left < right {
		middle := (left + right) / 2
		if isLteMiddle(a, n, k, middle) {
			right = middle
		} else {
			left = middle + 1
		}
	}
	fmt.Printf("%d\n", left)
}

var sc = bufio.NewScanner(os.Stdin)

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
