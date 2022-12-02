package model

import "fmt"

type SenmanticError int

const (
	UndefinedVariable SenmanticError = iota
	UndefinedFunction
	RedefineVariable
	RedefineFunction
	UnmatchedVariable
	LeftVarRevalue
	UnmatchedOperand
	ReturnTypeError
	FunctionArgumentUnmatched
	NotArray
	NotFunction
	IndexNotNumber
	NotStruct
	UndefinedStructNumber
	RedefineStruct
)

func (e SenmanticError) PrintError(line int, info string) {
	switch e {
	case UndefinedVariable:
		fmt.Printf("Error type %d at Line %d: undefined variable: %s\n", e+1, line, info)
		break
	case UndefinedFunction:
		fmt.Printf("Error type %d at Line %d: undefined function: %s\n", e+1, line, info)
		break
	case RedefineVariable:
		fmt.Printf("Error type %d at Line %d: redefined variable: %s\n", e+1, line, info)
		break
	case RedefineFunction:
		fmt.Printf("Error type %d at Line %d: redefined function: %s\n", e+1, line, info)
		break
	case UnmatchedVariable:
		fmt.Printf("Error type %d at Line %d: unmatching type on both sides of assignment \n", e+1, line)
		break
	case LeftVarRevalue:
		fmt.Printf("Error type %d at Line %d: left side in assignment is rvalue\n", e+1, line)
		break
	case UnmatchedOperand:
		fmt.Printf("Error type %d at Line %d: unmatching operands\n", e+1, line)
		break
	case ReturnTypeError:
		fmt.Printf("Error type %d at Line %d: incompatiable return type\n", e+1, line)
		break
	case FunctionArgumentUnmatched:
		fmt.Printf("Error type %d at Line %d: invalid argument for %s\n", e+1, line, info)
		break
	case NotArray:
		fmt.Printf("Error type %d at Line %d: indexing on non-array variable\n", e+1, line)
		break
	case NotFunction:
		fmt.Printf("Error type %d at Line %d: invoking non-function variable: %s\n", e+1, line, info)
		break
	case IndexNotNumber:
		fmt.Printf("Error type %d at Line %d: indexing by non-integer\n", e+1, line)
		break
	case NotStruct:
		fmt.Printf("Error type %d at Line %d: access members of a non-structure variable\n", e+1, line)
		break
	case UndefinedStructNumber:
		fmt.Printf("Error type %d at Line %d: access an undefined structure member\n", e+1, line)
		break
	case RedefineStruct:
		fmt.Printf("Error type %d at Line %d: redefine struct: %s\n", e+1, line, info)
		break
	}
}
