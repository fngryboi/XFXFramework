//based on nv10reg.h (rules) file

//this part already exists in openxdk hal/video.h header (openxdk header)

//outer GPU registers base address
#define VIDEO_BASE				0xFD000000

//Access macros (volatile means C optimizer must not consider useless to read again Ram)
#define VIDEOREG(x)   (*(volatile unsigned int*)(VIDEO_BASE + (x)))
#define VIDEOREG16(x) (*(volatile unsigned short*)(VIDEO_BASE + (x)))
#define VIDEOREG8(x)  (*(volatile unsigned char*)(VIDEO_BASE + (x)))

// Registers relative addresses and associated encoding constants
#define PCIO_CRTC_STATUS			0x006013DA

#define PCRTC_START				0x00600800
#define PCRTC_INTR				0x00600100
#define PCRTC_INTR_VBLANK_RESET		0x00000001

#define PCRTC_INTR_EN				0x00600140
#define PCRTC_INTR_EN_VBLANK_DISABLED	0x00000000
#define PCRTC_INTR_EN_VBLANK_ENABLED	0x00000001

#define NV_PMC_INTR_EN_0 			0x00000140
#define NV_PMC_INTR_EN_0_INTA_DISABLED	0x00000000
#define NV_PMC_INTR_EN_0_INTA_HARDWARE	0x00000001
#define NV_PMC_INTR_EN_0_INTA_SOFTWARE	0x00000002


//this part is new and doesn't exist in hal/video.h yet, and is not coming from "rules"

//additional needed registers
#define NV_PBUS_ROM_VERSION					0x00001218
#define NV_PBUS_ROM_VERSION_MASK			0x00000100

#define NV_PFB_WC_CACHE						0x00100410
#define NV_PFB_WC_CACHE_FLUSH_TRIGGER			0x00010000
#define NV_PFB_WC_CACHE_FLUSH_IN_PROGRESS		0x00010000

#define NV_PGRAPH_UNKNOWN_400098				0x00400098
#define NV_PGRAPH_UNKNOWN_40009C				0x0040009C

//these two ones are different from nv10reg.h
#define NV_PGRAPH_CHANNEL_CTX_POINTER				0x00400784
#define NV_PGRAPH_CHANNEL_CTX_POINTER_INST		0x0000FFFF

#define NV_PGRAPH_CHANNEL_CTX_STATUS				0x00400788
#define NV_PGRAPH_CHANNEL_CTX_STATUS_LOADED		1
#define NV_PGRAPH_CHANNEL_CTX_STATUS_UNLOADED		2

#define NV_PGRAPH_DEBUG_7					0x00400880
#define NV_PGRAPH_DEBUG_7_UNKNOWN_OPTIONS		0x0008CFFF

#define NV_PGRAPH_TILE_XBOX					0x00400900
#define NV_PGRAPH_TLIMIT_XBOX					0x00400904
#define NV_PGRAPH_TSIZE_XBOX					0x00400908
#define NV_PGRAPH_ZCOMP_XBOX					0x00400980
#define NV_PGRAPH_ZCOMP_OFFSET_XBOX				0x004009A0
#define NV_PGRAPH_CFG0_XBOX					0x004009A4
#define NV_PGRAPH_CFG1_XBOX					0x004009A8

#define NV_PGRAPH_UNKNOWN_400B80				0x00400B80
#define NV_PGRAPH_UNKNOWN_400B84				0x00400B84
#define NV_PGRAPH_UNKNOWN_400B88				0x00400B88

#define NV_PGRAPH_PARAMETER_A					0x00401A88
#define NV_PGRAPH_PARAMETER_B					0x0040186C


//already known registers (coming from rules - nv10reg.h)
#define NV_PMC_INTR_0						0x00000100
#define NV_PMC_INTR_0_NOT_PENDING			0
#define NV_PMC_INTR_0_MD_PENDING			0x00000001
#define NV_PMC_INTR_0_PMEDIA_PENDING			0x00000010
#define NV_PMC_INTR_0_PFIFO_PENDING			0x00000100
#define NV_PMC_INTR_0_PGRAPH_PENDING			0x00001000
#define NV_PMC_INTR_0_PVIDEO_PENDING			0x00010000
#define NV_PMC_INTR_0_PTIMER_PENDING			0x00100000
#define NV_PMC_INTR_0_PCRTC_PENDING			0x01000000

