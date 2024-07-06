section .data
    c_code db "#include <stdio.h>", 10
            db "int main() {", 10
            db "    printf(""Hello World"");", 10
            db "    return 0;", 10
            db "}", 0

    output_filename db "output.o", 0
    c_code_len equ $ - c_code  ; comprimento do código C

section .text
    global _start

_start:
    ; Abrir o arquivo para escrita
    mov rax, 2           ; syscall para sys_open
    mov rdi, output_filename
    mov rsi, 0x201        ; O_WRONLY | O_CREAT
    mov rdx, 0x1C0        ; permissões de escrita
    syscall

    mov r8, rax          ; salve o descritor de arquivo retornado

    ; Escrever o código C no arquivo
    mov rax, 1           ; syscall para sys_write
    mov rdi, r8          ; file descriptor
    mov rsi, c_code      ; ponteiro para o código C
    mov rdx, c_code_len  ; comprimento do código C
    syscall

    ; Fechar o arquivo
    mov rax, 3           ; syscall para sys_close
    mov rdi, r8          ; descritor de arquivo
    syscall

    ; Sair do programa
    mov rax, 60          ; syscall para sys_exit
    xor rdi, rdi         ; código de retorno 0
    syscall
