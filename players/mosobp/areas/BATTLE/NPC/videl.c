/*
 *  File:   /players/mosobp/areas/BATTLE/NPC/videl.c
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

inherit "/obj/monster";

reset(arg)
{
  object gold;
  ::reset(arg);
  if(arg) return ;
  set_name("videl");
  set_short(MAG+"Videl"+NORM);
  set_race("human");
  set_long(
  "Videl is Gohan's girlfriend and future wife. She helps him fight crime\n"+
  "about the city, and he teaches her to fly. Videl's father is Mr. Satan.\n");
  set_level(20);
  set_hp(1100+random(200));
  set_al(1000);
  gold=clone_object("/obj/money");
  gold->set_money(random(3000)+8000);
  move_object(gold,this_object());
  move_object(clone_object("/players/mosobp/areas/BATTLE/OBJ/eki.c"), this_object());
  init_command("wear shield");
  set_wc(44+random(10));
  set_ac(22);
  add_spell("powerrush",
    "#MN# "+HIK+" rushes forward and "+HIB+"UPPERCUTS"+HIK+" your "+HIR+"FACE"+NORM+" !!! \n",
    "#MN# "+HIK+" screams as she runs forward with a "+HIR+" POWERRUSH "+NORM+" !!! \n",
    30,70,"other|energy");
}
