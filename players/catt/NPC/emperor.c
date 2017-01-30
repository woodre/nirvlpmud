
inherit"obj/monster";
reset(arg) {
object money;
::reset(arg);
if(arg) return;
set_name("emperor");
set_alias("emperor");
set_short("emperor of the galaxy");
set_long("This is the wimpy emperor. He was not always wimpy. "+
         "He still has a great constitution. \n");
set_level(8);
set_aggressive(0);
set_chat_chance(10);
load_chat("emperor screams: GET OUT!!!! THIS IS MY GALAXY!!!\n");
load_chat("emperor pouts: I think I wet myself, what do you care!\n");
set_hp(300);
set_al(-3000);
set_wc(5);
set_ac(15);
set_chance(50);
set_spell_dam(15);
set_spell_mess1("The Emperor goes mad!\n");

set_spell_mess2("The Emperor goes mad!\n");
 set_can_kill(100);
money = clone_object("obj/money");
money->set_money(200);
move_object(money, this_object());
}
