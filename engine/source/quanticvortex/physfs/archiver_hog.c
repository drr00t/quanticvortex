/*
 * HOG support routines for PhysicsFS.
 *
 * This driver handles Descent I/II HOG archives.
 *
 * The format is very simple:
 *
 *   The file always starts with the 3-byte signature "DHF" (Descent
 *   HOG file). After that the files of a HOG are just attached after
 *   another, divided by a 17 bytes header, which specifies the name
 *   and length (in bytes) of the forthcoming file! So you just read
 *   the header with its information of how big the following file is,
 *   and then skip exact that number of bytes to get to the next file
 *   in that HOG.
 *
 *    char sig[3] = {'D', 'H', 'F'}; // "DHF"=Descent HOG File
 *
 *    struct {
 *     char file_name[13]; // Filename, padded to 13 bytes with 0s
 *     int file_size; // filesize in bytes
 *     char data[file_size]; // The file data
 *    } FILE_STRUCT; // Repeated until the end of the file.
 *
 * (That info is from http://www.descent2.com/ddn/specs/hog/)
 *
 * Please see the file LICENSE.txt in the source's root directory.
 *
 *  This file written by Bradley Bell.
 *  Based on grp.c by Ryan C. Gordon.
 */

#if (defined PHYSFS_SUPPORTS_HOG)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "physfs.h"

#define __PHYSICSFS_INTERNAL__
#include "physfs_internal.h"

static inline int readAll(PHYSFS_Io *io, void *buf, const PHYSFS_uint64 len)
{
    return (io->read(io, buf, len) == len);
} /* readAll */

static UNPKentry *hogLoadEntries(PHYSFS_Io *io, PHYSFS_uint32 *_entCount)
{
    const PHYSFS_uint64 iolen = io->length(io);
    PHYSFS_uint32 entCount = 0;
    void *ptr = NULL;
    UNPKentry *entries = NULL;
    UNPKentry *entry = NULL;
    PHYSFS_uint32 size = 0;
    PHYSFS_uint32 pos = 3;

    while (pos < iolen)
    {
        entCount++;
        ptr = allocator.Realloc(ptr, sizeof (UNPKentry) * entCount);
        GOTO_IF_MACRO(ptr == NULL, ERR_OUT_OF_MEMORY, hogLoad_failed);
        entries = (UNPKentry *) ptr;
        entry = &entries[entCount-1];

        GOTO_IF_MACRO(!readAll(io, &entry->name, 13), NULL, hogLoad_failed);
        pos += 13;
        GOTO_IF_MACRO(!readAll(io, &size, 4), NULL, hogLoad_failed);
        pos += 4;

        entry->size = PHYSFS_swapULE32(size);
        entry->startPos = pos;
        pos += size;

        /* skip over entry */
        GOTO_IF_MACRO(!io->seek(io, pos), NULL, hogLoad_failed);
    } /* while */

    *_entCount = entCount;
    return entries;

hogLoad_failed:
    allocator.Free(entries);
    return NULL;
} /* hogLoadEntries */


static void *HOG_openArchive(PHYSFS_Io *io, const char *name, int forWriting)
{
    PHYSFS_uint8 buf[3];
    PHYSFS_uint32 entryCount = 0;
    UNPKentry *entries = NULL;

    assert(io != NULL);  /* shouldn't ever happen. */
    BAIL_IF_MACRO(forWriting, ERR_ARC_IS_READ_ONLY, 0);
    BAIL_IF_MACRO(!readAll(io, buf, 3), NULL, 0);
    BAIL_IF_MACRO(memcmp(buf, "DHF", 3) != 0, ERR_NOT_AN_ARCHIVE, NULL);

    entries = hogLoadEntries(io, &entryCount);
    BAIL_IF_MACRO(entries == NULL, NULL, NULL);
    return UNPK_openArchive(io, entries, entryCount);
} /* HOG_openArchive */


const PHYSFS_ArchiveInfo __PHYSFS_ArchiveInfo_HOG =
{
    "HOG",
    HOG_ARCHIVE_DESCRIPTION,
    "Bradley Bell <btb@icculus.org>",
    "http://icculus.org/physfs/",
};


const PHYSFS_Archiver __PHYSFS_Archiver_HOG =
{
    &__PHYSFS_ArchiveInfo_HOG,
    HOG_openArchive,        /* openArchive() method    */
    UNPK_enumerateFiles,     /* enumerateFiles() method */
    UNPK_openRead,           /* openRead() method       */
    UNPK_openWrite,          /* openWrite() method      */
    UNPK_openAppend,         /* openAppend() method     */
    UNPK_remove,             /* remove() method         */
    UNPK_mkdir,              /* mkdir() method          */
    UNPK_dirClose,           /* dirClose() method       */
    UNPK_stat                /* stat() method           */
};

#endif  /* defined PHYSFS_SUPPORTS_HOG */

/* end of hog.c ... */

