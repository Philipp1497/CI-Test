/*****************************************************************************/
/* crc_tbl.h                                                                 */
/*                                                                           */
/* Copyright (c) 2010 Texas Instruments Incorporated                         */
/* http://www.ti.com/                                                        */
/*                                                                           */
/*  Redistribution and  use in source  and binary forms, with  or without    */
/*  modification,  are permitted provided  that the  following conditions    */
/*  are met:                                                                 */
/*                                                                           */
/*     Redistributions  of source  code must  retain the  above copyright    */
/*     notice, this list of conditions and the following disclaimer.         */
/*                                                                           */
/*     Redistributions in binary form  must reproduce the above copyright    */
/*     notice, this  list of conditions  and the following  disclaimer in    */
/*     the  documentation  and/or   other  materials  provided  with  the    */
/*     distribution.                                                         */
/*                                                                           */
/*     Neither the  name of Texas Instruments Incorporated  nor the names    */
/*     of its  contributors may  be used to  endorse or  promote products    */
/*     derived  from   this  software  without   specific  prior  written    */
/*     permission.                                                           */
/*                                                                           */
/*  THIS SOFTWARE  IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS    */
/*  "AS IS"  AND ANY  EXPRESS OR IMPLIED  WARRANTIES, INCLUDING,  BUT NOT    */
/*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR    */
/*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT    */
/*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,    */
/*  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL  DAMAGES  (INCLUDING, BUT  NOT    */
/*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,    */
/*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY    */
/*  THEORY OF  LIABILITY, WHETHER IN CONTRACT, STRICT  LIABILITY, OR TORT    */
/*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE    */
/*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.     */
/*                                                                           */
/*                                                                           */
/* Specification of CRC table data structures which can be automatically     */
/* generated by the linker (using the crc_table() operator in the linker     */
/* command file).                                                            */
/*****************************************************************************/
/*****************************************************************************/
/*                                                                           */
/*  The CRC generator used by the linker is based on concepts from the       */
/*  document:                                                                */
/*     "A Painless Guide to CRC Error Detection Algorithms"                  */
/*                                                                           */
/* Author : Ross Williams (ross@guest.adelaide.edu.au.).                     */
/* Date   : 3 June 1993.                                                     */
/* Status : Public domain (C code).                                          */
/*                                                                           */
/* Description : For more information on the Rocksoft^tm Model CRC           */
/* Algorithm, see the document titled "A Painless Guide to CRC Error         */
/* Detection Algorithms" by Ross Williams (ross@guest.adelaide.edu.au.).     */
/* This document is likely to be in "ftp.adelaide.edu.au/pub/rocksoft" or    */
/* at http:www.ross.net/crc/download/crc_v3.txt.                             */
/*                                                                           */
/* Note: Rocksoft is a trademark of Rocksoft Pty Ltd, Adelaide, Australia.   */
/*****************************************************************************/
#ifndef _CRC_TBL_H_
#define _CRC_TBL_H_

#include <stdint.h>        /* For uintXX_t */
#include "crc_defines.h"


/****************************************************************************/
/* CRC Record Data Structure                                                */
/* NOTE: The list of fields and the size of each field varies by target     */
/*       and memory model.                                                  */
/****************************************************************************/
typedef struct crc_record
{
   uint32_t         crc_value;
   uint16_t         crc_alg_ID;  /* CRC algorithm ID                        */
   uintptr_t        addr;        /* Starting address                        */
#if defined(__LARGE_CODE_MODEL__) || defined(__LARGE_DATA_MODEL__)
   uint32_t         size;        /* size of data in 8-bit addressable units */
#else
   uint16_t         size;        /* size of data in 8-bit addressable units */
#endif
} CRC_RECORD;

 
/**********************************************************/
/* CRC Table Data Structure                               */
/**********************************************************/
typedef struct crc_table
{
   uint16_t         rec_size;    /* 8-bit addressable units */
   uint16_t         num_recs;
   CRC_RECORD       recs[1];
} CRC_TABLE;

#endif /* _CRC_TBL_H_ */