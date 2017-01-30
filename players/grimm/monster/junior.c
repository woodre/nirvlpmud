inherit "obj/monster.talk";
object coins, item, attack_ob;
int i, j;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("junior");
set_short("Junior");
set_long("This is the son of what lies below you.  He is only about 6 foot tall,\nand seems to be about 7 years old.\n");
set_al(-300);
set_level(18);
set_wc(26);
set_hp(450);
set_ac(15);
set_aggressive(0);
set_chat_chance(95);
load_chat("Junior says: Daddy ain't gonna be happy that you are here...\n");
load_chat("Junior says: You like my gun?\n");
load_chat("Junior says: Go away! My cartoons are coming on!\n");
load_chat("Junior says: I wanna happy meal for lunch!\n");
load_chat("Junior screams:  WWWHHHHHHAAAAAAAAAAAAAAAAAAAAA!!!!!!!\n");
load_chat("Junior says: Have you seen my pet? Her name is MommyKin.\n");
load_chat("Junior says: Will you change my dyper?\n");
set_a_chat_chance(85);
load_a_chat("Junior shoots you with his gun.\n");
load_a_chat("Junior screams: WHHHHAAAAAAAAAAAAAAAAAAAAAAA!!!!!\n");
load_a_chat("Junior says: I'm gonna tell my daddy!\n");
load_a_chat("Junior thows his wet dyper at you!\n");
load_a_chat("Junior says: Daddy thinks you are a pretty boy from San Francisco.\n");
load_a_chat("Junior spits up on you.\n");
load_a_chat("Junior throws a fit over his spilt milk.\n");

item = clone_object("players/grimm/object/car_gun");
move_object(item,this_object());
coins = clone_object("obj/money");
coins->set_money(20+(random(40)));
move_object(coins,this_object());
}
