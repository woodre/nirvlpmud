/*                                                                   
 *      File:             /players/lacar/area/crater/obj/spore.c       
 *      Function:        obj			                                        
 *      Author(s):        Lacar@nirvana                               
 *      Copyright:        Copyright (c) 2007 Lacar (Carla J Merrill)   
 *                                All Rights Reserved                  
 *      Source:    		01/14/2007                                       
 *      Notes:            area
 *      Change History:
 */
#include <ansi.h>
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Sporel");
  add_alias("spore");
  set_short("green spore");
  set_long("Green spore from a mushroom that looks eatable. ");
  set_type("heal");
  set_type_single("heal");
  set_msg("You eat the spore.\n");
  set_msg2(" ate a tasty spore.\n");
  add_cmd("eat");
  set_heal(20,20);
  set_charges(2);
  set_soak(3);
  set_stuff(3);
  set_value(160);
}

query_save_flag(){
  return 1;
  }

