	.file	"scope.c"
	.globl	top
	.bss
	.align 8
	.type	top, @object
	.size	top, 8
top:
	.zero	8
	.globl	resolve_result
	.data
	.align 4
	.type	resolve_result, @object
	.size	resolve_result, 4
resolve_result:
	.long	1
	.globl	typecheck_result
	.align 4
	.type	typecheck_result, @object
	.size	typecheck_result, 4
typecheck_result:
	.long	1
	.comm	x,4,4
	.text
	.globl	scope_enter
	.type	scope_enter, @function
scope_enter:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	top(%rip), %rax
	testq	%rax, %rax
	je	.L1
	movq	top(%rip), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	top(%rip), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	scope_node_create
	movq	%rax, top(%rip)
.L1:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	scope_enter, .-scope_enter
	.globl	scope_exit
	.type	scope_exit, @function
scope_exit:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	top(%rip), %rax
	testq	%rax, %rax
	je	.L3
	movq	top(%rip), %rax
	movq	%rax, -8(%rbp)
	movq	top(%rip), %rax
	movq	8(%rax), %rax
	movq	%rax, %rdi
	call	hash_table_delete
	movq	top(%rip), %rax
	movq	16(%rax), %rax
	movq	%rax, top(%rip)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	scope_exit, .-scope_exit
	.globl	scope_level
	.type	scope_level, @function
scope_level:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	top(%rip), %rax
	testq	%rax, %rax
	je	.L6
	movq	top(%rip), %rax
	movl	(%rax), %eax
	jmp	.L7
.L6:
	movl	$1, %eax
.L7:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	scope_level, .-scope_level
	.section	.rodata
	.align 8
.LC0:
	.string	"Unable to declare variable %s\n"
	.text
	.globl	scope_bind
	.type	scope_bind, @function
scope_bind:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	top(%rip), %rax
	testq	%rax, %rax
	jne	.L9
	movl	$1, %esi
	movl	$0, %edi
	call	scope_node_create
	movq	%rax, top(%rip)
.L9:
	movq	top(%rip), %rax
	movq	8(%rax), %rax
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	hash_table_insert
	testl	%eax, %eax
	je	.L10
	movq	top(%rip), %rax
	movl	4(%rax), %edx
	movq	-16(%rbp), %rax
	movl	%edx, 4(%rax)
	movq	top(%rip), %rax
	movl	4(%rax), %edx
	addl	$1, %edx
	movl	%edx, 4(%rax)
	jmp	.L8
.L10:
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, resolve_result(%rip)
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	scope_bind, .-scope_bind
	.globl	scope_lookup
	.type	scope_lookup, @function
scope_lookup:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	top(%rip), %rax
	movq	%rax, -8(%rbp)
	jmp	.L13
.L16:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	hash_table_lookup
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	je	.L14
	movq	-16(%rbp), %rax
	jmp	.L15
.L14:
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
.L13:
	cmpq	$0, -8(%rbp)
	jne	.L16
	movl	$0, %eax
.L15:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	scope_lookup, .-scope_lookup
	.globl	scope_lookup_current
	.type	scope_lookup_current, @function
scope_lookup_current:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	top(%rip), %rax
	testq	%rax, %rax
	je	.L18
	movq	top(%rip), %rax
	movq	8(%rax), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	hash_table_lookup
	jmp	.L19
.L18:
	movl	$0, %eax
.L19:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	scope_lookup_current, .-scope_lookup_current
	.globl	scope_node_create
	.type	scope_node_create, @function
scope_node_create:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$24, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movl	$0, %esi
	movl	$0, %edi
	call	hash_table_create
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-8(%rbp), %rax
	movl	$0, 4(%rax)
	movq	-8(%rbp), %rax
	movl	-28(%rbp), %edx
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 16(%rax)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	scope_node_create, .-scope_node_create
	.ident	"GCC: (GNU) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
