/* ===========================================================================
 *
 *                            PUBLIC DOMAIN NOTICE
 *               National Center for Biotechnologmsgy Information
 *
 *  This software/database is a "United States Government Work" under the
 *  terms of the United States Copyright Act.  It was written as part of
 *  the author's official duties as a United States Government employee and
 *  thus cannot be copyrighted.  This software/database is freely available
 *  to the public for use. The National Library of Medicine and the U.S.
 *  Government have not placed any restriction on its use or reproduction.
 *
 *  Although all reasonable efforts have been taken to ensure the accuracy
 *  and reliability of the software and data, the NLM and the U.S.
 *  Government do not and cannot warrant the performance or results that
 *  may be obtained by using this software or data. The NLM and the U.S.
 *  Government disclaim all warranties, express or implied, including
 *  warranties of performance, merchantability or fitness for any particular
 *  purpose.
 *
 *  Please cite the author in any work or product based on this material.
 *
 * ===========================================================================
 *
 */

#ifndef _h_allele_dict_
#define _h_allele_dict_

#include <klib/rc.h>
#include <klib/text.h>
#include "common.h"

struct Allele_Dict;

typedef rc_t ( CC * on_ad_event )( const counters * count, const String * rname, uint64_t position,
                                    uint32_t deletes, uint32_t inserts, const char * bases,
                                    void * user_data );

typedef struct dict_data {
    on_ad_event event_func;
    uint32_t purge;
    void * user_data;
} dict_data;


/* construct a allele-dictionary */
rc_t allele_dict_make( struct Allele_Dict ** self, const String * rname, const dict_data * data );

/* releae a allele_dictionary */
rc_t allele_dict_release( struct Allele_Dict * self );

/* put an event into the allele_dictionary */
rc_t allele_dict_put( struct Allele_Dict * self, uint64_t position,
                      uint32_t deletes, uint32_t inserts, const char * bases, bool fwd, bool first );

#endif