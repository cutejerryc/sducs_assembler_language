  ; ===========================================
  ; ddraw.inc copyright MASM32 1998 - 2003
  ; ===========================================

DDGetAttachedSurfaceLcl PROTO :DWORD,:DWORD,:DWORD
DDInternalLock PROTO :DWORD,:DWORD
DDInternalUnlock PROTO :DWORD
DSoundHelp PROTO :DWORD,:DWORD,:DWORD
DirectDrawCreate PROTO :DWORD,:DWORD,:DWORD
DirectDrawCreateClipper PROTO :DWORD,:DWORD,:DWORD
DirectDrawCreateEx PROTO :DWORD,:DWORD,:DWORD,:DWORD
DirectDrawEnumerateA PROTO :DWORD,:DWORD
DirectDrawEnumerate equ <DirectDrawEnumerateA>

DirectDrawEnumerateExA PROTO :DWORD,:DWORD,:DWORD
DirectDrawEnumerateEx equ <DirectDrawEnumerateExA>

DirectDrawEnumerateExW PROTO :DWORD,:DWORD,:DWORD
DirectDrawEnumerateW PROTO :DWORD,:DWORD
GetDDSurfaceLocal PROTO :DWORD,:DWORD,:DWORD
GetSurfaceFromDC PROTO :DWORD,:DWORD,:DWORD
