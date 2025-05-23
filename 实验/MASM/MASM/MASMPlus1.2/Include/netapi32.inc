  ; ===========================================
  ; netapi32.inc copyright MASM32 1998 - 2003
  ; ===========================================

DsAddressToSiteNamesA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsAddressToSiteNames equ <DsAddressToSiteNamesA>

DsAddressToSiteNamesExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsAddressToSiteNamesEx equ <DsAddressToSiteNamesExA>

DsAddressToSiteNamesExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsAddressToSiteNamesW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsDeregisterDnsHostRecordsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsDeregisterDnsHostRecords equ <DsDeregisterDnsHostRecordsA>

DsDeregisterDnsHostRecordsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsEnumerateDomainTrustsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsEnumerateDomainTrusts equ <DsEnumerateDomainTrustsA>

DsEnumerateDomainTrustsW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsGetDcClose PROTO :DWORD
DsGetDcNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsGetDcName equ <DsGetDcNameA>

DsGetDcNameW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsGetDcNameWithAccountA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsGetDcNameWithAccount equ <DsGetDcNameWithAccountA>

DsGetDcNameWithAccountW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsGetDcNext PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsGetDcOpen PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsGetDcSiteCoverageA PROTO :DWORD,:DWORD,:DWORD
DsGetDcSiteCoverage equ <DsGetDcSiteCoverageA>

DsGetDcSiteCoverageW PROTO :DWORD,:DWORD,:DWORD
DsGetSiteNameA PROTO :DWORD,:DWORD
DsGetSiteName equ <DsGetSiteNameA>

DsGetSiteNameW PROTO :DWORD,:DWORD
DsRoleAbortDownlevelServerUpgrade PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsRoleCancel PROTO :DWORD,:DWORD
DsRoleDcAsDc PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsRoleDcAsReplica PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsRoleDemoteDc PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsRoleDnsNameToFlatName PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsRoleFreeMemory PROTO :DWORD
DsRoleGetDcOperationProgress PROTO :DWORD,:DWORD,:DWORD
DsRoleGetDcOperationResults PROTO :DWORD,:DWORD,:DWORD
DsRoleGetPrimaryDomainInformation PROTO :DWORD,:DWORD,:DWORD
DsRoleServerSaveStateForUpgrade PROTO :DWORD
DsRoleUpgradeDownlevelServer PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsValidateSubnetNameA PROTO :DWORD
DsValidateSubnetName equ <DsValidateSubnetNameA>

