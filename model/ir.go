package model

import (
	"fmt"
	"strconv"
)

type operandType int

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

func NewOperand(opType operandType, val any) Operand {
	return Operand{
		opType: opType,
		val:    val,
	}
}

func (op *Operand) String() string {
	switch op.opType {
	case VARIABLE:
		return op.val.(string)
	case CONSTANT:
		return "#" + strconv.Itoa(op.val.(int))
	case LABEL:
		return "label" + strconv.Itoa(op.val.(int))
	case FUNC:
		return op.val.(string)
	}
	return ""
}

type IrCode struct {
	IrType WordType
	val    []Operand
	ifR    WordType
	Prev   *IrCode
	Next   *IrCode
}

func ConnectIr(code ...*IrCode) *IrCode {
	t := make([]*IrCode, 0, len(code))
	for _, v := range code {
		if v != nil {
			t = append(t, v)
		}
	}
	for i := 0; i < len(t)-1; i++ {
		cur := t[i]
		for ; cur.Next != nil; cur = cur.Next {
		}
		cur.Next = t[i+1]
		t[i+1].Prev = cur
	}
	return t[0]
}
func (c *IrCode) String() string {
	switch c.IrType {
	case LAB:
		return fmt.Sprintf("LABEL %s :", c.val[0].String())
	case FUN:
		return fmt.Sprintf("FUNCTION %s :", c.val[0].String())
	case GOTO:
		return fmt.Sprintf("GOTO %s", c.val[0].String())
	case RETURN:
		return fmt.Sprintf("RETURN %s", c.val[0].String())
	case ARG:
		return fmt.Sprintf("ARG %s", c.val[0].String())
	case PARAM:
		return fmt.Sprintf("PARAM %s", c.val[0].String())
	case READ:
		return fmt.Sprintf("READ %s", c.val[0].String())
	case WRITE:
		return fmt.Sprintf("WRITE %s", c.val[0].String())
	case ASSIGN:
		return fmt.Sprintf("%s := %s", c.val[0].String(), c.val[1].String())
	case ADDRESS:
		return fmt.Sprintf("%s := &%s", c.val[0].String(), c.val[1].String())
	case DEC:
		return fmt.Sprintf("DEC %s %s", c.val[0].String(), c.val[1].String())
	case CALL:
		return fmt.Sprintf("%s := CALL %s", c.val[0].String(), c.val[1].String())
	case LEFT:
		return fmt.Sprintf("*%s := %s", c.val[0].String(), c.val[1].String())
	case RIGHT:
		return fmt.Sprintf("%s := *%s", c.val[0].String(), c.val[1].String())
	case PLUS:
		return fmt.Sprintf("%s := %s + %s", c.val[2].String(), c.val[0].String(), c.val[1].String())
	case MINUS:
		return fmt.Sprintf("%s := %s - %s", c.val[2].String(), c.val[0].String(), c.val[1].String())
	case MUL:
		return fmt.Sprintf("%s := %s * %s", c.val[2].String(), c.val[0].String(), c.val[1].String())
	case DIV:
		return fmt.Sprintf("%s := %s / %s", c.val[2].String(), c.val[0].String(), c.val[1].String())
	case IF:
		return fmt.Sprintf("IF %s %s %s GOTO %s", c.val[0].String(), c.ifR.String(), c.val[1].String(), c.val[2].String())
	}

	return ""
}

func NewIrCode(irType WordType, val []Operand, ifR WordType) *IrCode {
	return &IrCode{
		IrType: irType,
		val:    val,
		ifR:    ifR,
	}
}
