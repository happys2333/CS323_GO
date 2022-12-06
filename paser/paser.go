package paser

import (
	"CS323_GO/model"
	"container/list"
)

// Private Func

func getStructSymbol(structNode *model.GrammarNode, list map[string]*model.SymbolNode, table *list.List) *model.SymbolNode {
	if len(structNode.Child) == 2 {
		id := structNode.Child[1].String()
		structId := "struct " + id
		structSymbol := GetSymbolById(structId, table)
		if structSymbol != nil {
			return structSymbol
		} else {
			model.UndefinedStructNumber.PrintError(structNode.Line, structId)
			return nil
		}

	} else {
		id := structNode.Child[1].String()
		structId := "struct " + id
		symbol := GetSymbolById(structId, table)
		structSymbol := model.NewSymbolNode("struct")
		symbolList := make(map[string]*model.SymbolNode)
		stack := model.NewStack()
		stack.Push(structNode)
		for !stack.IsEmpty() {
			parent, err := stack.Pop()
			if err != nil {
				return nil
			}
			pare := *parent
			if pare.IsEmpty || pare.Child == nil {
				continue
			}
			if pare.WordType == model.NTERM && (*pare).String() == "Def" {
				defList := GetDefSymbol(pare, list, table)
				for k, v := range defList {
					symbolList[k] = v
				}
				continue
			}
			for i := len(pare.Child) - 1; i >= 0; i-- {
				stack.Push(pare.Child[i])
			}

		}
		for k, v := range symbolList {
			structSymbol.AddStructField(&model.FiledType{
				Name: k,
				Base: v,
				Next: nil,
			})
		}
		if symbol != nil {
			model.RedefineStruct.PrintError(structNode.Line, structId)
			return symbol
		}
		list[structId] = structSymbol
		return structSymbol
	}
}

func getParameterFromArgs(args *model.GrammarNode, table *list.List) *model.ParameterType {
	exp := args.Child[0]
	param := &model.ParameterType{
		Name: "",
		Base: GetExpSymbol(exp, table),
		Next: nil,
	}
	if len(args.Child) != 1 {
		param.Next = getParameterFromArgs(args.Child[len(args.Child)-1], table)
	}
	return param
}
func getSymbolFromParamdec(node *model.GrammarNode, list map[string]*model.SymbolNode, table *list.List) *model.SymbolNode {
	specifierSymbol := getSymbolFromSpecifier(node.Child[0], list, table)
	return getSymbolFromVarDec(node.Child[1], specifierSymbol, nil, list, table)
}
func getSymbolFromFunction(funcS *model.GrammarNode, returnT *model.SymbolNode, list map[string]*model.SymbolNode, table *list.List) *model.SymbolNode {
	id := funcS.Child[0].String()
	funcT := model.NewSymbolNode("func")
	funcT.Type.(*model.FuncType).Line = funcS.Line
	funcT.SetFuncReturnSymbol(returnT)
	parentMap := make(map[string]*model.SymbolNode)
	stack := model.NewStack()
	stack.Push(funcS)
	for !stack.IsEmpty() {
		par, err := stack.Pop()
		if err != nil {
			println(err)
			return nil
		}
		pare := *par
		if pare.IsEmpty || pare.Child == nil {
			continue
		}
		if pare.WordType == model.NTERM && (*pare).String() == "ParamDec" {
			t := getSymbolFromParamdec(pare, list, table)
			if parentMap[t.Name] != nil {
				model.RedefineVariable.PrintError(funcS.Line, t.Name)
			}
			parentMap[t.Name] = t
			continue
		}
		for i := len(pare.Child) - 1; i >= 0; i-- {
			stack.Push(pare.Child[i])
		}
	}
	for _, v := range parentMap {
		funcT.AddFuncParam(v)
	}
	return &model.SymbolNode{
		Name:     id,
		Type:     funcT,
		Category: model.FUNCTION,
	}
}
func getSymbolFromVarDec(node *model.GrammarNode, specifier, array *model.SymbolNode, list map[string]*model.SymbolNode, table *list.List) *model.SymbolNode {
	if len(node.Child) == 1 {
		child := node.Child[0]
		if array == nil && specifier == nil {
			return &model.SymbolNode{Name: child.String()}
		}
		if array == nil {
			specifier.Name = child.String()
			return specifier
		} else {
			array.Name = child.String()
			return array
		}
	} else {
		t := model.NewSymbolNode("array")
		size := node.Child[2].Value.(int32)
		next := node.Child[0]
		Array := t.Type.(*model.ArrayType)
		Array.SetArraySize(int(size))
		if array == nil {
			Array.SetArrayType(specifier)
		} else {
			Array.SetArrayType(array)
		}
		return getSymbolFromVarDec(next, specifier, t, list, table)
	}
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
		return getStructSymbol(child, list, table)
	}
}

