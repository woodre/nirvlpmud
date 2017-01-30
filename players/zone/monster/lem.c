
inherit"obj/monster";
reset(arg) {
object treasure;
::reset(arg);
if(arg) return;
set_name("lemming");
set_short("lemming");
set_level(5);
set_race("rodent");
set_hp(75);
set_al(1);
set_wc(9);
set_ac(5);
set_spell_mess2("");
set_random_pick(20);
treasure = clone_object("/players/zone/obj/lemmingskin.c");
if(treasure) move_object(treasure,this_object());
}
