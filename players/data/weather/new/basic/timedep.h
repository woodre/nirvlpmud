/*
    $Id: timedep.h,v 1.2 1992/06/11 11:59:54 tubmud Exp $
    basic/timedep.h - time dependant references
    Jun 1992 by marion@cs.tu-berlin.de
    Many ideas from Foslay.

    Please don't use this file in your code anymore; the defines are moved
    to <timedep.h>.   Coogan, 25-Oct-1997
*/

/* $Log: timedep.h,v $
 * Revision 1.2  1992/06/11  11:59:54  tubmud
 * regular check in
 *
 * Revision 1.1  92/05/25  09:50:08  tubmud
 * Initial revision
 * 
 */

#ifndef _basic_timedep_h
#define _basic_timedep_h

// the following include is only for compatibility, Coogan.
#include <timedep.h>

string* set_timedep   (int *when, mixed *what, string *space, string which);
mixed   query_timedep (string *space);
// changed int to string* in the next line, Coogan, 12-Sep-00
string* add_timedep   (int when, mixed what, string *space);
mixed*  query_timedep_table (string *space);
void    set_default_depspace (string *depspace);

#endif /* _basic_timedep_h */
