#include <ndis.h>
#include "Filter.h"

NDIS_STATUS
FilterAttach(
    NDIS_HANDLE NdisFilterHandle,
    NDIS_HANDLE FilterDriverContext,
    PNDIS_FILTER_ATTACH_PARAMETERS AttachParameters
)
{
    UNREFERENCED_PARAMETER(FilterDriverContext);
    UNREFERENCED_PARAMETER(AttachParameters);

    KdPrint(("FilterAttach called\n"));

    NdisFSetAttributes(NdisFilterHandle, NULL, NULL);
    return NDIS_STATUS_SUCCESS;
}

VOID
FilterDetach(
    NDIS_HANDLE FilterModuleContext
)
{
    UNREFERENCED_PARAMETER(FilterModuleContext);
    KdPrint(("FilterDetach called\n"));
}

NDIS_STATUS
FilterRestart(
    NDIS_HANDLE FilterModuleContext,
    PNDIS_FILTER_RESTART_PARAMETERS RestartParameters
)
{
    UNREFERENCED_PARAMETER(FilterModuleContext);
    UNREFERENCED_PARAMETER(RestartParameters);

    KdPrint(("FilterRestart called\n"));
    return NDIS_STATUS_SUCCESS;
}

NDIS_STATUS
FilterPause(
    NDIS_HANDLE FilterModuleContext,
    PNDIS_FILTER_PAUSE_PARAMETERS PauseParameters
)
{
    UNREFERENCED_PARAMETER(FilterModuleContext);
    UNREFERENCED_PARAMETER(PauseParameters);

    KdPrint(("FilterPause called\n"));
    return NDIS_STATUS_SUCCESS;
}

VOID
FilterSendNetBufferLists(
    NDIS_HANDLE FilterModuleContext,
    PNET_BUFFER_LIST NetBufferLists,
    NDIS_PORT_NUMBER PortNumber,
    ULONG SendFlags
)
{
    UNREFERENCED_PARAMETER(FilterModuleContext);
    UNREFERENCED_PARAMETER(PortNumber);
    UNREFERENCED_PARAMETER(SendFlags);

    KdPrint(("FilterSendNetBufferLists called\n"));

    NdisFSendNetBufferLists(FilterModuleContext, NetBufferLists, PortNumber, SendFlags);
}

VOID
FilterReceiveNetBufferLists(
    NDIS_HANDLE FilterModuleContext,
    PNET_BUFFER_LIST NetBufferLists,
    NDIS_PORT_NUMBER PortNumber,
    ULONG NumberOfNetBufferLists,
    ULONG ReceiveFlags
)
{
    UNREFERENCED_PARAMETER(PortNumber);
    UNREFERENCED_PARAMETER(NumberOfNetBufferLists);
    UNREFERENCED_PARAMETER(ReceiveFlags);

    KdPrint(("FilterReceiveNetBufferLists called\n"));

    NdisFIndicateReceiveNetBufferLists(FilterModuleContext, NetBufferLists, PortNumber, NumberOfNetBufferLists, ReceiveFlags);
}
