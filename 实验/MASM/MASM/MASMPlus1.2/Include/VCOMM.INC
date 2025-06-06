ifndef _VCOMM_H
_VCOMM_H	EQU	1
ifndef Not_VxD
Begin_Service_Table VCOMM, VxD
VCOMM_Service	 VCOMM_Get_Version, LOCAL
VCOMM_Service	 _VCOMM_Register_Port_Driver,LOCAL
VCOMM_Service	 _VCOMM_Acquire_Port,LOCAL
VCOMM_Service	 _VCOMM_Release_Port,LOCAL
VCOMM_Service	 _VCOMM_OpenComm, VxD_CODE
VCOMM_Service	 _VCOMM_SetCommState, VxD_CODE
VCOMM_Service	 _VCOMM_GetCommState, VxD_CODE
VCOMM_Service	 _VCOMM_SetupComm, VxD_CODE
VCOMM_Service	 _VCOMM_TransmitCommChar, VxD_CODE
VCOMM_Service	 _VCOMM_CloseComm, VxD_CODE
VCOMM_Service	 _VCOMM_GetCommQueueStatus, VxD_CODE
VCOMM_Service	 _VCOMM_ClearCommError, VxD_CODE
VCOMM_Service	 _VCOMM_GetModemStatus, VxD_CODE
VCOMM_Service	 _VCOMM_GetCommProperties, VxD_CODE
VCOMM_Service	 _VCOMM_EscapeCommFunction, VxD_CODE
VCOMM_Service	 _VCOMM_PurgeComm, VxD_CODE
VCOMM_Service	 _VCOMM_SetCommEventMask, VxD_CODE
VCOMM_Service	 _VCOMM_GetCommEventMask, VxD_CODE
VCOMM_Service	 _VCOMM_WriteComm, VxD_CODE
VCOMM_Service	 _VCOMM_ReadComm, VxD_CODE
VCOMM_Service	 _VCOMM_EnableCommNotification, VxD_CODE
VCOMM_Service	 _VCOMM_GetLastError, VxD_CODE
VCOMM_Service	 _VCOMM_Steal_Port,LOCAL
VCOMM_Service	 _VCOMM_SetReadCallBack, VxD_CODE
VCOMM_Service	 _VCOMM_SetWriteCallBack, VxD_CODE
VCOMM_Service	 _VCOMM_Add_Port, LOCAL
ifndef		WIN31COMPAT
VCOMM_Service	 _VCOMM_GetSetCommTimeouts, VxD_CODE
VCOMM_Service	 _VCOMM_SetWriteRequest, VxD_CODE
VCOMM_Service	 _VCOMM_SetReadRequest, VxD_CODE
VCOMM_Service	 _VCOMM_Dequeue_Request, VxD_CODE
VCOMM_Service	 _VCOMM_Enumerate_DevNodes, VxD_CODE
VCOMM_Service	 VCOMM_Map_Win32DCB_To_Ring0, VxD_CODE
VCOMM_Service	 VCOMM_Map_Ring0DCB_To_Win32, VxD_CODE
VCOMM_Service	 _VCOMM_Get_Contention_Handler, VxD_CODE
VCOMM_Service	 _VCOMM_Map_Name_To_Resource, VxD_CODE
endif
VCOMM_Service	 _VCOMM_PowerOnOffComm, VxD_CODE
End_Service_Table VCOMM, VxD
endif

_PortFunctions	STRUC
pPortSetCommState	DD	?
pPortGetCommState	DD	?
pPortSetup	DD	?
pPortTransmitChar	DD	?
pPortClose	DD	?
pPortGetQueueStatus	DD	?
pPortClearError	DD	?
pPortSetModemStatusShadow	DD	?
pPortGetProperties	DD	?
pPortEscapeFunction	DD	?
pPortPurge	DD	?
pPortSetEventMask	DD	?
pPortGetEventMask	DD	?
pPortWrite	DD	?
pPortRead	DD	?
pPortEnableNotification	DD	?
pPortSetReadCallBack	DD	?
pPortSetWriteCallBack	DD	?
pPortGetModemStatus	DD	?
ifndef	WIN31COMPAT
pPortGetCommConfig	DD	?
pPortSetCommConfig	DD	?
pPortGetError	DD	?
pPortDeviceIOCtl	DD	?
endif
_PortFunctions	ENDS

