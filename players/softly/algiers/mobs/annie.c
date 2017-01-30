#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

object robe;

reset(arg) {
  if(!present("robe")){ 
    move_object(clone_object("players/softly/algiers/obj/srobe.c"),this_object());
  }

  ::reset(arg);
  if (arg) return;
   
  set_name("annie");
  set_alt_name("spinster");   
  set_alias("woman");
  set_long("\nAnnie is a small woman who sits in a hard chair behind\n\
a wooden spinning wheel.  Beside her is a basket filled with\n\
locks of wool.  Her long hair is tied at the back of her neck\n\
but a few strands fall across her face.  She wears a shapeless\n\
pale grey dress and ornate earrings.  Her bare feet work the\n\
wheel while her strong hands feed the wool evenly.\n");
  set_short("Annie");
  set_race("human");
  set_gender("female");
  set_level(20);
  set_al(-400);
  set_hp(1200);
  set_aggressive(0);
  add_money(300+random(100));
  set_dead_ob(this_object());
  set_chat_chance (5);
  load_chat("The chair rocks:         sqrrrrrk.......   sqrrrrrk.......\n");
  load_chat("Annie hums softly as she works.\n");  
  set_a_chat_chance(10);
  load_a_chat("Annie punctures you with her spindle!!\n");
  set_chance(35);
  set_spell_dam(30);
  set_spell_mess1("Annie's hidden power forces her spindle into her attacker!\n");
  set_spell_mess2("\nAnnie momentarily curls her body into a muscular knot.\n"+
		  "She suddenly THRUSTS herself forward, driving her spindle home!\n\n"+  
		  "    "+BOLD+"PAIN radiates throughout your body from the sudden attack!!\n"+NORM);
}

monster_died(){
  write_file("/players/softly/logs/algiers",
  ctime()[4..15]+": "+this_object()->query_attack()->query_name()+" [L "+this_object()->query_attack()->query_level()+
  "+"+this_object()->query_attack()->query_extra_level()+"] killed Annie.\n");
}
