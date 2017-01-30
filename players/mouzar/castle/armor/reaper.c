inherit "obj/weapon";

reset(arg){
if(arg) return;
::reset(arg);
set_name("reaper");
set_alt_name("reaper");
set_alias("weapon");
set_short("A Reaper");
	set_long("As you grasp the reaper in your hands, you get a disrupting\n" +
	"feeling in your soul.  The wooden handle is spattered with blood and\n" +
	"the blade appears to be broken in, but very sharp.\n");
set_class(18);
set_weight(3);
set_value(20000);
set_hit_func(this_object());
}
weapon_hit(attacker){
	if (random (100) < 30) {
	write("The handle of your reaper is soaked with more blood.\n");
	say(capitalize(this_player()->query_real_name()) + "'s reaper is soaked with there opponents blood.\n");
	return(random(6)+3);
}
}