COMMTIMEOUTS	STRUC
ReadIntervalTimeout	DD	?
ReadTotalTimeoutMultiplier	DD	?
ReadTotalTimeoutConstant	DD	?
WriteTotalTimeoutMultiplier	DD	?
WriteTotalTimeoutConstant	DD	?
COMMTIMEOUTS	ENDS

_PortData	STRUC
PDLength	DW	?
PDVersion	DW	?
PDfunctions	DD	?
PDNumFunctions	DD	?
dwLastError	DD	?
dwClientEventMask	DD	?
lpClientEventNotify	DD	?
lpClientReadNotify	DD	?
lpClientWriteNotify	DD	?
dwClientRefData	DD	?
dwWin31Req	DD	?
dwClientEvent	DD	?
dwCallerVMId	DD	?
dwDetectedEvents	DD	?
dwCommError	DD	?
bMSRShadow	DB	?
wFlags	DW	?
LossByte	DB	?
QInAddr	DD	?
QInSize	DD	?
QOutAddr	DD	?
QOutSize	DD	?
QInCount	DD	?
QInGet	DD	?
QInPut	DD	?
QOutCount	DD	?
QOutGet	DD	?
QOutPut	DD	?
ValidPortData	DD	?
lpLoadHandle	DD	?
cmto	DB	SIZE COMMTIMEOUTS DUP (?)
lpReadRequestQueue	DD	?
lpWriteRequestQueue	DD	?
dwLastReceiveTime	DD	?
dwReserved1	DD	?
dwReserved2	DD	?
_PortData	ENDS
ifndef	Not_VxD
IE_BADID	EQU	-1
IE_OPEN	EQU	-2
IE_NOPEN	EQU	-3
IE_MEMORY	EQU	-4
IE_DEFAULT	EQU	-5
IE_INVALIDSERVICE	EQU	-6
IE_HARDWARE	EQU	-10
IE_BYTESIZE	EQU	-11
IE_BAUDRATE	EQU	-12
IE_EXTINVALID	EQU	-20
IE_INVALIDPARAM	EQU	-21
IE_TRANSMITCHARFAILED	EQU	-30
IE_DEVICEID	EQU	-31
EV_RXCHAR	EQU	00000001H
EV_RXFLAG	EQU	00000002H
EV_TXEMPTY	EQU	00000004H
EV_CTS	EQU	00000008H
EV_DSR	EQU	00000010H
EV_RLSD	EQU	00000020H
EV_BREAK	EQU	00000040H
EV_ERR	EQU	00000080H
EV_RING	EQU	00000100H
EV_PERR	EQU	00000200H
EV_CTSS	EQU	00000400H
EV_DSRS	EQU	00000800H
EV_RLSDS	EQU	00001000H
EV_RingTe	EQU	00002000H
EV_TXCHAR	EQU	00004000H
EV_DRIVER	EQU	00008000H
EV_UNAVAIL	EQU	00010000H
EV_AVAIL	EQU	00020000H
CE_RXOVER	EQU	00000001H
CE_OVERRUN	EQU	00000002H
CE_RXPARITY	EQU	00000004H
CE_FRAME	EQU	00000008H
CE_BREAK	EQU	00000010H
CE_CTSTO	EQU	00000020H
CE_DSRTO	EQU	00000040H
CE_RLSDTO	EQU	00000080H
CE_TXFULL	EQU	00000100H
CE_PTO	EQU	00000200H
CE_IOE	EQU	00000400H
CE_DNS	EQU	00000800H
CE_OOP	EQU	00001000H
CE_Unused1	EQU	00002000H
CE_Unused2	EQU	00004000H
CE_MODE	EQU	00008000H
endif
MS_CTS_ON	EQU	0010H
MS_DSR_ON	EQU	0020H
MS_RING_ON	EQU	0040H
MS_RLSD_ON	EQU	0080H
MS_Modem_Status	EQU	00F0H
Event_Sent	EQU	0001H
Event_Sent_Bit	EQU	0000H
TimeOut_Error	EQU	0002H
TimeOut_Error_Bit	EQU	0001H
Flush_In_Progress	EQU	0004H
Flush_In_Progress_Bit	EQU	0002H
TxQueuesSet	EQU	0008H
TxQueuesSetBit	EQU	0003H
CloseComm_In_Progress	EQU	0010H
CloseComm_In_Progress_Bit	EQU	0004H
Spec_Timeouts_Set	EQU	0020H
Spec_Timeouts_Set_Bit	EQU	0005H