#define NV_PMC_ENABLE						0x00000200
#define NV_PMC_ENABLE_ALL_ENABLE			0xFFFFFFFF
#define NV_PMC_ENABLE_ALL_DISABLE			0
#define NV_PMC_ENABLE_PGRAPH_DISABLED			0xFFFFEFFF
#define NV_PMC_ENABLE_PGRAPH_ENABLED			0x00001000

#define NV_PBUS_PCI_NV_0					0x00001800
#define NV_CONFIG_PCI_NV_0_DEVICE_ID			0xFFFC0000

#define NV_PBUS_PCI_NV_1					0x00001804
#define NV_PBUS_PCI_NV_1_BUS_MASTER_ENABLED		4

#define NV_PBUS_PCI_NV_2					0x00001808
#define NV_PBUS_PCI_NV_2_REVISION_ID			0x000000FF

#define NV_PBUS_PCI_NV_3					0x0000180C
#define NV_PBUS_PCI_NV_3_LATENCY_TIMER_248_CLOCKS	0x0000F800

#define NV_PBUS_PCI_NV_12					0x00001830
#define NV_PBUS_PCI_NV_12_ROM_DECODE_DISABLED		0

#define NV_PBUS_PCI_NV_19					0x0000184C
#define NV_PBUS_PCI_NV_19_AGP_COMMAND_SBA_ENABLE_OFF	0xFFFFFDFF
#define NV_PBUS_PCI_NV_19_AGP_COMMAND_AGP_ENABLE_OFF	0xFFFFFEFF

#define NV_PFIFO_DELAY_0					0x00002040
#define NV_PFIFO_DELAY_0_WAIT_RETRY			0x000003FF

#define NV_PFIFO_DMA_TIMESLICE					0x00002044
#define NV_PFIFO_DMA_TIMESLICE_SELECT_128K		0x0001FFFF
#define NV_PFIFO_DMA_TIMESLICE_TIMEOUT_ENABLED		0x01000000
#define NV_PFIFO_DMA_TIMESLICE_ALL_DISABLE		0

#define NV_PFIFO_TIMESLICE					0x0000204C
#define NV_PFIFO_TIMESLICE_TIMER_EXPIRED		0x001FFFFF

#define NV_PFIFO_DEBUG_0					0x00002080
#define NV_PFIFO_DEBUG_0_CACHE_ERROR0_PENDING		0x00000001

#define NV_PFIFO_INTR_0						0x00002100
#define NV_PFIFO_INTR_0_NOT_PENDING			0
#define NV_PFIFO_INTR_0_CACHE_ERROR_PENDING		0x00000001
#define NV_PFIFO_INTR_0_CACHE_ERROR_RESET		0x00000001
#define NV_PFIFO_INTR_0_RUNOUT_PENDING			0x00000010
#define NV_PFIFO_INTR_0_RUNOUT_OVERFLOW_PENDING		0x00000100
#define NV_PFIFO_INTR_0_DMA_PUSHER_PENDING		0x00001000
#define NV_PFIFO_INTR_0_DMA_PUSHER_RESET		0x00001000
#define NV_PFIFO_INTR_0_DMA_PT_PENDING			0x00010000
#define NV_PFIFO_INTR_0_DMA_PT_RESET			0x00010000
#define NV_PFIFO_INTR_0_SEMAPHORE_PENDING		0x00100000
#define NV_PFIFO_INTR_0_SEMAPHORE_RESET			0x00100000
#define NV_PFIFO_INTR_0_ACQUIRE_TIMEOUT_PENDING		0x01000000
#define NV_PFIFO_INTR_0_ACQUIRE_TIMEOUT_RESET		0x01000000
#define NV_PFIFO_INTR_0_ALL_RESET			0xFFFFFFFF

#define NV_PFIFO_INTR_EN_0					0x00002140
#define NV_PFIFO_INTR_EN_0_ALL_DISABLE			0
#define NV_PFIFO_INTR_EN_0_ALL_ENABLE			0x01111111

