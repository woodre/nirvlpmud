#include "/players/grimm/header"
inherit "obj/monster";
object coins,weapon;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("dog");
set_short("Vampire dog");
set_long("Large German Shepards invused with vampire blood! Very deadly!\n");
set_level(12);
set_wc(16);
set_aggressive(1);
coins = clone_object("obj/money");
coins->set_money(500+(random(100)));
move_object(coins,this_object());
weapon = clone_object(DIR3(dogteeth));
move_object(weapon,this_object());
}