_DCB	STRUC
DCBLength	DD	?
BaudRate	DD	?
BitMask	DD	?
XonLim	DD	?
XoffLim	DD	?
wReserved	DW	?
ByteSize	DB	?
Parity	DB	?
StopBits	DB	?
XonChar	DB	?
XoffChar	DB	?
ErrorChar	DB	?
EofChar	DB	?
EvtChar1	DB	?
EvtChar2	DB	?
bReserved	DB	?
RlsTimeout	DD	?
CtsTimeout	DD	?
DsrTimeout	DD	?
TxDelay	DD	?
_DCB	ENDS
ifndef	Not_VxD
CBR_110	EQU	0000FF10H
CBR_300	EQU	0000FF11H
CBR_600	EQU	0000FF12H
CBR_1200	EQU	0000FF13H
CBR_2400	EQU	0000FF14H
CBR_4800	EQU	0000FF15H
CBR_9600	EQU	0000FF16H
CBR_14400	EQU	0000FF17H
CBR_19200	EQU	0000FF18H
CBR_38400	EQU	0000FF1BH
CBR_56000	EQU	0000FF1FH
CBR_128000	EQU	0000FF23H
CBR_256000	EQU	0000FF27H
endif
fBinary	EQU	00000001H
fRTSDisable	EQU	00000002H
fParity	EQU	00000004H
fOutXCTSFlow	EQU	00000008H
fOutXDSRFlow	EQU	00000010H
fEnqAck	EQU	00000020H
fEtxAck	EQU	00000040H
fDTRDisable	EQU	00000080H
fOutX	EQU	00000100H
fInX	EQU	00000200H
fPErrChar	EQU	00000400H
fNullStrip	EQU	00000800H
fCharEvent	EQU	00001000H
fDTRFlow	EQU	00002000H
fRTSFlow	EQU	00004000H
fWin30Compat	EQU	00008000H
fDsrSensitivity	EQU	00010000H
fTxContinueOnXoff	EQU	00020000H
fDtrEnable	EQU	00040000H
fAbortOnError	EQU	00080000H
fRTSEnable	EQU	00100000H
fRTSToggle	EQU	00200000H
NOPARITY	EQU	0
ODDPARITY	EQU	1
EVENPARITY	EQU	2
MARKPARITY	EQU	3
SPACEPARITY	EQU	4
ONESTOPBIT	EQU	0
ONE5STOPBITS	EQU	1
TWOSTOPBITS	EQU	2
WCHAR STRUC  
	DW	?
WCHAR ENDS