#define NV_PFIFO_RAMHT						0x00002210
#define NV_PFIFO_RAMHT_BASE_ADDRESS			0x000001F0
#define NV_PFIFO_RAMHT_BASE_ADDRESS_10000		0x00000100
#define NV_PFIFO_RAMHT_SEARCH_128			0x03000000

#define NV_PFIFO_RAMFC						0x00002214
#define NV_PFIFO_RAMFC_BASE_ADDRESS			0x000001FC
#define NV_PFIFO_RAMFC_BASE_ADDRESS_11000		0x00000110

#define NV_PFIFO_RUNOUT_STATUS					0x00002400
#define NV_PFIFO_RUNOUT_STATUS_LOW_MARK_EMPTY		0x00000010

#define NV_PFIFO_RUNOUT_PUT					0x00002410
#define NV_PFIFO_RUNOUT_PUT_ADDRESS			0x00001FF8

#define NV_PFIFO_RUNOUT_GET					0x00002420
#define NV_PFIFO_RUNOUT_GET_ADDRESS			0x00003FF8

#define NV_PFIFO_CACHES						0x00002500
#define NV_PFIFO_CACHES_ALL_DISABLE			0
#define NV_PFIFO_CACHES_REASSIGN_ENABLED		0x00000001
#define NV_PFIFO_CACHES_DMA_SUSPEND_BUSY		0x00000010

#define NV_PFIFO_MODE						0x00002504
#define NV_PFIFO_MODE_ALL_PIO				0

#define NV_PFIFO_DMA						0x00002508
#define NV_PFIFO_DMA_NOT_PENDING			0

#define NV_PFIFO_SIZE						0x0000250C

#define NV_PFIFO_CACHE0_PUSH0					0x00003000
#define NV_PFIFO_CACHE0_PUSH0_ACCESS_DISABLE		0

#define NV_PFIFO_CACHE0_PULL0					0x00003050
#define NV_PFIFO_CACHE0_PULL0_ACCESS_DISABLE		0

#define NV_PFIFO_CACHE0_HASH					0x00003058
#define NV_PFIFO_CACHE0_HASH_INSTANCE			0x0000FFFF
#define NV_PFIFO_CACHE0_HASH_VALID			0x00010000

#define NV_PFIFO_CACHE1_PUSH0					0x00003200
#define NV_PFIFO_CACHE1_PUSH0_ACCESS_DISABLE		0
#define NV_PFIFO_CACHE1_PUSH0_ACCESS_ENABLE		0x00000001

#define NV_PFIFO_CACHE1_PUSH1					0x00003204
#define NV_PFIFO_CACHE1_PUSH1_CHID			0x0000001F
#define NV_PFIFO_CACHE1_PUSH1_MODE_DMA			0x00000100

#define NV_PFIFO_CACHE1_PUT					0x00003210
#define NV_PFIFO_CACHE1_PUT_ADDRESS			0x000003FC

#define NV_PFIFO_CACHE1_STATUS					0x00003214
#define NV_PFIFO_CACHE1_STATUS_LOW_MARK_EMPTY		0x00000010

#define NV_PFIFO_CACHE1_DMA_PUSH				0x00003220
#define NV_PFIFO_CACHE1_DMA_PUSH_ACCESS_DISABLE		0
#define NV_PFIFO_CACHE1_DMA_PUSH_ACCESS_ENABLE		0x00000001
#define NV_PFIFO_CACHE1_DMA_PUSH_STATE_BUSY		0x00000010
#define NV_PFIFO_CACHE1_DMA_PUSH_STATUS_RUNNING		0xFFFFEFFF

#define NV_PFIFO_CACHE1_DMA_FETCH				0x00003224
#define NV_PFIFO_CACHE1_DMA_FETCH_TRIG			0x000000F8
#define NV_PFIFO_CACHE1_DMA_FETCH_TRIG_128_BYTES	0x00000078
#define NV_PFIFO_CACHE1_DMA_FETCH_SIZE			0x0000E000
#define NV_PFIFO_CACHE1_DMA_FETCH_SIZE_32_BYTES		0x00000000
#define NV_PFIFO_CACHE1_DMA_FETCH_MAX_REQS		0x001F0000
#define NV_PFIFO_CACHE1_DMA_FETCH_MAX_REQS_15		0x000F0000

