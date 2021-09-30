data segment
led db 3fh,06h,5bh,4fh,66h,6dh,7dh,07h,7fh
ends
code segment
start： ；设置 8255 方式选择控制字
；A 口输入 B 口输出。
mov dx，096h
mov al，10010000b
out dx，al
；循环读 A 口数据，输出到 B 口。 l： mov dx，090h
in al，dx
；检查是否有人抢答，如果没有转向 no。
not al
or al，al
je no
；有人抢答，求出对应的段码。
mov cl，00h
rr： shr al，1
inc cl
jnc rr
mov al，cl
mov bx，offset led
xlat
；输出对应的段码到 B 口。
Mov dx，092h ；输出段码
out dx，al
；输出延时
mov cx，10
de1：mov di，0000h
de0：dec di
jnz de0
loop de1
jmp l ；延时结束后继续从 A 口读数据。 ；没人抢答时输出 0 的段码到 B 口，不延时，
no：mov bx，offset led
xlat
mov dx，092h
out dx，al
jmp l ；继续从 A 口读数据
end start