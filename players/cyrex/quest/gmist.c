
inherit "obj/monster";
object rmobj;
int items;

reset(arg) {
::reset(arg);
if(arg) return;

set_name("guardian mist");
set_alias("guardian");
set_short("Guardian Mist");
set_long("A guardian created by the Masters. Be careful!\n");
set_level(20);
set_hp(1000);
set_al(1000);
set_ac(10);
set_wc(21);
set_aggressive(0);

set_chance(10);
set_spell_dam(50);
set_spell_mess1("The Guardian smacks you across the face!\n");
set_spell_mess2("The Guardian sends you flying!\n");

set_chat_chance(2);
load_chat("The Guardian hovers around.\n");
load_chat("The Guardian stares at you.\n");
set_a_chat_chance(2);
load_a_chat("Guardian yells: WHAT??\n");
load_a_chat("Guardian yawns.\n");

rmobj = clone_object("players/cyrex/quest/rmobj");
move_object(rmobj, this_object());
return 1;
}
