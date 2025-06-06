ifndef _INC_PIF
_INC_PIF	EQU	1
PIFNAMESIZE	EQU	30
PIFSTARTLOCSIZE	EQU	63
PIFDEFPATHSIZE	EQU	64
PIFPARAMSSIZE	EQU	64
PIFSHPROGSIZE	EQU	64
PIFSHDATASIZE	EQU	64
PIFDEFFILESIZE	EQU	80
PIFMAXFILEPATH	EQU	260
ifndef LF_FACESIZE
LF_FACESIZE	EQU	32
endif
LARGEST_GROUP	EQU	SIZE PROPPRG
OPENPROPS_NONE	EQU	0000H
OPENPROPS_RAWIO	EQU	0001H
OPENPROPS_INFONLY	EQU	0002H
OPENPROPS_FORCEREALMODE	EQU	0004H
OPENPROPS_INHIBITPIF	EQU	8000H
GETPROPS_NONE	EQU	0000H
GETPROPS_RAWIO	EQU	0001H
GETPROPS_OEM	EQU	0008H
SETPROPS_NONE	EQU	0000H
SETPROPS_RAWIO	EQU	0001H
SETPROPS_CACHE	EQU	0002H
SETPROPS_OEM	EQU	0008H
FLUSHPROPS_NONE	EQU	0000H
FLUSHPROPS_DISCARD	EQU	0001H
CLOSEPROPS_NONE	EQU	0000H
CLOSEPROPS_DISCARD	EQU	0001H
CREATEPROPS_NONE	EQU	0000H
DELETEPROPS_NONE	EQU	0000H
DELETEPROPS_DISCARD	EQU	0001H
DELETEPROPS_ABORT	EQU	0002H
LOADPROPLIB_DEFER	EQU	0001H
ifdef  RECT
_INC_WINDOWS	EQU	1
endif
ifndef _INC_WINDOWS
RECT    struc
        rcLeft      dw  ?
        rcTop       dw  ?
        rcRight     dw  ?
        rcBottom    dw  ?
RECT    ends

endif
GROUP_PRG	EQU	1
PRG_DEFAULT	EQU	0
PRG_CLOSEONEXIT	EQU	0001H
PRG_NOSUGGESTMSDOS	EQU	0400H
PRGINIT_DEFAULT	EQU	0
PRGINIT_MINIMIZED	EQU	0001H
PRGINIT_MAXIMIZED	EQU	0002H
PRGINIT_WINLIE	EQU	0004H
PRGINIT_REALMODE	EQU	0008H
PRGINIT_REALMODESILENT	EQU	0100H
PRGINIT_AMBIGUOUSPIF	EQU	0400H
PRGINIT_NOPIF	EQU	1000H
PRGINIT_DEFAULTPIF	EQU	2000H
PRGINIT_INFSETTINGS	EQU	4000H
PRGINIT_INHIBITPIF	EQU	8000H
RMOPT_MOUSE	EQU	0001H
RMOPT_EMS	EQU	0002H
RMOPT_CDROM	EQU	0004H
RMOPT_NETWORK	EQU	0008H
RMOPT_DISKLOCK	EQU	0010H
RMOPT_PRIVATECFG	EQU	0020H
RMOPT_VESA	EQU	0040H
ICONFILE_DEFAULT	EQU	<"PIFMGR.DLL">
ICONINDEX_DEFAULT	EQU	0

PROPPRG	STRUC
flPrg	DW	?
flPrgInit	DW	?
achTitle	DB	PIFNAMESIZE DUP (?)
achCmdLine	DB	PIFSTARTLOCSIZE+PIFPARAMSSIZE+1 DUP (?)
achWorkDir	DB	PIFDEFPATHSIZE DUP (?)
wHotKey	DW	?
achIconFile	DB	PIFDEFFILESIZE DUP (?)
wIconIndex	DW	?
dwEnhModeFlags	DD	?
dwRealModeFlags	DD	?
achOtherFile	DB	PIFDEFFILESIZE DUP (?)
achPIFFile	DB	PIFMAXFILEPATH DUP (?)
PROPPRG	ENDS
GROUP_TSK	EQU	2
TSK_DEFAULT	EQU	<(TSK_BACKGROUND)>
TSK_ALLOWCLOSE	EQU	0001H
TSK_BACKGROUND	EQU	0002H
TSK_NOWARNTERMINATE	EQU	0010H
TSK_NOSCREENSAVER	EQU	0020H
TSKINIT_DEFAULT	EQU	0
TSKIDLESENS_DEFAULT	EQU	50

