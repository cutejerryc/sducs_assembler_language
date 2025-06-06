ifndef	_PCCARD_H
_PCCARD_H	EQU	1
PCCARD_DEVICE_ID	EQU	097CH
ifndef IS_16
Begin_Service_Table PCCARD, VxD
PCCARD_Service	     PCCARD_Get_Version, LOCAL
PCCARD_Service	     PCCARD_Card_Services, LOCAL
PCCARD_Service	     _PCCARD_Access_CIS_Memory, VxD_CODE
End_Service_Table PCCARD, VxD
ACMF_READ	EQU	00000000H
ACMF_WRITE	EQU	00000001H
endif
F_CLOSE_MEMORY	EQU	00H
F_COPY_MEMORY	EQU	01H
F_DEREGISTER_CLIENT	EQU	02H
F_GET_CLIENT_INFO	EQU	03H
F_GET_CONFIGURATION_INFO	EQU	04H
F_GET_FIRST_PARTITION	EQU	05H
F_GET_FIRST_REGION	EQU	06H
F_GET_FIRST_TUPLE	EQU	07H
F_GET_NEXT_PARTITION	EQU	08H
F_GET_NEXT_REGION	EQU	09H
F_GET_NEXT_TUPLE	EQU	0AH
F_GET_CARD_SERVICES_INFO	EQU	0BH
F_CS_GET_STATUS	EQU	0CH
F_GET_TUPLE_DATA	EQU	0DH
F_GET_FIRST_CLIENT	EQU	0EH
F_REGISTER_ERASE_QUEUE	EQU	0FH
F_REGISTER_CLIENT	EQU	10H
F_RESET_CARD	EQU	11H
F_MAP_LOG_SOCKET	EQU	12H
F_MAP_LOG_WINDOW	EQU	13H
F_MAP_MEM_PAGE	EQU	14H
F_MAP_PHY_SOCKET	EQU	15H
F_MAP_PHY_WINDOW	EQU	16H
F_MODIFY_WINDOW	EQU	17H
F_OPEN_MEMORY	EQU	18H
F_READ_MEMORY	EQU	19H
F_REGISTER_MTD	EQU	1AH
F_RELEASE_IO	EQU	1BH
F_RELEASE_IRQ	EQU	1CH
F_RELEASE_WINDOW	EQU	1DH
F_RELEASE_CONFIGURATION	EQU	1EH
F_REQUEST_IO	EQU	1FH
F_REQUEST_IRQ	EQU	20H
F_REQUEST_WINDOW	EQU	21H
F_REQUEST_SOCKET_MASK	EQU	22H
F_RETURN_SS_ENTRY	EQU	23H
F_WRITE_MEMORY	EQU	24H
F_DEREGISTER_ERASE_QUEUE	EQU	25H
F_CHECK_ERASE_QUEUE	EQU	26H
F_MODIFY_CONFIGURATION	EQU	27H
F_REGISTER_TIMER	EQU	28H
F_SET_REGION	EQU	29H
F_GET_NEXT_CLIENT	EQU	2AH
F_VALIDATE_CIS	EQU	2BH
F_REQUEST_EXCLUSIVE	EQU	2CH
F_RELEASE_EXCLUSIVE	EQU	2DH
F_GET_EVENT_MASK	EQU	2EH
F_RELEASE_SOCKET_MASK	EQU	2FH
F_REQUEST_CONFIGURATION	EQU	30H
F_SET_EVENT_MASK	EQU	31H
F_ADD_SOCKET_SERVICES	EQU	32H
F_REPLACE_SOCKET_SERVICES	EQU	33H
F_CS_VENDOR_SPECIFIC	EQU	34H
F_ADJUST_RESOURCE_INFO	EQU	35H
F_ACCESS_CONFIGURATION_REGISTER	EQU	36H
MAX_CS_FUNCTIONS	EQU	37H
EV_BATTERY_DEAD	EQU	01H
EV_BATTERY_LOW	EQU	02H
EV_CARD_LOCK	EQU	03H
EV_CARD_READY	EQU	04H
EV_CARD_REMOVAL	EQU	05H
EV_CARD_UNLOCK	EQU	06H
EV_EJECTION_COMPLETE	EQU	07H
EV_EJECTION_REQUEST	EQU	08H
EV_INSERTION_COMPLETE	EQU	09H
EV_INSERTION_REQUEST	EQU	0AH
EV_PM_RESUME	EQU	0BH
EV_PM_SUSPEND	EQU	0CH
EV_EXCLUSIVE_COMPLETE	EQU	0DH
EV_EXCLUSIVE_REQUEST	EQU	0EH
EV_RESET_PHYSICAL	EQU	0FH
EV_RESET_REQUEST	EQU	10H
EV_CARD_RESET	EQU	11H
EV_MTD_REQUEST	EQU	12H
EV_CLIENT_INFO	EQU	14H
EV_TIMER_EXPIRED	EQU	15H
EV_SS_UPDATED	EQU	16H
EV_WRITE_PROTECT	EQU	17H
EV_CARD_INSERTION	EQU	40H
EV_RESET_COMPLETE	EQU	80H
EV_ERASE_COMPLETE	EQU	81H
EV_REGISTRATION_COMPLETE	EQU	82H
R_SUCCESS	EQU	00H
R_BAD_ADAPTER	EQU	01H
R_BAD_ATTRIBUTE	EQU	02H
R_BAD_BASE	EQU	03H
R_BAD_EDC	EQU	04H
R_RESERVED_05	EQU	05H
R_BAD_IRQ	EQU	06H
R_BAD_OFFSET	EQU	07H
R_BAD_PAGE	EQU	08H
R_READ_FAILURE	EQU	09H
R_BAD_SIZE	EQU	0AH
R_BAD_SOCKET	EQU	0BH
R_RESERVED_0C	EQU	0CH
R_BAD_TYPE	EQU	0DH
R_BAD_VCC	EQU	0EH
R_BAD_VPP	EQU	0FH
R_RESERVED_10	EQU	10H
R_BAD_WINDOW	EQU	11H
R_WRITE_FAILURE	EQU	12H
R_RESERVED_13	EQU	13H
R_NO_CARD	EQU	14H
R_UNSUPPORTED_FUNCTION	EQU	15H
R_UNSUPPORTED_MODE	EQU	16H
R_BAD_SPEED	EQU	17H
R_BUSY	EQU	18H
R_GENERAL_FAILURE	EQU	19H
R_WRITE_PROTECTED	EQU	1AH
R_BAD_ARG_LENGTH	EQU	1BH
R_BAD_ARGS	EQU	1CH
R_CONFIGURATION_LOCKED	EQU	1DH
R_IN_USE	EQU	1EH
R_NO_MORE_ITEMS	EQU	1FH
R_OUT_OF_RESOURCE	EQU	20H
R_BAD_HANDLE	EQU	21H

