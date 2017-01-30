#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/monster";
#define ATT attacker->query_name()

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("papa");
   set_alt_name("smurf");
   set_short(""+HIB+"Papa Smurf"+NORM+"");
   set_race("smurf");
   set_long(
      "The village leader is recognizable with his white beard and\n"+
      "by the way he talks to the other Smurfs.  He isn't pretending\n"+
      "to be above them when he hides away in his home, he just feels\n"+
      "that some of them need to learn to do things for themselves.  \n"+
      "He has been known to get the occasional Smurf out of trouble\n"+
      "in the past, though.\n");
   set_level(8);
   set_hp(300);
   set_wc(7);
   set_ac(7);
   set_al(250);
   set_chat_chance(7);
   load_chat("Papa Smurf watches the Smurfs from his window.\n");
   load_chat("Papa Smurf mixes some chemicals.\n");
   set_chance(90);
   set_spell_dam(10);
   set_spell_mess2("Papa Smurf blows some dust on you.\n"+
      "Something Zaps you from above.\n");
   move_object(clone_object("/players/puppy/s/heal/good.c"), this_object());
   move_object(clone_object("/players/puppy/s/eq/sbook.c"), this_object());
}
get_spell_mess1()
{
   return ("Papa Smurf blows some dust on pours his latest concoction over " + BOLD +
      attacker_ob->query_name() + NORM + ".\nSomething "+RED+"ZAPS"+NORM+" " + BOLD +
      attacker_ob->query_name() + NORM + " from above!\n");
}