PROPTSK	STRUC
flTsk	DW	?
flTskInit	DW	?
wReserved1	DW	?
wReserved2	DW	?
wReserved3	DW	?
wReserved4	DW	?
wIdleSensitivity	DW	?
PROPTSK	ENDS
GROUP_VID	EQU	3
ifndef NEC_98
VID_DEFAULT	EQU	<(VID_TEXTEMULATE)>
VID_TEXTEMULATE	EQU	0001H
VID_RETAINMEMORY	EQU	0080H
endif
VID_FULLSCREEN	EQU	0100H
ifdef NEC_98
VID_DEFAULT	EQU	0200H
VIDNEC_NTMODEFF	EQU	0001H
VIDNEC_NTMODEFFC16	EQU	0002H
VIDNEC_NTDISPRW	EQU	0004H
VIDNEC_NTPAL	EQU	0008H
VIDNEC_NTGDC	EQU	0020H
VIDNEC_NTGDCTON	EQU	0040H
VIDNEC_NTGDCGON	EQU	0080H
VIDNEC_NTFONT	EQU	0100H
VIDNEC_CRTC	EQU	0200H
VIDNEC_XFERDATA	EQU	0400H
VIDNEC_XFERP0	EQU	0800H
VIDNEC_XFERP1	EQU	1000H
VIDNEC_XFERP2	EQU	2000H
VIDNEC_XFERP3	EQU	4000H
endif
VIDINIT_DEFAULT	EQU	0
VIDSCREENLINES_MIN	EQU	0
VIDSCREENLINES_DEFAULT	EQU	0

PROPVID	STRUC
flVid	DW	?
flVidInit	DW	?
ifdef NEC_98
flVidNEC	DW	?
else
wReserved1	DW	?
endif
wReserved2	DW	?
wReserved3	DW	?
cScreenLines	DW	?
PROPVID	ENDS
GROUP_MEM	EQU	4
MEM_DEFAULT	EQU	0
MEMINIT_DEFAULT	EQU	0
MEMINIT_NOHMA	EQU	0001H
MEMINIT_LOWLOCKED	EQU	0002H
MEMINIT_EMSLOCKED	EQU	0004H
MEMINIT_XMSLOCKED	EQU	0008H
MEMINIT_GLOBALPROTECT	EQU	0010H
MEMLOW_MIN	EQU	0
MEMLOW_DEFAULT	EQU	0
MEMLOW_MAX	EQU	640
MEMEMS_MIN	EQU	0
MEMEMS_DEFAULT	EQU	0
MEMEMS_MAX	EQU	0FFFFH
MEMXMS_MIN	EQU	0
MEMXMS_DEFAULT	EQU	0
MEMXMS_MAX	EQU	0FFFFH

PROPMEM	STRUC
flMem	DW	?
flMemInit	DW	?
wMinLow	DW	?
wMaxLow	DW	?
wMinEMS	DW	?
wMaxEMS	DW	?
wMinXMS	DW	?
wMaxXMS	DW	?
PROPMEM	ENDS
GROUP_KBD	EQU	5
KBD_DEFAULT	EQU	<(KBD_FASTPASTE)>
KBD_FASTPASTE	EQU	0001H
KBD_NOALTTAB	EQU	0020H
KBD_NOALTESC	EQU	0040H
KBD_NOALTSPACE	EQU	0080H
KBD_NOALTENTER	EQU	0100H
KBD_NOALTPRTSC	EQU	0200H
KBD_NOPRTSC	EQU	0400H
KBD_NOCTRLESC	EQU	0800H
KBDINIT_DEFAULT	EQU	0
KBDALTDELAY_MIN	EQU	1
KBDALTDELAY_DEFAULT	EQU	5
KBDALTDELAY_MAX	EQU	5000
KBDALTPASTEDELAY_MIN	EQU	1
KBDALTPASTEDELAY_DEFAULT	EQU	25
KBDALTPASTEDELAY_MAX	EQU	5000
KBDPASTEDELAY_MIN	EQU	1
KBDPASTEDELAY_DEFAULT	EQU	3
KBDPASTEDELAY_MAX	EQU	5000
KBDPASTEFULLDELAY_MIN	EQU	1
KBDPASTEFULLDELAY_DEFAULT	EQU	200
KBDPASTEFULLDELAY_MAX	EQU	5000
KBDPASTETIMEOUT_MIN	EQU	1
KBDPASTETIMEOUT_DEFAULT	EQU	1000
KBDPASTETIMEOUT_MAX	EQU	5000
KBDPASTESKIP_MIN	EQU	1
KBDPASTESKIP_DEFAULT	EQU	2
KBDPASTESKIP_MAX	EQU	100
KBDPASTECRSKIP_MIN	EQU	1
KBDPASTECRSKIP_DEFAULT	EQU	10
KBDPASTECRSKIP_MAX	EQU	100

