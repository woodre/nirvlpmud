#include "/players/illarion/dfns.h"
inherit "/obj/monster";


void reset(int arg) {
  ::reset(arg);
  if(arg) return;
/*  Basic appearance */  
  set_name("man");
  set_alias("veteran");
  set_race("human");
  set_short("A crazed looking man in army fatigues");
  set_long(
"This man hangs about the alley, looking off to the south and clutching\n"+
"what seems to be an automatic weapon.  His eyes seem wild and distant,\n"+
"as if he's looking at someplace other than the alley.  His dark green\n"+
"clothes look like army surplus, and his accessories look like they came\n"+
"from an NRA warehouse.  He's almost certainly insane.\n");
/*  Monster stats */
  set_level(18);
  set_wc(30);
  set_ac(13);
  set_hp(500);
  set_al(-150);
/* Other things */
  set_chat_chance(7);
  load_chat("The crazy man says, \"There's something bad going down in "+
            "there, man!\"\n");
  load_chat("The crazy man nervously cocks his weapon...  again.\n");
  load_chat("\"Someone has to do something about those maniacs,\" the man "+
            "explains.\n");
  set_a_chat_chance(7);
  load_a_chat("\"You don't understand,\" explains the wacko, \"It's not me "+
              "you should worry about, it's THEM.\"\n");
  load_a_chat("The wacko screams loudly and tries to aim his weapon at you.\n");
  /*
  set_spell_mess2("The man fires off a long burst of automatic weapon fire at you!\n");
  set_spell_mess1("The man fires off a long burst of automatic weapon fire at his opponent!\n");
  set_spell_dam(30);
  set_chance(20);
  */
}
