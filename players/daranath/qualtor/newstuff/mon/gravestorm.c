#include <ansi.h>
inherit "/players/daranath/closed/monster1.c";

reset(arg){
  ::reset(arg);
  if (!arg){
          
set_name("Gravestorm");
set_short("A "+BOLD+BLK+"GraveStorm"+NORM+" lurks here");
set_alias("storm");
set_alt_name("gravestorm");
set_race("spirit");
set_gender("creature");
set_long("Insanity overtook this spirit as it was brutally tortured and finally\n"+
         "killed during the end of its life. Now, wandering through the\n"+
         "graveyard in Qual'tor, the Storm collects kills and tears them\n"+
         "into pieces. Shards of bone and bits of flesh twirl within\n"+
         "the GraveStorm's dance of death.\n");

set_level(19);
set_ac(14+random(4));
set_wc(24+random(10));
set_hp(380+random(150));
set_al(-1000);
set_aggressive(0);

set_chance(25);
set_spell_dam(20+random(40));
set_spell_mess1("The "+BOLD+BLK+"GraveStorm"+NORM+" spins throughout the dark graveyard.\n");
set_spell_mess2("\n          The "+BOLD+BLK+"GraveStorm"+NORM+" descends upon you.\n"+
     ""+WHT+"Shards of Bone"+NORM+" and chunks of "+YEL+"flesh"+NORM+" tear at "+
      "your armor and body.\n");

     }
    }

