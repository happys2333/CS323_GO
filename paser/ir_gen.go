package paser

import (
	"CS323_GO/model"
	"strconv"
)

func GenStmtCode(node *model.GrammarNode) *model.IrCode {
	node.IsTrans = true
	parent := node.Child[0]
	if parent.WordType == model.NTERM && parent.String() == "Exp" {
		place := newPlace()
		return genExpCode(parent, place)
	} else if len(node.Child) == 1 {
		defList := parent.Child[1]
		stmtList := parent.Child[2]
		back := genDefList(defList)
		var c *model.IrCode
		for !stmtList.IsEmpty {
			stmt := stmtList.Child[0]
			stmtList = stmtList.Child[1]
			c = model.ConnectIr(c, GenStmtCode(stmt))
		}
		return model.ConnectIr(back, c)
	}

	if parent.WordType == model.RETURN {
		second := node.Child[1]
		place := newPlace()
		back := genExpCode(second, place)
		return model.ConnectIr(back, model.NewIrCode(model.RETURN, []model.Operand{model.NewOperand(model.VARIABLE, place)}, model.NONE))

	} else if parent.WordType == model.IF {
		exp := parent.Parent.Child[2]
		stmt := parent.Parent.Child[4]
		lb1 := newLabel()
		lb2 := newLabel()
		if len(parent.Parent.Child) > 6 {
			lb3 := newLabel()
			stmt2 := parent.Parent.Child[6]
			c1 := model.ConnectIr(genCondExp(exp, lb1, lb2), model.NewIrCode(model.LAB, []model.Operand{model.NewOperand(model.LABEL, lb1)}, model.NONE))
			c2 := model.ConnectIr(GenStmtCode(stmt), model.NewIrCode(model.GOTO, []model.Operand{model.NewOperand(model.LABEL, lb3)}, model.NONE), model.NewIrCode(model.LAB, []model.Operand{model.NewOperand(model.LABEL, lb2)}, model.NONE))
			c3 := model.ConnectIr(GenStmtCode(stmt2), model.NewIrCode(model.LAB, []model.Operand{model.NewOperand(model.LABEL, lb3)}, model.NONE))
			return model.ConnectIr(c1, c2, c3)
		} else {
			c1 := model.ConnectIr(genCondExp(exp, lb1, lb2), model.NewIrCode(model.LAB, []model.Operand{model.NewOperand(model.LABEL, lb1)}, model.NONE))
			c2 := model.ConnectIr(GenStmtCode(stmt), model.NewIrCode(model.LAB, []model.Operand{model.NewOperand(model.LABEL, lb2)}, model.NONE))
			return model.ConnectIr(c1, c2)
		}
	} else if parent.WordType == model.WHILE {
		exp := parent.Parent.Child[2]
		stmt := parent.Parent.Child[4]
		lb1 := newLabel()
		lb2 := newLabel()
		lb3 := newLabel()
		c1 := model.ConnectIr(model.NewIrCode(model.LAB, []model.Operand{model.NewOperand(model.LABEL, lb1)}, model.NONE), genCondExp(exp, lb2, lb3))
		c2 := model.ConnectIr(model.NewIrCode(model.LAB, []model.Operand{model.NewOperand(model.LABEL, lb2)}, model.NONE), GenStmtCode(stmt), model.NewIrCode(model.GOTO, []model.Operand{model.NewOperand(model.LABEL, lb1)}, model.NONE))
		return model.ConnectIr(c1, c2, model.NewIrCode(model.LAB, []model.Operand{model.NewOperand(model.LABEL, lb3)}, model.NONE))
	}
	return nil
}
func GenFunDecCode(node *model.GrammarNode) *model.IrCode {
	parent := node.Child[0]
	if len(node.Child) == 3 {
		val := parent.String()
		return model.NewIrCode(model.FUN, []model.Operand{model.NewOperand(model.FUNC, val)}, model.NONE)
	} else {
		val := parent.String()
		c1 := model.NewIrCode(model.FUN, []model.Operand{model.NewOperand(model.FUNC, val)}, model.NONE)
		varList := node.Child[2]
		c2 := genVarList(varList)
		return model.ConnectIr(c1, c2)
	}
}
func GenDecCode(node *model.GrammarNode) *model.IrCode {
	varDec := node.Child[0]
	if len(node.Child) == 1 {
		return genVarDec(varDec)
	} else {
		id := varDec.Child[0]
		val := id.String()
		exp := node.Child[2]
		c1 := genExpCode(exp, val)
		return c1
	}
}