AccessConfigurationRegister_s	STRUC
Socket	DW	?
Action	DB	?
RegOffset	DB	?
Value	DB	?
AccessConfigurationRegister_s	ENDS
ACRA_READ	EQU	0
ACRA_WRITE	EQU	1

AddSSData_s	STRUC
devnode	DD	?
AddSSData_s	ENDS

AddSocketServices_s	STRUC
Attributes	DW	?
DataPointer	DD	?
AddSocketServices_s	ENDS
SSA_REAL_MODE	EQU	0
SSA_1616_PROTECT_MODE	EQU	1
SSA_1632_PROTECT_MODE	EQU	2
SSA_FLAT_PROTECT_MODE	EQU	3
ARIR_MEM_RANGE	EQU	0
ARIR_IO_RANGE	EQU	1
ARIR_IRQ	EQU	2

CopyMemory_s	STRUC
SourceOffset	DD	?
DestOffset	DD	?
Count	DD	?
Attributes	DW	?
CopyMemory_s	ENDS
MEMA_DISABLE_ERASE	EQU	0004H
MEMA_VERIFY	EQU	0008H

GetCardServicesInfo_s	STRUC
InfoLen	DW	?
Signature	DB	2 DUP (?)
Count	DW	?
Revision	DW	?
CSLevel	DW	?
VStrOff	DW	?
VStrLen	DW	?
GetCardServicesInfo_s	ENDS

