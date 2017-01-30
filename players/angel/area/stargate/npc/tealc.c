/*                                                                    *
 *    File:             /players/angel/area/stargate/npc/tealc.c      *
 *    Function:         npc                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           1/5/06                                        *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */
 
#include "/sys/lib.h"
 
#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("teal'c");
  set_alt_name("tealc");
  set_race("military");
  set_alias("jaffa");
  set_short("Teal'c");
  set_long("\
  Jaffa Teal'c, a strong and dependable warrior who defected to the\n\
Tau'ri after realizing they could be the key to freeing his species\n\
from slavery to the Goa'uld. His name means 'strength'. Teal'c is a\n\
Jaffa -- a human used by the Goa'uld as an incubator for infant\n\
Goa'uld parasites. Teal'c was not joined with his Goa'uld, but\n\
carried one in larval form within his belly. He is more than 100\n\
years old. His long service to the Goa'uld has made him knowledgable\n\
of language, enemies, races, technology and extreamly strong.\n");
  set_level(29);
  set_hp(2000 + random (100));
  set_ac(28 + random (5));
  set_wc(55 + random (5));
  set_al(0);
  set_heal(5,10);
  gold=clone_object("obj/money");
  gold->set_money(random(1000)+28000);
  move_object(gold, this_object());
  weapon=clone_object("/players/angel/area/stargate/obj/staff.c");
  move_object(weapon, this_object());
  command("wield staff", this_object());
  set_chat_chance(5);
  load_chat("Teal'c raises his eyebrow and makes you crumble to your knees.\n");
  load_chat("Teal'c stares you down. You feel insignificant to his massive stature.\n");
/*  This mob has three special spell attacks and one heal */
  set_multi_cast(3);

  add_spell("head bust",
"#MN# swiftly swings his staff around $G$B U S T I N G$N$\n"+
"you, directly in your head!\n",
"#MN#  $G$B U S T$N$\n"+
" #TN#, direct hit!\n",
20,({5,40}),({"physical","physical"}));

add_spell("energy",
"#MN# summons forth a massive $HM$B U R S T$N$, of energy from his symbiote!\n",
"#MN# summons forth a massive $HM$B U R S T$N$, of energy from his symbiote!\n",
20,({10,40}),({"physical","other|eletric"}));

  add_spell("staff fire",
"#MN# releases a massive force   $HR$WEAPON$N$-$HR$BLAST$N$\n"+
"burning your flesh!\n",
"#MN# releases a massive force   $HR$WEAPON$N$-$HR$BLAST$N$!\n",
15,({25,35}),({"other|fire","other|laser"}),1);
}