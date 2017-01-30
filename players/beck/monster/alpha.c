inherit "obj/monster";
#include "/players/beck/rangers/Defs.h"

RangerNPC(){ return 1; }
reset(arg)
{
   object gold, weapon;
   ::reset(arg);
   if(arg) return;
   set_name("alpha");
   set_alias("alpha");
   set_short("Alpha");
   set_long("Alpha is the power rangers tiny robot friend.\n"+
      "He can control the command center all by himself.\n");
   set_level(6);
   set_hp(100);
   set_wc(11);
   set_ac(5);
   set_chat_chance(2);
   load_chat("Alpha cries: Aye, Aye, Aye!\n");
   gold=clone_object("obj/money");
   gold->set_money(250);
   move_object(gold, this_object());
}

