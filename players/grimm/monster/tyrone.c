inherit "obj/monster.talk";
object coins, bla, paper;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("tyrone");
set_short("Tyrone");
set_long("This is the leader of a gang.  His name is Tyrone and he wants\n"+
"you to think he is real bad by what you can tell from his attitude.\n");
set_level(15);
set_al(-100);
set_wc(12);
set_aggressive(1);
set_chat_chance(30);
load_chat("Tyrone says: Yo!\n");
load_chat("Tyrone says: Get outta here, man!\n");
load_chat("Tyrone says: I'm bad. I'm bad.\n");
load_chat("Tyrone says: Don't mess with me man, I'll mess you up!\n");
load_chat("Tyrone says: You like my ghetto blaster? It will mess you up!\n");
load_chat("Tyrone says: You just wait for my possee to get here!\n");
coins = clone_object("obj/money");
coins->set_money(100+(random(100)));
move_object(coins,this_object());
bla = clone_object("players/grimm/object/blaster");
move_object(bla,this_object());
paper = clone_object("players/grimm/object/paper3");
move_object(paper, this_object());
}
