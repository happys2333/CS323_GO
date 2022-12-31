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

type operand struct {
	opType operandType
	val    any
}

func (op *operand) String() string {
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
	irType WordType
	val    []operand
	next   *IrCode
	prev   *IrCode
	ifR    WordType
}

func (c *IrCode) String() string {
	switch c.irType {
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
		return fmt.Sprintf("%s := %s + %s", c.val[0].String(), c.val[1].String(), c.val[2].String())
	case MINUS:
		return fmt.Sprintf("%s := %s - %s", c.val[0].String(), c.val[1].String(), c.val[2].String())
	case MUL:
		return fmt.Sprintf("%s := %s * %s", c.val[0].String(), c.val[1].String(), c.val[2].String())
	case DIV:
		return fmt.Sprintf("%s := %s / %s", c.val[0].String(), c.val[1].String(), c.val[2].String())
	case IF:
		return fmt.Sprintf("IF %s %s %s GOTO %s", c.val[0].String(), c.ifR.String(), c.val[1].String(), c.val[2].String())
	}

	return ""
}