#define NV_PFIFO_CACHE1_DMA_STATE				0x00003228
#define NV_PFIFO_CACHE1_DMA_STATE_METHOD_COUNT_0	0x00000000

#define NV_PFIFO_CACHE1_DMA_INSTANCE				0x0000322C
#define NV_PFIFO_CACHE1_DMA_INSTANCE_ADDRESS		0x0000FFFF

#define NV_PFIFO_CACHE1_DMA_CTL					0x00003230
#define NV_PFIFO_CACHE1_DMA_CTL_ALL_DISABLE		0

#define NV_PFIFO_CACHE1_DMA_PUT					0x00003240
#define NV_PFIFO_CACHE1_DMA_PUT_OFFSET			0x1FFFFFFC

#define NV_PFIFO_CACHE1_DMA_GET					0x00003244
#define NV_PFIFO_CACHE1_DMA_GET_OFFSET			0x1FFFFFFC

#define NV_PFIFO_CACHE1_REF					0x00003248
#define NV_PFIFO_CACHE1_REF_CNT				0xFFFFFFFF

#define NV_PFIFO_CACHE1_DMA_SUBROUTINE				0x0000324C
#define NV_PFIFO_CACHE1_DMA_SUBROUTINE_STATE_ACTIVE	0x00000001
#define NV_PFIFO_CACHE1_DMA_SUBROUTINE_RETURN_OFFSET	0x0FFFFFFC

#define NV_PFIFO_CACHE1_PULL0					0x00003250
#define NV_PFIFO_CACHE1_PULL0_ACCESS_DISABLE		0
#define NV_PFIFO_CACHE1_PULL0_ACCESS_ENABLE		0x00000001
#define NV_PFIFO_CACHE1_PULL0_HASH_FAILED		0x00000010
#define NV_PFIFO_CACHE1_PULL0_DEVICE_SOFTWARE		0x00000100
#define NV_PFIFO_CACHE1_PULL0_HASH_STATE_BUSY		0x00001000

#define NV_PFIFO_CACHE1_PULL1					0x00003254

#define NV_PFIFO_CACHE1_HASH					0x00003258
#define NV_PFIFO_CACHE1_HASH_INSTANCE			0x0000FFFF
#define NV_PFIFO_CACHE1_HASH_VALID			0x00010000

#define NV_PFIFO_CACHE1_ACQUIRE_0				0x00003260
#define NV_PFIFO_CACHE1_ACQUIRE_0_TIMEOUT		0xFFFFFFFF

#define NV_PFIFO_CACHE1_ACQUIRE_1				0x00003264
#define NV_PFIFO_CACHE1_ACQUIRE_1_TIMESTAMP		0xFFFFFFFF

#define NV_PFIFO_CACHE1_ACQUIRE_2				0x00003268
#define NV_PFIFO_CACHE1_ACQUIRE_2_VALUE			0x7FFFFFFF

#define NV_PFIFO_CACHE1_SEMAPHORE				0x0000326C
#define NV_PFIFO_CACHE1_SEMAPHORE_CTXDMA_VALID		0x00000001
#define NV_PFIFO_CACHE1_SEMAPHORE_OFFSET		0x00000FFC
#define NV_PFIFO_CACHE1_SEMAPHORE_PAGE_ADDRESS		0xFFFFF000

#define NV_PFIFO_CACHE1_GET					0x00003270
#define NV_PFIFO_CACHE1_GET_ADDRESS			0x000003FC

#define NV_PFIFO_CACHE1_ENGINE					0x00003280
#define NV_PFIFO_CACHE1_ENGINE_ALL_SW			0

#define NV_PVIDEO_DEBUG_2					0x00008088
#define NV_PVIDEO_DEBUG_2_BURST1_CLEAR			0xFFFFF43F
#define NV_PVIDEO_DEBUG_2_BURST1_INIT			0x00000400
#define NV_PVIDEO_DEBUG_2_BURST2_CLEAR			0xF43FFFFF
#define NV_PVIDEO_DEBUG_2_BURST2_INIT			0x04000000

