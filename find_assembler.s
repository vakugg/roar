.text
.globl  _get_call_adress
_get_call_address:
        mov (%esp), %eax
    mov %eax,%esp
	ret
