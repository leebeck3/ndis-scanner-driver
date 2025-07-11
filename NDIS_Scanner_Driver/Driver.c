#include <ndis.h>
#include "Filter.h"

NDIS_HANDLE FilterDriverHandle = NULL;

NDIS_STATUS
DriverEntry(
    _In_  PDRIVER_OBJECT     DriverObject,
    _In_  PUNICODE_STRING    RegistryPath
)
{
    NDIS_FILTER_DRIVER_CHARACTERISTICS FChars = {
        .Header = {
            .Type = NDIS_OBJECT_TYPE_FILTER_DRIVER_CHARACTERISTICS,
            .Revision = NDIS_FILTER_CHARACTERISTICS_REVISION_2,
            .Size = NDIS_SIZEOF_FILTER_DRIVER_CHARACTERISTICS_REVISION_2
        },
        //.MajorNdisVersion = NDIS_FILTER_MAJOR_VERSION,
        //.MinorNdisVersion = NDIS_FILTER_MINOR_VERSION,
        .MajorDriverVersion = 1,
        .MinorDriverVersion = 0,
        .FriendlyName = L"Example Filter Driver",
        .UniqueName = L"ExampleFilter",
        .ServiceName = L"ExampleFilterService",

        .AttachHandler = FilterAttach,
        .DetachHandler = FilterDetach,
        .RestartHandler = FilterRestart,
        .PauseHandler = FilterPause,
        .SendNetBufferListsHandler = FilterSendNetBufferLists,
        .ReceiveNetBufferListsHandler = FilterReceiveNetBufferLists
    };

    NDIS_STATUS status = NdisFRegisterFilterDriver(
        DriverObject,
        (NDIS_HANDLE)DriverObject,
        &FChars,
        &FilterDriverHandle
    );

    if (status != NDIS_STATUS_SUCCESS) {
        KdPrint(("RegisterFilterDriver failed with status 0x%x\n", status));
    }
    else {
        KdPrint(("Filter driver registered successfully\n"));
    }

    return status;
}