#define NV_PVIDEO_DEBUG_3					0x0000808C
#define NV_PVIDEO_DEBUG_3_WATER_MARK1_CLEAR		0xFFFFF40F
#define NV_PVIDEO_DEBUG_3_WATER_MARK1_INIT		0x00000400
#define NV_PVIDEO_DEBUG_3_WATER_MARK2_CLEAR		0xF40FFFFF
#define NV_PVIDEO_DEBUG_3_WATER_MARK2_INIT		0x04000000

#define NV_PVIDEO_INTR						0x00008100
#define NV_PVIDEO_INTR_BUFFER_0_PENDING			0x00000001
#define NV_PVIDEO_INTR_BUFFER_0_RESET			0x00000001

#define NV_PVIDEO_LUMINANCE_0					0x00008910
#define NV_PVIDEO_LUMINANCE_1					0x00008914
#define NV_PVIDEO_LUMINANCE_CONTRAST_UNITY		0x00001000
#define NV_PVIDEO_LUMINANCE_BRIGHTNESS_UNITY		0x00000000

#define NV_PVIDEO_CHROMINANCE_0					0x00008918
#define NV_PVIDEO_CHROMINANCE_1					0x0000891C
#define NV_PVIDEO_CHROMINANCE_SAT_COS_UNITY		0x00001000
#define NV_PVIDEO_CHROMINANCE_SAT_SIN_UNITY		0x00000000

#define NV_PVIDEO_OFFSET_0					0x00008920
#define NV_PVIDEO_OFFSET_1					0x00008924
#define NV_PVIDEO_OFFSET_VALUE_ZERO			0x00000000

#define NV_PVIDEO_SIZE_IN_0					0x00008928
#define NV_PVIDEO_SIZE_IN_1					0x0000892C
#define NV_PVIDEO_SIZE_IN_UNKNOWN_WIDTH			0x0000FFFF
#define NV_PVIDEO_SIZE_IN_UNKNOWN_HEIGHT		0xFFFF0000

#define NV_PVIDEO_POINT_IN_0					0x00008930
#define NV_PVIDEO_POINT_IN_1					0x00008934
#define NV_PVIDEO_POINT_IN_S_ORIGIN			0x00000000
#define NV_PVIDEO_POINT_IN_T_ORIGIN			0x00000000

#define NV_PVIDEO_DS_DX_0					0x00008938
#define NV_PVIDEO_DS_DX_1					0x0000893C
#define NV_PVIDEO_DS_DX_RATIO_UNITY			0x00100000

#define NV_PVIDEO_DT_DY_0					0x00008940
#define NV_PVIDEO_DT_DY_1					0x00008944
#define NV_PVIDEO_DT_DY_RATIO_UNITY			0x00100000

#define NV_PTIMER_INTR_0					0x00009100
#define NV_PTIMER_INTR_0_ALARM_NOT_PENDING		0
#define NV_PTIMER_INTR_0_ALARM_RESET			0x00000001

#define NV_PTIMER_INTR_EN_0					0x00009140
#define NV_PTIMER_INTR_EN_0_ALARM_DISABLED		0

#define NV_PTIMER_NUMERATOR					0x00009200

#define NV_PTIMER_DENOMINATOR					0x00009210

#define NV_PTIMER_TIME_0					0x00009400

#define NV_PTIMER_TIME_1					0x00009410

#define NV_PTIMER_ALARM_0					0x00009420

#define NV_PFB_CFG0						0x00100200
#define NV_PFB_CFG0_PART_3				0x00000003

#define NV_PFB_CFG1						0x00100204

#define NV_PFB_FIFO_DATA					0x0010020C

#define NV_PFB_NVM						0x00100214
#define NV_PFB_NVM_MODE_DISABLE				0xFFFFFFFE
#define NV_PFB_NVM_MODE_ENABLE				0x00000001

#define NV_PFB_TILE						0x00100240

#define NV_PFB_TLIMIT						0x00100244

#define NV_PFB_TSIZE						0x00100248

#define NV_PFB_ZCOMP						0x00100300

#define NV_PFB_ZCOMP_OFFSET					0x00100324

#define NV_PGRAPH_DEBUG_0					0x00400080
#define NV_PGRAPH_DEBUG_0_NO_RESET			0
#define NV_PGRAPH_DEBUG_0_IDX_STATE_RESET		0x00010000
#define NV_PGRAPH_DEBUG_0_VTX_STATE_RESET		0x00020000
#define NV_PGRAPH_DEBUG_0_CAS_STATE_RESET		0x00040000