func genExpCode(node *model.GrammarNode, place string) *model.IrCode {
	pare := node.Child[0]
	if pare.WordType == model.INT && len(node.Child) == 1 {
		val := int(pare.Value.(int32))
		return model.NewIrCode(model.ASSIGN, []model.Operand{model.NewOperand(model.VARIABLE, place), model.NewOperand(model.CONSTANT, val)}, model.NONE)
	} else if pare.WordType == model.ID && len(pare.Parent.Child) == 1 {
		val := pare.String()
		return model.NewIrCode(model.ASSIGN, []model.Operand{model.NewOperand(model.VARIABLE, place), model.NewOperand(model.VARIABLE, val)}, model.NONE)
	} else if pare.WordType == model.NTERM && pare.String() == "Exp" && len(pare.Parent.Child) == 3 {
		second := pare.Parent.Child[1]
		third := pare.Parent.Child[2]
		if second.WordType == model.ASSIGN {
			if len(pare.Child) == 1 {
				exp := pare.Child[0]
				val := exp.String()
				places := newPlace()
				c1 := genExpCode(third, places)
				c2 := model.NewIrCode(model.ASSIGN, []model.Operand{model.NewOperand(model.VARIABLE, val), model.NewOperand(model.VARIABLE, places)}, model.NONE)
				c3 := model.NewIrCode(model.ASSIGN, []model.Operand{model.NewOperand(model.VARIABLE, place), model.NewOperand(model.VARIABLE, val)}, model.NONE)
				return model.ConnectIr(c1, c2, c3)
			} else {
				p1 := newPlace()
				p2 := newPlace()
				c1 := genExpCode(third, p1)
				c2 := genExpAddr(pare, p2, 4)
				c3 := model.NewIrCode(model.LEFT, []model.Operand{model.NewOperand(model.VARIABLE, p2), model.NewOperand(model.VARIABLE, p1)}, model.NONE)
				return model.ConnectIr(c1, c2, c3)
			}
		} else if second.WordType == model.PLUS {
			p1 := newPlace()
			p2 := newPlace()
			c1 := genExpCode(pare, p1)
			c2 := genExpCode(third, p2)
			c3 := model.NewIrCode(model.PLUS, []model.Operand{model.NewOperand(model.VARIABLE, p1), model.NewOperand(model.VARIABLE, p2), model.NewOperand(model.VARIABLE, place)}, model.NONE)
			return model.ConnectIr(c1, c2, c3)
		} else if second.WordType == model.MINUS {
			p1 := newPlace()
			p2 := newPlace()
			c1 := genExpCode(pare, p1)
			c2 := genExpCode(third, p2)
			c3 := model.NewIrCode(model.MINUS, []model.Operand{model.NewOperand(model.VARIABLE, p1), model.NewOperand(model.VARIABLE, p2), model.NewOperand(model.VARIABLE, place)}, model.NONE)
			return model.ConnectIr(c1, c2, c3)
		} else if second.WordType == model.MUL {
			p1 := newPlace()
			p2 := newPlace()
			c1 := genExpCode(pare, p1)
			c2 := genExpCode(third, p2)
			c3 := model.NewIrCode(model.MUL, []model.Operand{model.NewOperand(model.VARIABLE, p1), model.NewOperand(model.VARIABLE, p2), model.NewOperand(model.VARIABLE, place)}, model.NONE)
			return model.ConnectIr(c1, c2, c3)
		} else if second.WordType == model.DIV {
			p1 := newPlace()
			p2 := newPlace()
			c1 := genExpCode(pare, p1)
			c2 := genExpCode(third, p2)
			c3 := model.NewIrCode(model.DIV, []model.Operand{model.NewOperand(model.VARIABLE, p1), model.NewOperand(model.VARIABLE, p2), model.NewOperand(model.VARIABLE, place)}, model.NONE)
			return model.ConnectIr(c1, c2, c3)
		} else if second.WordType == model.DOT {
			addr := newPlace()
			c1 := genExpAddr(node, addr, 0)
			return model.ConnectIr(c1, model.NewIrCode(model.RIGHT, []model.Operand{model.NewOperand(model.VARIABLE, place), model.NewOperand(model.VARIABLE, addr)}, model.NONE))
		}
	} else if pare.WordType == model.MINUS && len(pare.Parent.Child) == 2 {
		second := pare.Parent.Child[1]
		if second.WordType == model.NTERM && second.String() == "Exp" {
			p1 := newPlace()
			c1 := genExpCode(second, p1)
			c2 := model.NewIrCode(model.MINUS, []model.Operand{model.NewOperand(model.CONSTANT, 0), model.NewOperand(model.VARIABLE, p1), model.NewOperand(model.VARIABLE, place)}, model.NONE)
			return model.ConnectIr(c1, c2)
		}
	} else if pare.WordType == model.LP {
		second := node.Child[1]
		return genExpCode(second, place)
	} else if pare.WordType == model.NTERM && pare.String() == "Exp" && len(pare.Parent.Child) == 4 {
		p1 := newPlace()
		c1 := genExpAddr(node, p1, 4)
		c2 := model.NewIrCode(model.RIGHT, []model.Operand{model.NewOperand(model.VARIABLE, place), model.NewOperand(model.VARIABLE, p1)}, model.NONE)
		return model.ConnectIr(c1, c2)
	}

	if pare.WordType == model.READ {
		return model.NewIrCode(model.READ, []model.Operand{model.NewOperand(model.VARIABLE, place)}, model.NONE)
	} else if pare.WordType == model.WRITE {
		p1 := newPlace()
		exp := node.Parent.Child[2]
		return model.ConnectIr(genExpCode(exp, p1), model.NewIrCode(model.WRITE, []model.Operand{model.NewOperand(model.VARIABLE, p1)}, model.NONE))
	} else if pare.WordType == model.ID {
		if len(node.Child) == 3 {
			val := pare.String()
			if val == "read" {
				return model.NewIrCode(model.READ, []model.Operand{model.NewOperand(model.VARIABLE, place)}, model.NONE)
			}
			return model.NewIrCode(model.CALL, []model.Operand{model.NewOperand(model.VARIABLE, place), model.NewOperand(model.FUNC, val)}, model.NONE)
		} else if len(node.Child) == 4 {
			args := pare.Parent.Child[2]
			val := pare.String()
			if val == "write" {
				p1 := newPlace()
				third := pare.Parent.Child[2]
				exp := third.Child[0]
				return model.ConnectIr(genExpCode(exp, p1), model.NewIrCode(model.WRITE, []model.Operand{model.NewOperand(model.VARIABLE, p1)}, model.NONE))
			}
			c1 := genArg(args)
			return model.ConnectIr(c1, model.NewIrCode(model.CALL, []model.Operand{model.NewOperand(model.VARIABLE, place), model.NewOperand(model.VARIABLE, val)}, model.NONE))
		}
	}
	l1 := newLabel()
	l2 := newLabel()
	c1 := model.NewIrCode(model.ASSIGN, []model.Operand{model.NewOperand(model.VARIABLE, place), model.NewOperand(model.CONSTANT, 0)}, model.NONE)
	c2 := genCondExp(pare, l1, l2)
	c3 := model.ConnectIr(model.NewIrCode(model.LAB, []model.Operand{model.NewOperand(model.LABEL, l1)}, model.NONE), model.NewIrCode(model.ASSIGN, []model.Operand{model.NewOperand(model.VARIABLE, place), model.NewOperand(model.CONSTANT, 1)}, model.NONE))
	c4 := model.NewIrCode(model.LAB, []model.Operand{model.NewOperand(model.LABEL, l2)}, model.NONE)
	return model.ConnectIr(c1, c2, c3, c4)
}

