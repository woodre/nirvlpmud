inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("vampire");
set_short("A Vampire");
set_long("You see a light complected being with blood on his lips.  He must have just fed!\n");
set_level(19);
set_al(-293);
set_aggressive(1);
set_chat_chance(15);
load_chat("You ignorant human.  You have sealed your fate by entering!\n");
coins = clone_object("obj/money");
coins->set_money(300+random(400));
move_object(coins,this_object());
}
