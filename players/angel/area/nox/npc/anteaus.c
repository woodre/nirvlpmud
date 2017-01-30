/*                                                                    *
 *    File:             /players/angel/area/nox/npc/anteaus.c         *
 *    Function:         npc                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2008 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           07/01/08                                      *
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
  object gold, armor;
  ::reset(arg);
  if(arg) return;
  set_name("anteaus");
  set_alt_name("nox");
  set_race("nox");
  set_alias("nox");
  set_short("");
  set_long("\
  Anteaus a Nox man, is the husband of Lya, and father of Nafrayu.\n\
He is five feet two inches tall with wild hair.\n");
  set_level(29);
  set_hp(2000);
  set_ac(28 + random (4));
  set_wc(55 + random (4));
  set_al(0);
  set_heal(40,10);
  gold=clone_object("obj/money");
  gold->set_money(random(1000)+30000);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/nox/obj/boots.c");
  move_object(armor, this_object());
  command("wear boots", this_object());
  set_chat_chance(2);
  load_chat("You feel a tug at your hair as something moves by!\n");
  load_chat("A cool breeze moves through the air!\n");
  /*This NPC is invisible w/a silent_move_object, moves, has a heal, and has 2 multi cast(3) spells*/
  set_multi_cast(3);
  add_spell("forcefield",
    "#MN# concentrates and a $HW$FORCEFIELD$N$ surrounds his body reflecting your attack!\n",
    "#MN# concentrates and a $HW$FORCEFIELD$N$ surrounds his body reflecting your attack!\n",
    10,({25,25}),({"physical","physical"}));
  add_spell("fist",
    "#MN# swiftly swings his fist $G$B U S T I N G$N$ #TN#, directly in the head!\n",
    "#MN# swiftly swings his fist $G$B U S T I N G$N$ #TN#, directly in the head!\n",
    20,({5,40}),({"physical","physical"}));
  /*
  call_out("random_move",10);
  */
}

short() { return 0; }

random_move() {
    int n;
  if(!environment()) return 1;
    if(!query_attack()) {
        n = random(8);
    if (n == 0)
        command("west");
    else if (n == 1)
        command("east");
    else if (n == 2)
        command("south");
    else if (n == 3)
        command("north");
    else if (n == 4)
        command("northwest");
    else if (n == 5)
        command("southwest");
    else if (n == 6)
        command("northeast");
    else if (n == 7)
        command("southeast");
}
call_out("random_move",10);
return 1;
}
