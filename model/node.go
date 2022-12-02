package model

import "C"
import "strconv"

type WordType int

const (
	ID WordType = iota
	TYPE
	INT
	FLOAT
	CHAR
	NTERM
	STRUCT
	IF
	ELSE
	WHILE
	RETURN
	FOR
	DOT
	SEMI
	COMMA
	ASSIGN
	LE
	LT
	GE
	GT
	NE
	EQ
	PLUS
	MINUS
	MUL
	DIV
	D_PLUS
	D_MINUS
	PLUS_EQ
	MINUS_EQ
	MUL_EQ
	DIV_EQ
	AND
	OR
	NOT
	LP
	RP
	LB
	RB
	LC
	RC
	UNKNOWN_TYPE_OF_WORD
)

type GrammarNode struct {
	WordType   WordType
	Line       int
	Value      interface{}
	Child      []*GrammarNode
	Parent     *GrammarNode
	IsRight    bool
	IsEmpty    bool
	IsVisited  bool
	SymbolNode *SymbolNode
}

func (node *GrammarNode) String() string {
	if node == nil {
		return "nil"
	}
	switch node.WordType {
	case INT:
		return strconv.FormatInt(int64(node.Value.(int32)), 10)
	case FLOAT:
		return strconv.FormatFloat(float64(node.Value.(float32)), 'f', 20, 32)
	default:
		return node.Value.(string)

	}
}