PROPKBD	STRUC
flKbd	DW	?
flKbdInit	DW	?
msAltDelay	DW	?
msAltPasteDelay	DW	?
msPasteDelay	DW	?
msPasteFullDelay	DW	?
msPasteTimeout	DW	?
cPasteSkip	DW	?
cPasteCRSkip	DW	?
PROPKBD	ENDS
GROUP_MSE	EQU	6
MSE_DEFAULT	EQU	<(MSE_WINDOWENABLE)>
MSE_WINDOWENABLE	EQU	0001H
MSE_EXCLUSIVE	EQU	0002H
MSEINIT_DEFAULT	EQU	0

PROPMSE	STRUC
flMse	DW	?
flMseInit	DW	?
PROPMSE	ENDS
GROUP_FNT	EQU	8
FNT_DEFAULT	EQU	<(FNT_BOTHFONTS OR FNT_AUTOSIZE)>
FNT_RASTERFONTS	EQU	0004H
FNT_TTFONTS	EQU	0008H
FNT_BOTHFONTS	EQU	(FNT_RASTERFONTS OR FNT_TTFONTS)
FNT_AUTOSIZE	EQU	0010H
FNT_RASTER	EQU	0400H
FNT_TT	EQU	0800H
FNT_FONTMASK	EQU	(FNT_BOTHFONTS)
FNT_FONTMASKBITS	EQU	2
FNTINIT_DEFAULT	EQU	0
FNTINIT_NORESTORE	EQU	0001H

PROPFNT	STRUC
flFnt	DW	?
flFntInit	DW	?
cxFont	DW	?
cyFont	DW	?
cxFontActual	DW	?
cyFontActual	DW	?
achRasterFaceName	DB	LF_FACESIZE DUP (?)
achTTFaceName	DB	LF_FACESIZE DUP (?)
wCurrentCP	DW	?
PROPFNT	ENDS
GROUP_WIN	EQU	9
WIN_DEFAULT	EQU	<(WIN_SAVESETTINGS OR WIN_TOOLBAR)>
WIN_SAVESETTINGS	EQU	0001H
WIN_TOOLBAR	EQU	0002H
WININIT_DEFAULT	EQU	0
WININIT_NORESTORE	EQU	0001H

PROPWIN	STRUC
flWin	DW	?
flWinInit	DW	?
cxCells	DW	?
cyCells	DW	?
cxClient	DW	?
cyClient	DW	?
cxWindow	DW	?
cyWindow	DW	?
ifdef WPF_SETMINPOSITION
wp	DB	SIZE WINDOWPLACEMENT DUP (?)
else
wLength	DW	?
wShowFlags	DW	?
wShowCmd	DW	?
xMinimize	DW	?
yMinimize	DW	?
xMaximize	DW	?
yMaximize	DW	?
rcNormal	DB	SIZE RECT DUP (?)
endif
PROPWIN	ENDS
GROUP_ENV	EQU	10
ENV_DEFAULT	EQU	0
ENVINIT_DEFAULT	EQU	0
ENVSIZE_MIN	EQU	0
ENVSIZE_DEFAULT	EQU	0
ENVSIZE_MAX	EQU	32768
ENVDPMI_MIN	EQU	0
ENVDPMI_DEFAULT	EQU	0
ENVDPMI_MAX	EQU	0FFFFH

