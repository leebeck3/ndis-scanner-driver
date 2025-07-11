#pragma once
#include <ndis.h>

// Required callback declarations
NDIS_STATUS
FilterAttach(
    NDIS_HANDLE NdisFilterHandle,
    NDIS_HANDLE FilterDriverContext,
    PNDIS_FILTER_ATTACH_PARAMETERS AttachParameters
);

VOID
FilterDetach(
    NDIS_HANDLE FilterModuleContext
);

NDIS_STATUS
FilterRestart(
    NDIS_HANDLE FilterModuleContext,
    PNDIS_FILTER_RESTART_PARAMETERS RestartParameters
);

NDIS_STATUS
FilterPause(
    NDIS_HANDLE FilterModuleContext,
    PNDIS_FILTER_PAUSE_PARAMETERS PauseParameters
);

VOID
FilterSendNetBufferLists(
    NDIS_HANDLE FilterModuleContext,
    PNET_BUFFER_LIST NetBufferLists,
    NDIS_PORT_NUMBER PortNumber,
    ULONG SendFlags
);

VOID
FilterReceiveNetBufferLists(
    NDIS_HANDLE FilterModuleContext,
    PNET_BUFFER_LIST NetBufferLists,
    NDIS_PORT_NUMBER PortNumber,
    ULONG NumberOfNetBufferLists,
    ULONG ReceiveFlags
);
