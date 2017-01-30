inherit "obj/monster";
object gold;
int items;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("drunk");
set_alias("man");
set_short("drunken old man");
set_long("How the hell did he get here??!\n");
set_level(5);
set_hp(50);
set_ac(5);
set_wc(10);
set_chat_chance(15);
load_chat("The drunken old man gives you a dirty look.\n");
load_chat("Man says: You want a drink Sonny?\n");
load_chat("The drunken old man gives you a finger!\n");
set_a_chat_chance(20);
load_a_chat("Man whimpers: HELP!!\n");
load_a_chat("Man whimpers: What have I done to you!\n");
gold=clone_object("obj/money");
gold->set_money(random(20)+100);
move_object(gold, this_object());
}