PROPENV	STRUC
flEnv	DW	?
flEnvInit	DW	?
achBatchFile	DB	PIFDEFFILESIZE DUP (?)
cbEnvironment	DW	?
wMaxDPMI	DW	?
PROPENV	ENDS
MAX_GROUP	EQU	0FFH
PIFEXTSIGSIZE	EQU	16
MAX_GROUP_NAME	EQU	PIFEXTSIGSIZE
STDHDRSIG	EQU	<"MICROSOFT PIFEX">
LASTHDRPTR	EQU	0FFFFH
W286HDRSIG30	EQU	<"WINDOWS 286 3.0">
W386HDRSIG30	EQU	<"WINDOWS 386 3.0">
WENHHDRSIG40	EQU	<"WINDOWS VMM 4.0">
ifdef  NEC_98
WNECHDRSIG	EQU	<"WINDOWS NEC 3.0">

PIFNECEXT	STRUC
cPlaneFlags	DB	?
cNecFlags	DB	?
cVCDFlags	DB	?
EnhExtBit	DB	?
Extcont	DB	?
cReserved	DB	27 DUP (?)
PIFNECEXT	ENDS
P0MASK	EQU	01H
NOTP0MASK	EQU	0feH
P1MASK	EQU	02H
NOTP1MASK	EQU	0fdH
P2MASK	EQU	04H
NOTP2MASK	EQU	0fbH
P3MASK	EQU	08H
NOTP3MASK	EQU	0f7H
CRTCMASK	EQU	01H
NOTCRTCMASK	EQU	0feH
EXCHGMASK	EQU	02H
NOTEXCHGMASK	EQU	0fdH
MODEFFMASK	EQU	01H
NOTMODEFFMASK	EQU	0feH
DISPLAYDRAWMASK	EQU	02H
NOTDISPLAYDRAWMASK	EQU	0fdH
COLORPALLETTMASK	EQU	04H
NOTCOLORPALLETTMASK	EQU	0fbH
GDCMASK	EQU	08H
NOTGDCMASK	EQU	0f7H
FONTMASK	EQU	10H
NOTFONTMASK	EQU	0efH
VDDMASK	EQU	80H
NOTVDDMASK	EQU	7fH
MODEFF16	EQU	01H
MODEFF8	EQU	0feH
GDCTEXTMASK	EQU	04H
NOTGDCTEXTMASK	EQU	0fbH
GDCGRPHMASK	EQU	08H
NOTGDCGRPHMASK	EQU	0f7H
endif
CONFIGHDRSIG40	EQU	<"CONFIG  SYS 4.0">
AUTOEXECHDRSIG40	EQU	<"AUTOEXECBAT 4.0">
MAX_CONFIG_SIZE	EQU	4096
MAX_AUTOEXEC_SIZE	EQU	4096
CONFIGFILE	EQU	<"\CONFIG.SYS">
AUTOEXECFILE	EQU	<"\AUTOEXEC.BAT">
MCONFIGFILE	EQU	<"\CONFIG.APP">
MAUTOEXECFILE	EQU	<"\AUTOEXEC.APP">
WCONFIGFILE	EQU	<"\CONFIG.WOS">
WAUTOEXECFILE	EQU	<"\AUTOEXEC.WOS">
ifdef JAPAN
WAXHDRSIG30	EQU	<"AX WIN 3.0 PRIV">
endif

PIFEXTHDR	STRUC
extsig	DB	PIFEXTSIGSIZE DUP (?)
extnxthdrfloff	DW	?
extfileoffset	DW	?
extsizebytes	DW	?
PIFEXTHDR	ENDS
fResident	EQU	01H
fGraphics	EQU	02H
fNoSwitch	EQU	04H
fNoGrab	EQU	08H
fDestroy	EQU	10H
fCOM2	EQU	40H
fCOM1	EQU	80H
MEMMASK	EQU	fResident
GRAPHMASK	EQU	fGraphics
TEXTMASK	EQU	((NOT GRAPHMASK))
PSMASK	EQU	fNoSwitch
SGMASK	EQU	fNoGrab
EXITMASK	EQU	fDestroy
COM2MASK	EQU	fCOM2
COM1MASK	EQU	fCOM1
fScreen	EQU	80H
fForeground	EQU	40H
f8087	EQU	20H
fKeyboard	EQU	10H
SCRMASK	EQU	(fScreen+fForeground)
MASK8087	EQU	f8087
KEYMASK	EQU	fKeyboard
SWAPMASK	EQU	20H
PARMMASK	EQU	40H

