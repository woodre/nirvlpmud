/*
    basic/macros.h - useful macros _not_ defining void - sigh
    Feb 1992 by marion@cs.tu-berlin.de
*/

#ifndef _basic_macros_h
#define _basic_macros_h

/* foslay Jul-09-1992 */
#define BLUEPRINT(x)	(explode((objectp(x) ? object_name(x) : x),"#")[0])

/* is ob cloned */
#define CLONED(ob)      (!!sizeof (regexp (({object_name (ob)}), ".*#[0-9]*")))
#define LOAD(file)	(!catch(call_other(file,"-"))) /* load file */

/* does ob contain what */
#define CONTAINS(ob,what) (member(all_environment(what), ob)>=0)

#define INSIDE		(CONTAINS(this_object(),this_player()))

#endif /* _basic_macros_h */
