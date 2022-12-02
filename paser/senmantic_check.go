package paser

import "CS323_GO/model"
import "container/list"

func BuildSymbolTable(root *model.GrammarNode) *list.List {
	symbolTable := list.New()
	symbolList := make(map[string]*model.SymbolNode)

	grammarStack := model.NewStack()
	grammarStack.Push(root)
	symbolTable.PushBack(symbolList)
	for !grammarStack.IsEmpty() {
		t, err := grammarStack.Pop()
		now := *t
		if err != nil {
			println(err)
			return nil
		}
		if now.WordType == model.RC && now.Parent.WordType == model.NTERM && now.Parent.String() == "CompSt" {
			symbolTable.Remove(symbolTable.Back())
			symbolList = symbolTable.Back().Value.(map[string]*model.SymbolNode)
		}
		if now.IsEmpty || now.Child == nil {
			continue
		}
		if now.WordType == model.NTERM {
			nterm := (*now).String()
			if nterm == "CompSt" {
				symbolList = make(map[string]*model.SymbolNode)
				symbolTable.PushBack(symbolList)
				if now.Parent.String() == "ExtDef" {
					funcNode := now.Parent.Child[0]
					funcId := funcNode.Child[0].String()
					if symbolList[funcId] != nil {
						model.RedefineFunction.PrintError(funcNode.Line, funcId)
					}
					funcSymbol := GetSymbolById(funcId, symbolTable)
					Parameter := GetParameter(funcSymbol)
					for k, v := range Parameter {
						symbolList[k] = v
					}
				}
			} else if nterm == "Def" && !now.IsVisited {
				tmp := GetDefSymbol(now, symbolList, symbolTable)
				for k, v := range tmp {
					if symbolList[k] != nil {
						model.RedefineVariable.PrintError(now.Line, k)
					}
					symbolList[k] = v
				}
			} else if nterm == "Exp" && !now.IsVisited {
				GetExpSymbol(now, symbolTable)
			} else if nterm == "ExtDef" && !now.IsVisited {
				tmp := GetSymbolFromExtdef(now, symbolList, symbolTable)
				for k, v := range tmp {
					symbolList[k] = v
				}
			} else if nterm == "Stmt " && len(now.Child) == 3 {
				function := GetCurrentFunction(symbolTable)
				exp := now.Child[1]
				returnType := function.Type.(*model.FuncType).Return
				actType := GetExpSymbol(exp, symbolTable)
				if actType == nil {
					model.ReturnTypeError.PrintError(exp.Line, function.Name)
				} else if !returnType.Equal(actType) {
					model.ReturnTypeError.PrintError(exp.Line, function.Name)
				}
			}
		}

		childList := now.Child
		for _, child := range childList {
			grammarStack.Push(child)
		}
	}

	return symbolTable
}
