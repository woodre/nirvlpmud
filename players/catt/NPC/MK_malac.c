inherit"obj/monster";
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
object weapon, money;
::reset(arg);
if(arg) return;
set_name("malac");
set_alias("slayer");
set_short("malac the giant slayer");
set_long("Malac, The Giant Slayer, is a great fighter who made his\n" +
"name slaying giants for his home country. His might is great, don't\n" +
     "underestimate him... you may just come up short.\n");
set_level(20);
set_hp(2000);
set_al(200);
set_ac(18);
weapon = clone_object(WPN+"hammerdest");
  if(weapon) {
   move_object(weapon, this_object());
   command("wield "+weapon->query_name());
     }
set_wc(30);
money = clone_object("obj/money");
   money->set_money(4500);
   move_object(money, this_object());
}
