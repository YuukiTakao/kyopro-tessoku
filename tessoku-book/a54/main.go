package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

func main() {
	sc.Buffer(make([]byte, 128), 500000)
	sc.Split(bufio.ScanWords)
	q := scanInt()
	// fmt.Printf("%d\n", q)

	grades := make(map[string]int)
	for i := 0; i < q; i++ {
		query := scanInt()
		if query == 1 {
			s := scanText()
			grades[s] = scanInt()
		} else if query == 2 {
			s := scanText()
			fmt.Printf("%d\n", grades[s])
		} else {
			log.Fatalln("制約エラー！")
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
