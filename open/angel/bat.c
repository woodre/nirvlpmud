#include "/players/fred/ansi.h";
#include "/players/fred/defines.h";
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
   
  set_name("bat");
  set_race("critter");
  set_short("A small bat");
  set_long(
    "  A small brown bat with sharp white teeth.  It has bright\n"+
    ""+GRN+"green"+NORM+" eyes that stare at you from the darkness.\n");
  set_level(18);
  set_al(-(random(200)));
  set_ac(15);
  set_wc(26);
  set_hp(350+(random(125)));
  set_gender("male");
  set_dead_ob(this_object());
  set_aggressive(0);
  set_chat_chance(5);
   load_chat("The bat swoops at your head...\n");
   load_chat("The bat flies around the room...\n");
   load_chat("You hear the flutter of powerful wings...\n");
  }
  
  monster_died(){
      say("King Solomon comes forward!\n\
\n\
King Solomon starts praying for the salvation of the fallen martyr!\n\
\n\
\n\
O' come to life again, RISE from the dead!\n\
\n\
\n\
O' come to LIFE again, RISE from the DEAD!\n\
\n\
\n\
O' COME TO LIFE AGAIN AND NOW RISE FROM THE DEAD!\n");

    MO(CO("/open/angel/bat.c"),
    environment(TO));
    return 1;  
}