_COMMPROP	STRUC
wPacketLength	DW	?
wPacketVersion	DW	?
dwServiceMask	DD	?
dwReserved1	DD	?
dwMaxTxQueue	DD	?
dwMaxRxQueue	DD	?
dwMaxBaud	DD	?
dwProvSubType	DD	?
dwProvCapabilities	DD	?
dwSettableParams	DD	?
dwSettableBaud	DD	?
wSettableData	DW	?
wSettableStopParity	DW	?
dwCurrentTxQueue	DD	?
dwCurrentRxQueue	DD	?
dwProvSpec1	DD	?
dwProvSpec2	DD	?
wcProvChar	DW	1 DUP (?)
filler	DW	?
_COMMPROP	ENDS
SP_SERIALCOMM	EQU	(00000001H)
PST_UNSPECIFIED	EQU	(00000000H)
PST_RS232	EQU	(00000001H)
PST_PARALLELPORT	EQU	(00000002H)
PST_RS422	EQU	(00000003H)
PST_RS423	EQU	(00000004H)
PST_RS449	EQU	(00000005H)
PST_MODEM	EQU	(00000006H)
PST_FAX	EQU	(00000021H)
PST_SCANNER	EQU	(00000022H)
PST_NETWORK_BRIDGE	EQU	(00000100H)
PST_LAT	EQU	(00000101H)
PST_TCPIP_TELNET	EQU	(00000102H)
PST_X25	EQU	(00000103H)
PCF_DTRDSR	EQU	(0001H)
PCF_RTSCTS	EQU	(0002H)
PCF_RLSD	EQU	(0004H)
PCF_PARITY_CHECK	EQU	(0008H)
PCF_XONXOFF	EQU	(0010H)
PCF_SETXCHAR	EQU	(0020H)
PCF_TOTALTIMEOUTS	EQU	(0040H)
PCF_INTTIMEOUTS	EQU	(0080H)
PCF_SPECIALCHARS	EQU	(0100H)
PCF_16BITMODE	EQU	(0200H)
SP_PARITY	EQU	(0001H)
SP_BAUD	EQU	(0002H)
SP_DATABITS	EQU	(0004H)
SP_STOPBITS	EQU	(0008H)
SP_HANDSHAKING	EQU	(0010H)
SP_PARITY_CHECK	EQU	(0020H)
SP_RLSD	EQU	(0040H)
BAUD_075	EQU	(00000001H)
BAUD_110	EQU	(00000002H)
BAUD_134_5	EQU	(00000004H)
BAUD_150	EQU	(00000008H)
BAUD_300	EQU	(00000010H)
BAUD_600	EQU	(00000020H)
BAUD_1200	EQU	(00000040H)
BAUD_1800	EQU	(00000080H)
BAUD_2400	EQU	(00000100H)
BAUD_4800	EQU	(00000200H)
BAUD_7200	EQU	(00000400H)
BAUD_9600	EQU	(00000800H)
BAUD_14400	EQU	(00001000H)
BAUD_19200	EQU	(00002000H)
BAUD_38400	EQU	(00004000H)
BAUD_56K	EQU	(00008000H)
BAUD_128K	EQU	(00010000H)
BAUD_USER	EQU	(10000000H)
DATABITS_5	EQU	(0001H)
DATABITS_6	EQU	(0002H)
DATABITS_7	EQU	(0004H)
DATABITS_8	EQU	(0008H)
DATABITS_16	EQU	(0010H)
DATABITS_16X	EQU	(0020H)
STOPBITS_10	EQU	(0001H)
STOPBITS_15	EQU	(0002H)
STOPBITS_20	EQU	(0004H)
PARITY_NONE	EQU	(0100H)
PARITY_ODD	EQU	(0200H)
PARITY_EVEN	EQU	(0400H)
PARITY_MARK	EQU	(0800H)
PARITY_SPACE	EQU	(1000H)

_COMSTAT	STRUC
BitMask	DD	?
cbInque	DD	?
cbOutque	DD	?
_COMSTAT	ENDS
fCtsHold	EQU	00000001H
fDsrHold	EQU	00000002H
fRlsdHold	EQU	00000004H
fXoffHold	EQU	00000008H
fXoffSent	EQU	00000010H
fEof	EQU	00000020H
fTximmed	EQU	00000040H

