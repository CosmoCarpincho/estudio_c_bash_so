	.file	"mit_lomas.c"
	.intel_syntax noprefix
# GNU C17 (Ubuntu 9.4.0-1ubuntu1~20.04.1) version 9.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 9.4.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.22.1-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu mit_lomas.c -masm=intel
# -mtune=generic -march=x86-64 -auxbase-strip m3.s -O0 -fverbose-asm
# -fasynchronous-unwind-tables -fstack-protector-strong -Wformat
# -Wformat-security -fstack-clash-protection -fcf-protection
# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
# -fassume-phsa -fasynchronous-unwind-tables -fauto-inc-dec -fcommon
# -fdelete-null-pointer-checks -fdwarf2-cfi-asm -fearly-inlining
# -feliminate-unused-debug-types -ffp-int-builtin-inexact -ffunction-cse
# -fgcse-lm -fgnu-runtime -fgnu-unique -fident -finline-atomics
# -fipa-stack-alignment -fira-hoist-pressure -fira-share-save-slots
# -fira-share-spill-slots -fivopts -fkeep-static-consts
# -fleading-underscore -flifetime-dse -flto-odr-type-merging -fmath-errno
# -fmerge-debug-strings -fpeephole -fplt -fprefetch-loop-arrays
# -freg-struct-return -fsched-critical-path-heuristic
# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
# -fsemantic-interposition -fshow-column -fshrink-wrap-separate
# -fsigned-zeros -fsplit-ivs-in-unroller -fssa-backprop
# -fstack-clash-protection -fstack-protector-strong -fstdarg-opt
# -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math -ftree-cselim
# -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -malign-stringops -mavx256-split-unaligned-load
# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64	
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
# mit_lomas.c:4: 	int val1 = 5;
	mov	DWORD PTR -12[rbp], 5	# val1,
# mit_lomas.c:5: 	int val2 = 10;
	mov	DWORD PTR -8[rbp], 10	# val2,
# mit_lomas.c:6: 	int resu = 0;
	mov	DWORD PTR -4[rbp], 0	# resu,
# mit_lomas.c:8: 	resu = val1 + val2;
	mov	edx, DWORD PTR -12[rbp]	# tmp88, val1
	mov	eax, DWORD PTR -8[rbp]	# tmp89, val2
	add	eax, edx	# tmp87, tmp88
	mov	DWORD PTR -4[rbp], eax	# resu, tmp87
# mit_lomas.c:9: 	resu = val1 + val2;
	mov	edx, DWORD PTR -12[rbp]	# tmp94, val1
	mov	eax, DWORD PTR -8[rbp]	# tmp95, val2
	add	eax, edx	# tmp93, tmp94
	mov	DWORD PTR -4[rbp], eax	# resu, tmp93
# mit_lomas.c:10: 	resu = val1 * val2;
	mov	eax, DWORD PTR -12[rbp]	# tmp97, val1
	imul	eax, DWORD PTR -8[rbp]	# tmp96, val2
	mov	DWORD PTR -4[rbp], eax	# resu, tmp96
# mit_lomas.c:11: 	resu = val2 / val1;
	mov	eax, DWORD PTR -8[rbp]	# tmp101, val2
	cdq
	idiv	DWORD PTR -12[rbp]	# val1
	mov	DWORD PTR -4[rbp], eax	# resu, tmp99
# mit_lomas.c:13: return resu;
	mov	eax, DWORD PTR -4[rbp]	# _8, resu
# mit_lomas.c:14: }
	pop	rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