DsValidateSubnetNameW PROTO :DWORD
I_BrowserDebugCall PROTO :DWORD,:DWORD,:DWORD
I_BrowserDebugTrace PROTO :DWORD,:DWORD
I_BrowserQueryEmulatedDomains PROTO :DWORD,:DWORD,:DWORD
I_BrowserQueryOtherDomains PROTO :DWORD,:DWORD,:DWORD,:DWORD
I_BrowserQueryStatistics PROTO :DWORD,:DWORD
I_BrowserResetNetlogonState PROTO :DWORD
I_BrowserResetStatistics PROTO :DWORD
I_BrowserServerEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_BrowserSetNetlogonState PROTO :DWORD,:DWORD,:DWORD,:DWORD
I_NetAccountDeltas PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetAccountSync PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetDatabaseDeltas PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetDatabaseRedo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetDatabaseSync2 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetDatabaseSync PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetDfsCreateExitPoint PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetDfsCreateLocalPartition PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetDfsDeleteExitPoint PROTO :DWORD,:DWORD,:DWORD,:DWORD
I_NetDfsDeleteLocalPartition PROTO :DWORD,:DWORD,:DWORD
I_NetDfsFixLocalVolume PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetDfsGetFtServers PROTO :DWORD,:DWORD,:DWORD,:DWORD
I_NetDfsGetVersion PROTO :DWORD,:DWORD
I_NetDfsIsThisADomainName PROTO :DWORD
I_NetDfsManagerReportSiteInfo PROTO :DWORD,:DWORD
I_NetDfsModifyPrefix PROTO :DWORD,:DWORD,:DWORD
I_NetDfsSetLocalVolumeState PROTO :DWORD,:DWORD,:DWORD,:DWORD
I_NetDfsSetServerInfo PROTO :DWORD,:DWORD,:DWORD
I_NetGetDCList PROTO :DWORD,:DWORD,:DWORD,:DWORD
I_NetListCanonicalize PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetListTraverse PROTO :DWORD,:DWORD,:DWORD
I_NetLogonControl2 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetLogonControl PROTO :DWORD,:DWORD,:DWORD,:DWORD
I_NetLogonGetDomainInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetLogonSamLogoff PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetLogonSamLogon PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetLogonSamLogonEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetLogonSendToSam PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetLogonUasLogoff PROTO :DWORD,:DWORD,:DWORD
I_NetLogonUasLogon PROTO :DWORD,:DWORD,:DWORD
I_NetNameCanonicalize PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetNameCompare PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetNameValidate PROTO :DWORD,:DWORD,:DWORD,:DWORD
I_NetPathCanonicalize PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetPathCompare PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetPathType PROTO :DWORD,:DWORD,:DWORD,:DWORD
I_NetServerAuthenticate2 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetServerAuthenticate3 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetServerAuthenticate PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetServerPasswordGet PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetServerPasswordSet2 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetServerPasswordSet PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetServerReqChallenge PROTO :DWORD,:DWORD,:DWORD,:DWORD
I_NetServerSetServiceBits PROTO :DWORD,:DWORD,:DWORD,:DWORD
I_NetServerSetServiceBitsEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetlogonComputeClientDigest PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetlogonComputeServerDigest PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_NetlogonGetTrustRid PROTO :DWORD,:DWORD,:DWORD
NetAlertRaise PROTO :DWORD,:DWORD,:DWORD
NetAlertRaiseEx PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetApiBufferAllocate PROTO :DWORD,:DWORD
NetApiBufferFree PROTO :DWORD
NetApiBufferReallocate PROTO :DWORD,:DWORD,:DWORD
NetApiBufferSize PROTO :DWORD,:DWORD
NetAuditClear PROTO :DWORD,:DWORD,:DWORD
NetAuditRead PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetAuditWrite PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetBrowserStatisticsGet PROTO :DWORD,:DWORD,:DWORD
NetConfigGet PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetConfigGetAll PROTO :DWORD,:DWORD,:DWORD
NetConfigSet PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetConnectionEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetDfsAdd PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetDfsAddFtRoot PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetDfsAddStdRoot PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetDfsAddStdRootForced PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetDfsEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetDfsGetClientInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetDfsGetDcAddress PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetDfsGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetDfsManagerGetConfigInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetDfsManagerInitialize PROTO :DWORD,:DWORD
NetDfsManagerSendSiteInfo PROTO :DWORD,:DWORD,:DWORD
NetDfsMove PROTO :DWORD,:DWORD
NetDfsRemove PROTO :DWORD,:DWORD,:DWORD
NetDfsRemoveFtRoot PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetDfsRemoveFtRootForced PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetDfsRemoveStdRoot PROTO :DWORD,:DWORD,:DWORD
NetDfsRename PROTO :DWORD,:DWORD
NetDfsSetClientInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetDfsSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetEnumerateTrustedDomains PROTO :DWORD,:DWORD
NetErrorLogClear PROTO :DWORD,:DWORD,:DWORD
NetErrorLogRead PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetErrorLogWrite PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetFileClose PROTO :DWORD,:DWORD
NetFileEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetFileGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetGetAnyDCName PROTO :DWORD,:DWORD,:DWORD
NetGetDCName PROTO :DWORD,:DWORD,:DWORD
NetGetDisplayInformationIndex PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetGetJoinInformation PROTO :DWORD,:DWORD,:DWORD
NetGetJoinableOUs PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetGroupAdd PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetGroupAddUser PROTO :DWORD,:DWORD,:DWORD
NetGroupDel PROTO :DWORD,:DWORD
NetGroupDelUser PROTO :DWORD,:DWORD,:DWORD
NetGroupEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetGroupGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetGroupGetUsers PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetGroupSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetGroupSetUsers PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetJoinDomain PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetLocalGroupAdd PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetLocalGroupAddMember PROTO :DWORD,:DWORD,:DWORD
NetLocalGroupAddMembers PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetLocalGroupDel PROTO :DWORD,:DWORD
NetLocalGroupDelMember PROTO :DWORD,:DWORD,:DWORD
NetLocalGroupDelMembers PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetLocalGroupEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetLocalGroupGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetLocalGroupGetMembers PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetLocalGroupSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetLocalGroupSetMembers PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetLogonGetTimeServiceParentDomain PROTO :DWORD,:DWORD,:DWORD
NetLogonSetServiceBits PROTO :DWORD,:DWORD,:DWORD
NetMessageBufferSend PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetMessageNameAdd PROTO :DWORD,:DWORD
NetMessageNameDel PROTO :DWORD,:DWORD
NetMessageNameEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetMessageNameGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetQueryDisplayInformation PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetRegisterDomainNameChangeNotification PROTO :DWORD
NetRemoteComputerSupports PROTO :DWORD,:DWORD,:DWORD
NetRemoteTOD PROTO :DWORD,:DWORD
NetRenameMachineInDomain PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetReplExportDirAdd PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetReplExportDirDel PROTO :DWORD,:DWORD
NetReplExportDirEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetReplExportDirGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetReplExportDirLock PROTO :DWORD,:DWORD
NetReplExportDirSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetReplExportDirUnlock PROTO :DWORD,:DWORD,:DWORD
NetReplGetInfo PROTO :DWORD,:DWORD,:DWORD
NetReplImportDirAdd PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetReplImportDirDel PROTO :DWORD,:DWORD
NetReplImportDirEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetReplImportDirGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetReplImportDirLock PROTO :DWORD,:DWORD
NetReplImportDirUnlock PROTO :DWORD,:DWORD,:DWORD
NetReplSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetScheduleJobAdd PROTO :DWORD,:DWORD,:DWORD
NetScheduleJobDel PROTO :DWORD,:DWORD,:DWORD
NetScheduleJobEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetScheduleJobGetInfo PROTO :DWORD,:DWORD,:DWORD
NetServerComputerNameAdd PROTO :DWORD,:DWORD,:DWORD
NetServerComputerNameDel PROTO :DWORD,:DWORD
NetServerDiskEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetServerEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetServerEnumEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetServerGetInfo PROTO :DWORD,:DWORD,:DWORD
NetServerSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetServerTransportAdd PROTO :DWORD,:DWORD,:DWORD
NetServerTransportAddEx PROTO :DWORD,:DWORD,:DWORD
NetServerTransportDel PROTO :DWORD,:DWORD,:DWORD
NetServerTransportEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetServiceControl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetServiceEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetServiceGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetServiceInstall PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetSessionDel PROTO :DWORD,:DWORD,:DWORD
NetSessionEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetSessionGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetShareAdd PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetShareCheck PROTO :DWORD,:DWORD,:DWORD
NetShareDel PROTO :DWORD,:DWORD,:DWORD
NetShareDelSticky PROTO :DWORD,:DWORD,:DWORD
NetShareEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetShareEnumSticky PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetShareGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetShareSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetStatisticsGet PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetUnjoinDomain PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetUnregisterDomainNameChangeNotification PROTO :DWORD
NetUseAdd PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetUseDel PROTO :DWORD,:DWORD,:DWORD
NetUseEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetUseGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetUserAdd PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetUserChangePassword PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetUserDel PROTO :DWORD,:DWORD
NetUserEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetUserGetGroups PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetUserGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetUserGetLocalGroups PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetUserModalsGet PROTO :DWORD,:DWORD,:DWORD
NetUserModalsSet PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetUserSetGroups PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetUserSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetValidateName PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetWkstaGetInfo PROTO :DWORD,:DWORD,:DWORD
NetWkstaSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetWkstaTransportAdd PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetWkstaTransportDel PROTO :DWORD,:DWORD,:DWORD
NetWkstaTransportEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetWkstaUserEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetWkstaUserGetInfo PROTO :DWORD,:DWORD,:DWORD
NetWkstaUserSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetapipBufferAllocate PROTO :DWORD,:DWORD
Netbios PROTO :DWORD
NetpAccessCheck PROTO :DWORD,:DWORD,:DWORD
NetpAccessCheckAndAudit PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetpAllocConfigName PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetpAllocStrFromStr PROTO :DWORD
NetpAllocStrFromWStr PROTO :DWORD
NetpAllocTStrFromString PROTO :DWORD,:DWORD
NetpAllocWStrFromStr PROTO :DWORD
NetpAllocWStrFromWStr PROTO :DWORD
NetpApiStatusToNtStatus PROTO :DWORD
NetpAssertFailed PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetpCloseConfigData PROTO :DWORD
NetpCopyStringToBuffer PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetpCreateSecurityObject PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetpDbgDisplayServerInfo PROTO :DWORD,:DWORD
NetpDeleteSecurityObject PROTO :DWORD
NetpGetComputerName PROTO :DWORD
NetpGetConfigBool PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetpGetConfigDword PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetpGetConfigTStrArray PROTO :DWORD,:DWORD,:DWORD
NetpGetConfigValue PROTO :DWORD,:DWORD,:DWORD
NetpGetDomainName PROTO :DWORD
NetpGetFileSecurity PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetpGetPrivilege PROTO :DWORD,:DWORD
NetpHexDump PROTO :DWORD,:DWORD
NetpInitOemString PROTO :DWORD,:DWORD
NetpIsRemote PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetpIsUncComputerNameValid PROTO :DWORD
NetpLocalTimeZoneOffset PROTO 
NetpLogonPutUnicodeString PROTO :DWORD,:DWORD,:DWORD
NetpNetBiosAddName PROTO :DWORD,:DWORD,:DWORD
NetpNetBiosCall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetpNetBiosDelName PROTO :DWORD,:DWORD
NetpNetBiosGetAdapterNumbers PROTO :DWORD,:DWORD
NetpNetBiosHangup PROTO :DWORD,:DWORD
NetpNetBiosReceive PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetpNetBiosReset PROTO :DWORD
NetpNetBiosSend PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetpNetBiosStatusToApiStatus PROTO :DWORD
NetpNtStatusToApiStatus PROTO :DWORD
NetpOpenConfigData PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetpPackString PROTO :DWORD,:DWORD,:DWORD
NetpParmsQueryUserProperty PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetpParmsQueryUserPropertyWithLength PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetpParmsSetUserProperty PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetpParmsSetUserPropertyWithLength PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetpParmsUserPropertyFree PROTO :DWORD
NetpReleasePrivilege PROTO 
NetpSetConfigBool PROTO :DWORD,:DWORD,:DWORD
NetpSetConfigDword PROTO :DWORD,:DWORD,:DWORD
NetpSetConfigTStrArray PROTO :DWORD,:DWORD,:DWORD
NetpSetFileSecurity PROTO :DWORD,:DWORD,:DWORD
NetpSmbCheck PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetpStringToNetBiosName PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetpTStrArrayEntryCount PROTO :DWORD
NetpUpgradePreNT5JoinInfo PROTO 
NetpwNameCanonicalize PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetpwNameCompare PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetpwNameValidate PROTO :DWORD,:DWORD,:DWORD
NetpwPathCanonicalize PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetpwPathCompare PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetpwPathType PROTO :DWORD,:DWORD,:DWORD
NlBindingAddServerToCache PROTO :DWORD,:DWORD
NlBindingRemoveServerFromCache PROTO :DWORD,:DWORD
NlBindingSetAuthInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RxNetAccessAdd PROTO :DWORD,:DWORD,:DWORD,:DWORD
RxNetAccessDel PROTO :DWORD,:DWORD
RxNetAccessEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RxNetAccessGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
RxNetAccessGetUserPerms PROTO :DWORD,:DWORD,:DWORD,:DWORD
RxNetAccessSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RxNetServerEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RxNetUserPasswordSet PROTO :DWORD,:DWORD,:DWORD,:DWORD
