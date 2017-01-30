#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

     set_name("thanatos");
     set_alias("thanatos");
     set_alt_name("thanatos");
     set_race("minor god");
     set_gender("male");
     set_short(RED+"Thanatos"+NORM+", Minor God of Death");
     set_long(
         "\n"+
         "    Dressed in all black, this hooded god stands before\n"+
         "you.  His eyes seem to glow just beyond the shroud of his\n"+
         "hood.  According to legend, he is one of the sons of Nyx, \n"+
         "the goddess of night, and lives beside the river Lethe in \n"+
         "a remote cave that he shares with his brother Hypnos, god\n"+
         "of sleep.  Evilness seems to surround this great god of \n"+
         "death.\n");

     set_level(24);
     set_hp(800);
     set_al(-1000);
     set_aggressive(1);

  if(!present("machine")) {
    move_object(clone_object("players/dreamspeakr/CASTLE/OBJ/tatmach.c"),
     this_object()); 
    }
     init_command("wield machine");

     set_ac(19);
     set_wc(35);
     set_a_chat_chance(20);
       load_a_chat(RED+"Thanatos"+NORM+" mumbles some unrecognizable words, you become hypnotized.\n");
       load_a_chat(RED+"Thanatos "+NORM+"conjures the spirits of the dead.\n"); 
       load_a_chat(RED+"Thanatos "+NORM+"calls upon the greater Gods to curse you!\n");
}