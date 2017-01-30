/* ========================================================================== */
/*                                                                            */
/*   maxim_chest.c                                                            */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Treasure chest in King Maxim's treasury                                  */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types

inherit "/players/rumplemintz/obj/chest.c";

void reset(status arg){
  if(arg) return;
  set_name("chest");
  add_alias("treasure chest");
  set_short("A treasure chest");
  set_long("One of King Maxim's treasure chests.\n");
  set_weight(8);
  set_value(200);
}

status get(){ return 0; }
