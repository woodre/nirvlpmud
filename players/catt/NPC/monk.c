
inherit"obj/monster";
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
object weapon;
::reset(arg);
if(arg) return;
set_name("shintae monk");
set_alias("monk");
set_short("shintae monk");
set_long(
"This little man is a shintae monk... an order dedicated to the\n"
+ "destruction of Demon Lords and all that they stand for.\n"
+ "He is clothed in a simple grey robe and carries a bo staff for protection.\n");
set_level(5);
set_race("human");
set_hp(100);
set_ac(5);
set_spell_mess2("");
set_chat_chance(10);
load_chat("monk sighs: those damn Demon Lords. Look what the world is coming to!\n");
load_chat("monk says: listen, follow the true paths my son, turn\n"+
          "not to darkness as the Lords have.\n");
weapon = clone_object(WPN+"bostaff");
if(weapon) {
move_object(weapon,this_object());
command("wield "+weapon->query_name());
   }
set_wc(7+random(4));
}