GetClientInfo_s	STRUC
MaxLen	DW	?
InfoLen	DW	?
Attributes	DW	?
Revision	DW	?
CSLevel	DW	?
RevDate	DW	?
NameOff	DW	?
NameLen	DW	?
VStringOff	DW	?
VStringLen	DW	?
GetClientInfo_s	ENDS
CLTA_MEM_DRIVER	EQU	0001H
CLTA_MTD_DRIVER	EQU	0002H
CLTA_IO_DRIVER	EQU	0004H
CLTA_INSERT_SHARED	EQU	0008H
CLTA_INSERT_EXCLUSIVE	EQU	0010H
CLTA_INFO_SUBFUNCTION	EQU	0FF00H
CLTA_DRIVER_MASK	EQU	(CLTA_MEM_DRIVER OR CLTA_MTD_DRIVER OR CLTA_IO_DRIVER)

IOParms_s	STRUC
BasePort	DW	?
NumPorts	DB	?
Attributes	DB	?
IOParms_s	ENDS
IOPA_SHARED	EQU	01H
IOPA_FIRST_SHARED	EQU	02H
IOPA_FORCE_ALIAS	EQU	04H
IOPA_16BIT	EQU	08H
MAX_IO_WDWS_PER_SKT	EQU	2

GetConfigurationInfo_s	STRUC
Socket	DW	?
Attributes	DW	?
Vcc	DB	?
Vpp1	DB	?
Vpp2	DB	?
IntType	DB	?
ConfigBase	DD	?
Status	DB	?
Pin	DB	?
Copy	DB	?
ConfigIndex	DB	?
Present	DB	?
FirstDevType	DB	?
FuncCode	DB	?
SysInitMask	DB	?
ManufCode	DW	?
ManufInfo	DW	?
CardValues	DB	?
AssignedIRQ	DB	?
IRQAttributes	DW	?
IOParms	DB	SIZE IOParms_s * MAX_IO_WDWS_PER_SKT DUP (?)
IOAddrLines	DB	?
GetConfigurationInfo_s	ENDS
CFGA_EXCLUSIVELY_USED	EQU	0001H
CFGA_ENABLE_IRQ	EQU	0002H
CFGA_VALID_CLIENT	EQU	0100H
CNFG_OPTION_VALID	EQU	01H
CNFG_STATUS_VALID	EQU	02H
CNFG_PIN_VALID	EQU	04H
CNFG_COPY_VALID	EQU	08H
CNFG_PRESENT_MASK	EQU	0FH
CNFG_STATUS_SIGCHG	EQU	40H
CNFG_STATUS_PWRDWN	EQU	04H

EventMask_s	STRUC
Attributes	DW	?
EventMask	DW	?
Socket	DW	?
EventMask_s	ENDS
EVTA_SOCKET_ONLY	EQU	0001H
EVTM_WRITE_PROTECT	EQU	0001H
EVTM_CARD_LOCK_CHG	EQU	0002H
EVTM_EJECT_REQUEST	EQU	0004H
EVTM_INSERT_REQUEST	EQU	0008H
EVTM_BATTERY_DEAD	EQU	0010H
EVTM_BATTERY_LOW	EQU	0020H
EVTM_READY_CHG	EQU	0040H
EVTM_CARD_DETECT_CHG	EQU	0080H
EVTM_PWR_MGMT_CHG	EQU	0100H
EVTM_RESET_EVENTS	EQU	0200H
EVTM_SS_UPDATED	EQU	0400H

GetClient_s	STRUC
Socket	DW	?
Attributes	DW	?
GetClient_s	ENDS
CLTA_SOCKET_ONLY	EQU	0001H

