inherit "obj/monster";
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
object weapon;
object armor;
::reset(arg);
if(arg) return;
set_name(" Ki Lawwnum");
set_alias("commander");
set_short("Ki Lawwnum: the Lion Man commander");
set_long("Ki Lawwnum is the leader of the Lion Men who protect the \n" +
         "royal pansy of an emperor that rules the galaxy of his time.\n" +
         "Let's hope he can do a good job protecting him because the\n" +
          "rebellion is in full swing and only the GUARDSMAN can protect\n" +
          "or kill him.\n");
set_level(25);
set_hp(800);
set_al(1000);
set_wc(15);
set_ac(12);
set_chance(20);
load_chat("I MUST PROTECT THE EMPEROR!!!");
weapon = clone_object(WPN+"comkatana");
if(weapon) {
move_object(weapon, this_object());
command("wield "+weapon->query_name());
  }
armor = clone_object(ARM+"hakama");
if(armor) {
move_object(armor, this_object());
}
}
