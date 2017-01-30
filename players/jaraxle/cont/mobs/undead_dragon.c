#include "/players/jaraxle/ansi.h"

inherit "obj/monster.c";



int bdelay;



reset(arg)  {



  ::reset(arg);

  if(arg) return;

set_name("dragon");

set_alt_name("undead dragon");

set_race("undead");

set_short(BOLD+"Undead Dragon"+NORM);

set_long(

"This is a huge undead dragon. Once a dragon, now you see only\n"+

"the animated skeleton of a once great beast. The King of the\n"+

"Red Dragons, to destroy disobedience, turns those who would\n"+

"betray him into undead servants such as this. This creatures\n"+

"long neck ends in a huge skull filled with long sharp teeth.\n"+

"Its wings are no longer capable of flight and spread out with\n"+

"a long bony reach. This creature exudes the coldness of death\n"+

"from its large form.\n");

set_level(20);

set_hp(300);

set_al(0);

set_wc(80);

set_ac(8);

set_heart_beat(1);

set_chance(20);

set_spell_dam(15);

set_spell_mess1(

"The Undead Dragon lashes out at its opponent...\n\n"+

"           "+BOLD+"FROZEN DEATH"+NORM+"\n\n"+

"            flows over the victim of the soul slave.\n");

set_spell_mess2(

"The Undead Dragon touches you, "+BOLD+"FREEZING"+NORM+" the blood in your veins!\n");

}