STDPIF	STRUC
unknown	DB	?
id	DB	?
appname	DB	PIFNAMESIZE DUP (?)
maxmem	DW	?
minmem	DW	?
startfile	DB	PIFSTARTLOCSIZE DUP (?)
MSflags	DB	?
reserved	DB	?
defpath	DB	PIFDEFPATHSIZE DUP (?)
params	DB	PIFPARAMSSIZE DUP (?)
screen	DB	?
cPages	DB	?
lowVector	DB	?
highVector	DB	?
rows	DB	?
cols	DB	?
rowoff	DB	?
coloff	DB	?
sysmem	DW	?
shprog	DB	PIFSHPROGSIZE DUP (?)
shdata	DB	PIFSHDATASIZE DUP (?)
behavior	DB	?
sysflags	DB	?
STDPIF	ENDS
fALTTABdis286	EQU	0001H
fALTESCdis286	EQU	0002H
fALTPRTSCdis286	EQU	0004H
fPRTSCdis286	EQU	0008H
fCTRLESCdis286	EQU	0010H
fNoSaveVid286	EQU	0020H
fCOM3_286	EQU	4000H
fCOM4_286	EQU	8000H

W286PIF30	STRUC
PfMaxXmsK	DW	?
PfMinXmsK	DW	?
PfW286Flags	DW	?
W286PIF30	ENDS
fEnableClose	EQU	00000001H
fEnableCloseBit	EQU	0
fBackground	EQU	00000002H
fBackgroundBit	EQU	1
fFullScreen	EQU	00000008H
fFullScreenBit	EQU	3
fALTTABdis	EQU	00000020H
fALTTABdisBit	EQU	5
fALTESCdis	EQU	00000040H
fALTESCdisBit	EQU	6
fALTSPACEdis	EQU	00000080H
fALTSPACEdisBit	EQU	7
fALTENTERdis	EQU	00000100H
fALTENTERdisBit	EQU	8
fALTPRTSCdis	EQU	00000200H
fALTPRTSCdisBit	EQU	9
fPRTSCdis	EQU	00000400H
fPRTSCdisBit	EQU	10
fCTRLESCdis	EQU	00000800H
fCTRLESCdisBit	EQU	11
fPollingDetect	EQU	00001000H
fPollingDetectBit	EQU	12
fNoHMA	EQU	00002000H
fNoHMABit	EQU	13
fHasHotKey	EQU	00004000H
fHasHotKeyBit	EQU	14
fEMSLocked	EQU	00008000H
fEMSLockedBit	EQU	15
fXMSLocked	EQU	00010000H
fXMSLockedBit	EQU	16
fINT16Paste	EQU	00020000H
fINT16PasteBit	EQU	17
fVMLocked	EQU	00040000H
fVMLockedBit	EQU	18
fGlobalProtect	EQU	00080000H
fGlobalProtectBit	EQU	19
fMinimized	EQU	00100000H
fMinimizedBit	EQU	20
fMaximized	EQU	00200000H
fMaximizedBit	EQU	21
fRealMode	EQU	00800000H
fRealModeBit	EQU	23
fWinLie	EQU	01000000H
fWinLieBit	EQU	24
fNoSuggestMSDOS	EQU	04000000H
fNoSuggestMSDOSBit	EQU	26
fRealModeSilent	EQU	10000000H
fRealModeSilentBit	EQU	28
fAmbiguousPIF	EQU	40000000H
fAmbiguousPIFBit	EQU	30
fVDDMask	EQU	0000FFFFH
fVDDMinBit	EQU	0
fVDDMaxBit	EQU	15
ifndef NEC_98
fVidTxtEmulate	EQU	00000001H
fVidTxtEmulateBit	EQU	0
fVidNoTrpTxt	EQU	00000002H
fVidNoTrpTxtBit	EQU	1
fVidNoTrpLRGrfx	EQU	00000004H
fVidNoTrpLRGrfxBit	EQU	2
fVidNoTrpHRGrfx	EQU	00000008H
fVidNoTrpHRGrfxBit	EQU	3
endif
fVidTextMd	EQU	00000010H
fVidTextMdBit	EQU	4
ifndef NEC_98
fVidLowRsGrfxMd	EQU	00000020H
fVidLowRsGrfxMdBit	EQU	5
fVidHghRsGrfxMd	EQU	00000040H
fVidHghRsGrfxMdBit	EQU	6
fVidRetainAllo	EQU	00000080H
fVidRetainAlloBit	EQU	7
endif
ifdef  NEC_98
fVidNTModeFF	EQU	00000001H
fVidNTModeFFBit	EQU	0
fVidNTModeFFC16	EQU	00000002H
fVidNTModeFFC16Bit	EQU	1
fVidNTDispRW	EQU	00000004H
fVidNTDispRWBit	EQU	2
fVidNTPal	EQU	00000008H
fVidNTPalBit	EQU	3
fVidNTGDC	EQU	00000020H
fVidNTGDCBit	EQU	5
fVidNTGDCTON	EQU	00000040H
fVidNTGDCTONBit	EQU	6
fVidNTGDCGON	EQU	00000080H
fVidNTGDCGONBit	EQU	7
fVidNTFont	EQU	00000100H
fVidNTFontBit	EQU	8
fVidCRTC	EQU	00000200H
fVidCRTCBit	EQU	9
fVidDispDataXfer	EQU	00000400H
fVidDispDataXferBit	EQU	10
fVidXFERPlane0	EQU	00000800H
fVidXFERPlane0Bit	EQU	11
fVidXFERPlane1	EQU	00001000H
fVidXFERPlane1Bit	EQU	12
fVidXFERPlane2	EQU	00002000H
fVidXFERPlane2Bit	EQU	13
fVidXFERPlane3	EQU	00004000H
fVidXFERPlane3Bit	EQU	14
fVidXFERPlaneAll	EQU	00003C00H
fVidNTH98Mask	EQU	(fVidNTModeFF+fVidNTModeFFC16+fVidNTDispRW+fVidNTPal+fVidNTGDC+fVidNTGDCTON+fVidNTGDCGON)
endif

