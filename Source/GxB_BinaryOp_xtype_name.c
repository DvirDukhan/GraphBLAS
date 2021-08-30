//------------------------------------------------------------------------------
// GxB_BinaryOp_xtype_name: return the type_name of x for z=f(x,y)
//------------------------------------------------------------------------------

// SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2021, All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

//------------------------------------------------------------------------------

#include "GB.h"

GrB_Info GxB_BinaryOp_xtype_name    // return the name of the type of x
(
    char *type_name,        // name of the type (char array of size at least
                            // GxB_MAX_NAME_LEN, owned by the user application).
    const GrB_BinaryOp binaryop
)
{ 

    //--------------------------------------------------------------------------
    // check inputs
    //--------------------------------------------------------------------------

    GB_WHERE1 ("GxB_BinaryOp_xtype_name (type_name, op)") ;
    GB_RETURN_IF_NULL (type_name) ;
    GB_RETURN_IF_NULL_OR_FAULTY (binaryop) ;
    ASSERT_BINARYOP_OK (binaryop, "binaryop for xtype_name", GB0) ;

    //--------------------------------------------------------------------------
    // get the type_name
    //--------------------------------------------------------------------------

    memcpy (type_name, binaryop->xtype->name, GxB_MAX_NAME_LEN) ;
    return (GrB_SUCCESS) ;
}

