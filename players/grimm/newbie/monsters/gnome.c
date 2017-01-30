inherit "obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("gnome");
set_short("A Gnome");
set_long("This is a little gnome out looking for a fight.\n");
set_al(-15);
set_level(1);
set_wc(2);
set_hp(10);
set_ac(2);
set_aggressive(0);
}
