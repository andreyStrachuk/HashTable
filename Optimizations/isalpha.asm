%macro          saveregs 0
                push rbx
                push r12
                push r13
                push r14
                push r15
%endmacro

%macro          restoreregs 0
                pop r15
                pop r14
                pop r13
                pop r12
                pop rbx
%endmacro

section .text

global isalphA

isalphA:

        saveregs

        cmp rdi, 'A'
        jb not

        cmp rdi, 'Z'
        jbe alpha

        cmp rdi, 'a'
        jb not

        cmp rdi, 'z'
        jbe alpha

not:    mov rax, 0
        jmp end

alpha:  mov rax, 1024

end:    restoreregs

        ret

