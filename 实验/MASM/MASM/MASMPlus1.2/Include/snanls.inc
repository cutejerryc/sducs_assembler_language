  ; ===========================================
  ; snanls.inc copyright MASM32 1998 - 2003
  ; ===========================================

CloseNlsRegistry PROTO :DWORD
FindCloseCodePage PROTO :DWORD
FindFirstCodePage PROTO :DWORD,:DWORD
FindNextCodePage PROTO :DWORD,:DWORD
GetCodePage PROTO :DWORD,:DWORD
GetCodePageDisplayStr PROTO :DWORD,:DWORD
GetCodePages PROTO :DWORD,:DWORD,:DWORD
IsInstalledCodePage PROTO :DWORD,:DWORD
OpenNlsRegistry PROTO :DWORD,:DWORD,:DWORD
SnaNlsInit PROTO :DWORD
SnaNlsMapString PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
