package model

import (
	"fmt"
	"sync"
)

type T *GrammarNode

type Stack struct {
	sync.RWMutex
	array []T
}

func NewStack() *Stack {
	stack := &Stack{}
	stack.array = []T{}

	return stack
}

// Push adds t to the top of the stack
func (s *Stack) Push(t T) {
	s.Lock()
	s.array = append(s.array, t)
	s.Unlock()
}

// Pop removes the top element from the stack
func (s *Stack) Pop() (*T, error) {
	if s.IsEmpty() {
		return nil, fmt.Errorf("stack must not be empty")
	}

	s.Lock()
	item := s.array[len(s.array)-1]
	s.array = s.array[0 : len(s.array)-1]
	s.Unlock()
	return &item, nil
}

// Size returns the size of the stack
func (s *Stack) Size() int {
	s.RLock()
	defer s.RUnlock()

	return len(s.array)
}

func (s *Stack) IsEmpty() bool {
	s.RLock()
	defer s.RUnlock()

	return len(s.array) == 0
}
