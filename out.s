.data
y:
	.quad 10
.data
x:
	.quad 5
.data
a:
	.quad 1, 2, 3, 4, 5, 6, 7, 8
.text
.globl func
func:
	PUSHQ %rbp
	MOVQ %rsp, %rbp
	PUSHQ %rdi
	PUSHQ %rsi
	SUBQ $0, %rsp
	PUSHQ %rbx
	PUSHQ %r12
	PUSHQ %r13
	PUSHQ %r14
	PUSHQ %r15

	.data
.L1:
	.string "hello"
	.text
	LEAQ .L1, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ $1, %r10
	LEAQ a, %r11
	MOVQ (%r11, %r10, 8), %r11
	MOVQ %r11, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_integer
	POPQ %r11
	POPQ %r10
	.data
.L2:
	.string "\n"
	.text
	LEAQ .L2, %r10
	MOVQ %r10, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
func_epilogue:
	POPQ %r15
	POPQ %r14
	POPQ %r13
	POPQ %r12
	POPQ %rbx
	MOVQ %rbp, %rsp
	POPQ %rbp
	RET
.text
.globl main
main:
	PUSHQ %rbp
	MOVQ %rsp, %rbp
	PUSHQ %rdi
	SUBQ $8, %rsp
	PUSHQ %rbx
	PUSHQ %r12
	PUSHQ %r13
	PUSHQ %r14
	PUSHQ %r15

	MOVQ $0, -16(%rbp)
	MOVQ $0, %r12
	MOVQ %r12, -16(%rbp)
.L3:
	MOVQ -16(%rbp), %r13
	MOVQ $8, %r14
	CMPQ %r14, %r13
	JL .L5
	MOVQ $0, %r14
	JMP .L6
.L5:
	MOVQ $1, %r14
.L6:
	CMPQ $0, %r14
	JE .L4
	MOVQ -16(%rbp), %r13
	LEAQ a, %r14
	MOVQ (%r14, %r13, 8), %r14
	MOVQ %r14, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_integer
	POPQ %r11
	POPQ %r10
	.data
.L7:
	.string "\n"
	.text
	LEAQ .L7, %r13
	MOVQ %r13, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ -16(%rbp), %r15
	INCQ %r15
	MOVQ %r15, -16(%rbp)
	JMP .L3
.L4:
main_epilogue:
	POPQ %r15
	POPQ %r14
	POPQ %r13
	POPQ %r12
	POPQ %rbx
	MOVQ %rbp, %rsp
	POPQ %rbp
	RET
