; This makes your function available to other files
; This makes your function available to other files
global get_pin
BITS 64

section .data
;Carter Shin u21470864
;Qwinton Knocklein u21669849
;James Cooks u21654680
; ==========================
; Your data goes here
; ==========================
prompt db "Enter 4-digit PIN: "
promtLen equ $ - prompt

section .bss
  buffer resb 4




section .text
; uint32_t get_pin()
; Reads a 4-digit PIN from stdin and converts it to an integer.
; The PIN returned must be a valid 4-digit (32-bit) integer.
get_pin:
  push rbp
  mov rbp, rsp
; Do not modify anything above this line unless you know what you are doing
; ==========================
; Your code goes here
; 
; Print the message that asks for a pin
  mov eax, 4;system call for write
  mov ebx, 1;file descriptor (stdout)
  mov ecx, prompt;message to write
  mov edx, promtLen;length of message
  int 0x80;call kernel

;
  mov eax, 3;system call for read
  mov ebx, 0;file descriptor (stdin)
  lea ecx, [buffer];
  mov edx, 16
  int 0x80

  xor eax, eax
  lea esi, [buffer]
  ;counter for the loop
  mov ecx, 4


  convertInput:
    movzx edx, byte [esi]
    cmp ecx, 0
    je endConvert
    dec ecx
    imul eax, 10
    sub edx, '0'
    add eax, edx
    inc esi
    jmp convertInput

  endConvert:

; ==========================
; Do not modify anything below this line unless you know what you are doing
  leave
  ret