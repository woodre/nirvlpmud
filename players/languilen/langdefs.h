/*
 *  Langdefs.h  -  A header file for common definitions.
 */

#define TP this_player()
#define TPN this_player()->query_name()
#define TPRN this_player()->query_real_name()

#define TO this_object()

#define ENV environment()
#define ETO environment(this_object())
#define ETP environment(this_player())

#define FOREACH(x, y) for(x=first_inventory(y);x;x=next_inventory(x))

