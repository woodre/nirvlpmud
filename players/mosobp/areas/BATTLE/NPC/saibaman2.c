inherit "/obj/monster";
/*
 *  File:   /players/mosobp/areas/BATTLE/NPC/saibaman2.c
 *  Function:  mob          
 *  Author(s):  Mosobp@Nirvana
 *  Copyright: copyright (c) 2008 Mosobp
 *             all rights reserved
 *
 *   
 *  Source:  6/17/08
 *  Notes:
 *
 *                      
 *  Change History:
 */

#include "/sys/lib.h"

#include <ansi.h>


reset(arg)
{
  object gold;
  if(arg) return;
  ::reset(arg);
  set_name("saibaman");
  set_short(HIB+"Saibaman"+NORM);
  set_race("saiba");
  set_long(
  "Saibamen are short little colorful creatures that look\n"+
  "similar to ET. Its looks are rather deceiving because\n"+
  "the saibamen are actually powerful foes.\n");
  set_level(20);
  set_hp(700+random(150));
  set_heart_beat(1);
  set_wander(1);
  set_wander_interval(6);
  set_wander_realm("/players/mosobp/areas/BATTLE/rooms/");
  set_al(0);
  gold=clone_object("/obj/money");
  gold->set_money(random(1000)+5000);
  move_object(gold,this_object());
  set_wc(30);
  set_ac(13+random(5));
  add_spell("kiblast",
    "The "+HIC+"Ki Blast"+NORM+" burns your stomach!\n",
    HIB+"#MN#"+NORM+" puts his hands in front of him and a"+HIC+" Ki Blast "+NORM+"shoots from his hands.\n",
    45,55,"other|fire");
}
