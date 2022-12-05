package test

import (
	"CS323_GO/paser"
	"io/ioutil"
	"os"
	"strings"
	"testing"
)
func TestPaser(t *testing.T){
	filePath := "./senmantic/given/in/test_2_r01.spl"
	outputFilePath := strings.Replace(filePath, ".spl", ".out", 1)
	outputFile, err := os.OpenFile(outputFilePath, os.O_WRONLY|os.O_TRUNC|os.O_CREATE, 0777)
	if err != nil {
		println(err.Error())
	}
	defer outputFile.Close()
	os.Stdout = outputFile

	paser.Syntax(filePath)
}
func diff(file1, file2 string) bool {
	f1, err := ioutil.ReadFile(file1)
    if err!= nil {
        println(err.Error())
        return false
    }
	f2, err := ioutil.ReadFile(file2)
	if err!= nil {
        println(err.Error())
	    return false
    }
	return string(f1) == string(f2)
}

