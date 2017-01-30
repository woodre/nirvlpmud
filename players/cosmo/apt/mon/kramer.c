#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object golf, moto;
  ::reset(arg);
  if(arg) return;

set_name(HIY+"Kramer"+NORM);
set_alias("kramer");
set_alt_name("cosmo");
set_race("human");
set_short("Cosmo Kramer");
set_long(
  "  Kramer is quite peculiar to say the least.  He is tall\n"+
  "and thin, with dark hair that stands almost completely\n"+
  "upright.  He is very quick and has a way of entering and\n"+
  "leaving rooms that is tough to not notice.  Kramer carries\n"+
  "his motorcycle helmet which he got from Newman, and his\n"+
  "Big Bertha golf club which he uses quite frequently.\n");

set_level(15);
  set_hp(200);
  set_al(0);
move_object(clone_object("players/cosmo/apt/weap/bertha.c"));
move_object(clone_object("players/cosmo/apt/armor/helmet.c"));
init_command("wield driver");
init_command("wear helmet");
  set_wc(22);
  set_ac(11);
  set_heal(3,20);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chance(20);
set_spell_dam(35);
set_spell_mess1(
  "\nKramer shouts: Giddy up!! \n");
set_spell_mess2(
  "\nKramer shouts: Giddy up!!\n"+
  BLU+"Big Bertha"+NORM+" rips loose in perfect motion.\n"+
  GRN+"W H O O S H !!"+NORM+"\n"+
  "Kramer's perfect swing lands squarely on your temple.\n"+
  RED+"T H U D !!"+NORM+"\n"+
  "Blood spews forth from your skull.\n");

}

monster_died() {
  tell_room(environment(this_object()),
	"Kramer falls face-first into the hot tub.\n");
return 0; }

