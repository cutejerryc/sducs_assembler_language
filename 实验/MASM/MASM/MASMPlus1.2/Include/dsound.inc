  ; ===========================================
  ; dsound.inc copyright MASM32 1998 - 2003
  ; ===========================================

DirectSoundCaptureCreate PROTO :DWORD,:DWORD,:DWORD
DirectSoundCaptureEnumerateA PROTO :DWORD,:DWORD
DirectSoundCaptureEnumerate equ <DirectSoundCaptureEnumerateA>

DirectSoundCaptureEnumerateW PROTO :DWORD,:DWORD
DirectSoundCreate PROTO :DWORD,:DWORD,:DWORD
DirectSoundEnumerateA PROTO :DWORD,:DWORD
DirectSoundEnumerate equ <DirectSoundEnumerateA>

DirectSoundEnumerateW PROTO :DWORD,:DWORD
