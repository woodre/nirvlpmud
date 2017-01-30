#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

reset(arg) {
  if(!present("cluestick")){ 
    move_object(clone_object("players/softly/algiers/obj/cstick.c"),this_object());
  }
  ::reset(arg);
  if (arg) return;
   
  set_name("nick");
  set_alt_name("detective");   
  set_alias("man");
  set_long("\nNick is a short man who once may have been attractive in a dangerous\n\
sort of way.  His rumpled suit casually falls over his body and the\n\
blue shirt is open at the collar.  His dusty shoes lead one to think\n\
that he has spent some time plodding on the dusty road outside.  His\n\
dark hair is in need of cutting.  He has a slight, sardonic smile on\n\
his face and a tired look about his eyes.\n");
  set_short("Nick");
  set_race("human");
  set_gender("male");
  set_level(19);
  set_hp(850);
  set_al(-500);
  set_aggressive(0);
  add_money(2000+random(800));
  command ("wield stick");
  set_chat_chance(10);
  load_chat("Nick nods slightly in your direction.\n");     
  load_chat("Nick paces in front of his desk, his brow knotted.\n");
  load_chat("Nick briefly shuffles through the papers on his desk.\n");
  set_a_chat_chance(10);     
  load_a_chat("Nick pounds on you with a cluestick!\n");
  load_a_chat("Get out of here!!  Go back where you came from!!\n");
  load_a_chat("Nick shouts: Get a clue!!\n");
  set_chance(20);
  set_spell_dam(35);
  set_spell_mess1("Nick beats his attacker with large club.\n");
  set_spell_mess2("\nNick flails you repeatedly with the long club.\n"+
		  "You fall to your knees.  Blood trickles down your face.\n");

}
