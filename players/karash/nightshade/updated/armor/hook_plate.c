inherit "obj/armor";
#include <ansi.h>

/******************************************************************************
 * Program: hook_plate.c
 * Path: /players/nightshade/armor
 * Type: Armor
 * Created: November 2014 by Karash
 *
 * Purpose: An armor piece worn by the hook horror.  Lowering the value of the 
 *		original object compared to similar pieces of armor.
 * 
 * History:
 *          
 ******************************************************************************/

reset(arg){
   ::reset(arg);
   set_short("Hook Plate");
   set_long("Armor made from the chest and back plate of a hook horror. It would provide very good protection.\n");
   set_ac(4);
   set_weight(3);
   set_value(2000);
   set_alias("armor");
   set_name("armor");
   set_type("armor");
}
