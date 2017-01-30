#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;
   
  set_name("reverend");
  set_alt_name("minister");   
  set_alias("johnson");
  set_long(
	   "The Reverend Albert Johnson is a tall thin dignified man\n\
whose short dark hair is greying at the temples.  He wears\n\
a worn but well kept black suit, a pressed white shirt and\n\
and dark tie of indeterminate color.  His black shoes are\n\
well worn but carefully polished.  His long fingers hold a\n\
a book very tightly.\n");
  set_short("Reverend Albert Johnson");
  set_race("human");
  set_gender("male");
  set_level(12);
  set_attrib("pie", 20);
  set_al(1000);
  set_aggressive(0);
  set_chat_chance (5);
  load_chat("Reverend Johnson reads: 'They shall take up serpents. And\n"+
	    "if they drink any deadly thing, it shall not hurt them.\n"+
	    "They shall lay hands on the sick, and they shall recover.'\n");
  load_chat("Reverend Johnson preaches: 'Thou shalt tread upon the lion\n"+
	    "and adder. The young lion and the dragon shalt thou trample...'\n");
  add_money(300+random(250));
}

attacked_by(ob) 
{ 
  if(!environment()->query_snaked()) environment()->make_snakes(); 
  ::attacked_by(ob); 
}
