inherit"obj/monster";
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
object weapon;
::reset(arg);
if(arg) return;
  set_name("black slayer");
  set_alias("slayer");
  set_short("black slayer");
  set_long("You see a black slayer from the Keep of Brakian, A Demon\n" +
           "Lord. These are mighty soldiers whose power is only matched\n" +
           "by the power of the other Demon Lords.\n");
set_hp(200);
set_level(8);
set_al(-500);
set_wc(12);
set_ac(7);
   weapon = clone_object(WPN+"slayer_sword");
if(weapon) {
       move_object(weapon, this_object());
  command("wield "+weapon->query_name());
     }
}
