/*
    $Id: namespace.h,v 1.1 92/05/25 05:36:58 tubmud Exp $
    marion@cs.tu-berlin.de
*/

/* $Log:	namespace.h,v $
 * Revision 1.1  92/05/25  05:36:58  tubmud
 * Initial revision
 * 
 */

#ifndef _basic_namespace_h
#define _basic_namespace_h

void add_namespace(mixed key);
status set_namespace(mixed keys, mixed data);
mixed get_namespace(mixed keys);

mixed export_namespace();
void import_namespace(mixed import);

#endif /* _basic_namespace_h */
