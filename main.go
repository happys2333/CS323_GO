package main

import (
	"CS323_GO/paser"
	"os"
	"strings"
)

func main() {
	if len(os.Args) < 2 {
		println("No file input")
		return
	}
	filePath := os.Args[1]
	outputFilePath := strings.Replace(filePath, ".spl", ".out", 1)
	outputFile, err := os.OpenFile(outputFilePath, os.O_WRONLY|os.O_TRUNC|os.O_CREATE, 0777)
	if err != nil {
		println(err.Error())
		return
	}
	defer outputFile.Close()
	os.Stdout = outputFile

	paser.Syntax(filePath)

}
