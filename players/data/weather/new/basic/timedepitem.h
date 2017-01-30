/*
    $Id: timedepitem.h,v 1.1 1992/06/11 16:21:11 tubmud Exp $
    basic/timedepitem.h
    Jun 92 by marion@cs.tu-berlin.de
*/

/* $Log: timedepitem.h,v $
 * Revision 1.1  1992/06/11  16:21:11  tubmud
 * regular checkin
 *
 */

#ifndef _basic_timedepitem_h
#define _basic_timedepitem_h

varargs void
    set_item_descriptions (mixed *names, string *descriptions,
			    string when, string *dep, string *space);

    /* set_item_descriptions (names, descriptions, [when], [dep], [space])
     * Set a list of item descriptions. Names and descriptions are both
     * ({"string", ...}). If `when' is given, it specifies the timedep key
     * when the items listed should get the given descriptions. If `dep'
     * is given, it specifies the timedep namespace identifier. If `space'
     * is given, it specifies the timedepitem namespace identifier.
     */

varargs void
    set_one_item_description (mixed name, string description,
				string when, string *dep, string *space);
    
    /* set_one_item_descriptions (name, description, [when], [dep], [space])
     * Set one item description. See set_item_description.
     */

varargs void
    set_one_item_descriptions (mixed name, string *descriptions,
				string *dep, string *space);

    /* set_one_item_descriptions (name, descriptions, dep, [space])
     * Set one item description for a list of different times. Descriptions
     * are ({"string", ...}). `Dep' specifies the timedep namespace identifier.
     * If `space' is given, it specifies the timedepitem namespace identifier.
     */

/* Standard identify function */
int id (string ident);

/* Standard long description function */
string query_long (string ident);

varargs mixed *query_items (string *space, string when);

varargs void remove_item (string name, string when, string *space);

/* monst, Jun-06-1995
 * remove_items is the analogue function to set_one_item_descriptions
 */
varargs void remove_items (string name, string *depspace, string *space);

/* set the default timedepitem namespace */
void set_timedepitem_space (string *space);

#endif /* _basic_timedepitem_h */
