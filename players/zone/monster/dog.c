
inherit"obj/monster";
reset(arg) {
object treasure;
::reset(arg);
if(arg) return;
set_name("dog");
set_short("dog");
set_level(7);
set_race("dog");
set_hp(120);
set_al(1);
set_wc(12);
set_ac(7);
set_spell_mess2("");
set_random_pick(20);
treasure = clone_object("/players/zone/obj/collar.c");
if(treasure) move_object(treasure,this_object());
}
