; This makes your function available to other files
global calculate_balance

section .data
;Carter Shin u21470864
;Qwinton Knocklein u21669849
;James Cooks u21654680
; ==========================
; Your data goes here
; ==========================

section .text

calculate_balance:
  push rbp
  mov rbp, rsp
  
; Do not modify anything above this line unless you know what you are doing
; ==========================
; Your code goes here
  mov eax, edi ; eax is A
  add eax, esi ; eax now A + P
  imul eax, esi ; eax (A + P) * P
  xor esi, edi ; rsi is the xor of p and a
  and eax, esi ; eax ((A + P) * P) ^ (P ⊕ A)
  add eax, 50000
; ==========================
; Do not modify anything below this line unless you know what you are doing

  leave
  ret