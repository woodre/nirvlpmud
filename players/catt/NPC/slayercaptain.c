inherit"obj/monster";
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
object weapon, armor, money;
::reset(arg);
if(arg) return;
set_name("black slayer captain");
set_alias("captain");
set_short("black slayer captain");
set_long("This is a captain of the Demon Lord Brakian. This is one\n"+
         "of his wimpier captains, his specialty lying in \n"+
     "intelligence operations, but he is still a tough contender.\n");
set_hp(300);
set_level(15);
set_al(-500);
set_wc(20);
set_ac(12);
weapon = clone_object(WPN+"slayer_sword");
if(weapon) {
       move_object(weapon, this_object());
  command("wield "+weapon->query_name());
     }
armor = clone_object(ARM+"slayermail");
if(armor) {
    move_object(armor, this_object());
          }
money = clone_object("obj/money");
money->set_money(1000);
move_object(money, this_object());
}
