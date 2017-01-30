#include "/obj/ansi.h"  
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
  if(arg) return;
set_name("krillen");
set_short(YEL+"Krillen"+NORM);
set_race("human");
set_long(
"Krillen is a defender of the earth, and part of the Z Force. He has helped\n"+
"Goku defend the earth against countless threats, without regard to his own life.\n");
set_level(50);
set_hp(2400+random(500));
set_al(1000);
move_object(clone_object("/players/mosobp/areas/BATTLE/OBJ/eaura.c"), this_object());
init_command("wear misc");
set_wc(45);
set_ac(27);
add_spell("destructodisc",
"A round circular "+HIY+"DISC"+NORM+" screams toward you hitting your chest!\n",
"#MN# forms a circular "+HIY+"DISC "+NORM+"above his hand and throws it!.\n",
45,90-110,"other|energy");
add_spell("kamaehamaeha",
"A Bright "+HIC+"BEAM "+NORM+"of light flys toward you hitting your face!\n",
"#MN# screams: "+HIC+"KA MAE HA MAE HAAA!! "+NORM+"and a beam screams forward.\n",
20,115-150,"other|energy");
}