func genDefList(node *model.GrammarNode) *model.IrCode {
	stack := model.NewStack()
	stack.Push(node)
	var ir *model.IrCode
	for !stack.IsEmpty() {
		p, err := stack.Pop()
		if err != nil {
			return nil
		}
		pare := *p
		if pare.WordType == model.NTERM && (*pare).String() == "Dec" {
			ir = model.ConnectIr(ir, GenDecCode(pare))
		}
		if pare.IsEmpty || pare.Child == nil {
			continue
		}
		for _, v := range pare.Child {
			stack.Push(v)
		}
	}
	return ir
}
func genCondExp(node *model.GrammarNode, label1, label2 int) *model.IrCode {
	pare := node.Child[0]
	if pare.WordType == model.NTERM && pare.String() == "Exp" && len(pare.Parent.Child) == 3 {
		second := pare.Parent.Child[1]
		third := pare.Parent.Child[2]
		if second.WordType == model.AND {
			lb1 := newLabel()
			c1 := model.ConnectIr(genCondExp(pare, lb1, label2), model.NewIrCode(model.LAB, []model.Operand{model.NewOperand(model.LABEL, lb1)}, model.NONE))
			c2 := genCondExp(pare, label1, label2)
			return model.ConnectIr(c1, c2)
		} else if second.WordType == model.OR {
			lb1 := newLabel()
			c1 := model.ConnectIr(genCondExp(pare, label1, lb1), model.NewIrCode(model.LAB, []model.Operand{model.NewOperand(model.LABEL, lb1)}, model.NONE))
			c2 := genCondExp(third, label1, label2)
			return model.ConnectIr(c1, c2)
		} else if second.WordType == model.EQ || second.WordType == model.GE ||
			second.WordType == model.LE || second.WordType == model.LT ||
			second.WordType == model.GT || second.WordType == model.NE {
			p1 := newPlace()
			p2 := newPlace()
			c1 := genExpCode(pare, p1)
			c2 := genExpCode(third, p2)
			c3 := model.ConnectIr(model.NewIrCode(model.IF, []model.Operand{model.NewOperand(model.VARIABLE, p1), model.NewOperand(model.VARIABLE, p2), model.NewOperand(model.LABEL, label1)}, second.WordType), model.NewIrCode(model.GOTO, []model.Operand{model.NewOperand(model.LABEL, label2)}, model.NONE))
			return model.ConnectIr(c1, c2, c3)
		}

	} else if pare.WordType == model.NOT {
		return genCondExp(node, label2, label1)
	}
	return model.NewIrCode(model.LAB, []model.Operand{model.NewOperand(model.LABEL, -4)}, model.NONE)
}
func genExpAddr(node *model.GrammarNode, addr string, base int) *model.IrCode {
	pare := node.Child[0]
	if pare.WordType == model.ID && len(pare.Parent.Child) == 1 {
		val := pare.String()
		return model.NewIrCode(model.ASSIGN, []model.Operand{model.NewOperand(model.VARIABLE, addr), model.NewOperand(model.VARIABLE, val)}, model.NONE)
	} else if len(node.Child) == 4 {
		exp := node.Child[2]
		p1 := newPlace()
		p2 := newPlace()
		p3 := newPlace()
		c1 := genExpCode(exp, p1)
		c3 := model.NewIrCode(model.MUL, []model.Operand{model.NewOperand(model.VARIABLE, p1), model.NewOperand(model.CONSTANT, base), model.NewOperand(model.VARIABLE, p2)}, model.NONE)
		base *= pare.SymbolNode.Type.(*model.ArrayType).Size
		c2 := genExpAddr(pare, p3, base)
		c4 := model.NewIrCode(model.PLUS, []model.Operand{model.NewOperand(model.VARIABLE, p2), model.NewOperand(model.VARIABLE, p3), model.NewOperand(model.VARIABLE, addr)}, model.NONE)
		return model.ConnectIr(c1, c2, c3, c4)
	} else {
		third := node.Child[2]
		id := third.String()
		field := node.SymbolNode.Type.(*model.FiledType)
		s := 0
		for field.Name != id {
			s += 4
			field = field.Next
		}
		p1 := newPlace()
		c1 := genExpAddr(pare, p1, 4)
		c2 := model.NewIrCode(model.PLUS, []model.Operand{model.NewOperand(model.VARIABLE, p1), model.NewOperand(model.CONSTANT, s), model.NewOperand(model.VARIABLE, addr)}, model.NONE)
		return model.ConnectIr(c1, c2)
	}
}

