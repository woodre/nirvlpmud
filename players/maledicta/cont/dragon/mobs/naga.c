#define WAR "/players/maledicta/cont/daemon"
#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

int bdelay;

reset(arg)  {

  ::reset(arg);
  if(arg) return;
bdelay = 0;
set_name("naga");
set_alt_name("demon");
set_race("naga");
set_short("A Guardian Naga");
set_long(
"  This is a creature of magic.  It was summoned by the Dragons to\n"+
"defend this sacred place. It has a long body that is made of a\n"+
"tough black scale that seems able to defend against most attacks.\n"+
"Its head is a deep black with blue glowing eyes and long teeth\n"+
"that seem very menacing.\n");
set_level(18);
set_hp(450);
set_al(-1000);
set_wc(23);
set_ac(18);
set_heart_beat(1);
set_aggressive(1);
set_chance(25);
set_spell_dam(30);
set_spell_mess1(
"The Naga spits a seering blast of fire from its mouth!\n");
set_spell_mess2(
"You cry out in pain as the Naga spits a white hot flame at you!\n");
}

init(){
::init();
add_action("stop_exit", "north", 1);
add_action("stop_exit", "east", 1);
}

stop_exit(){
write("The Guardian Naga blocks you!\n");
return 1;
}