inherit "/players/emerson/closed/FuzzyBeast.c";
reset(arg){
   object gold,pizza;
   if(arg) return;
   set_name("patron");
   set_race("human");
    short_desc=({
    "A hungry patron",
	"An ugly patron",
	"A nerdy looking patron",
	"An annoying patron",
	"A pissed off patron",
	"A satisfied patron",
	"A happy patron",
  });
  long_desc=({
	"This customer is too busy waiting to even notice you, but it looks like\n" +
	"you will have to kill him to get some pizza.\n",
	"This customer seems to be suffering from a mild case of starvation you\n" +
   "better put him out of his misery.\n",
  });
  ::reset(arg);
   set_level(13);
   set_hp(195);
   set_al(100);
   set_wc(17);
   set_ac(10);
   set_aggressive(0);
   set_chat_chance (4);
    load_chat("The patron drools on the floor.\n");
   set_a_chat_chance(35);
   load_a_chat("The patron bites you.\n");
   load_a_chat("The patron screams: You fucking bastard!!!\n");
   load_a_chat("The patron knees you in the groin.\n");
   gold=clone_object("obj/money");
   gold->set_money(825+random(50));
   move_object(gold,this_object());
}
#include "def_hb.h"
