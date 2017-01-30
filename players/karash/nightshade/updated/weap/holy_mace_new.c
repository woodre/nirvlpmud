inherit "obj/weapon";
#include <ansi.h>

/******************************************************************************
 * Program: holy_mace_new.c
 * Path: /players/nightshade/weap/
 * Type: Weapon
 * Created: October 2014 by Karash
 *
 * Purpose: A holy mace where half damage is physical and half damage is holy.
 *
 * History:
 *          
 ******************************************************************************/
 
 
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("mace");
  set_short(HIW+"Holy Mace"+NORM);
  set_long("This blessed mace has a sturdy balanced handle with a ball of spikes\n\
protruding outward like the rays of the sun.\n");
  
  set_type("club");
  /* Physical Damage */
  set_class(8);
  /* Good Damage */
  set_params("other|good",8,0);
  set_weight(3);
  set_value(2500);
}