// Public Func

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
	param := node.Type.(*model.SymbolNode).Type.(*model.FuncType).Params
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
		if symbol == nil {
			model.UndefinedVariable.PrintError(node.Line, id)
		}
		return symbol
	} else if len(node.Child) >= 3 && first.WordType == model.ID {
		id := (*first).String()
		funcType := GetSymbolById(id, table)
		if funcType == nil {
			model.UndefinedFunction.PrintError(node.Line, id)
			node.SymbolNode = nil
			return nil
		}
		if funcType.Type == nil {
			model.UndefinedFunction.PrintError(node.Line, id)
			node.SymbolNode = nil
			return nil
		}
		funcType = funcType.Type.(*model.SymbolNode)
		if funcType == nil {
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
		} else if second.WordType != model.COMMA {
			left := node.Child[0]
			right := node.Child[2]
			GetExpSymbol(left, table)
			GetExpSymbol(right, table)
			if second.WordType == model.ASSIGN {
				if left.IsRight {
					model.LeftVarRevalue.PrintError(node.Line, "")
					node.SymbolNode = nil
					return nil
				}
				if left.SymbolNode.Equal(right.SymbolNode) {
					node.SymbolNode = left.SymbolNode
					return node.SymbolNode
				} else {
					model.UnmatchedVariable.PrintError(node.Line, "")
					node.SymbolNode = nil
					return nil
				}
			} else if second.WordType == model.AND || second.WordType == model.OR {
				if left.WordType != model.INT || right.WordType != model.INT {
					model.UnmatchedOperand.PrintError(node.Line, "")
					node.SymbolNode = nil
					return nil
				}
			} else {
				if left.SymbolNode != nil && right.SymbolNode != nil {
					if left.SymbolNode.Category == model.PRIMITIVE && left.SymbolNode.Equal(right.SymbolNode) {
						node.SymbolNode = left.SymbolNode
						return node.SymbolNode
					} else {
						model.UnmatchedOperand.PrintError(node.Line, "")
						node.SymbolNode = nil
						return nil
					}
				}
			}
			node.SymbolNode = GetExpSymbol(first, table)
			return node.SymbolNode
		}
	} else if len(node.Child) == 4 {
		// ARRAY
		index := node.Child[2]
		arraySymbol := GetExpSymbol(first, table)
		indexSymbol := GetExpSymbol(index, table)
		if arraySymbol == nil {
			model.NotArray.PrintError(node.Line, "")
			node.SymbolNode = nil
			return nil
		} else if arraySymbol.Category != model.ARRAY {
			model.NotArray.PrintError(node.Line, "")
			node.SymbolNode = nil
			return nil
		} else if indexSymbol.Category != model.PRIMITIVE {
			model.IndexNotNumber.PrintError(node.Line, "")
			node.SymbolNode = arraySymbol.Type.(*model.ArrayType).Base
			return node.SymbolNode
		} else if indexSymbol.SymbolType != model.INT {
			model.IndexNotNumber.PrintError(node.Line, "")
			node.SymbolNode = arraySymbol.Type.(*model.ArrayType).Base
			return node.SymbolNode
		} else {
			node.SymbolNode = arraySymbol.Type.(*model.ArrayType).Base
			return node.SymbolNode
		}
	}
	node.SymbolNode = nil
	return nil
}
func GetCurrentFunction(table *list.List) *model.SymbolNode {
	tables := table.Front().Value.(map[string]*model.SymbolNode)
	var back *model.SymbolNode
	backLine := -1
	for _, v := range tables {
		if v.Category != model.FUNCTION {
			continue
		}
		funcN := v.Type.(*model.SymbolNode).Type.(*model.FuncType)
		if funcN.Line > backLine {
			back = v
			backLine = funcN.Line
		}
	}
	return back
}

func GetDefSymbol(node *model.GrammarNode, list map[string]*model.SymbolNode, table *list.List) map[string]*model.SymbolNode {
	node.IsVisited = true
	returnMap := make(map[string]*model.SymbolNode)
	specifier := getSymbolFromSpecifier(node.Child[0], list, table)
	stack := model.NewStack()
	stack.Push(node.Child[1])
	for !stack.IsEmpty() {
		parent, err := stack.Pop()
		if err != nil {
			return nil
		}
		pare := *parent
		if pare.IsEmpty || pare.Child == nil {
			continue
		}
		if pare.WordType == model.NTERM && (*pare).String() == "VarDec" {
			tmp := getSymbolFromVarDec(pare, specifier, nil, list, table)
			if returnMap[tmp.Name] != nil {
				model.RedefineVariable.PrintError(node.Line, tmp.Name)
			} else {
				returnMap[tmp.Name] = tmp
			}
			continue
		}
		for i := len(pare.Child) - 1; i >= 0; i-- {
			stack.Push(pare.Child[i])
		}
	}
	return returnMap
}

func GetSymbolFromExtdef(node *model.GrammarNode, list map[string]*model.SymbolNode, table *list.List) map[string]*model.SymbolNode {
	node.IsVisited = true
	first := node.Child[0]
	if len(node.Child) == 2 {
		tmp := first.Child[0]
		if tmp.WordType == model.TYPE {
			return nil
		} else {
			getStructSymbol(tmp, list, table)
			return nil
		}
	} else if node.Child[2].WordType == model.SEMI {
		return GetDefSymbol(node, list, table)
	} else {
		newMap := make(map[string]*model.SymbolNode)
		returnSymbol := getSymbolFromSpecifier(node.Child[0], list, table)
		funcS := node.Child[1]
		tem := getSymbolFromFunction(funcS, returnSymbol, list, table)
		//re := false
		for e := table.Front(); e != nil; e = e.Next() {
			n := e.Value.(map[string]*model.SymbolNode)[tem.Name]
			if n != nil && n.Category == model.FUNCTION {
				//re = true
				model.RedefineFunction.PrintError(node.Line, tem.Name)
			}
		}
		//if !re {
		newMap[tem.Name] = tem
		//}
		return newMap
	}
}
