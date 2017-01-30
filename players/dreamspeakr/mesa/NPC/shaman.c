#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

     set_name("shaman");
     set_alias("shaman");
     set_alt_name("ocyos");
     set_race("american indian");
     set_gender("male");
     set_short(CYN+"Ocyos"+NORM+", Shaman to the Anasazi");
     set_long(
         "\n"+
         "The most powerful man of the tribe.  He is the spiritual \n"+
         "priest of the Anasazi, speaker of dreams, healer of the sick, \n"+
         "the chosen one.  Dancing wildly, he conjures the spirits of \n"+
         "the outer world.  Many feathers and beads decorate his \n"+
         "elaborate clothing.\n");

     set_level(20);
     set_hp(575);
     set_al(-1000);
     set_aggressive(1);

  if(!present("rainmaker")) {
    move_object(clone_object("players/dreamspeakr/mesa/OBJ/rmaker.c"),
     this_object()); 
    }

     init_command("wield rainmaker");

  if(!present("Perfleche")) {
    move_object(clone_object("players/dreamspeakr/mesa/OBJ/sbag.c"),
     this_object()); 
    }

     set_ac(17);
     set_wc(33);
     set_chat_chance(10);
       load_chat(CYN+"Ocyos "+NORM+"dances wildly about the room as he jingles his "+HIB+"Rainmaker"+NORM+".\n");
       load_chat("The shaman pulls something from his bag and begins chanting.\n");
       load_chat(CYN+"Ocyos whispers to you"+NORM+":  I can extend life beyond death.\n");
       load_chat("The fire blazes up as "+CYN+"Ocyos"+NORM+" throws magical dust onto it.\n");
       load_chat("This is the house of "+CYN+"dreamers"+NORM+"...\n"+
            "      the people who live here dream the first dream together.\n");
     set_a_chat_chance(25);
       load_a_chat(CYN+"Ocyos"+NORM+" mumbles some unrecognizable words, you become hypnotized.\n");
       load_a_chat(CYN+"Ocyos "+NORM+"conjures the spirits of the dead.\n"); 
       load_a_chat("The shaman pulls some "+RED+"dust"+NORM+" from his bag and blows it into your face.\n");
       load_a_chat("Ocyos raises his hands and begins chanting, a strange "+CYN+"mist"+NORM+" fills the room.\n");
}
