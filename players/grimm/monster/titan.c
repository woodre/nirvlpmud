/* This creature is very difficult because he is guarding a special "unique"
weapon that is very testy and there is only 1 at a time on the game
(check /players/grimm/weapon/shadow.c) ... at the moment he is NOT online */
inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("titan");
set_short("A Titan");
set_long("This is the last of a once powerful race of man hunters.  He is\n"
+"approximately 12 feet tall, is totally black, and is carrying\n"
+"the sword of his ascestors.  The sword is 6 foot long, and is\n"
+"also totally black.  It also has been rumored to have an attitude.\n");
set_al(-1000);
set_level(20);
set_wc(40);
set_hp(1000);
set_ac(25);
set_aggressive(1);
set_chat_chance(85);
set_a_chat_chance(85);
load_a_chat("Titan says: Come on you bitch! Let's rock!\n");
load_a_chat("Titan says: You want it? Come get it, I dare you!\n");
load_a_chat("Titan says: Don't mess with me, I'm way to much for you!\n");
load_a_chat("Titan flexes his muscles.\n");
load_a_chat("Titan says: Forget it baby, You're MINE!\n");
load_a_chat("Titan says: You killed my son, eh? Well guess what I get to do to you now!\n");
coins = clone_object("obj/money");
coins->set_money(900+(random(200)));
move_object(coins,this_object());
}
