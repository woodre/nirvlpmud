
inherit"obj/monster";
reset(arg) {
object armour;
object weapon;
::reset(arg);
if(arg) return;
set_name("hunter");
set_alias("john");
set_short("John the Hunter");
set_long(
" John is a large hunter, armed with a nasty spear.\n"
+ "He seems pretty upset that you are here, disturbing\n"
+ "his hunt, and might lash out at any time.\n");
set_level(16);
set_wc(22);
set_ac(13);
set_hp(400);
set_race("human");
armour = clone_object("players/bismarck/closed/armor/hunt_boots");
if(armour) {
move_object(armour,this_object());
  }
weapon = clone_object("players/bismarck/closed/weap/hunt_spear");
if(weapon) {
move_object(weapon,this_object());
   }
}
