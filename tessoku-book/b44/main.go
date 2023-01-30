package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

func printWithSpace(s2d [][]int) {
	for _, s := range s2d {
		for j, v := range s {
			if j >= 1 {
				fmt.Printf(" ")
			}
			fmt.Printf("%d", v)
		}
		fmt.Printf("\n")
	}
}
func main() {
	sc.Buffer(make([]byte, 128), 500000)
	sc.Split(bufio.ScanWords)
	n := scanInt()
	// fmt.Printf("%d\n", n)

	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, n)
		for j := 0; j < n; j++ {
			a[i][j] = scanInt()
		}
	}

	// printWithSpace(a)

	q := scanInt()
	for i := 0; i < q; i++ {
		query := scanInt()
		x, y := scanInt()-1, scanInt()-1
		if query == 1 {
			a[y], a[x] = a[x], a[y]
		} else if query == 2 {
			fmt.Printf("%d\n", a[x][y])
		} else {
			log.Fatalln("制約エラー")
		}
	}
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
