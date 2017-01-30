/*
    $Id: surface.c,v 1.1 11-Jun-1992 16:21:07 tubmud Exp $
    basic/surface.c
    Jun 92 by marion@cs.tu-berlin.de
*/

/* $Log: surface.c,v $
 * Revision 1.1  11-Jun-1992  16:21:07  tubmud
 * regular checkin
 *
 */

int
id (string ident)
{
    return !!present (ident, this_object());
}

int
apply_action (string skill, int level, string ident)
{
    object cont;

    if (skill == "examine" && (cont = present (ident, this_object()))) {
	if (!cont->apply_action (skill, level, ident)) {
	    write ((string)cont->long (ident)||""); /* adjust for 245 */
	}
    	return 1;
    }
}

int
insert_objects ()
{
    return 0;
}
