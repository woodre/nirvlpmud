/*                                                                    *
 *    File:             /players/angel/area/atlantis/npc/beckett.c    *
 *    Function:         npc                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           10/15/07                                      *
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
  set_name("beckett");
  set_alt_name("dr");
  set_race("military");
  set_alias("carson");
  set_short(""+HIG+"Dr. Beckett"+NORM+"");
  set_long(
  "  Dr. Beckett is a Biologist and chief medical doctor at\n"+
  "Earth's Atlantis base in the Pegasus Galaxy.  Beckett's\n"+
  "research on the Wraith's biology helped to develop a\n"+
  "drug that prevents the creatures from feeding on the life\n"+
  "force of a human victim.\n");
  set_level(15);
  set_hp(250);
  set_ac(12);
  set_wc(20);
  set_al(50);
  set_heal(5,10);
  gold=clone_object("obj/money");
  gold->set_money(random(400)+1000);
  move_object(gold, this_object());
  set_chat_chance(8);
  load_chat("Dr. Beckett says:  We're in another galaxy. How much more out can you get?\n");
  load_chat("Dr. Beckett says:  She knows I'm from Earth, son! It's not a bloody secret!\n");
}