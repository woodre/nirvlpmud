inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("punk");
set_short("Mutant Punk");
set_long("This is a foul looking punk that seems to have been born of\n"
+"a questionable background.\n");
set_al(-250);
set_level(11);
set_wc(10);
set_hp(160);
set_ac(4);
set_aggressive(0);

coins = clone_object("obj/money");
coins->set_money(100+(random(200)));
move_object(coins,this_object());
}
