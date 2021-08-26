//------------------------------------------------------------------------------
// GB_serialize_to_blob: copy a set of blocks to the blob
//------------------------------------------------------------------------------

// SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2021, All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

//------------------------------------------------------------------------------

#include "GB.h"
#include "GB_serialize.h"

void GB_serialize_to_blob
(
    // input/output
    GB_void *blob,          // blocks are appended to the blob
    size_t *s_handle,       // location to append into the blob
    // input:
    GB_blocks *Blocks,      // Blocks: array of size nblocks+1
    int64_t *Sblock,        // array of size nblocks
    int32_t nblocks,        // # of blocks
    int nthreads_max        // # of threads to use
)
{

    //--------------------------------------------------------------------------
    // check inputs
    //--------------------------------------------------------------------------

    GrB_Info info ;
    ASSERT (blob != NULL) ;
    ASSERT (s_handle != NULL) ;
    ASSERT (nblocks >= 0) ;
    ASSERT ((nblocks > 0) == (Blocks != NULL)) ;
    ASSERT (nthreads_max > 0) ;

    //--------------------------------------------------------------------------
    // check for quick return
    //--------------------------------------------------------------------------

    if (nblocks == 0)
    {
        // no blocks for this array
        return ;
    }

    //--------------------------------------------------------------------------
    // determine # of threads to use
    //--------------------------------------------------------------------------

    int nthreads = GB_IMIN (nthreads_max, nblocks) ;

    //--------------------------------------------------------------------------
    // copy the blocks into the blob
    //--------------------------------------------------------------------------

    size_t s = (*s_handle) ;
    int blockid ;
    #pragma omp parallel for num_threads(nthreads) schedule(dynamic)
    for (blockid = 0 ; blockid < nblocks ; blockid++)
    {
        // copy the compressed block itself, of size s_size
        size_t s_start = (blockid == 0) ? 0 : Sblock [blockid-1] ;
        size_t s_end   = Sblock [blockid] ;
        size_t s_size  = s_end - s_start ;
        memcpy (blob + s + s_start, Blocks [blockid].p, s_size) ;
    }

    s += Sblock [nblocks-1] ;

    //--------------------------------------------------------------------------
    // return the updated index into the blob
    //--------------------------------------------------------------------------

    (*s_handle) = s ;
}