GetPartition_s	STRUC
Socket	DW	?
Attributes	DW	?
TupleMask	DB	?
AccessSpeed	DB	?
Flags	DW	?
LinkOffset	DD	?
CISOffset	DD	?
CardOffset	DD	?
PartSize	DD	?
EffBlockSize	DD	?
PartMultiple	DW	?
JedecID	DW	?
PartType	DW	?
GetPartition_s	ENDS
MEMA_ATTRIB_MEM	EQU	0001H
MEMA_VIRTUAL	EQU	0100H
MEMA_WRITE_ERASE_MASK	EQU	0600H
MEMA_WE_WRITE	EQU	0200H
MEMA_WE_WRITE_ERASE	EQU	0400H
MEMA_WE_DISABLE_ERASE	EQU	0600H
MEMA_WRITE_VERIFY	EQU	0800H
MEMA_ERASE_SUPPORTED	EQU	1000H
MEMM_ACCESS_SPEED	EQU	0001H
MEMM_CARD_OFFSET	EQU	0002H
MEMM_PART_SIZE	EQU	0004H
MEMM_EFF_BLK_SIZE	EQU	0008H
MEMM_PART_MULTIPLE	EQU	0010H
MEMM_JEDEC_ID	EQU	0020H
MEMM_PART_TYPE	EQU	0040H
ASP_CODE_EXP	EQU	07H
ASP_MANTISSA	EQU	71H
ASP_WAIT	EQU	80H
ASPC_250NS	EQU	01H
ASPC_200NS	EQU	02H
ASPC_150NS	EQU	03H
ASPC_100NS	EQU	04H
PRTT_NO_PART	EQU	0000H
PRTT_DOS_PART	EQU	0001H
PRTT_FFS1_PART	EQU	0002H
PRTT_FFS2_PART	EQU	0003H
PRTT_XIP_PART	EQU	0004H
PRTT_UNKNOWN_PART	EQU	7FFFH

GetRegion_s	STRUC
Socket	DW	?
Attributes	DW	?
TupleMask	DB	?
AccessSpeed	DB	?
Flags	DW	?
LinkOffset	DD	?
CISOffset	DD	?
CardOffset	DD	?
RegionSize	DD	?
EffBlockSize	DD	?
PartMultiple	DW	?
JedecID	DW	?
GetRegion_s	ENDS

GetTuple_s	STRUC
Socket	DW	?
Attributes	DW	?
DesiredTuple	DB	?
Reserved	DB	?
Flags	DW	?
LinkOffset	DD	?
CISOffset	DD	?
TupleCode	DB	?
TupleLink	DB	?
GetTuple_s	ENDS
TPLA_RET_LINKS	EQU	0001H
TPLC_ANY_TUPLE	EQU	0FFH

GetStatus_s	STRUC
Socket	DW	?
CardState	DW	?
SocketState	DW	?
GetStatus_s	ENDS
CRDS_WRITE_PROTECTED	EQU	0001H
CRDS_CARD_LOCKED	EQU	0002H
CRDS_EJECT_REQUEST	EQU	0004H
CRDS_INSERT_REQUEST	EQU	0008H
CRDS_BATTERY_DEAD	EQU	0010H
CRDS_BATTERY_WARNING	EQU	0020H
CRDS_READY	EQU	0040H
CRDS_CARD_DETECTED	EQU	0080H
SKTS_WRITE_PROTECT	EQU	0001H
SKTS_CARD_LOCK	EQU	0002H
SKTS_EJECT_REQUEST	EQU	0004H
SKTS_INSERT_REQUEST	EQU	0008H
SKTS_BATTERY_DEAD	EQU	0010H
SKTS_BATTERY_WARNING	EQU	0020H
SKTS_READY	EQU	0040H
SKTS_CARD_DETECT	EQU	0080H

GetTupleData_s	STRUC
Socket	DW	?
Attributes	DW	?
DesiredTuple	DB	?
TupleOffset	DB	?
Flags	DW	?
LinkOffset	DD	?
CISOffset	DD	?
TupleDataMax	DW	?
TupleDataLen	DW	?
GetTupleData_s	ENDS

MapSocket_s	STRUC
LogSocket	DW	?
PhyAdapter	DB	?
PhySocket	DB	?
MapSocket_s	ENDS

MapWindow_s	STRUC
PhyAdapter	DB	?
PhyWindow	DB	?
MapWindow_s	ENDS

MapMemPage_s	STRUC
CardOffset	DD	?
PageNum	DB	?
MapMemPage_s	ENDS

ModifyConfiguration_s	STRUC
Socket	DW	?
Attributes	DW	?
Vcc	DB	?
Vpp1	DB	?
Vpp2	DB	?
ModifyConfiguration_s	ENDS
CFGA_IRQ_CHG	EQU	0004H
CFGA_VCC_CHG	EQU	0008H
CFGA_VPP1_CHG	EQU	0010H
CFGA_VPP2_CHG	EQU	0020H

ModifyWindow_s	STRUC
Attributes	DW	?
AccessSpeed	DB	?
ModifyWindow_s	ENDS
WDWA_ATTRIB_MEM	EQU	0002H
WDWA_ENABLED	EQU	0004H
WDWA_SPEED_VALID	EQU	0008H

