inherit "obj/monster.talk";
object coins, paper;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("terminator");
set_short("Guardian Terminator");
set_long("This is the guardian of the terminator's realm...\n"+
"You aren't sure but it looks like he is hiding something that\n"+
"looks like a scrap of paper.\n");
set_al(-300);
set_level(20);
set_wc(30);
set_hp(500);
set_ac(9);
set_aggressive(0);
set_chat_chance(10);
load_chat("Terminator says: You will never leave here alive!\n");
set_a_chat_chance(10);
load_a_chat("Terminator says: Hasta la vista, baby!\n");
set_a_chat_chance(10);
load_a_chat("Terminator says: I will destroy you!\n");
set_a_chat_chance(10);
load_a_chat("Terminator says: YOU won't be back!\n");
set_a_chat_chance(10);
load_a_chat("Terminator flexes his muscles..\n");
coins = clone_object("obj/money");
coins->set_money(1000+(random(1000)));
move_object(coins,this_object());
paper = clone_object("players/grimm/object/paper");
move_object(paper, this_object());
}
