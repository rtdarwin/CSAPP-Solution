int cread_alt (int *xp)
{
	int zero = 0;
	int *rvp = xp? xp: &zero;
	return *rvp;
}

/*
 * 在我的 GNU/Debian x86-64 gcc 4.9.2-10 上以
 *   gcc -m32 -march=i686 -S -O1 3.57_cread-alt.c
 * 编译时，确实出现了
 *   cmove %edx, %eax 的条件数据转移指令。
 *
 * 但，若以
 *   gcc -m32 -march=i686 -S -O1 3.57_cread-alt.c
 * 编译时，产出的汇编文件并没有使用 cmove 指令。
 *

___O1: OUTPUT____________________________________

	.file	"3.57_cread-alt.c"
	.text
	.globl	cread_alt
	.type	cread_alt, @function
cread_alt:
.LFB0:
	.cfi_startproc
	subl	$16, %esp
	.cfi_def_cfa_offset 20
	movl	20(%esp), %eax
	movl	$0, 12(%esp)
	leal	12(%esp), %edx
	testl	%eax, %eax
	cmove	%edx, %eax
	movl	(%eax), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE0:
	.size	cread_alt, .-cread_alt
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits


___O2: OUTPUT_____________________________________

	.file	"3.57_cread-alt.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	cread_alt
	.type	cread_alt, @function
cread_alt:
.LFB0:
	.cfi_startproc
	movl	4(%esp), %eax
	testl	%eax, %eax
	je	.L3
	movl	(%eax), %eax
	ret
	.p2align 4,,10
	.p2align 3
.L3:
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	cread_alt, .-cread_alt
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits

*/