OpenMemory_s	STRUC
Socket	DW	?
Attributes	DW	?
CardOffset	DD	?
OpenMemory_s	ENDS
OPMA_ATTRIB_MEM	EQU	0001H
OPMA_EXCLUSIVE	EQU	0002H

ReadMemory_s	STRUC
CardOffset	DD	?
Count	DD	?
ReadMemory_s	ENDS

ClientData_s	STRUC
ReferenceData	DW	?
ReservedWord	DW	?
DataOffset	DD	?
ClientData_s	ENDS

RegisterClient_s	STRUC
Attributes	DW	?
EventMask	DW	?
ClientData	DB	SIZE ClientData_s DUP (?)
Version	DW	?
RegisterClient_s	ENDS

QueueEntry_s	STRUC
MemoryHandle	DW	?
EntryState	DB	?
EraseSize	DB	?
EraseOffset	DD	?
QueueEntry_s	ENDS

RegisterEraseQueue_s	STRUC
QueueEntryLen	DW	?
QueueEntryCnt	DW	?
RegisterEraseQueue_s	ENDS
EQES_QUEUED_FOR_ERASE	EQU	00H
EQES_ERASE_IN_PROGRESS	EQU	01H
EQES_MEDIA_MISSING	EQU	80H
EQES_MEDIA_WRITE_PROTECTED	EQU	84H
EQES_MEDIA_NOT_ERASABLE	EQU	86H
EQES_MEDIA_NOT_WRITABLE	EQU	87H
EQES_BAD_OFFSET	EQU	0C1H
EQES_BAD_TECHNOLOGY	EQU	0C2H
EQES_BAD_SOCKET	EQU	0C3H
EQES_BAD_VCC	EQU	0C4H
EQES_BAD_VPP	EQU	0C5H
EQES_BAD_SIZE	EQU	0C6H
EQES_ERASE_PASSED	EQU	0E0H
EQES_ERASE_FAILED	EQU	0E1H
EQES_IDLE	EQU	0FFH

RegisterMTD_s	STRUC
Socket	DW	?
Attributes	DW	?
CardOffset	DD	?
MTDMediaID	DW	?
RegisterMTD_s	ENDS

MTDRequest_s	STRUC
PktLength	DW	?
Socket	DW	?
SourceOffset	DD	?
DestOffset	DD	?
XferLength	DD	?
Function	DB	?
AccessSpeed	DB	?
MTDID	DW	?
MTDStatus	DW	?
TimeoutCount	DW	?
MATDataPtr	DD	?
CardSetAddressPtr	DD	?
CardSetAutoIncPtr	DD	?
CardReadBytePtr	DD	?
CardReadWordPtr	DD	?
CardReadWordsPtr	DD	?
CardReadByteAIPtr	DD	?
CardReadWordAIPtr	DD	?
CardReadWordsAIPtr	DD	?
CardWriteBytePtr	DD	?
CardWriteWordPtr	DD	?
CardWriteWordsPtr	DD	?
CardWriteByteAIPtr	DD	?
CardWriteWordAIPtr	DD	?
CardWriteWordsAIPtr	DD	?
CardCompareBytePtr	DD	?
CardCompareByteAIPtr	DD	?
CardCompareWordsPtr	DD	?
CardCompareWordsAIPtr	DD	?
MTDHelperEntryPtr	DD	?
MTDRequest_s	ENDS
MTDF_FUNC	EQU	03H
MTDF_ERASE	EQU	00H
MTDF_READ	EQU	01H
MTDF_WRITE	EQU	02H
MTDF_COPY	EQU	03H
MTDF_DISABLE_ERASE	EQU	04H
MTDF_VERIFY	EQU	08H
MTDF_READY_CONT	EQU	10H
MTDF_TIMEOUT_CONT	EQU	20H
MTDF_FIRST	EQU	40H
MTDF_LAST	EQU	80H
MTDS_WAITREQ	EQU	0
MTDS_WAITTIMER	EQU	1
MTDS_WAITRDY	EQU	2
MTDS_WAITPOWER	EQU	3

MTDInit_s	STRUC
Socket	DW	?
CardOffset	DD	?
MTDInit_s	ENDS