#define NV_PGRAPH_DEBUG_1					0x00400084
#define NV_PGRAPH_DEBUG_1_VTX_PTE_ENABLED		0x00000100
#define NV_PGRAPH_DEBUG_1_VTX_CACHE_ENABLED		0x00000200
#define NV_PGRAPH_DEBUG_1_VTX_FILE_ENABLED		0x00000400
#define NV_PGRAPH_DEBUG_1_DRAWDIR_Y_INCR		0x00008000
#define NV_PGRAPH_DEBUG_1_INSTANCE_ENABLED		0x00010000
#define NV_PGRAPH_DEBUG_1_CTX_ENABLED			0x00100000
#define NV_PGRAPH_DEBUG_1_CACHE_INVALIDATE		0x01000000

#define NV_PGRAPH_DEBUG_3					0x0040008C
#define NV_PGRAPH_DEBUG_3_FLUSHING_ENABLED		0x00000001
#define NV_PGRAPH_DEBUG_3_SYNC_TO_CRTC_ENABLED		0x00000008
#define NV_PGRAPH_DEBUG_3_FAST_DATA_STRTCH_ENABLED	0x00000010
#define NV_PGRAPH_DEBUG_3_FAST_3D_SHADOW_DATA_ENABLED	0x00000020
#define NV_PGRAPH_DEBUG_3_FAST_DMA_READ_ENABLED		0x00000040
#define NV_PGRAPH_DEBUG_3_IDLE_FILTER_ENABLED		0x00000400
#define NV_PGRAPH_DEBUG_3_SINGLE_CYCLE_LOAD_ENABLED	0x00020000
#define NV_PGRAPH_DEBUG_3_BILINEAR_3D_ENABLED		0x00040000
#define NV_PGRAPH_DEBUG_3_VOLATILE_RESET_ENABLED	0x00080000
#define NV_PGRAPH_DEBUG_3_DATA_CHECK_ENABLED		0x00100000
#define NV_PGRAPH_DEBUG_3_FORMAT_CHECK_ENABLED		0x00400000
#define NV_PGRAPH_DEBUG_3_DMA_CHECK_ENABLED		0x00800000
#define NV_PGRAPH_DEBUG_3_STATE_CHECK_ENABLED		0x01000000
#define NV_PGRAPH_DEBUG_3_IMAGE_64BIT_ENABLED		0x02000000
#define NV_PGRAPH_DEBUG_3_XFMODE_COALESCE_ENABLED	0x10000000
#define NV_PGRAPH_DEBUG_3_CTX_METHODS_ENABLED		0x20000000
#define NV_PGRAPH_DEBUG_3_OP_METHODS_ENABLED		0x40000000
#define NV_PGRAPH_DEBUG_3_IGNORE_PATCHVALID_ENABLED	0x80000000

#define NV_PGRAPH_DEBUG_4					0x00400090
#define NV_PGRAPH_DEBUG_4_ALL_DISABLE			0

#define NV_PGRAPH_DEBUG_5					0x00400094
#define NV_PGRAPH_DEBUG_5_ZCULL_SPARE2_ENABLED		0x00000004

#define NV_PGRAPH_INTR						0x00400100
#define NV_PGRAPH_INTR_NOT_PENDING			0
#define NV_PGRAPH_INTR_NOTIFY_PENDING			0x00000001
#define NV_PGRAPH_INTR_NOTIFY_RESET			0x00000001
#define NV_PGRAPH_INTR_MISSING_HW_PENDING		0x00000010
#define NV_PGRAPH_INTR_MISSING_HW_RESET			0x00000010
#define NV_PGRAPH_INTR_TLB_PRESENT_A_PENDING		0x00000100
#define NV_PGRAPH_INTR_TLB_PRESENT_B_PENDING		0x00000200
#define NV_PGRAPH_INTR_CONTEXT_SWITCH_PENDING		0x00001000
#define NV_PGRAPH_INTR_CONTEXT_SWITCH_RESET		0x00001000
#define NV_PGRAPH_INTR_BUFFER_NOTIFY_PENDING		0x00010000
#define NV_PGRAPH_INTR_ERROR_PENDING			0x00100000
#define NV_PGRAPH_INTR_ERROR_RESET			0x00100000
#define NV_PGRAPH_INTR_SINGLE_STEP_PENDING		0x01000000
#define NV_PGRAPH_INTR_SINGLE_STEP_RESET		0x01000000
#define NV_PGRAPH_INTR_MORE_RESET			0xFFF00000
#define NV_PGRAPH_INTR_ALL_ENABLE			0xFFFFFFFF

