/*                                                                    *
 *    File:             /players/angel/area/stargate/npc/corporal.c   *
 *    Function:         npc                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           1/1/06                                        *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

inherit "/obj/monster";

#include "/sys/lib.h"

#include <ansi.h>


reset(arg)
{
  object gold,armor,weapon;
int random_index;
  ::reset(arg);
  if(arg) return;
random_index=random(10);
set_name( ({"bob","bill","tim","phil","ralph","mark","matt","kasey","tabitha","melissa"})[random_index] );
set_alt_name("worker");
set_race("human");
set_alias("geologist");
set_short( ({"Bob, a geologist","Bill, a geologist","Tim, a geologist","Phil, a geologist","Ralph, a geologist","Mark, a geologist","Matt, a geologist","Kasey, a geologist","Tabitha, a geologist","Melissa, a geologist"})[random_index] );
  set_long("\
  The corporal is a highly trained machine.\n\
Anyone would be a fool to try and fight him!\n");
set_level(51);
set_hp(400 + random(100));
set_ac(21 + random(3));
set_wc(41 + random(8));
set_al(750);
add_money(random(2000)+4000);
  armor=clone_object("/players/angel/area/stargate/obj/P90_no_ammo.c");
  move_object(armor, this_object());
  weapon=clone_object("/players/angel/area/stargate/obj/bullets.c");
  move_object(weapon, this_object());
  command("load P90", this_object());
  set_chat_chance(5);
  load_chat(query_name()+" says, \"You are not allowed beyond this point!\"\n");
  load_chat("This is a highly secure area!\n");
  add_spell("P90","#MN# shoots his $HR$P-90$N$ piercing you.\n",
                     "#MN# shoots his $HR$P-90$N$ piercing #TN#.\n",
                     75,30,"other|physical");
}
