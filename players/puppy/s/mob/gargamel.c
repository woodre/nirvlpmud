#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/monster";
#define ATT attacker->query_name()

object gold;
reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("gargamel");
   set_alt_name("sorcerer");
   set_short(""+HIK+"Gargamel the Sorcerer"+NORM+"");
   set_race("human");
   set_long(
      "Living in a dilapidated castle on the edge of the forest,\n"+
      "Gargamel the horrible sorcerer is an evil man.  His only\n"+
      "mission in life is to destroy the Smurfs.  He hates the\n"+
      "Smurfs and is constantly in pursuit of them, but the Smurfs\n"+
      "always outwit him and manage to escape.\n");
   set_level(8);
   set_hp(400);
   set_wc(10);
   set_ac(8);
   set_al(-425);
   set_chat_chance(20);
   load_chat("Gargamel the Sorcerer mixes some potions.\n");
   load_chat("Gargamel mumbles something about the Smurfs.\n");
   set_chance(11);
   set_spell_dam(10);
   set_spell_mess2("Gargamel pours his latest concoction over you.\n"+
      "It "+RED+"BURNS"+NORM+" your flesh.\n");
   gold = clone_object("obj/money");
   gold->set_money(250);
   move_object(gold,this_object());
   move_object(clone_object("/players/puppy/s/heal/bad.c"), this_object());
}
get_spell_mess1()
{
   return ("Gargamel pours his latest concoction over " + BOLD +
      attacker_ob->query_name() + NORM + ".\nIt "+RED+"BURNS"+NORM+" " + BOLD +
      attacker_ob->query_name() + NORM + "'s flesh!\n");
}
