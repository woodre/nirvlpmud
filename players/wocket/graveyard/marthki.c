#include "/players/wocket/closed/ansi.h"
inherit "obj/monster.c";

reset(arg){
  ::reset(arg);
  if(arg) return;
move_object(clone_object("/players/wocket/graveyard/diamond.c"),this_object());
move_object(clone_object("/players/wocket/graveyard/lies.c"),this_object());
set_name("marthki");
set_alias("dryant");
set_alt_name("mummy");
set_race("seussian");
set_short(BLU+"Marthki"+NORM);
set_long("She towers above, yet her figure is perfectly proportioned.  Long\n"+
      "flowing robes adorn her body and huge rings her hands.  A powerful\n"+
         "looking sword lays across her side hung by a silver sash.\n");
set_aggressive(1);
set_level(21);
set_hp(600+random(401));
set_wc(35);
set_ac(20);
set_gender("female");
set_chance(40);
set_spell_dam(90);
set_spell_mess1(HIY+"LIGHTNING "+NORM+"from her finger, streaks through the air, "+HIY+"DESTROYING"+NORM+" her adversary.\n");
set_spell_mess2(HIY+"LIGHTING "+NORM+"from her fingers, streaks through the air, "+HIY+"DESTROYING"+NORM+" her adversary.\n"+RED+"...burns tear away your flesh...\n"+NORM);
}
