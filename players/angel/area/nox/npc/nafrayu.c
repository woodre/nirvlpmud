/*                                                                    *
 *    File:             /players/angel/area/nox/npc/nafrayu.c         *
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
  set_name("nafrayu");
  set_alt_name("nox");
  set_race("nox");
  set_alias("nox");
  set_short("");
  set_long("\
  This is Nafrayu a Nox boy. He is very inquisitive and friendly.\n\
He is the son of Anteaus and Lya. Nafrayu is about four feet tall.\n");
  set_level(23);
  set_hp(2000);
  set_ac(21 + random (3));
  set_wc(40 + random (3));
  set_al(100);
  set_heal(20,10);
  gold=clone_object("obj/money");
  gold->set_money(random(500)+8000);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/nox/obj/boots.c");
  move_object(armor, this_object());
  command("wear boots", this_object());
  set_chat_chance(4);
  load_chat("You feel a tug at your hair as something moves by!\n");
  load_chat("A cool breeze moves through the air!\n");
  /*This NPC is invisible w/a silent_move_object, moves, has a heal, and has 1 multi cast(3) spell*/
  set_multi_cast(3);
  add_spell("forcefield",
    "#MN# concentrates and a $HW$FORCEFIELD$N$ surrounds his body reflecting your attack!\n",
    "#MN# concentrates and a $HW$FORCEFIELD$N$ surrounds his body reflecting your attack!\n",
    10,({25,25}),({"physical","physical"}));
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
