/* 10/07/05 - Earwax - Changed align to -350 to match description */

inherit "/players/emerson/closed/FuzzyBeast.c";
reset(arg){
   object gold,pizza;
   if(arg) return;
   set_name("man");
   set_alias("button man");
   set_race("human");
    short_desc=({
	"A mean looking button man",
	"A tough looking button man",
	"An ugly button man",
	"A suspicious looking button man",
	"A devious button man",
	"A protective button man",
	"An evil button man",
	"A big button man",
  });
  long_desc=({
   "The button men are here to look out for any of the other members\n" +
   "of the five families. They aren't too bright, but I'll bet money they\n" +
   "know where Jimmi Hoffa's body is buried.\n",
   "This button man looks pretty tough, but not too bright. He looks around\n" +
   "the room for members of the other five families.\n",
  });
  ::reset(arg);
   set_level(13);
   set_hp(195);
   set_al(-350);
   set_wc(17);
   set_ac(10);
   set_aggressive(0);
   set_chat_chance (4);
   load_chat("The button man looks about the room carefully.\n");
   load_chat("The button man eyes you suspiciously.\n");
   load_chat("The button man looks at you with an evil grin.\n");
   set_a_chat_chance(35);
   load_a_chat("The button man punches you in the nose.\n");
   load_a_chat("The button man shouts: You'll be wearing cement boots when I'm done!\n");
   load_a_chat("The button man shoots at you but misses.\n");
   gold=clone_object("obj/money");
   gold->set_money(475+random(50));
   move_object(gold,this_object());
    pizza=clone_object("/players/emerson/heal/pizza.c");
   move_object(pizza,this_object());
}
#include "def_hb.h"
