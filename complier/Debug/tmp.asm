	.386
	.model flat, stdcall
	option casemap :none

	include C:\masm32\include\windows.inc
	include C:\masm32\include\user32.inc
	include C:\masm32\include\kernel32.inc
	include C:\masm32\include\masm32.inc

	includelib C:\masm32\lib\user32.lib
	includelib C:\masm32\lib\kernel32.lib
	includelib C:\masm32\lib\masm32.lib


	.data
		_a DWORD 0
		buffer BYTE 128 dup(0)
		LF BYTE 13, 10, 0


	.code
_start:
	MOV eax, 6
	MOV _a, eax
	invoke dwtoa, _a, ADDR buffer
	invoke StdOut, ADDR buffer
	invoke StdOut, ADDR LF
	invoke ExitProcess, 0
end _start
