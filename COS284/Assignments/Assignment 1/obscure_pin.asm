global obscure_pin

section .data

;Carter Shin u21470864
;Qwinton Knocklein u21669849
;James Cooks u21654680

; ==========================
; Your data goes here
ASCII_0 equ 48 ; ASCII value for 0
; ==========================

; void obscure_pin(char* pin)
; Obscures a 4-digit ASCII PIN in place.
; Assumes pin is in rdi.
section .text
obscure_pin:
  push rbp
  mov rbp, rsp
; Do not modify anything above this line unless you know what you are doing
; ==========================
; Your code goes here
  ; load PIN digits
  mov rsi, rdi ; Copy the address of the PIN string to rsi


  ; obscure digits and store back in reverse order
  mov rcx, 4 ; set loop counter to 4

  .loop
    mov al, byte [rsi] ; load current digit into al
    sub al, ASCII_0 ; convert to decimal: di - 48
    xor al, 0x0F ; obscure digit: di XOR 0x0F
    add al, ASCII_0 ; convert back to ASCII: di + 48
    mov [rsi], al ; store digit
    inc rsi ; move to next digit
    dec rcx ; decrement loop counter
    cmp rcx, 0 ; check if loop counter is 0
    jne .loop ; if not, loop again

    sub rsi, 4 ; move back to first digit

  ; reverse PIN digits
  mov al, byte [rsi] ; load first digit into al
  inc rsi ; move to next digit
  mov ah, byte [rsi] ; load second digit into bl
  inc rsi ; move to next digit
  mov bl, byte [rsi] ; load third digit into ah
  inc rsi ; move to next digit
  mov bh, byte [rsi] ; load fourth digit into bh
  mov [rsi], al ; store first digit
  dec rsi ; move to next digit
  mov [rsi], ah ; store second digit
  dec rsi ; move to next digit
  mov [rsi], bl ; store third digit
  dec rsi ; move to next digit
  mov [rsi], bh ; store fourth digit


; ==========================
; Do not modify anything below this line unless you know what you are doing

  leave
  ret