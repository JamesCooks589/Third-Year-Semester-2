; This makes your function available to other files
global greeting
section .data
;Carter Shin u21470864
;Qwinton Knocklein u21669849
;James Cooks u21654680
; ==========================
; Your data goes here
; ==========================
;msg 
msg dq 'Welcome to the Bank of <<Redacted>>', 10
msglen equ $ - msg


section .text
; void greeting()
; This function prints a greeting to the screen
greeting:
  push rbp
  mov rbp, rsp
; Do not modify anything above this line unless you know what you are doing
; ==========================
; Your code goes here
; ==========================
 mov eax, 4; system call for write
 mov ebx, 1; file handle (stdout)
 mov ecx, msg; address of string to output
 mov edx, msglen; number of bytes
 int 0x80; invoke operating system to do the write
; Do not modify anything below this line unless you know what you are doing
  leave
  ret