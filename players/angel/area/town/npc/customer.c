/*                                                                            *
 *      File:             /players/angel/area/town/npc/customer.c             *
 *      Function:         NPC                                                 *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2006 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           11/20/06                                            *
 *      Notes:                                                                *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
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
    case 0: A = "James"; break;
    case 1: A = "Billy"; break;
    case 2: A = "Thomas"; break;
    case 3: A = "Robert"; break;
    case 4: A = "Michael"; break;
    case 5: A = "Brandon"; break;
    case 6: A = "Brent"; break;
    case 7: A = "Alex"; break;
    case 8: A = "Zack"; break;
    case 9: A = "Robbie"; break; }

  set_name("customer");
  set_race("human");
  set_alias("customer");
  set_short(""+HIC+A+NORM+" [customer]");
  set_long("\
This is regular customer, but beware you never know how strong a stranger is!\n");
  set_level(15 + random (4));
  set_hp(180 + random (90));
  set_wc(16 + random (8));
  set_ac(10 + random (5));
  set_al(0);
  set_chat_chance(4);
  set_a_chat_chance(8);
  load_chat(query_name()+" asks, \"Hello, can I get some help here?\"\n");
  load_chat(query_name()+" says, \"Man this is a long line!\"\n");
  load_a_chat(query_name()+" says, \"Is that all you have?\"\n");
  gold=clone_object("obj/money");
  gold->set_money(random(1500)+2000);
  move_object(gold, this_object());
    switch(random(3))
    {
      case 0:
        armor=clone_object("/players/angel/area/school/obj/underwear_01.c");
        move_object(armor, this_object());
        command("wear underwear", this_object());
        break;
      case 1:
        armor=clone_object("/players/angel/area/school/obj/boots_02.c");
        move_object(armor, this_object());
        command("wear boots", this_object());
        break;
      case 2:
        armor=clone_object("/players/angel/area/school/obj/jeans_01.c");
        move_object(armor, this_object());
        command("wear jeans", this_object());
        break;
    }
set_multi_cast(1);

  add_spell("stiffarm",
"#MN# $HG$Stiff Arms$N$ you in the face!\n",
"#MN# $HG$Stiff Arms$N$ #TN# in the face!\n",
5,({10,10}),({"physical","physical"}));

  add_spell("fistjab",
"#MN# hurls your body to the ground then lands a stiff $G$FIST JAB$N$!\n",
"#MN# hurls a body to the ground then lands a stiff $G$FIST JAB$N$ at #TN#!\n",
10,({5,40}),({"physical","physical"}));

}