
inherit"obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("frog");
set_short("A magic frog");
set_long(
"This frog looks very strange.  It's back looks wet and very tasty.\n"
+ "Legend says that if you 'lick' these frogs something strange is supposed\n"
+ "to happen.\n");
set_level(4);
set_race("frog");
set_hp(50);
set_wc(8);
set_ac(4);
}
init() {
add_action("lick","lick");
}
lick(str) {
if(!id(str)) { write("Lick what?\n"); return 1; }
say(this_player()->query_name()+" licks the frog.\n");
if(!present("hallucinations",this_player())) move_object(clone_object("players/morgoth/OBJ/hal"),this_player());
return 1; }