RegisterTimer_s	STRUC
WaitTicks	DW	?
RegisterTimer_s	ENDS

ReleaseConfiguration_s	STRUC
Socket	DW	?
ReleaseConfiguration_s	ENDS

Exclusive_s	STRUC
Socket	DW	?
Attributes	DW	?
Exclusive_s	ENDS

ReleaseIO_s	STRUC
Socket	DW	?
IOParms	DB	SIZE IOParms_s * MAX_IO_WDWS_PER_SKT DUP (?)
IOAddrLines	DB	?
ReleaseIO_s	ENDS

ReleaseIRQ_s	STRUC
Socket	DW	?
Attributes	DW	?
AssignedIRQ	DB	?
ReleaseIRQ_s	ENDS
IRQA_IRQ_TYPE_MASK	EQU	0003H
IRQA_EXCLUSIVE	EQU	0
IRQA_TIME_MUX	EQU	1
IRQA_DYNAMIC	EQU	2
IRQA_FORCE_PULSE	EQU	0004H
IRQA_FIRST_SHARED	EQU	0008H
IRQA_PULSE_ALLOC	EQU	0100H

ReleaseSocketMask_s	STRUC
Socket	DW	?
ReleaseSocketMask_s	ENDS

ReplaceSocketServices_s	STRUC
Socket	DW	?
NumSockets	DW	?
Attributes	DW	?
DataPointer	DD	?
ReplaceSocketServices_s	ENDS

RequestConfiguration_s	STRUC
Socket	DW	?
Attributes	DW	?
Vcc	DB	?
Vpp1	DB	?
Vpp2	DB	?
IntType	DB	?
ConfigBase	DD	?
Status	DB	?
Pin	DB	?
Copy	DB	?
ConfigIndex	DB	?
Present	DB	?
RequestConfiguration_s	ENDS
CFGI_MEMORY	EQU	01H
CFGI_MEMORY_AND_IO	EQU	02H

RequestIO_s	STRUC
Socket	DW	?
IOParms	DB	SIZE IOParms_s * MAX_IO_WDWS_PER_SKT DUP (?)
IOAddrLines	DB	?
RequestIO_s	ENDS

RequestIRQ_s	STRUC
Socket	DW	?
Attributes	DW	?
AssignedIRQ	DB	?
IRQInfo1	DB	?
IRQInfo2	DW	?
RequestIRQ_s	ENDS
IRQI_NUMBER_MASK	EQU	0FH
IRQI_NMI	EQU	01H
IRQI_LOCK	EQU	02H
IRQI_BERR	EQU	04H
IRQI_VEND	EQU	08H
IRQI_MASK	EQU	10H
IRQI_LEVEL	EQU	20H
IRQI_PULSE	EQU	40H
IRQI_SHARE	EQU	80H

RequestSocketMask_s	STRUC
Socket	DW	?
EventMask	DW	?
RequestSocketMask_s	ENDS

RequestWindow_s	STRUC
Socket	DW	?
Attributes	DW	?
Base	DD	?
MemSize	DD	?
AccessSpeed	DB	?
RequestWindow_s	ENDS
WDWA_16BIT	EQU	0008H
WDWA_PAGED	EQU	0010H
WDWA_SHARED	EQU	0020H
WDWA_FIRST_SHARED	EQU	0040H
WDWA_OFFSETS_SIZED	EQU	0100H

ResetCard_s	STRUC
Socket	DW	?
Attributes	DW	?
ResetCard_s	ENDS

ReturnSSEntry_s	STRUC
Attributes	DW	?
ReturnSSEntry_s	ENDS

SetRegion_s	STRUC
Socket	DW	?
Attributes	DW	?
CardOffset	DD	?
RegionSize	DD	?
EffBlockSize	DD	?
PartMultiple	DW	?
JedecID	DW	?
BiasOffset	DD	?
AccessSpeed	DB	?
SetRegion_s	ENDS
MEMA_DELETE_REGION	EQU	0002H

ValidateCIS_s	STRUC
Socket	DW	?
Chains	DW	?
ValidateCIS_s	ENDS

WriteMemory_s	STRUC
CardOffset	DD	?
Count	DD	?
Attributes	DW	?
WriteMemory_s	ENDS
endif
