inherit "obj/monster";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("werewolf");
set_long("A protector werewolf..very dangerous!\n");
set_short("A large werewolf");
set_level(20);
set_hp(500);
set_ac(13);
set_al(-400);
set_wc(30);
set_aggressive(1);
coins = clone_object("obj/money");
coins->set_money(100+(random(200)));
move_object(coins,this_object());
}
