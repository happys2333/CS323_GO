package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	if len(os.Args) < 2 {
		fmt.Println("Please input a file")
		os.Exit(-1)
	}
	inputFileName := os.Args[1]
	outputFileName := strings.Split(inputFileName, ".splc")[0] + ".out"
	fmt.Println(outputFileName)
	inputFile, err := os.OpenFile(inputFileName, os.O_RDONLY, 0644)
	if err != nil {
		fmt.Printf("Input file open failure: %v\n", err)
		os.Exit(-1)
	}
	outputFile, err := os.OpenFile(outputFileName, os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		fmt.Printf("Output file open failure: %v\n", err)
		os.Exit(-1)
	}

}