func genVarList(node *model.GrammarNode) *model.IrCode {
	param := node.Child[0]
	varNode := param.Child[1]
	for len(varNode.Child) > 1 {
		varNode = varNode.Child[0]
	}
	id := varNode.Child[0]
	val := id.String()
	c1 := model.NewIrCode(model.PARAM, []model.Operand{model.NewOperand(model.VARIABLE, val)}, model.NONE)
	if len(node.Child) == 3 {
		valList := node.Child[2]
		c2 := genVarList(valList)
		return model.ConnectIr(c1, c2)
	} else {
		return c1
	}
}

func genVarDec(node *model.GrammarNode) *model.IrCode {
	if len(node.Child) == 1 {
		return nil
	}
	s := 4
	for len(node.Child) == 4 {
		varNode := node.Child[0]
		intNode := node.Child[2]
		s *= int(intNode.Value.(int32))
		node = varNode
	}
	id := node.Child[0]
	name := id.String()
	size := strconv.Itoa(s)
	return model.NewIrCode(model.DEC, []model.Operand{model.NewOperand(model.VARIABLE, name), model.NewOperand(model.VARIABLE, size)}, model.NONE)
}
func genArg(node *model.GrammarNode) *model.IrCode {
	exp := node.Child[0]
	place := newPlace()
	c1 := genExpCode(exp, place)
	c2 := model.NewIrCode(model.ARG, []model.Operand{model.NewOperand(model.VARIABLE, place)}, model.NONE)
	if len(node.Child) == 3 {
		args := node.Child[2]
		c3 := genArg(args)
		return model.ConnectIr(c3, c1, c2)
	} else {
		return model.ConnectIr(c1, c2)
	}
}

var x int = 0
var y int = 0

func newPlace() string {
	y++
	return "t" + strconv.Itoa(y)
}

func newLabel() int {
	x++
	return x
}
