package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc.Buffer(make([]byte, 128), 500000)
	sc.Split(bufio.ScanWords)
	q := scanInt()
	// fmt.Printf("%d\n", q)

	cards := make(map[int]int)
	for i := 0; i < q; i++ {
		query := scanInt()

		x := scanInt()
		if query == 1 {
			cards[x] = x
		} else if query == 2 {
			delete(cards, x)
		} else if query == 3 {
			tmp := int(10e12)
			min := tmp
			for _, card := range cards {
				if card < x {
					continue
				}
				if min > card {
					min = card
				}
			}
			if min == tmp {
				fmt.Printf("%d\n", -1)
			} else {
				fmt.Printf("%d\n", min)
			}
		}
	}
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
