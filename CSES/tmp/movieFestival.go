package main

import (
	"fmt"
	"sort"
)

func sol(movies [][]int) int {
	sort.Slice(movies, func(i, j int) bool {
		return movies[i][1] < movies[j][1]
	})
	cur, watch := 0, 0
	for _, mov := range movies {
		if mov[0] >= cur {
			watch++
			cur = mov[1]
		}
	}
	return watch
}

func main() {
	var n int
	fmt.Scan(&n)
	movies := [][]int{}
	for i := 0; i < n; i++ {
		var start, end int
		fmt.Scanf("%d %d", &start, &end)
		movies = append(movies, []int{start, end})
	}
	fmt.Println(sol(movies))
}
