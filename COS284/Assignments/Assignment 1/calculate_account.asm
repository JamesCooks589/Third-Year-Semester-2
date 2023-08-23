; This makes your function available to other files
global calculate_account

section .data
;Carter Shin u21470864
;Qwinton Knocklein u21669849
;James Cooks u21654680
; ==========================
; Your data goes here
; ==========================

section .text

calculate_account:
  push rbp
  mov rbp, rsp

; Do not modify anything above this line unless you know what you are doing
; ==========================
; Your code goes here
  mov eax, edi ; move pin
  add eax, 10000 ; add 10000
; ==========================
; Do not modify anything below this line unless you know what you are doing

  leave
  ret