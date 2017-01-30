/*                                                                    *
 *    File:             /players/angel/area/atlantis/npc/athosians.c  *
 *    Function:         npc                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           10/05/07                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/monster";

string A;
int a;

object gold,armor,weapon;
reset(arg) {
  ::reset(arg);
  if(arg) return;

  a = random(10);
  switch(a){
    case 0: A = "Charin"; break;
    case 1: A = "Tagan"; break;
    case 2: A = "Jinto"; break;
    case 3: A = "Wex"; break;
    case 4: A = "Talus"; break;
    case 5: A = "Cetus"; break;
    case 6: A = "Wallace"; break;
    case 7: A = "Panou "; break;
    case 8: A = "Nykl"; break;
    case 9: A = "Vukelic"; break; }

  set_name("athosian");
  set_race("athosian");
  set_alias("athos");
  set_short(""+HIB+A+NORM+" [Athosian]");
  set_long(
  "At first glance the Athosians might not appear technologically\n"+
  "advanced, but they certainly have enhanced tools. They choose\n"+
  "not to advance too far for fear that it will bring the Wraith\n"+
  "down upon them. The Athosians possess keen intellects and\n"+
  "abilities.\n");
  set_level(15);
  set_hp(250);
  set_ac(12);
  set_wc(20);
  set_al(0);
  set_heal(5,10);
  gold=clone_object("obj/money");
  gold->set_money(random(500)+1000);
  move_object(gold, this_object());
  set_chat_chance(6);
  load_chat("Have you seen our leader Teyla?\n");
  load_chat("Have you been to the mainland?\n");
  armor=clone_object("/players/angel/area/atlantis/obj/escrima.c");
  move_object(armor, this_object());
  command("wield staff", this_object());
  armor=clone_object("/players/angel/area/atlantis/obj/scan.c");
  move_object(armor, this_object());
  set_multi_cast(1);
  add_spell("stiffarm",
    "#MN# $HG$Stiff Arms$N$ you in the face!\n",
    "#MN# $HG$Stiff Arms$N$ #TN# in the face!\n",
    5,({10,10}),({"physical","physical"}));
  add_spell("fistjab",
    "#MN# hurls your body to the ground then lands a stiff $G$FIST JAB$N$!\n",
    "#MN# hurls a body to the ground then lands a stiff $G$FIST JAB$N$ at #TN#!\n",
    10,({5,20}),({"physical","other|lightning"}));
}