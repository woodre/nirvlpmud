inherit "/players/vertebraker/closed/std/monster.c";
object gold;

reset(arg) {
::reset(arg);
if(arg) return;
set_chat_chance(25);
load_chat("Zombie Hhhmmmmms\n");
set_name("zombie");
set_short("Zombie");
set_wander(30, 0, ({ "up" }));
set_long(
"The body of this creature is missing some limbs.  There is flesh and hair\n"
+ "missing or falling off.  It's movements or jerky and uneven.\n");
set_level(15);
set_race("undead");
set_aggro(1, 10, 100);

gold = clone_object("obj/money");
gold->set_money(900 + random(200));
move_object(gold,this_object());
}
