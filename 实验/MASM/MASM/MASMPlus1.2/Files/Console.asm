;#Mode=CON
;MASMPlus ���ļ�����ģ�� - ����̨����
;--------------------------------------------------------------------
;�����ļ���Ҫָ������ģʽ,����Ĭ����EXE��ʽ,��ϵͳ�����п�������Ĭ����DOS����Windows.
;����ģʽ�Դ���DOS/COM/CON/EXE/DLL/LIB�⼸��,����б�Ҫ,���Ը���ide.ini����µı���ģʽ
;��Ȼ,���õ��Ǵ���Ϊһ������.�����㼰���ڹ���,ʹ�÷���:��Ctrl��ѡ->��������.�����ж���ļ�

.386
.model flat, stdcall
option casemap :none

include windows.inc
include user32.inc
include kernel32.inc
include masm32.inc

includelib user32.lib
includelib kernel32.lib
includelib masm32.lib
include macro.asm

.data?
	buffer	db 100 dup(?)
	
.CODE
START:
	
	invoke StdOut,CTXT("Hello World!")

	;��ͣ��ʾ,�س����ر�
	invoke StdIn,addr buffer,sizeof buffer
	invoke ExitProcess,0
	
end START