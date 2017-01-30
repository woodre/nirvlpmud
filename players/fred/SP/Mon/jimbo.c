#include "/players/fred/ansi.h"
inherit "obj/monster.c";

object gun;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("jimbo");
set_alias("jim");
set_race("human");
set_short(MAG+"Jimbo"+NORM);
set_long(
  "  Jimbo is your average hunting guru.  He is wearing an orange\n"+
  "shirt with a hunting vest full of pockets to hold his many other\n"+
  "weapons and of course plenty of ammunition.\n");

set_level(13);
set_hp(195);
set_al(0);
set_ac(10);
set_aggressive(0);
set_a_chat_chance(8);
  load_a_chat("Jimbo yells: Its coming right for us!!\n");

	gun = clone_object("/players/fred/SP/Obj/sgun.c");
      move_object(gun, this_object());
	command("wield gun", this_object());
set_wc(17);
}


