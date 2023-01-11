# CS323 Project 
*单人project 韩梓辰*

~~有现代化编程语言，狗都不写C~~

This project written in golang (go version 1.18) 


## Usage

Due to I used cgo in the code. You should compile the code through gcc or clang.

```bash
go build -o bin/splc main.go
```

to run the code you need a spl file
```bash
${OutputExeFile} ${SPL_FILE_PATH}
```

output file will in the same path of your input


## Project 3
IR 的生成依赖于ir_gen这个类，其中会分析我们在之前分析代码的时候生成的语法树，然后生成中间代码

我们使用ir的数据结构，将整个生成变成一个链表
```go
type IrCode struct {
	IrType WordType
	val    []Operand
	ifR    WordType
	Prev   *IrCode
	Next   *IrCode
}
```
将operand独立生成一个类，方便传入类型
```go
const (
	VARIABLE operandType = iota
	CONSTANT
	LABEL
	FUNC
)

type Operand struct {
	opType operandType
	val    any
}
```
operand只有四种类型，我们将会把运算放入ircode的节点，从而表示一行的输出

分析完成后会逐行输出ircode
