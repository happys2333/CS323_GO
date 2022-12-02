package model

type Category int

const (
	PRIMITIVE Category = iota
	ARRAY
	STRUCTURE
	FUNCTION
)

type SymbolNode struct {
	Type       any
	Name       string
	SymbolType WordType
	Category   Category
}

type ArrayType struct {
	Size int
	Base *SymbolNode
}

type ParameterType struct {
	Name string
	Base *SymbolNode
	Next *ParameterType
}
type FiledType struct {
	Name string
	Base *SymbolNode
	Next *FiledType
}
type FuncType struct {
	Return *SymbolNode
	Params *ParameterType
}

type ValType struct {
	Name string
	Base *SymbolNode
	Type Category
}

func NewSymbolNode(name string) *SymbolNode {
	switch name {
	case "int":
		return &SymbolNode{
			SymbolType: INT,
			Category:   PRIMITIVE,
		}
	case "float":
		return &SymbolNode{
			SymbolType: FLOAT,
			Category:   PRIMITIVE,
		}
	case "char":
		return &SymbolNode{
			SymbolType: CHAR,
			Category:   PRIMITIVE,
		}
	case "array":
		return &SymbolNode{
			Type: &ArrayType{
				Base: nil,
			},
			Category: ARRAY,
		}
	case "struct":
		return &SymbolNode{
			Type:     nil,
			Category: STRUCTURE,
		}
	case "func":
		return &SymbolNode{
			Type:     &FuncType{},
			Category: FUNCTION,
		}
	}
	return nil
}

func (s1 *FiledType) Equal(s2 *FiledType) bool {
	if s1.Base.Category != s2.Base.Category {
		return false
	}
	result := false
	switch s1.Base.Category {
	case PRIMITIVE:
		result = s1.Base.SymbolType == s1.Base.SymbolType
		break
	case ARRAY:
		result = s1.Base.Type.(*ArrayType).Equal(s1.Base.Type.(*ArrayType))
		break
	case STRUCTURE:
		result = s1.Base.Type.(*FiledType).Equal(s1.Base.Type.(*FiledType))
		break
	}
	if result {
		return true
	}
	if s1.Next == nil && s2.Next == nil {
		return true
	} else if s1.Next != nil && s2.Next != nil {
		return s1.Next.Equal(s2.Next)
	} else {
		return false
	}

}
func (f1 *FuncType) Equal(f2 *FuncType) bool {
	return f1.Params.Equal(f2.Params)
}
func (a1 *ArrayType) Equal(a2 *ArrayType) bool {
	if a1.Size != a2.Size || a1.Base.Category != a2.Base.Category {
		return false
	}
	switch a1.Base.Category {
	case PRIMITIVE:
		return a1.Base.SymbolType == a2.Base.SymbolType
	case ARRAY:
		return a1.Base.Type.(*ArrayType).Equal(a2.Base.Type.(*ArrayType))
	case STRUCTURE:
		return a1.Base.Type.(*FiledType).Equal(a2.Base.Type.(*FiledType))
	}
	return false
}

func (s1 *SymbolNode) Equal(s2 *SymbolNode) bool {
	if s1 == nil && s2 == nil {
		return true
	}
	if s1 == nil || s2 == nil {
		return false
	}
	if s1.Category != s2.Category {
		return false
	}
	switch s1.Category {
	case PRIMITIVE:
		return s1.SymbolType == s2.SymbolType
	case ARRAY:
		return s1.Type.(*ArrayType).Equal(s2.Type.(*ArrayType))
	case STRUCTURE:
		return s1.Type.(*FiledType).Equal(s2.Type.(*FiledType))
	case FUNCTION:
		return s1.Type.(*FiledType).Equal(s2.Type.(*FiledType))
	}
	return false
}

func (p1 *ParameterType) Equal(p2 *ParameterType) bool {
	if !p1.Base.Equal(p2.Base) {
		return false
	}
	if p1.Next == nil && p2.Next == nil {
		return true
	} else if p1.Next != nil && p2.Next != nil {
		return p1.Next.Equal(p2.Next)
	} else {
		return false
	}
}

func (t *FiledType) FindById(id string) *SymbolNode {
	for t != nil {
		if t.Name == id {
			return t.Base
		}
		t = t.Next
	}
	return nil
}
