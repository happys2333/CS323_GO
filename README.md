# CS323 Project 
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
