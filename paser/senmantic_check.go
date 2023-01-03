package paser

import (
	"CS323_GO/model"
)
import "container/list"

func BuildSymbolTable(root *model.GrammarNode) {
	symbolTable := list.New()

	symbolList := make(map[string]*model.SymbolNode)

	grammarStack := model.NewStack()
	grammarStack.Push(root)
	symbolTable.PushBack(symbolList)
	read := &model.SymbolNode{
		Type:       model.NewSymbolNode("func"),
		Name:       "read",
		SymbolType: 0,
		Category:   0,
	}
	write := &model.SymbolNode{
		Type:       model.NewSymbolNode("func"),
		Name:       "write",
		SymbolType: 0,
		Category:   0,
	}
	read.Type.(*model.SymbolNode).SetFuncReturnSymbol(model.NewSymbolNode("int"))
	paramWrite := model.NewSymbolNode("int")
	paramWrite.Name = "x"
	write.Type.(*model.SymbolNode).AddFuncParam(paramWrite)
	symbolList["read"] = read
	symbolList["write"] = write
	for !grammarStack.IsEmpty() {
		t, err := grammarStack.Pop()
		now := *t
		if err != nil {
			println(err)
			return
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
					funcNode := now.Parent.Child[1]
					funcId := funcNode.Child[0].String()

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
				if tmp != nil {
					for k, v := range tmp {
						symbolList[k] = v
					}
				}

			} else if nterm == "Stmt" && len(now.Child) == 3 {
				function := GetCurrentFunction(symbolTable)
				exp := now.Child[1]
				returnType := function.Type.(*model.SymbolNode).Type.(*model.FuncType).Return
				actType := GetExpSymbol(exp, symbolTable)
				if actType == nil {
					model.ReturnTypeError.PrintError(exp.Line, function.Name)
				} else if !returnType.Equal(actType) {
					model.ReturnTypeError.PrintError(exp.Line, function.Name)
				}
			}

		}

		childList := now.Child
		for i := len(childList) - 1; i >= 0; i-- {
			grammarStack.Push(childList[i])
		}
	}
}

func GenIr(root *model.GrammarNode) *model.IrCode {
	rootCode := model.NewIrCode(model.NONE, nil, model.NONE)
	cur := rootCode
	grammarStack := model.NewStack()
	grammarStack.Push(root)
	for !grammarStack.IsEmpty() {
		t, err := grammarStack.Pop()
		now := *t
		if err != nil {
			println(err)
			return nil
		}
		if now.IsEmpty || now.Child == nil {
			continue
		}
		if now.WordType == model.NTERM {
			nterm := (*now).String()
			if nterm == "FunDec" {
				code := GenFunDecCode(now)
				if code != nil {
					model.ConnectIr(cur, code)
					for cur.Next != nil {
						cur = cur.Next
					}
				}

			} else if nterm == "Dec" {
				code := GenDecCode(now)
				if code != nil {
					model.ConnectIr(cur, code)
					for cur.Next != nil {
						cur = cur.Next
					}
				}
			} else if nterm == "Stmt" && !now.IsVisited {
				code := GenStmtCode(now)
				if code != nil {
					model.ConnectIr(cur, code)
					for cur.Next != nil {
						cur = cur.Next
					}
				}
			}
		}
		childList := now.Child
		for i := len(childList) - 1; i >= 0; i-- {
			grammarStack.Push(childList[i])
		}
	}
	return rootCode
}