_QSB	STRUC
ReceiveQueueGetPtr	DD	?
ReceiveQueueCount	DD	?
_QSB	ENDS
VCOMM_PM_API_OpenCom	EQU	0
VCOMM_PM_API_SetCom	EQU	1
VCOMM_PM_API_Setup	EQU	2
VCOMM_PM_API_ctx	EQU	3
VCOMM_PM_API_TrmCom	EQU	4
VCOMM_PM_API_StaCom	EQU	5
VCOMM_PM_API_cextnfcn	EQU	6
VCOMM_PM_API_cFlush	EQU	7
VCOMM_PM_API_cevt	EQU	8
VCOMM_PM_API_cevtget	EQU	9
VCOMM_PM_API_SetMSRShadow	EQU	10
VCOMM_PM_API_WriteString	EQU	11
VCOMM_PM_API_ReadString	EQU	12
VCOMM_PM_API_EnableNotify	EQU	13
ifndef	Not_VxD
Dummy	EQU	0
SETXOFF	EQU	1
SETXON	EQU	2
SETRTS	EQU	3
CLRRTS	EQU	4
SETDTR	EQU	5
CLRDTR	EQU	6
RESETDEV	EQU	7
endif
ifdef	Not_VxD
GETLPTMAX	EQU	8
GETCOMMAX	EQU	9
endif
GETCOMBASEIRQ	EQU	10
GETCOMBASEIRQ1	EQU	11
SETBREAK	EQU	12
CLEARBREAK	EQU	13
ifdef	Not_VxD
GETPORTHANDLE	EQU	14
GETEXTENDEDFNADDR	EQU	15
endif
CLRTIMERLOGIC	EQU	16
GETDEVICEID	EQU	17
SETECPADDRESS	EQU	18
SETUPDATETIMEADDR	EQU	19
IGNOREERRORONREADS	EQU	20
ENABLETIMERLOGIC	EQU	21
IGNORESELECT	EQU	22
SET_PEPPY_RLE_COUNT	EQU	23
SET_PEPPY_BURST_SIZE	EQU	24
GETCURRENTMODE	EQU	25
PREPFLAG	EQU	26
GETPORTSTATUS	EQU	27
PM_QUERY_D1	EQU	28
PM_QUERY_D2	EQU	29
PM_QUERY_D3	EQU	30
PM_CANCEL_D1	EQU	31
PM_CANCEL_D2	EQU	32
PM_CANCEL_D3	EQU	33
PM_SET_D0	EQU	34
PM_SET_D1	EQU	35
PM_SET_D2	EQU	36
PM_SET_D3	EQU	37
PM_ARM_WAKEUP	EQU	38
PM_DISARM_WAKEUP	EQU	39
STARTNONSTDESCAPES	EQU	200
PEEKCHAR	EQU	200
PM_SUCCESS	EQU	0
PM_FAILURE	EQU	1
ifndef	Not_VxD
CN_RECEIVE	EQU	1
CN_TRANSMIT	EQU	2
CN_EVENT	EQU	4
endif
ifndef	Not_VxD
IGNORE	EQU	0
endif
INFINITE32	EQU	-1
PD_UNSUPPORTED	EQU	0
PD_DEFAULT	EQU	1
PD_BEST	EQU	-1
fBaudRate	EQU	00000001H
fBitMask	EQU	00000002H
fXonLim	EQU	00000004H
fXoffLim	EQU	00000008H
fByteSize	EQU	00000010H
fbParity	EQU	00000020H
fStopBits	EQU	00000040H
fXonChar	EQU	00000080H
fXoffChar	EQU	00000100H
fErrorChar	EQU	00000200H
fEofChar	EQU	00000400H
fEvtChar1	EQU	00000800H
fEvtChar2	EQU	00001000H
fRlsTimeout	EQU	00002000H
fCtsTimeout	EQU	00004000H
fDsrTimeout	EQU	00008000H
fTxDelay	EQU	00010000H
fTimeout	EQU	(fRlsTimeout OR fDsrTimeout OR fCtsTimeout)
fLCR	EQU	00000070H

IORequest	STRUC
IOBuffer	DD	?
IOCount	DD	?
IOCallCompletionRoutine	DD	?
NumBytes	DD	?
dwReserved	DD	8 DUP (?)
dwSig	DD	?
IORequest	ENDS
WRITE_REQUEST	EQU	1
READ_REQUEST	EQU	0
DC_Initialize	EQU	00000000H

IFDEF	WIN31COMPAT

VxD_My_Pageable_Code_Seg MACRO
VxD_Locked_Code_Seg
ENDM

VxD_My_Pageable_Code_Ends MACRO
VxD_Locked_Code_Ends
ENDM

VxD_My_Pageable_Data_Seg MACRO
VxD_Locked_Data_Seg
ENDM

VxD_My_Pageable_Data_Ends MACRO
VxD_Locked_Data_Ends
ENDM


ELSE

VxD_My_Pageable_Code_Seg MACRO
VxD_Pageable_Code_Seg
ENDM

VxD_My_Pageable_Code_Ends MACRO
VxD_Pageable_Code_Ends
ENDM

VxD_My_Pageable_Data_Seg MACRO
VxD_Pageable_Data_Seg
ENDM

VxD_My_Pageable_Data_Ends MACRO
VxD_Pageable_Data_Ends
ENDM

ENDIF


ERROR_NOT_READY	EQU	21
ERROR_OUT_OF_PAPER	EQU	28
ERROR_COUNTER_TIMEOUT	EQU	1121
endif

IOCtlBlock	STRUC
IO_lpOverlapped	DD	?
IO_lpcbBytesReturned	DD	?
IO_Event	DD	?
IO_ThreadHandle	DD	?
IO_NumBytesReturned	DD	?
IOCtlBlock	ENDS
MAP_DEVICE_TO_RESOURCE	EQU	0
ACQUIRE_RESOURCE	EQU	1
STEAL_RESOURCE	EQU	2
RELEASE_RESOURCE	EQU	3
ADD_RESOURCE	EQU	4
REMOVE_RESOURCE	EQU	5
MAX_CONTEND_FUNCTIONS	EQU	5