#define NV_PGRAPH_NSOURCE					0x00400108
#define NV_PGRAPH_NSOURCE_DATA_ERROR_PENDING		0x00000002
#define NV_PGRAPH_NSOURCE_PROTECTION_ERROR_PENDING	0x00000004
#define NV_PGRAPH_NSOURCE_RANGE_EXCEPTION_PENDING	0x00000008
#define NV_PGRAPH_NSOURCE_LIMIT_COLOR_PENDING		0x00000010
#define NV_PGRAPH_NSOURCE_LIMIT_ZETA_PENDING		0x00000020
#define NV_PGRAPH_NSOURCE_ILLEGAL_MTHD_PENDING		0x00000040
#define NV_PGRAPH_NSOURCE_DMA_R_PROTECTION_PENDING	0x00000080
#define NV_PGRAPH_NSOURCE_DMA_W_PROTECTION_PENDING	0x00000100
#define NV_PGRAPH_NSOURCE_FORMAT_EXCEPTION_PENDING	0x00000200
#define NV_PGRAPH_NSOURCE_PATCH_EXCEPTION_PENDING	0x00000400
#define NV_PGRAPH_NSOURCE_STATE_INVALID_PENDING		0x00000800
#define NV_PGRAPH_NSOURCE_DOUBLE_NOTIFY_PENDING		0x00001000
#define NV_PGRAPH_NSOURCE_NOTIFY_IN_USE_PENDING		0x00002000
#define NV_PGRAPH_NSOURCE_METHOD_CNT_PENDING		0x00004000
#define NV_PGRAPH_NSOURCE_BFR_NOTIFICATION_PENDING	0x00008000
#define NV_PGRAPH_NSOURCE_DMA_VTX_PROTECTION_PENDING	0x00010000
#define NV_PGRAPH_NSOURCE_IDX_INLINE_REUSE_PENDING	0x00020000
#define NV_PGRAPH_NSOURCE_INVALID_OPERATION_PENDING	0x00040000
#define NV_PGRAPH_NSOURCE_FD_INVALID_OPERATION_PENDING	0x00080000
#define NV_PGRAPH_NSOURCE_TEX_A_PROTECTION_PENDING	0x00400000
#define NV_PGRAPH_NSOURCE_TEX_B_PROTECTION_PENDING	0x00800000

#define NV_PGRAPH_INTR_EN					0x00400140
#define NV_PGRAPH_INTR_EN_ALL_ENABLE			0xFFFFFFFF

#define NV_PGRAPH_CTX_CONTROL					0x00400144
#define NV_PGRAPH_CTX_CONTROL_TIME_NOT_EXPIRED		0x00000100
#define NV_PGRAPH_CTX_CONTROL_CHID_VALID		0x00010000
#define NV_PGRAPH_CTX_CONTROL_DEVICE_ENABLED		0x10000000

#define NV_PGRAPH_CTX_USER					0x00400148
#define NV_PGRAPH_CTX_USER_CHID				0x1F000000

#define NV_PGRAPH_CTX_SWITCH1					0x0040014C
#define NV_PGRAPH_CTX_SWITCH1_ALL_DISABLE		0
#define NV_PGRAPH_CTX_SWITCH1_GRCLASS			0x000000FF

#define NV_PGRAPH_CTX_SWITCH2					0x00400150
#define NV_PGRAPH_CTX_SWITCH2_ALL_DISABLE		0

#define NV_PGRAPH_CTX_SWITCH3					0x00400154
#define NV_PGRAPH_CTX_SWITCH3_ALL_DISABLE		0

