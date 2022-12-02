package paser

/*
	#cgo CFLAGS: -I../c
	#include "syntax.tab.c"
	#include "tree.c"
	node* get_grammer_node(FILE* f){
        yylineno = 1;
    	yyrestart(f);
    	yyparse();
        return root;
	}
	char* void_to_char(void* pointer){
        return (char*)pointer;
	}
    node* list_node_to_node(list_node* ln){
		return (node*)ln->data;
    }



*/
import "C"
import (
	"CS323_GO/model"
	"unsafe"
)

func cValToGoVal(val unsafe.Pointer, wordType model.WordType) interface{} {
	if wordType == model.INT {
		return *(*int32)(val)
	} else if wordType == model.FLOAT {
		return *(*float32)(val)
	} else {
		return C.GoString(C.void_to_char(val))
	}
}
func cTypeToGoType(val int) model.WordType {
	return model.WordType(val)
}
func cToGoNode(node *C.struct_Node, from *model.GrammarNode) *model.GrammarNode {
	if node == nil {
		return nil
	}
	cList := node.list
	grammarNode := &model.GrammarNode{
		WordType:  cTypeToGoType(int(node.word_type)),
		Line:      int(node.line),
		Value:     cValToGoVal(node.val, cTypeToGoType(int(node.word_type))),
		Child:     nil,
		Parent:    from,
		IsRight:   int(node.lval_or_rval) == 1,
		IsEmpty:   int(node.empty) == 1,
		IsVisited: false,
	}
	if cList == nil {
		return grammarNode
	}
	childList := make([]*model.GrammarNode, int(cList.length))
	listNode := cList.first
	for i := 0; i < int(cList.length); i++ {
		childList[i] = cToGoNode(C.list_node_to_node(listNode), grammarNode)
		listNode = listNode.next
	}
	grammarNode.Child = childList
	return grammarNode

}

func GetGrammerNode(filePath string) *model.GrammarNode {
	file := C.fopen(C.CString(filePath), C.CString("r"))
	defer C.fclose(file)
	root := C.get_grammer_node(file)
	backRoot := cToGoNode(root, nil)
	return backRoot
}
