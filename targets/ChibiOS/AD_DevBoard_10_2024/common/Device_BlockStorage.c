//
// Copyright (c) .NET Foundation and Contributors
// See LICENSE file in the project root for full license information.
//

#include <nanoHAL_Types.h>
#include <nanoPAL_BlockStorage.h>

// // 8kB blocks (single-banking flash)
// const BlockRange BlockRange1[] = 
// {
//     { BlockRange_BLOCKTYPE_BOOTSTRAP ,   0, 3 },        // nanoBooter (32kB)   0x0800 0000 - 0x0800 7FFF 
//     { BlockRange_BLOCKTYPE_CONFIG    ,   4, 7 },        // nanoConfig (32kB)   0x0800 8000 - 0x0800 FFFF
//     { BlockRange_BLOCKTYPE_CODE      ,   8, 79 },       // nanoCLR    (576kB)  0x0801 0000 - 0x0809 FFFF
//     { BlockRange_BLOCKTYPE_DEPLOYMENT,   80, 255 },     // Deployment (1408KB) 0x080A 0000 - 0x081F FFFF
// };

// 4kB blocks (dual-banking flash)
const BlockRange BlockRange1[] = 
{
    { BlockRange_BLOCKTYPE_BOOTSTRAP ,   0, 7 },            // nanoBooter (32kB)   0x0800 0000 - 0x0800 7FFF 
    { BlockRange_BLOCKTYPE_CONFIG    ,   8, 15 },           // nanoConfig (32kB)   0x0800 8000 - 0x0800 FFFF
    { BlockRange_BLOCKTYPE_CODE      ,   16, 159 },         // nanoCLR    (576kB)  0x0801 0000 - 0x0809 FFFF
    { BlockRange_BLOCKTYPE_DEPLOYMENT,   160, 511 },        // Deployment (1408KB) 0x080A 0000 - 0x081F FFFF
};

const BlockRegionInfo BlockRegions[] = 
{
    {
        (BlockRegionAttribute_ProgramWidthIs64bits),   // 128 bit program width
        0x08000000,                                     // start address for block region
        512,                                            // total number of blocks in this region
        0x1000,                                         // total number of bytes per block
        ARRAYSIZE_CONST_EXPR(BlockRange1),
        BlockRange1,
    }
};

const DeviceBlockInfo Device_BlockInfo =
{
    (MediaAttribute_SupportsXIP),           // MediaAttributes
    2,                                      // UINT32 BytesPerSector
    ARRAYSIZE_CONST_EXPR(BlockRegions),     // UINT32 NumRegions;
    (BlockRegionInfo*)BlockRegions,         // const BlockRegionInfo* pRegions;
};

MEMORY_MAPPED_NOR_BLOCK_CONFIG Device_BlockStorageConfig =
{
    { // BLOCK_CONFIG
        {
            0,          // GPIO_PIN             Pin;
            false,      // BOOL                 ActiveState;
        },

        (DeviceBlockInfo*)&Device_BlockInfo,    // BlockDeviceinfo
    },

    { // CPU_MEMORY_CONFIG
        0,                          // UINT8  CPU_MEMORY_CONFIG::ChipSelect;
        true,                       // UINT8  CPU_MEMORY_CONFIG::ReadOnly;
        0,                          // UINT32 CPU_MEMORY_CONFIG::WaitStates;
        0,                          // UINT32 CPU_MEMORY_CONFIG::ReleaseCounts;
        16,                         // UINT32 CPU_MEMORY_CONFIG::BitWidth;
        0x08000000,                 // UINT32 CPU_MEMORY_CONFIG::BaseAddress;
        0x00200000,                 // UINT32 CPU_MEMORY_CONFIG::SizeInBytes;
        0,                          // UINT8  CPU_MEMORY_CONFIG::XREADYEnable 
        0,                          // UINT8  CPU_MEMORY_CONFIG::ByteSignalsForRead 
        0,                          // UINT8  CPU_MEMORY_CONFIG::ExternalBufferEnable
    },

    0,                              // UINT32 ChipProtection;
    0,                              // UINT32 ManufacturerCode;
    0,                              // UINT32 DeviceCode;
};

BlockStorageDevice    Device_BlockStorage;  