#define NV_PGRAPH_CTX_SWITCH4					0x00400158
#define NV_PGRAPH_CTX_SWITCH4_ALL_DISABLE		0

#define NV_PGRAPH_STATUS					0x00400700
#define NV_PGRAPH_STATUS_NOT_BUSY			0

#define NV_PGRAPH_TRAPPED_ADDR					0x00400704
#define NV_PGRAPH_TRAPPED_ADDR_MTHD			0x00001FFC
#define NV_PGRAPH_TRAPPED_ADDR_CHID			0x01F00000

#define NV_PGRAPH_TRAPPED_DATA_LOW				0x00400708
#define NV_PGRAPH_TRAPPED_DATA_LOW_VALUE			0xFFFFFFFF

#define NV_PGRAPH_TRAPPED_DATA_HIGH				0x0040070C
#define NV_PGRAPH_TRAPPED_DATA_HIGH_VALUE			0xFFFFFFFF

#define NV_PGRAPH_INCREMENT					0x0040071C
#define NV_PGRAPH_INCREMENT_READ_3D_TRIGGER		0x00000002

#define NV_PGRAPH_FIFO						0x00400720
#define NV_PGRAPH_FIFO_ACCESS_DISABLE			0
#define NV_PGRAPH_FIFO_ACCESS_ENABLE			0x00000001

#define NV_PGRAPH_RDI_INDEX					0x00400750 //addr
#define NV_PGRAPH_RDI_INDEX_ADDRESS			0x00001FFC
#define NV_PGRAPH_RDI_INDEX_SELECT			0x01FF0000

#define NV_PGRAPH_RDI_DATA					0x00400754 //data

#define NV_PGRAPH_FFINTFC_ST2					0x00400764
#define NV_PGRAPH_FFINTFC_ST2_CHID_STATUS_VALID		0x08000000
#define NV_PGRAPH_FFINTFC_ST2_CHSWITCH_CLEAR		0xEFFFFFFF
#define NV_PGRAPH_FFINTFC_ST2_FIFOHOLD_CLEAR		0xDFFFFFFF

#define NV_PGRAPH_CHANNEL_CTX_TABLE				0x00400780
#define NV_PGRAPH_CHANNEL_CTX_TABLE_INST		0x0000FFFF

#define NV_PCRTC_CONFIG						0x00600804
#define NV_PCRTC_CONFIG_START_ADDRESS			0x00000007
#define NV_PCRTC_CONFIG_START_ADDRESS_VGA		0x00000000
#define NV_PCRTC_CONFIG_START_ADDRESS_NON_VGA		0x00000001
#define NV_PCRTC_CONFIG_START_ADDRESS_HSYNC		0x00000002

#define NV_PRMCIO_CRX__COLOR					0x006013D4 //addr
#define NV_PRMCIO_CR__COLOR					0x006013D5 //data

#define NV_PRAMDAC_NVPLL_COEFF					0x00680500
#define NV_PRAMDAC_NVPLL_COEFF_MDIV			0x000000FF
#define NV_PRAMDAC_NVPLL_COEFF_NDIV			0x0000FF00
#define NV_PRAMDAC_NVPLL_COEFF_PDIV			0x00070000

#define NV_PRAMDAC_MPLL_COEFF					0x00680504
#define NV_PRAMDAC_MPLL_COEFF_MDIV			0x000000FF
#define NV_PRAMDAC_MPLL_COEFF_NDIV			0x0000FF00
#define NV_PRAMDAC_MPLL_COEFF_PDIV			0x00070000

#define NV_PRAMDAC_VPLL_COEFF					0x00680508
#define NV_PRAMDAC_VPLL_COEFF_MDIV			0x000000FF
#define NV_PRAMDAC_VPLL_COEFF_NDIV			0x0000FF00
#define NV_PRAMDAC_VPLL_COEFF_PDIV			0x00070000

#define NV_USER_DAC_WRITE_MODE_ADDRESS				0x006813C8
#define NV_USER_DAC_WRITE_MODE_ADDRESS_VALUE		0x000000FF

#define NV_USER_DAC_PALETTE_DATA				0x006813C9
#define NV_USER_DAC_PALETTE_DATA_VALUE			0x000000FF

#define NV_PRAMIN						0x00700000

#define NV_USER							0x00800000