W386PIF30	STRUC
PfW386maxmem	DW	?
PfW386minmem	DW	?
PfFPriority	DW	?
PfBPriority	DW	?
PfMaxEMMK	DW	?
PfMinEMMK	DW	?
PfMaxXmsK	DW	?
PfMinXmsK	DW	?
PfW386Flags	DD	?
PfW386Flags2	DD	?
PfHotKeyScan	DW	?
PfHotKeyShVal	DW	?
PfHotKeyShMsk	DW	?
PfHotKeyVal	DB	?
PfHotKeyPad	DB	9 DUP (?)
PfW386params	DB	PIFPARAMSSIZE DUP (?)
W386PIF30	ENDS
ifdef JAPAN

WAXPIF30	STRUC
PfWAXInitCP	DW	?
WAXPIF30	ENDS
endif
HVM_ASSOCIATION	EQU	1
HWND_ASSOCIATION	EQU	2
SHEETTYPE_SIMPLE	EQU	0
SHEETTYPE_ADVANCED	EQU	1
ORD_OPENPROPERTIES	EQU	2
ORD_GETPROPERTIES	EQU	3
ORD_SETPROPERTIES	EQU	4
ORD_EDITPROPERTIES	EQU	5
ORD_FLUSHPROPERTIES	EQU	6
ORD_ENUMPROPERTIES	EQU	7
ORD_ASSOCIATEPROPERTIES	EQU	8
ORD_CLOSEPROPERTIES	EQU	9
ORD_LOADPROPERTYLIB	EQU	10
ORD_ENUMPROPERTYLIBS	EQU	11
ORD_FREEPROPERTYLIB	EQU	12
ORD_ADDPROPERTYSHEET	EQU	13
ORD_REMOVEPROPERTYSHEET	EQU	14
ORD_LOADPROPERTYSHEETS	EQU	15
ORD_ENUMPROPERTYSHEETS	EQU	16
ORD_FREEPROPERTYSHEETS	EQU	17
ORD_CREATESTARTUPPROPERTIES	EQU	20
ORD_DELETESTARTUPPROPERTIES	EQU	21
PIFWIZERR_SUCCESS	EQU	0
PIFWIZERR_GENERALFAILURE	EQU	1
PIFWIZERR_INVALIDPARAM	EQU	2
PIFWIZERR_UNSUPPORTEDOPT	EQU	3
PIFWIZERR_OUTOFMEM	EQU	4
PIFWIZERR_USERCANCELED	EQU	5
WIZACTION_UICONFIGPROP	EQU	0
WIZACTION_SILENTCONFIGPROP	EQU	1
WIZACTION_CREATEDEFCLEANCFG	EQU	2
endif
