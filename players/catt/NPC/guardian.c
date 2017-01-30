
inherit"obj/monster";
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
object weapon;
::reset(arg);
if(arg) return;
set_name("BLACK DEMON");
set_alias("demon");
set_short("Catts Guardian Demon");
set_long(
"A VERY large black demon thats primary function on this plane is to\n"
+ "guard and protect his master... the Demon Lord Catt... he stands 12ft tall\n"
+ "and has a very serious dont mess with me demeanor. dont mess with him...\n"
+ "he will destroy your existance.\n");
set_level(50);
set_race("demon");
set_hp(50000);
set_al(-10000);
set_wc(7500);
set_ac(7500);
set_spell_mess2("");
set_random_pick(50);
weapon = clone_object(WPN+"Great_axe");
if(weapon) {
move_object(weapon,this_object());
command("wield "+weapon->query_name());
   }
}
