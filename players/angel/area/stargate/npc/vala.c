/*                                                                    *
 *    File:             /players/angel/area/stargate/npc/vala.c       *
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
  set_name("vala mal doran");
  set_alt_name("vala");
  set_race("military");
  set_alias("doran");
  set_short("Vala Mal Doran");
  set_long("\
  Vala Mal Doran is an ally of SG-1. She makes a living trading,\n\
  stealing, and selling things, and though she provides weapons to\n\
  shadey characters, she is something of a morally conscious arms\n\
  dealer. She is brash and self-confident, and disguises her true,\n\
  sensitive character with humor and innuendo. Because of their\n\
  history together, Vala and Daniel Jackson have a special,\n\
  love-hate relationship.\n");
  set_level(26);
  set_hp(1200 + random (100));
  set_ac(24 + random (7));
  set_wc(46 + random (7));
  set_heal(5,10);
  set_al(0);
  weapon=clone_object("/players/angel/area/stargate/obj/zat.c");
  move_object(weapon, this_object());
  command("wield zat", this_object());
  set_chat_chance(5);
  load_chat(query_name()+" says, \"Baby I got something for you!\"\n");
  load_chat("What do you need, I could make you a great deal!\n");
/*  This mob has three special spell attacks and one heal */
  set_multi_cast(1);

  add_spell("bslap",
"#MN# $HR$B I T C H   S L A P S$N$ you with her venomous nails!\n",
"#MN# $HR$B I T C H   S L A P S$N$ #TN# with her venomous nails!\n",
5,({10,10}),({"other|poison","physical"}));

  add_spell("zat",
"#MN# releases a massive force from the ZAT  $HG$WEAPON$N$-$HR$BLAST$N$\n"+
"burning your flesh!\n",
"#MN# releases a massive force from the ZAT  $HG$WEAPON$N$-$HR$BLAST$N$!\n",
20,({5,40}),({"physical","other|laser"}));

  add_spell("cat claw",
"#MN# summons forth a massive  $HR$C A T$N$-$HR$C L A W$N$\n"+
"engulfing you!\n",
"#MN# summons forth a massive  $HR$C A T$N$-$HR$C L A W$N$!\n",
15,({25,35}),({"physcial","other|evil"}),1);
}