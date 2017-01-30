
inherit "obj/armor";
#include <ansi.h>

/******************************************************************************
 * Program: ego.c
 * Path: /players/karash/Outpost/items
 * Type: armor
 * Created: July 2014 by Karash
 *
 * Purpose: A non-drop armor to boost the AC of the mob after specific
 *			keywords are spoken.  This object is destructed when mob is killed.
 *
 * History:
 *          
 ******************************************************************************/

 
 
reset(arg){
   ::reset(arg);

   set_name("An Inflated Ego");
   set_short(CYAN+"An inflated ego"+NORM);
   set_alias("ego");
   set_long("An inflated ego can defend against harsh criticisms.\n");
   set_type("armor");
   set_ac(5);
   set_weight(0);
   set_value(0);
}
