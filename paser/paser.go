package paser

import (
	"CS323_GO/model"
	"container/list"
)

func getStructType(structNode *model.GrammarNode, list map[string]*model.SymbolNode, table *list.List) *model.SymbolNode {
	return nil
}

func getParameterFromArgs(args *model.GrammarNode, table *list.List) *model.ParameterType {
	return nil
}
func findFieldType(filed *model.FiledType, id string) *model.SymbolNode {
	for filed != nil {
		if filed.Name == id {
			return filed.Base
		}
		filed = filed.Next
	}
	return nil
}

func getSymbolFromSpecifier(spec *model.GrammarNode, list map[string]*model.SymbolNode, table *list.List) *model.SymbolNode {
	child := spec.Child[0]
	if child == nil {
		return nil
	}
	if child.WordType == model.TYPE {
		return model.NewSymbolNode(child.String())
	} else {
		return getStructType(child, list, table)
	}
}

func Syntax(path string) *list.List {
	root := GetGrammerNode(path)
	symbolTable := BuildSymbolTable(root)
	return symbolTable
}

func GetSymbolById(id string, table *list.List) *model.SymbolNode {
	current := table.Front()
	for current != nil {
		maps := current.Value.(map[string]*model.SymbolNode)
		if maps[id] != nil {
			return maps[id]
		}
		current = current.Next()
	}
	return nil
}
func GetParameter(node *model.SymbolNode) map[string]*model.SymbolNode {
	result := make(map[string]*model.SymbolNode)
	if node == nil {
		return result
	}
	param := node.Type.(*model.ParameterType)
	for param != nil {
		result[param.Name] = param.Base
		param = param.Next
	}
	return result
}

func GetExpSymbol(node *model.GrammarNode, table *list.List) *model.SymbolNode {
	node.IsVisited = true
	first := node.Child[0]
	if len(node.Child) == 1 && first.WordType == model.ID {
		id := (*first).String()
		symbol := GetSymbolById(id, table)
		node.SymbolNode = symbol
		if symbol != nil {
			model.UndefinedVariable.PrintError(node.Line, id)
		}
		return symbol
	} else if len(node.Child) >= 3 && first.WordType == model.ID {
		id := (*first).String()
		funcType := GetSymbolById(id, table)
		if funcType != nil {
			model.UndefinedFunction.PrintError(node.Line, id)
			node.SymbolNode = nil
			return nil
		} else if funcType.Category != model.FUNCTION {
			model.NotFunction.PrintError(node.Line, id)
			node.SymbolNode = nil
			return nil
		} else if len(node.Child) == 3 {
			if funcType.Type.(*model.FuncType).Params != nil {
				model.FunctionArgumentUnmatched.PrintError(node.Line, id)
			}
			node.SymbolNode = funcType.Type.(*model.FuncType).Return
			return node.SymbolNode
		} else {
			args := node.Child[2]
			callArgs := getParameterFromArgs(args, table)
			if !callArgs.Equal(funcType.Type.(*model.FuncType).Params) {
				model.FunctionArgumentUnmatched.PrintError(node.Line, id)
			}
			node.SymbolNode = funcType.Type.(*model.FuncType).Return
			return node.SymbolNode
		}
	} else if len(node.Child) == 1 && first.WordType == model.INT {
		node.SymbolNode = &model.SymbolNode{
			SymbolType: model.INT,
			Category:   model.PRIMITIVE,
		}
		return node.SymbolNode
	} else if len(node.Child) == 1 && first.WordType == model.FLOAT {
		node.SymbolNode = &model.SymbolNode{
			SymbolType: model.FLOAT,
			Category:   model.PRIMITIVE,
		}
		return node.SymbolNode
	} else if len(node.Child) == 2 {
		second := node.Child[1]
		if first.WordType == model.NOT {
			if second.WordType == model.INT {
				model.UnmatchedOperand.PrintError(node.Line, "")
				node.SymbolNode = nil
				return nil
			}
		}
		node.SymbolNode = GetExpSymbol(second, table)
		return node.SymbolNode
	} else if len(node.Child) == 3 {
		second := node.Child[1]
		if second.WordType == model.DOT {
			structType := GetExpSymbol(first, table)
			third := node.Child[2]
			if structType == nil {
				node.SymbolNode = nil
				return nil
			} else if structType.Category != model.STRUCTURE {
				model.NotStruct.PrintError(node.Line, "")
				node.SymbolNode = nil
				return nil
			}
			id := third.String()
			filed := findFieldType(structType.Type.(*model.FiledType), id)
			if filed == nil {
				model.UndefinedStructNumber.PrintError(node.Line, "")
				node.SymbolNode = nil
				return nil
			} else {
				node.SymbolNode = filed
				return node.SymbolNode
			}
		} else if second.WordType == model.NTERM && second.String() == "Exp" {
			node.SymbolNode = GetExpSymbol(second, table)
			return node.SymbolNode
		} else if second.WordType == model.COMMA {

		}
	}

	return nil
}
func GetCurrentFunction(table *list.List) *model.SymbolNode {

	return nil
}

func GetDefSymbol(node *model.GrammarNode, list map[string]*model.SymbolNode, table *list.List) map[string]*model.SymbolNode {
	return nil
}

func GetSymbolFromExtdef(node *model.GrammarNode, list map[string]*model.SymbolNode, table *list.List) map[string]*model.SymbolNode {
	return nil
}
