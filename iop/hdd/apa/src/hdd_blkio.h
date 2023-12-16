/*
# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright 2001-2004, ps2dev - http://www.ps2dev.org
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.
*/

#ifndef _HDD_BLKIO_H
#define _HDD_BLKIO_H

#ifdef APA_USE_ATAD
#include <atad.h>

#define BLKIO_MAX_VOLUMES 2

#define BLKIO_DIR_READ ATA_DIR_READ
#define BLKIO_DIR_WRITE ATA_DIR_WRITE

static inline int blkIoInit(void)
{
	return 0;
}

static inline int blkIoDmaTransfer(int device, void *buf, u32 lba, u32 nsectors, int dir)
{
    return sceAtaDmaTransfer(device, buf, lba, nsectors, dir);
}

static inline int blkIoIdle(int device, int period)
{
    return sceAtaIdle(device, period);
}

static inline int blkIoGetSceId(int device, void *data)
{
    return sceAtaGetSceId(device, data);
}

static inline int blkIoSmartReturnStatus(int device)
{
    return sceAtaSmartReturnStatus(device);
}

static inline int blkIoSmartSaveAttr(int device)
{
    return sceAtaSmartSaveAttr(device);
}

static inline int blkIoFlushCache(int device)
{
    return sceAtaFlushCache(device);
}

static inline int blkIoIdleImmediate(int device)
{
    return sceAtaIdleImmediate(device);
}
#else
#define BLKIO_MAX_VOLUMES 10

#define BLKIO_DIR_READ 0
#define BLKIO_DIR_WRITE 1

extern int blkIoInit(void);
extern int blkIoDmaTransfer(int device, void *buf, u32 lba, u32 nsectors, int dir);
extern int blkIoIdle(int device, int period);
extern int blkIoGetSceId(int device, void *data);
extern int blkIoSmartReturnStatus(int device);
extern int blkIoSmartSaveAttr(int device);
extern int blkIoFlushCache(int device);
extern int blkIoIdleImmediate(int device);

#ifdef APA_USE_IOMANX
extern int hdd_blkio_vhdd_mount(int slot, const char *filename);
extern int hdd_blkio_vhdd_umount(int slot);
#endif
#endif

#endif /* _HDD_BLKIO_H */
