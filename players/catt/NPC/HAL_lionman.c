inherit "obj/monster";
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
object armor;
object weapon;
::reset(arg);
if(arg) return;
set_name("lionman");
set_alias("guardsman");
set_short("lionman guardsman");
set_long("You see that this is a guardsman of some kind. He looks very\n" +
      "powerful and wields a slim put sharp katana.\n");
set_level(10);
set_race("lionman");
set_hp(300);
set_al(200);
set_wc(10);
set_ac(10);
weapon = clone_object(WPN+"katana");
if(weapon) {
move_object(weapon, this_object());
command("wield "+weapon->query_name());
      }
armor = clone_object(ARM+"liongloves");
   if(armor) {
   move_object(armor, this_object());
     }
}
